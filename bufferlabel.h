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
    void updateBuffer(unsigned char * buffer, unsigned int width, unsigned int height);
};

#endif // BUFFERLABEL_H
