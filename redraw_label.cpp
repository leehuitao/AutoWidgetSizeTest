#include "redraw_label.h"

#include <QMouseEvent>

RedrawLabel::RedrawLabel(QWidget *parent) :
    QLabel(parent)
{
    resize(500,500);
    setText("111");

    setStyleSheet("border: 2px solid black;");
    setScaledContents(true);
}

RedrawLabel::~RedrawLabel()
{

}

void RedrawLabel::wheelEvent(QWheelEvent *event)
{
    event->ignore();
    int x = event->x();
    int y = event->y();
    if(event->delta() > 0){
        //放大
        int newX = -(x*0.01);
        int newY = -(y*0.01);
        setGeometry(this->x()+newX,this->y()+newY,width()*1.01,height()*1.01);
    }else{
        //缩小
        int newX = x*0.01;
        int newY = y*0.01;
        setGeometry(this->x()+newX,this->y()+newY,width()*0.99,height()*0.99);
    }
}
