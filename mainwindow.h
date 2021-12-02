#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void sortWidget4();
    void sortWidget6();
    void sortWidget9();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QList<Form*> formList;
    int size = 0;
    int row = 3;
    int col = 3;
    bool followThisResize = 0;
};
#endif // MAINWINDOW_H
