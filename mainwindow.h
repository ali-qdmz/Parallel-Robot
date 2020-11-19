#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <windows.h>

#include <QMainWindow>
#include <QUdpSocket>
#include <QThread>

#include <mythread.h>

namespace Ui {
class MainWindow;
class Start;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QUdpSocket m_socket;

    MyThread m_thread;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onDatagramReady();

    void on_Set_clicked();

    void on_Start_clicked();

    void on_Jogup_pressed();

    void on_Jogup_released();

    void on_Jogdown_pressed();

    void on_Jogdown_released();

private:
    Ui::MainWindow *ui;

signals:
    void setMotorValue(float value);

};




#endif // MAINWINDOW_H
