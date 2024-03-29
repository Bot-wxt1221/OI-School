---
title: LKM开发
date: 2024-03-27
tags: [Linux]
toc: true
mathjax: true
---

Loadable Kernel Modules 用于动态向 Linux Kernel 插入代码，虽然但是不是很好写，接口经常变，几乎没有文档，所以记录一下一个简单的实例。

我们实现一个设备文件，可以读入读出数据即可。

# 准备工作

## Makefile

Makefile 在指定编译文件后需注意以 `-C **`的形式指定内核头文件的位置以 `-M xx`的形式指定源代码的位置。

给定示例：

```Makefile
obj-m+=lkm.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
test:
	sudo dmesg -C
	sudo insmod lkm.ko
	sudo rmmod lkm
	sudo dmesg
```

## 代码准备工作

对于每个模块，我们需要指定作者、开源协议等等信息，引入 `linux/modules.h` 头文件后，在全局以下列方式指定:

```cpp
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bot-wxt1221");
MODULE_DESCRIPTION("Only for a test.");
MODULE_VERSION("0.01");
```

另外需要指定加载、卸载模块的函数：

```cpp
module_init(lkm_example_init);
module_exit(lkm_example_exit);
```

请注意 `lkm_example_init` 的原型应该是：`int __init lkm_example_init(void);`，正常结束返回值为 $0$ 。

`lkm_example_exit` 的原型应该是：`void __exit lkm_example_exit(void);`

注意 `__init`,`__exit` 等关键字。

# 字符设备操作

若要实现文件读写，我们需要指定如何处理 `open` ，`close`，`read`，`write` 的操作，这些操作定义在 `struct file_operations` 内，有 `open` ，`release`，`write`，`read` 等函数指针替换为自己实现的就行了，之后使用这个对象去初始化设备文件，我们先行处理这些函数。函数原型可在 `Linux Kernel` 源码中找到。

## open

应有的函数原型：`int open_file(struct inode *,struct file *);`。

我们的实现较为简单分为以下若干步：

1. 查看是否已经被打开，按需返回繁忙信息。

2. 标记已打开，返回正常值。

3. 标记模块不可卸载。

因为我们只有一个文件，若有多个文件可通过 `struct file` 中的信息进行标识。

## close

函数原型：`int close_file(struct inode *node,struct file *file);`

1. 释放已打开的标识。

2. 重新标记模块可卸载。
