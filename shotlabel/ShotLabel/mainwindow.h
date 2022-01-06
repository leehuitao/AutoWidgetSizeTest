#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shot_polygon_label.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_select_img_btn_clicked();

    void onMouseRelease(QRect);

    void slotDrawPolygon(QVector<QPointF>);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
