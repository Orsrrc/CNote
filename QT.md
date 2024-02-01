# QT GUI

## 概念

**集成开发环境 IDE**

- 跨平台的C++图像用户界面(GUI)应用程序开发框架
- 可创建控制台程序  没有界面 提供系统调用 网络编程 数据库编程 2D/3D图形处理

- 跨平台  Linux Windows Mac OS x   Andriod IOS  嵌入式

![image-20240201144808523](QT.assets/image-20240201144808523.png)

**qmake** 构建makefile脚本文件

**designer** 可视化UI设计 生成.ui 文件

**uic** 把.ui文件 转化为C++编译器可编译的文件 转换为.h 

**assistant** Qt帮助文档

- Properties 属性

- Public Functions 公有函数

- Public Slots 公有槽函数

- Reimplemented Public Functions 重载后的公有函数

rcc 图片等在qt中视为资源  编译作为程序的一部分

moc 不属于c++标准库中的语法 将qt中特有语法翻译为c++编译器能够认识的语法

qtcreator 集成以上所有部件 最终使用

### QApplication Class

构造函数 QApplication(int argc, char** argv) 

由于没有默认值 故而main函数的参数中需要带有两个参数

desktop application 只有当用户点击叉了以后才会关闭 故而不需要写入return 0



## 编译为可执行文件

```C++
#include <QApplication> //
#include <QLabel> //标签类
int main(int argc, char** argv)
{
  QApplication(argc, argv);
  QLabel label("Hello World\n");
  //槽函数也可以做普通成员函数的调用
  label.show(); //显示标签
  return app.exec(); //进入循环等待
}
```

编译步骤 编译为一个可执行程序

![image-20240201160504126](QT.assets/image-20240201160504126.png)



```C++
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char** argv)
{
  //创建Qt应用程序对象
  QApplication app(argc, argv);
  
  //创建标签控件
  QLabel label("I am Label");
  //显示标签
  label.show();
  
  //创建按钮控件
  QPushButton button("I am Button");
  
  //显示按钮
  button.show();
  //进入主事件循环并等待exit()调用
  return app.exe();
}
```

## Qt父窗口 

将多个部件放到一个窗口内

常用父窗口

- QWidget
- QMainWindow //Qwidget的子类
- QDialog //QWidget 子类

**inherited by** 被谁继承

![image-20240201162131211](QT.assets/image-20240201162131211.png)

move基于父窗口的原点位置(x 向右增大 y向左增大)通常来说 左上角为原点

```C++
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>


int main(int argc, char** argv)
{
  //创建Qt应用程序对象
  QApplication app(argc, argv);
  
  QWidget parent;
  parent.move(500, 400);
  parent.resize(300, 200)； //父窗口的大小
  
  //创建标签控件
  QLabel label("I am Label", &parent);
  label.move(50, 40); //标签的位置
  label.resize(200, 40); //标签的大小
  //显示标签
//  label.show();
  
  //创建按钮控件
  QPushButton button("I am Button", &parent);
  button.move(90, 120);
  button.resize(120, 40);
  
  
  QPushBUtton* pBtn = new QPushButton("关闭", &parent);
  pBtn->move(170, 90);
  pBtn->resize(90, 30);
  
  //显示按钮
 // button.show();
  
  //由于show函数显示的是该控件及其子控件 则只需要显示父控件就回显示所有的子控件
  parent.show();
  //进入主事件循环并等待exit()调用
  return app.exe();
}
```

