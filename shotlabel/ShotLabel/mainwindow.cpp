#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->img_lab,&ShotLabel::signMouseRelease,this,&MainWindow::onMouseRelease);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_select_img_btn_clicked()
{
    //打开操作
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open file"));
    if(!fileName.isEmpty()){
        ui->img_path->setText(fileName);
    }
    ui->img_lab->setImage(fileName);
}

void MainWindow::onMouseRelease(QRect rect)
{
    ui->pos_text->append("X:"+QString::number(rect.x())+"Y:"+QString::number(rect.y())+"W:"+QString::number(rect.width())+"H:"+QString::number(rect.height()));
}
