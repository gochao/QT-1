#include <QApplication>
#include <QWidget>
#include <QPushButton>
int main(int argc, char ** argv)
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("hello QT!");

    /*需要指定父对象*/
    QPushButton b;
    b.setText("my button");
    b.setParent(&w);
    b.move(100,100);
    b.show();

    QPushButton b1(&w);
    b1.setText("myButton2");

    w.resize(400,300);
    w.show();
    app.exec();
    return 0;
}
