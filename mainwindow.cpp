#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "redraw_label.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    for(auto it : formList){
        it->setParentWH(this->width(),this->height());
        if(followThisResize){
            sortWidget4();
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
//    RedrawLabel *lab = new RedrawLabel(this);
//    lab->show();
    size = ui->lineEdit->text().toInt();
    for(int i = 0  ; i <size ;i++){
        Form* f = new Form(this);
        f->setLabel(QString::number(i+1));
        f->setParentWH(this->width(),this->height());
        f->show();
        formList.append(f);
    }
    sortWidget4();
}

void MainWindow::on_pushButton_2_clicked()
{
    sortWidget4();
}

void MainWindow::sortWidget4()
{

    int w = this->width()/col;
    int h = this->height()/row;
    int currentSortIndex = 0;
    for(auto it : formList){
        int currentX = currentSortIndex%col*w ;
        int currentY = currentSortIndex/col*h ;
        it->setGeometry( currentX, currentY , w , h);
        currentSortIndex++;
    }
}

void MainWindow::sortWidget6()
{
    int w = this->width()/col;
    int h = this->height()/row;
    int currentSortIndex = 0;
    for(auto it : formList){
        int currentX = currentSortIndex%3*col ;
        int currentY = currentSortIndex/3*col ;
        it->setGeometry( currentX, currentY , w , h);
        currentSortIndex++;
    }
}

void MainWindow::sortWidget9()
{
    int w = this->width()/col;
    int h = this->height()/row;
    int currentSortIndex = 0;
    for(auto it : formList){
        int currentX = currentSortIndex%3*col ;
        int currentY = currentSortIndex/3*col ;
        it->setGeometry( currentX, currentY , w , h);
        currentSortIndex++;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    for(auto it : formList){
        delete it;
    }
    formList.clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    row = ui->row_lineEdit->text().toInt();
    col = ui->col_lineEdit->text().toInt();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    followThisResize = arg1;
}

void MainWindow::on_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
