#include <QApplication>
#include "SideBySideRenderWindowsQt.h"
#include "simthread.h"

int main( int argc, char** argv )
{

    int j = 0;
    unsigned char * arrayImage = new unsigned char[256*256];
    for (int i = 0; i < 256*256; i++)
    {
        arrayImage[i] = i%255;
    }

    // QT Stuff
    QApplication app( argc, argv );

    SimThread thread;
  
    SideBySideRenderWindowsQt sideBySideRenderWindowsQt(arrayImage, thread);

    sideBySideRenderWindowsQt.show();

    thread.start();
  
    app.exec();

    return 0;
}
