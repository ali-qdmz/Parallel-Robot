#ifndef START_H
#define START_H

#include <QThread>

class Start : public QThread
{


public:
    Start();

    void run1();
    void run2();
    void run3();
    void run4();

};


#endif // START_H
