#include "bufferlabel.h"

#include <QImage>
#include <QPixmap>

BufferLabel::BufferLabel(QWidget * parent)
    : QLabel(parent),
      image(0)
{

}

BufferLabel::~BufferLabel()
{

}

void BufferLabel::updateBuffer(unsigned char * buffer, unsigned int width, unsigned int height)
{
    if (image != 0)
        delete image;

    image = new QImage(buffer, width, height, QImage::Format_Grayscale8);
    setPixmap(QPixmap::fromImage(*image));
    adjustSize();
}
