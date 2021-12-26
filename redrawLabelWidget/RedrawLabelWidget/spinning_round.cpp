#include "spinning_round.h"

#include <QPainter>
#include <QImage>

#define OuterRoundSize 150
#define InsideRoundSize 32
#define ProgressSize    5
SpinningRound::SpinningRound(QWidget *parent) : QLabel(parent)
{

}

void SpinningRound::paintEvent(QPaintEvent *)
{
    if(m_progress<0)
    {
        return;
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//设置圆滑绘制风格（抗锯齿）
    //定义矩形绘制区域
    QRectF outRect(0,0, OuterRoundSize, OuterRoundSize);//设置外圆大小
    QRectF inRect(0,0, OuterRoundSize, OuterRoundSize);//设定底层大小
    QRectF zRect(ProgressSize,ProgressSize, OuterRoundSize-(ProgressSize*2), OuterRoundSize-(ProgressSize*2));//设定遮罩大小
    //画底层
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#4e4e4e"));
    painter.drawEllipse(inRect);
    QRect source(0,0,InsideRoundSize,InsideRoundSize);

    //转换需要绘出的值  渐变的扇形
    QConicalGradient con (40,40,-m_progress-180);
    con.setColorAt(0.75,QColor("#3d3d3d"));
    con.setColorAt(0.5,QColor("#00bb56"));

    //    painter.rotate(90);
    painter.setPen(Qt::NoPen);
    painter.setBrush(con);//渐变色
    painter.drawPie(outRect,-m_progress*16,90*16);//设置外部边框
    //画遮罩

    painter.setPen(Qt::NoPen);
    painter.setBrush(palette().window().color());
    painter.drawEllipse(zRect);
    painter.drawImage(QPointF((OuterRoundSize-InsideRoundSize) / 2, (OuterRoundSize-InsideRoundSize) / 2), m_image, source);
    //Value为当前进度显示文字


}
