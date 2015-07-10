#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class SimThread : public QThread
{
    Q_OBJECT

public:
    SimThread();
    ~SimThread();

    unsigned char * arrayImage;
    const unsigned int arrayWidth = 256;
    const unsigned int arrayHeight = 256;

signals:
    void frameFinished(unsigned char * buffer, unsigned int width, unsigned int height);

private:
    void run() override;

    int colorOffset = 0;
};

#endif // THREAD_H
