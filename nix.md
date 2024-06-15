---
title: NixOS 快速入门
date: 2024-06-14
tags: [Nix, NixOS]
toc: true
mathjax: true
---

# NixOS 快速使用

本文面向一定命令行基础的人食用。

## NixOS & Nix

NixOS 作为不变性系统，设计宗旨是为了保证软件包构建结果统一，为了做到这一点，每个软件包的构建过程都被认为是一个纯函数，该软件包构建过程的所有依赖为函数输入，Nix通过对这些输入计算哈希，通过哈希区分不同版本依赖软件包。

这也奠定了其 /nix/store 下放置所有文件，其他文件均以链接方式存在的基础，并且提供了难以想象的自由度。

## 系统安装

下载 [https://nixos.org/](https://nixos.org/) ，引导后连接网络。

### 更换 channel

```bash
sudo -i
nix-channel --add https://mirrors.ustc.edu.cn/nix-channels/nixpkgs-unstable nixpkgs  # 订阅镜像仓库频道
nix-channel --add https://mirrors.ustc.edu.cn/nix-channels/nixos-24.05 nixos  # 请注意系统版本
nix-channel --list  # 列出频道
nix-channel --update  # 更新并解包频道
nixos-rebuild --option substituters "https://mirror.ustc.edu.cn/nix-channels/store" switch --upgrade  # 临时切换二进制缓存源，并更新生成
```

建议均使用 unstable 。

### 分区

/boot 和 根目录必须有，其他任意。

然后挂载到 /mnt 相应位置

### 生成配置并部署

```bash
nixos-generate-config --root /mnt
```

系统内 nixos-help 可查阅文档。

然后我们修改一下配置，使用你常用的编辑器打开 /mnt/etc/nixos/configuration.nix

根据文档把 grub 和 NetWorkManager 先打开。

添加一个非 root 用户。

改完后

```bash
sudo nixos-install --option substituters "https://mirror.ustc.edu.cn/nix-channels/store"
```

最后会提醒你改 root 密码。

可以通过 `nixos-enter` 进入 chroot 环境更改非 root 用户密码。

然后重启，祈祷开机。

## 软件安装

你应该已经发现了，向 `environment.systemPackages` 内加入软件包名字即可安装软件。

然而如何应用更改呢？

在系统内可以用 `nixos-rebuild switch` 来更改。

接下来我们尝试安装桌面，以 Gnome 为例。

参照 NixOS Manual ：

```bash
services.xserver.desktopManager.gnome.enable = true;
services.xserver.displayManager.gdm.enable = true;
```

意味着启动这两个服务，相应软件会自动安装。

rebuild 后就可以看到桌面了。

接下来就可以乱装软件了，可以参照 NixOS wiki , NixOS Manual 进行折腾。

别急，Nix 的功力初见端倪，接下来我们引入两个实验特性 `Flakes & Nix Commands`

## Flakes & Nix Commands

即使此二者仍为实验性质，其已被广泛应用。

Flakes 是取代 channel 的功能，它旨在统一软件包尤其是 `nixpkgs` 的版本。

这里提到 `nixpkgs` 是 [https://github.com/NixOS/nixpkgs](https://github.com/NixOS/nixpkgs)

是 NixOS 及所有软件包的集合，NixOS 的开发都在这里进行。

Flakes 引入了一个 flakes.nix 用于管理所有输入，flakes.lock 以 git commits 和文件 hash 的方式固定版本。

这个特性的引入不仅提高了可复现性，并且可以同时引入多个对象。

我们可以引入 `nixpkgs` 的不同版本，使得系统中某个软件包停留在这个版本，可以引入其他作者的仓库提供更多软件，并且更新更及时（nixpkgs 审核要时间）。

Flakes 还可以提供不同的配置文件，使不同环境不会互相干扰，并且不用考虑容器化带来的效率问题，因为 Flakes 只需要简单的切换环境变量达到目的。

(实践待完善，推荐阅读[https://nixos-and-flakes.thiscute.world/zh/nixos-with-flakes/nixos-with-flakes-enabled](https://nixos-and-flakes.thiscute.world/zh/nixos-with-flakes/nixos-with-flakes-enabled))

## 奇技淫巧

### 非 NixOS 二进制软件

为了保证多版本软件共存，NixOS 不遵守 FHS 规范，导致大部分未经修改的软件无法直接运行，一般情况我们可以启用 `nix-ld` 提供一部分链接，很多软件也可以从 `nixpkgs` 里找到，Nix 在构建时提供了一个 'AutopatchelfHook' 可以在打包软件后自动解决动态库依赖问题。我们也可以优先考虑 flatpak 和 appimage ，其中 appimage 可以使用 `appimage-run` 运行, 安装 'nix-ld' 后大部分静态编译的程序也可运行。

也可以使用 `bwrap` 之类的轻量化容器。

以上方法成功率较大并且不复杂。

更多方法：[https://unix.stackexchange.com/questions/522822/different-methods-to-run-a-non-nixos-executable-on-nixos](https://unix.stackexchange.com/questions/522822/different-methods-to-run-a-non-nixos-executable-on-nixos)
