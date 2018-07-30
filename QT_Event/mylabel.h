#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

signals:

public slots:

};

#endif // MYLABEL_H
