#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QObject>
#include <QMouseEvent>

namespace Ui { class Form; }

class Form : public QWidget
{
    Q_OBJECT
public:
    Form(QWidget *parent = 0);
    ~Form();
    void setLabel(QString );
    void setParentWH(int w, int h ){parentw = w;parenth = h;}
private:
    Ui::Form *ui;
    QPoint dragPosition;   //鼠标拖动的位置
    int    edgeMargin;     //鼠标检测的边缘距离
    enum {nodir,
          top = 0x01,
          bottom = 0x02,
          left = 0x04,
          right = 0x08,
          topLeft = 0x01 | 0x04,
          topRight = 0x01 | 0x08,
          bottomLeft = 0x02 | 0x04,
          bottomRight = 0x02 | 0x08} resizeDir; //更改尺寸的方向
    bool editWidgetStatus = 0;
private:
    void testEdge();  //检测鼠标是否接近窗口边缘
    int parentw;
    int parenth;
    int currentx;
    int currenty;
    int currentw;
    int currenth;
protected:
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);


};

#endif // FORM_H
