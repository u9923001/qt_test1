#include "MouseEvent.h"

MouseEvent::MouseEvent(QWidget *parent):QWidget(parent)
{
    parent->setMouseTracking(true);
}

MouseEvent::~MouseEvent( )
{

}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    emit touchPressEvent(e);
}

void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    emit touchMoveEvent(e);
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    emit touchReleaseEvent(e);
}
