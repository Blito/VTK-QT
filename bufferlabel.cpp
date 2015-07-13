#include "bufferlabel.h"

#include <QImage>
#include <QPixmap>

BufferLabel::BufferLabel(QWidget * parent)
    : QLabel(parent)
{

}

BufferLabel::~BufferLabel()
{

}

void BufferLabel::updateBuffer(unsigned char * buffer, unsigned int width, unsigned int height)
{
    setPixmap(QPixmap::fromImage(QImage(buffer, width, height, QImage::Format_Grayscale8)));
    adjustSize();
}
