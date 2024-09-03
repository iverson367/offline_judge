# offline_judge

问题：
onlinejudge有几个问题

1，测试数据一般都是保密的，用户无法获得测试数据，不能在本地调试。有些oj像leetcode有一些示例数据，但是不多。

2，有些oj像leetcode，每个题目的输入都不一样。在本地调试的时候需要做数据的转换，很麻烦

3，有些oj要收费，比如leetcode

4，有些oj，当出错的时候没有提供对应的输入数据，用户无法知道错误的原因。

总的来说，有很多问题，用户体验很不好。

解决方法：

主要思想是通过创建随机或固定的测试输入数据，从dmoj可以得到指定题目的正确代码，编译正确代码，运行，就可以得到测试用的参考输出数据，作为我们自己写程序的参考。

dmoj 

主要流程是： 以https://dmoj.ca/problem/16bitswonly 为例

使用系统：windows

使用IDE：Visual Studio2022。原因是支持c++17，可以使用stl的filesystem库。并且安装插件Microsoft Child Process Debugging Power Tool，用来调试子进程。

1，通过编程的方式来创建随机的输入数据，或者固定数据也可以，参考problem/16bitswonly/input.cpp文件。

2，登陆dmoj网站，把 https://dmoj.ca/problem/16bitswonly 上的正确代码拷贝下来，保存为problem/16bitswonly/main.cpp文件

3，修改CMakeLists.txt，添加到编译列表里。

4，右键选择CMakeLists.txt,添加调试配置，如下所示：

{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CMakeLists.txt",
      "projectTarget": "Engine.exe",
      "name": "debug 16bitswonly",
      "args": [ "16bitswonly" ]
    }
  ]
}

5，在菜单栏 调试->其他调试目标->Child Process Debugging Settings，勾选。 

6，在contest/16bitswonly下写main.cpp，可以写程序，下断点调试了。调试成功，就可以直接提交到dmoj。