#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
 
#define BUFFER_LENGTH 256               ///< 缓冲区长度（简陋但是可以工作）
static char receive[BUFFER_LENGTH];     ///< 可加载内核模块接收缓存
 
int main(){
   int ret, fd;
   char stringToSend[BUFFER_LENGTH];
   printf("Starting device test code example...\n");
   fd = open("/dev/HelloBot", O_RDWR);             // 使用读写权限打开设备
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
   printf("Type in a short string to send to the kernel module:\n");
   scanf("%[^\n]%*c", stringToSend);                // 读取字符串（包含空格）
   printf("Writing message to the device [%s].\n", stringToSend);
   ret = write(fd, stringToSend, strlen(stringToSend)); // 将字符串发送给内核模块
   if (ret < 0){
      perror("Failed to write the message to the device.");
      return errno;
   }
 
   printf("Press ENTER to read back from the device...\n");
   getchar();
 
   printf("Reading from the device...\n");
   ret = read(fd, receive, BUFFER_LENGTH);        // 从内核模块读取响应
   if (ret < 0){
      perror("Failed to read the message from the device.");
      return errno;
   }
   printf("The received message is: [%s]\n", receive);
   printf("End of the program\n");
   return 0;
}
