#include "qdeamonapp.h"

#include <QDebug>
#include <QFile>

QDeamonApp::QDeamonApp(int &argc, char **argv, int flags)
 : QCoreApplication(argc, argv, flags)
{
    connect(&m_socket, SIGNAL(readyRead()), this,SLOT(onSocketReadyRead()));
    m_socket.bind(QHostAddress::Any, 2080);
}

void QDeamonApp::chip0_activator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm0/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}




void QDeamonApp::chip2_activator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm2/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}


void QDeamonApp::chip3_activator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm3/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}





void QDeamonApp::chip5_activator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm5/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}




void QDeamonApp::chip7_activator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm7/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}


void QDeamonApp::chip0_deactivator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm0/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}




void QDeamonApp::chip2_deactivator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm2/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}


void QDeamonApp::chip3_deactivator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm3/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}





void QDeamonApp::chip5_deactivator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm5/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}






void QDeamonApp::chip7_deactivator()
{
    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm7/run");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}




void QDeamonApp::chip0_dircctivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio49/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}




void QDeamonApp::chip2_dircctivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio66/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}


void QDeamonApp::chip3_dircctivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio69/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}




void QDeamonApp::chip5_dircctivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio47/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}





void QDeamonApp::chip7_dircctivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio20/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("1");
    fl.close();
}



void QDeamonApp::chip0_dircdectivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio49/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}




void QDeamonApp::chip2_dircdectivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio66/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}


void QDeamonApp::chip3_dircdectivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio69/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}




void QDeamonApp::chip5_dircdectivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio47/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}





void QDeamonApp::chip7_dircdectivator()
{
    QFile fl;

    fl.setFileName("/sys/class/gpio/gpio20/value");
    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }
    fl.write("0");
    fl.close();
}







void QDeamonApp::chip0_duty_cycle_Set(QByteArray period,QByteArray duty_cycle)
{

    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm0/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write("0");
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm0/period_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(period);
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm0/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(duty_cycle);
    fl.close();


}








void QDeamonApp::chip2_duty_cycle_Set(QByteArray period,QByteArray duty_cycle)
{

    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm2/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write("0");
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm2/period_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(period);
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm2/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(duty_cycle);
    fl.close();


}



void QDeamonApp::chip3_duty_cycle_Set(QByteArray period,QByteArray duty_cycle)
{

    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm3/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write("0");
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm3/period_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(period);
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm3/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(duty_cycle);
    fl.close();


}







void QDeamonApp::chip5_duty_cycle_Set(QByteArray period,QByteArray duty_cycle)
{

    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm5/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write("0");
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm5/period_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(period);
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm5/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(duty_cycle);
    fl.close();


}






void QDeamonApp::chip7_duty_cycle_Set(QByteArray period,QByteArray duty_cycle)
{

    QFile fl;

    fl.setFileName("/sys/class/pwm/pwm7/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write("0");
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm7/period_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(period);
    fl.close();

    fl.setFileName("/sys/class/pwm/pwm7/duty_ns");

    if(!fl.open(QIODevice::WriteOnly)) {
        qDebug() << fl.errorString();
        return;
    }

    fl.write(duty_cycle);
    fl.close();


}





void QDeamonApp::onSocketReadyRead()
{

    QByteArray command;
    while(m_socket.hasPendingDatagrams()) {
        QByteArray data;
        data.resize(m_socket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        m_socket.readDatagram(data.data(), m_socket.pendingDatagramSize(), &sender, &senderPort);
        command.append(data);
    }

    //qDebug() << command;

    if(command.startsWith("ZAXIS"))  {
        QByteArrayList ls = command.split(',');
        QFile fl;

        chip0_duty_cycle_Set(ls[1],ls[2]);
        chip2_duty_cycle_Set(ls[3],ls[4]);
        chip3_duty_cycle_Set(ls[5],ls[6]);
        chip5_duty_cycle_Set(ls[7],ls[8]);
        chip7_duty_cycle_Set(ls[7],ls[8]);


     }

    else if(command.startsWith("ONZAXIS"))  {

        chip0_activator();
        chip2_activator();
        chip3_activator();
        chip5_activator();
        chip7_activator();



}
    else if(command.startsWith("OFFZAXIS"))  {

        chip0_deactivator();
        chip2_deactivator();
        chip3_deactivator();
        chip5_deactivator();
        chip7_deactivator();




}

    else if(command.startsWith("0activechip"))  {

        chip0_activator();

}

    else if(command.startsWith("2activechip"))  {

        chip2_activator();

}
    else if(command.startsWith("3activechip"))  {

        chip3_activator();

}

    else if(command.startsWith("5activechip"))  {

        chip5_activator();

}

    else if(command.startsWith("7activechip"))  {

        chip7_activator();

}
    else if(command.startsWith("0deactivechip"))  {

        chip0_deactivator();

}

    else if(command.startsWith("2deactivechip"))  {

        chip2_deactivator();

}
    else if(command.startsWith("3deactivechip"))  {

        chip3_deactivator();

}

    else if(command.startsWith("5deactivechip"))  {

        chip5_deactivator();

}

    else if(command.startsWith("7deactivechip"))  {

        chip7_deactivator();

}else if(command.startsWith("0dircactive"))  {

        chip0_dircctivator();

}else if(command.startsWith("2dircactive"))  {

        chip2_dircctivator();

}else if(command.startsWith("3dircactive"))  {

        chip3_dircctivator();

}else if(command.startsWith("5dircactive"))  {

        chip5_dircctivator();

}else if(command.startsWith("7dircactive"))  {

        chip7_dircctivator();

}else if(command.startsWith("0dedircactive"))  {

        chip0_dircdectivator();

}else if(command.startsWith("2dedircactive"))  {

        chip2_dircdectivator();

}else if(command.startsWith("3dedircactive"))  {

        chip3_dircdectivator();

}else if(command.startsWith("5dedircactive"))  {

        chip5_dircdectivator();

}else if(command.startsWith("7dedircactive"))  {

        chip7_dircdectivator();

}



}
