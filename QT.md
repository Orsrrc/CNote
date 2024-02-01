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

## 信号和槽

通信机制  实现对象之间的数据交互

当用户或系统触发了一个动作 导致某个控件的状态发生了改变  该控件就发送一个信号

槽函数对某种特定信号的处理 用槽和其他对象信号建立连接 绑定  当该信号发生时 触发和执行



### 定义

#### 信号的定义

```c++
class name:public QObject
{
	O_OBJECT;//宏
	signals:
  	void signal_func(……); //信号函数
};
```

信号函数只需声明 不能写定义 底层使用信号的机制 QT做了封装

#### 槽函数

```c++
class name:public QObject{
  Q_OBJECT;
  public slots:
  void slot_func(){;} //槽函数
};
//槽函数可以连接到某个信号 当信号被发射时 槽函数将被触发和执行
```

### 信号和槽的连接

QObect::connet(const QObect* sender, const char* signal, const QObect* receiver, const char* method);

- sender 信号发送对象指针
- signal 信号的函数

- receiver 信号接收对象指针
- method 接收信号后要执行的槽函数

```c++
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char** argv)
{
  //创建应用程序对象
  QApplication app(argc, argv);
  QLabel label("点击按钮关闭标签");
  label.show();
  
  QPushButton button("关闭");
  button.show();
  
  //信号和槽函数的连接
  QObject::connect(&button, SIGNAL(clicked()), &label, SLOT(close()));
  
  //进入主事件循环
  return app.exe();
}
```



信号和槽函数参数要一致 槽函数可以被直接调用

信号函数的参数可以多于槽函数 多于参数将被忽略

参数和槽的连接若参数不匹配 但不会编译错误 只会在产生信号时没有槽函数处理 代表连接失败

![image-20240201185614474](QT.assets/image-20240201185614474.png)

该机制类似于调用槽函数时 不直接调用 通过信号触发槽函数  **信号只有提供槽函数数据的功能** (迭代器调用算法)
