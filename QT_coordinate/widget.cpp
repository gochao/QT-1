#include "widget.h"
#include <QPushButton>
#include "mybutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    move(100,100);

    QPushButton *b1 = new QPushButton(this);
    b1->move(100,100);
    b1->setText("xxx");
    b1->resize(100,100);

    QPushButton *b2 = new QPushButton(this);
    b2->move(100,250);
    b2->setText("sss");

    MyButton *b3 = new MyButton(this);
    b3->move(50,50);
    b3->setText("ddd");

}

Widget::~Widget()
{

}
