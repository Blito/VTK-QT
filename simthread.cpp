#include "simthread.h"

SimThread::SimThread()
{
    arrayImage = new unsigned char[arrayWidth*arrayHeight];
}

SimThread::~SimThread()
{

}

void SimThread::run()
{
    while (true)
    {
        for (int i = 0; i < arrayWidth*arrayHeight; i++)
        {
            arrayImage[i] = (i+colorOffset)%255;
        }
        colorOffset++;
        emit frameFinished(arrayImage, arrayWidth, arrayHeight);
        usleep(5);
    }
}
