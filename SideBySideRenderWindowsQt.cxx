#include "SideBySideRenderWindowsQt.h"

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>

#include <QImage>

// Constructor
SideBySideRenderWindowsQt::SideBySideRenderWindowsQt(unsigned char * data, SimThread &thread) :
    myArray(data)
{
  this->setupUi(this);

  // Sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = 
      vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor = 
      vtkSmartPointer<vtkActor>::New();
  sphereActor->SetMapper(sphereMapper);

  // VTK Renderer
  vtkSmartPointer<vtkRenderer> leftRenderer = 
      vtkSmartPointer<vtkRenderer>::New();
  leftRenderer->AddActor(sphereActor);

  // VTK/Qt wedded
  this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);

  // Set up action signals and slots
  connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

  connect(&thread, SIGNAL(frameFinished(unsigned char*,uint,uint)), this->label, SLOT(updateBuffer(unsigned char*,uint,uint)));

}

void SideBySideRenderWindowsQt::slotExit() 
{
  qApp->exit();
}
