#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <linux/stat.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
long mseal(void *addr,size_t len,unsigned long flags){
	return syscall(__NR_mseal,addr,len,flags);
}
struct stat buf;
int main(){
	int fd=open("/home/wxt/a.txt",O_RDWR);
	if(fd<0){
		printf("file open error: %d",fd);
		return fd;
	}
	int ret=stat("/home/wxt/a.txt",&buf);
	char *MMap=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MMap==MAP_FAILED){
		close(fd);
		printf("mmap failed error: %p",MMap);
		return -1;
	}
  printf("the file is: %s",MMap);
  MMap[0]=getchar();
  printf("the file is: %s",MMap);
  ret=mseal(MMap,buf.st_size,0);
  if(ret<0){
    printf("mseal failed error: %d",ret);
    return ret;
  }
  ret=munmap(MMap,buf.st_size);
  if(ret<0){
    printf("munmap failed error: %d",ret);//it failed
    return ret;
  }
	return 0;
}
