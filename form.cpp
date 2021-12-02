#include "form.h"
#include "ui_form.h"
#include <QDebug>
#define min(a,b) ((a)<(b)? (a) :(b))
#define max(a,b) ((a)>(b)? (a) :(b))
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    edgeMargin = 20;        //设置检测边缘为20
    resizeDir = nodir;   //初始化检测方向为无
    setWindowFlags(Qt::FramelessWindowHint);  //设置无边框
    setMouseTracking(true); //开启鼠标追踪
    setMinimumSize(100,100);


}

Form::~Form()
{
    delete ui;
}

void Form::setLabel(QString str)
{
    ui->label->setText(str);
}

void Form::mousePressEvent(QMouseEvent * event)
{
    event->ignore();
    if (event->button() == Qt::LeftButton)  //每当按下鼠标左键就记录一下位置
    {
        this->raise();
        dragPosition = event->globalPos() - frameGeometry().topLeft();  //获得鼠标按键位置相对窗口左上面的位置
        QPoint p2 = event->pos();
        if(p2.x() > width() -8 && p2.y() > height() -8){
            currentx = p2.x();
            currenty = p2.y();
            currentw = width();
            currenth = height();
            editWidgetStatus = 1;
            QCursor tempCursor;
            tempCursor.setShape(Qt::SizeFDiagCursor);
            setCursor(tempCursor);
        }
    }
}
void Form::testEdge()
{
    int cursorx = cursor().pos().x();
    int cursory = cursor().pos().y();

    QCursor tempCursor;                                    //获得当前鼠标样式，注意:只能获得当前鼠标样式然后再重新设置鼠标样式
    tempCursor = cursor();                                 //因为获得的不是鼠标指针，所以不能这样用:cursor().setXXXXX

    if(cursorx < edgeMargin){                              //根据 边缘距离 分类改变尺寸的方向
        this->move(0,this->y());
    }
    else if(cursory < edgeMargin+20){
        this->move(this->x(),0);

    }
    else if(cursorx > parentw - edgeMargin){
        this->move(parentw - this->width(),this->y());
    }
    else if(cursory > parenth -edgeMargin){
        this->move(this->x(),parenth - this->height());
    }
    else{
        resizeDir = nodir;
        tempCursor.setShape(Qt::ArrowCursor);
    }

    setCursor(tempCursor);                    //重新设置鼠标,主要是改样式
}

void Form::mouseMoveEvent(QMouseEvent * event)
{
    event->ignore();
    if(!editWidgetStatus){

        if (event->buttons() & Qt::LeftButton){                 //如果左键是按下的
            if(resizeDir == nodir){
                QCursor tempCursor;                                    //获得当前鼠标样式，注意:只能获得当前鼠标样式然后再重新设置鼠标样式
                tempCursor = cursor();
                tempCursor.setShape(Qt::SizeAllCursor);
                setCursor(tempCursor);//如果鼠标不是放在边缘那么说明这是在拖动窗口
                move(event->globalPos() - dragPosition);
            }
            else{

                int ptop,pbottom,pleft,pright;                   //窗口上下左右的值
                ptop = frameGeometry().top();
                pbottom = frameGeometry().bottom();
                pleft = frameGeometry().left();
                pright = frameGeometry().right();
                if(resizeDir & top){                               //检测更改尺寸方向中包含的上下左右分量
                    if(height() == minimumHeight()){
                        ptop = min(event->globalY(),ptop);
                    }
                    else if(height() == maximumHeight()){
                        ptop = max(event->globalY(),ptop);
                    }
                    else{
                        ptop = event->globalY();
                    }
                }
                else if(resizeDir & bottom){
                    if(height() == minimumHeight()){
                        pbottom = max(event->globalY(),ptop);
                    }
                    else if(height() == maximumHeight()){
                        pbottom = min(event->globalY(),ptop);
                    }
                    else{
                        pbottom = event->globalY();
                    }
                }

                if(resizeDir & left){                        //检测左右分量
                    if(width() == minimumWidth()){
                        pleft = min(event->globalX(),pleft);
                    }
                    else if(width() == maximumWidth()){
                        pleft = max(event->globalX(),pleft);
                    }
                    else{
                        pleft = event->globalX();
                    }
                }
                else if(resizeDir & right){
                    if(width() == minimumWidth()){
                        pright = max(event->globalX(),pright);
                    }
                    else if(width() == maximumWidth()){
                        pright = min(event->globalX(),pright);
                    }
                    else{
                        pright = event->globalX();
                    }
                }
                setGeometry(QRect(QPoint(pleft,ptop),QPoint(pright,pbottom)));
            }
        }
        else {
            testEdge();   //当不拖动窗口、不改变窗口大小尺寸的时候  检测鼠标边缘
        }

    }else{
        this->resize(currentw +event->pos().x() - currentx ,currenth + event->pos().y() -currenty);
    }


}
void Form::mouseReleaseEvent(QMouseEvent *event)
{
    event->ignore();        //还原鼠标样式
    QCursor tempCursor;
    tempCursor = cursor();
    tempCursor.setShape(Qt::ArrowCursor);
    setCursor(tempCursor);
    testEdge();
    editWidgetStatus = 0;
}
