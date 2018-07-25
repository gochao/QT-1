#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(50,50);

    b2 = new QPushButton(this);
    b2->setText("abc");

    /*信号接收者, 处理的信号,信号接收者,槽函数*/
    connect(&b1,&QPushButton::pressed, this,&Widget::close);

    /*自定义槽函数   无返回值*/
    connect(b2, &QPushButton::released, this,&Widget::mySlot);

    /**/
    connect(b2, &QPushButton::released, &b1,&QPushButton::hide);

    setWindowTitle("老大");

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(100,100);
//    w.show();
    connect(&b3, &QPushButton::released, this, &Widget::changeWin);
    //处理子窗口的信号
    void (SubWidget::*funSignal)()=&SubWidget::mySignal;
    connect(&w, funSignal, this,&Widget::dealSub);

    void (SubWidget::*testSignal)(int, QString)=&SubWidget::mySignal;
    connect(&w, testSignal, this,&Widget::dealSlot);
    resize(400,300);


    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式！");
    b4->move(200,100);

//    int a=10, b=100;//默认修饰为只读
//    connect(b4, &QPushButton::released,
//           [=]()  mutable//拷贝的过程效率低安全,&是
//    {
//        b4->setText("我是b4");
//        qDebug() << "11111";
//        a = 11;
//        qDebug() << a << b;
//    }
//            );
    connect(b4, &QPushButton::clicked,
            [=](bool isCheck)  mutable//拷贝的过程效率低安全,&是
    {
        qDebug() << isCheck;
    }
    );

}

void Widget::dealSlot(int a, QString str)
{
    qDebug() << a << str.toUtf8().data();
}
void Widget::mySlot()
{
    b2->setText("123");
}
void Widget::dealSub()
{
    w.hide();
    this->show();
}
void Widget::changeWin()
{
    //显示子窗口,隐藏本窗口
    w.show();
   this->hide();
}

Widget::~Widget()
{

}
