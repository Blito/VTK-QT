#include "bufferlabel.h"

#include <QImage>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>

BufferLabel::BufferLabel(QWidget * parent)
    : QLabel(parent)
{

}

BufferLabel::~BufferLabel()
{

}

void BufferLabel::updateBuffer(const unsigned char * buffer, unsigned int width, unsigned int height)
{
    QPixmap p(QPixmap::fromImage(QImage(buffer, width, height, QImage::Format_Grayscale8)));

    QPainter painter(&p);
    QLineF line(begin.x(), begin.y(), end.x(), end.y());
    painter.drawLine(line);

    setPixmap(p);
    adjustSize();
}

void BufferLabel::mousePressEvent(QMouseEvent * event)
{
    begin = event->pos();
    isDragging = true;
}

void BufferLabel::mouseReleaseEvent(QMouseEvent * event)
{
    end = event->pos();
    isDragging = false;
}
