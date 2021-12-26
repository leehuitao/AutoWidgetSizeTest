#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_roundLabel = new SpinningRound(this);
    m_roundLabel->setImagePath("D:/3.png");
    m_roundLabel->resize(150,150);

    m_proressOfTheBarrel = new ProgressOfTheBarrel(this);
    m_proressOfTheBarrel->setImagePath("D:/3.png");
    m_proressOfTheBarrel->resize(150,150);
    m_proressOfTheBarrel->setGeometry(300,0,150,150);

    connect(&m_timer,&QTimer::timeout,[=]{
        m_progress += 3;
        if(m_progress == 360)
            m_progress = 0;
        m_roundLabel->setProgress(m_progress);
        m_proressOfTheBarrel->setProgress(m_progress);
    });
    m_timer.start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

