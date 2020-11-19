#ifndef QDEAMONAPP_H
#define QDEAMONAPP_H

#include <QCoreApplication>

#include <QUdpSocket>

#ifndef QByteArrayList
typedef QList<QByteArray> QByteArrayList;
#endif

class QDeamonApp : public QCoreApplication
{
    Q_OBJECT

    QUdpSocket m_socket;
public:
    explicit QDeamonApp(int &argc, char **argv, int flags = ApplicationFlags);

signals:

public slots:

    void onSocketReadyRead();
    void chip0_activator();
    void chip2_activator();
    void chip3_activator();
    void chip5_activator();
    void chip7_activator();
    void chip0_deactivator();
    void chip2_deactivator();
    void chip3_deactivator();
    void chip5_deactivator();
    void chip7_deactivator();
    void chip0_duty_cycle_Set(QByteArray period, QByteArray duty_cycle);
    void chip2_duty_cycle_Set(QByteArray period, QByteArray duty_cycle);
    void chip3_duty_cycle_Set(QByteArray period, QByteArray duty_cycle);
    void chip5_duty_cycle_Set(QByteArray period, QByteArray duty_cycle);
    void chip7_duty_cycle_Set(QByteArray period, QByteArray duty_cycle);
    void chip0_dircctivator();
    void chip2_dircctivator();
    void chip3_dircctivator();
    void chip5_dircctivator();
    void chip7_dircctivator();
    void chip0_dircdectivator();
    void chip2_dircdectivator();
    void chip3_dircdectivator();
    void chip5_dircdectivator();
    void chip7_dircdectivator();

};

#endif // QDEAMONAPP_H
