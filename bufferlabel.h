#ifndef BUFFERLABEL_H
#define BUFFERLABEL_H

#include <QLabel>

class BufferLabel : public QLabel
{
    Q_OBJECT

public:
    BufferLabel(QWidget* parent=0);
    ~BufferLabel();

public slots:
    void updateBuffer(const unsigned char * buffer, unsigned int width, unsigned int height);

private:
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

    QPoint begin, end;
    bool isDragging = false;
};

#endif // BUFFERLABEL_H
