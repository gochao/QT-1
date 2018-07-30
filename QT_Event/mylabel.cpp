#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i= ev->x();
    int j = ev->y();

    QString text = QString("<center><h1></h1></center>");
}
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{

}
