#ifndef SideBySideRenderWindowsQt_H
#define SideBySideRenderWindowsQt_H

#include <vtkSmartPointer.h>

#include <QMainWindow>

#include "ui_SideBySideRenderWindowsQt.h"

#include "simthread.h"

class SideBySideRenderWindowsQt : public QMainWindow, private Ui::SideBySideRenderWindowsQt
{
  Q_OBJECT

public:

  // Constructor/Destructor
  SideBySideRenderWindowsQt(unsigned char * data, SimThread &thread);
  ~SideBySideRenderWindowsQt() {}

public slots:

  virtual void slotExit();

private:
  unsigned char * myArray;
};

#endif
