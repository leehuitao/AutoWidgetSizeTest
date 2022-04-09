#ifndef SHOTLABEL_H
#define SHOTLABEL_H
#include <QMap>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#define  labelw 1280
#define  labelh 720

struct DetectArea {
    QVector<QRect>        rect;
    QVector<QPolygonF>    polygon;
};

enum ShotType{
    DrawRect    = 1,
    DrawPolygon = 2,
    DrawRound   = 3
};
class ShotLabel : public QLabel
{
    Q_OBJECT


public:
    ShotLabel(QWidget *wid = nullptr);

    void setDrawType(ShotType t){
        m_drawType =t;
    }
    void setImage(QImage img){
        this->m_img = img;
        update();
    }

    void setStartBuild(bool build){
        m_startbuild = build;
    }

    void setDetectArea(DetectArea r){
        m_allExistingArea = r;
        update();
    }

    DetectArea getDetectArea(){
        return m_allExistingArea;
    }


Q_SIGNALS:
    void signMouseRelease(QRect);

    void signUpdateArea(DetectArea);
protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);//鼠标抬起
    void paintEvent(QPaintEvent *event);
    //判断点和初始点是否需要闭合
    bool checkPFPDistance(int x, int y);

    bool checkWithInRect(int x, int y);

    bool checkOnTheOutline(int x, int y);
    void drawPolygon();
    void drawLine();
private:

    //--------------------通用变量-----------------
    QImage              m_img;
    int                 m_x;
    int                 m_y;
    int                 m_currentCheckRect = -1;
    int                 m_currentMode = 0 ;// 0画  1移动  2缩放
    int                 m_currentRectX;
    int                 m_currentRectY;
    bool                m_startbuild=true;
    bool                m_build=false;
    ShotType            m_drawType;
    DetectArea          m_allExistingArea;
    //--------------------矩形变量-----------------
    QRect               m_rect;//当前编辑的矩形
    //-------------------多边形变量-----------------
    //点位是否闭合
    bool                m_closed=false;
    QVector<QPointF>    m_currentPoint;
    QVector<QPointF>    m_uiList;
    QVector<QPointF>    m_realList;


};
#endif // SHOTLABEL_H
