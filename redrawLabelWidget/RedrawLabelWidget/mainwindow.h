#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "spinning_round.h"
#include "progress_of_the_barrel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    SpinningRound   *           m_roundLabel;

    ProgressOfTheBarrel *       m_proressOfTheBarrel;

    QTimer                      m_timer;

    int                         m_progress = 0;
};
#endif // MAINWINDOW_H
