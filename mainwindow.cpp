#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <windows.h>
#include <QUdpSocket>
#include <QMessageBox>
#include <QThread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(setMotorValue(float)), &m_thread, SLOT(motor1(float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onDatagramReady()
{
    QByteArray str;
    while(m_socket.hasPendingDatagrams()) {
        char buff[255] = {0};
        QHostAddress senderAddress;
        quint16 senderPort;

        m_socket.readDatagram(buff, 255, &senderAddress, &senderPort);
        str.append(buff);

    }
}





void MainWindow::on_Set_clicked()
{
    float Feedrate1 = ui->Motor1_feedrate->text().toFloat();
    float Feedrate2 = ui->Motor2_feedrate->text().toFloat();
    float Feedrate3 = ui->Motor3_feedrate->text().toFloat();
    float Feedrate4 = ui->Motor4_feedrate->text().toFloat();


    float Screw = 3;
    float Driver = 1600;

    float Period1;
    float duty_cycle1;
    float Period2;
    float duty_cycle2;
    float Period3;
    float duty_cycle3;
    float Period4;
    float duty_cycle4;

    float x1;
    float x2;
    float x3;
    float x4;

    x1 = (Feedrate1/Screw);
    x2 = (Feedrate2/Screw);
    x3 = (Feedrate3/Screw);
    x4 = (Feedrate4/Screw);

    Period1 = (1000000000/(x1*Driver));
    duty_cycle1 = (Period1*(0.5));
    Period1 = round(Period1);
    duty_cycle1 = round(duty_cycle1);


    Period2 = (1000000000/(x2*Driver));
    duty_cycle2 = (Period2*(0.5));
    Period2 = round(Period2);
    duty_cycle2 = round(duty_cycle2);


    Period3 = (1000000000/(x3*Driver));
    duty_cycle3 = (Period3*(0.5));
    Period3 = round(Period3);
    duty_cycle3 = round(duty_cycle3);


    Period4 = (1000000000/(x4*Driver));
    duty_cycle4 = (Period4*(0.5));
    Period4 = round(Period4);
    duty_cycle4 = round(duty_cycle4);


    QByteArray strPeriod1 = QByteArray::number(Period1);
    QByteArray strduty_cycle1 = QByteArray::number(duty_cycle1);

    QByteArray strPeriod2 = QByteArray::number(Period2);
    QByteArray strduty_cycle2 = QByteArray::number(duty_cycle2);

    QByteArray strPeriod3 = QByteArray::number(Period3);
    QByteArray strduty_cycle3 = QByteArray::number(duty_cycle3);

    QByteArray strPeriod4 = QByteArray::number(Period4);
    QByteArray strduty_cycle4 = QByteArray::number(duty_cycle4);

    QUdpSocket socket;
    QByteArray buff = "ZAXIS,";
    buff = buff.append(strPeriod1+","+strduty_cycle1+","+strPeriod2+","+strduty_cycle2+","+strPeriod3+","+strduty_cycle3+","+strPeriod4+","+strduty_cycle4);

    if( socket.writeDatagram(buff,QHostAddress("192.168.7.2"),2080) < 0) {
        QMessageBox::critical(this, "Error", socket.errorString());
        return;
    }

    socket.waitForBytesWritten(-1);
    ui->Lcd->clear();
    ui->Lcd->addItem(buff);

}



void MainWindow::on_Start_clicked()
{
    emit setMotorValue(ui->Motor1_feedrate->text().toFloat());
}

void MainWindow::on_Jogup_pressed()
{
    QUdpSocket socket;
    QByteArray buff = "ONZAXIS";

    if( socket.writeDatagram(buff,QHostAddress("192.168.7.2"),2080) < 0) {
        QMessageBox::critical(this, "Error", socket.errorString());
        return;
    }

    socket.waitForBytesWritten(-1);
}

void MainWindow::on_Jogup_released()
{
    QUdpSocket socket;
    QByteArray buff = "OFFZAXIS";

    if( socket.writeDatagram(buff,QHostAddress("192.168.7.2"),2080) < 0) {
        QMessageBox::critical(this, "Error", socket.errorString());
        return;
    }

    socket.waitForBytesWritten(-1);
}

void MainWindow::on_Jogdown_pressed()
{
    QUdpSocket socket;
    QByteArray buff = "DIRONZAXIS";

    if( socket.writeDatagram(buff,QHostAddress("192.168.7.2"),2080) < 0) {
        QMessageBox::critical(this, "Error", socket.errorString());
        return;
    }

    socket.waitForBytesWritten(-1);
}

void MainWindow::on_Jogdown_released()
{
    QUdpSocket socket;
    QByteArray buff = "DIROFFZAXIS";

    if( socket.writeDatagram(buff,QHostAddress("192.168.7.2"),2080) < 0) {
        QMessageBox::critical(this, "Error", socket.errorString());
        return;
    }

    socket.waitForBytesWritten(-1);
}
