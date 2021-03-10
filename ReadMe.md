[toc]

# MKlinkOpenCV

## 这是什么

> **MKlinkOpenCV**是一款我依据我个人配置制做的快速拷贝或者硬链接各个版本的OpenCV的便捷软件
>
> 但是这个需要在环境变量中添加opencv的路径的，例如我的部分环境如下：
>
> ![img\EnvironmentVar.png](.\img\EnvironmentVar.png)
>
> | 变量       | 值                          |
> | ---------- | --------------------------- |
> | OpenCV_310 | D:\opencv3.1.0\opencv\build |
> | OpenCV_330 | D:\opencv3.3.0\build        |
> | OpenCV_343 | D:\opencv3.3.0\gpu343       |
> | OpenCV_411 | D:\opencv4.1.1\build        |
>
> 

## 为什么制做这个

> **懒**
> 毕竟我配置了好几个opencv的环境，各种项目换着用，一个一个去复制粘贴dll太麻烦。最开始是只想做复制粘贴的，但是后面接触到了硬链接，也就一起做了。

## 复制粘贴与硬链接的区别

> 复制粘贴出来的是两个相同的文件，占用两份的空间。而硬链接出来的是一个文件，在不同的地方，并且只占用一份的空间。
> **注意：硬链接只能在同一个盘里执行。例如源文件在C盘，你想把它硬链接到D盘这是不可能的。**

## 关于删除

> 这个是我随手做的，建议无视。
> 如果你们想用，可以在源代码中把密码重新设置一下，或者删除密码这个选项都可以。
> **注意：数据无价，删除应该谨慎。**

## 关于直接执行的单选框

> 勾选直接执行会直接执行命令，不勾选会复制到粘贴板。