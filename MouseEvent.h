#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

class MouseEvent:public QWidget
{
    Q_OBJECT
    public:
        MouseEvent(QWidget *parent=0);
        ~MouseEvent();
    protected:

    private:
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);
    signals:
        void touchPressEvent(QMouseEvent *e);
        void touchMoveEvent(QMouseEvent *e);
        void touchReleaseEvent(QMouseEvent *e);
};

#endif // MOUSEEVENT_H
