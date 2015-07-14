#include "SideBySideRenderWindowsQt.h"

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkCommand.h>
#include <vtkSmartPointer.h>

#include <QImage>

vtkActor * cubeActor;
vtkRenderWindow * renWin;
float rot = 0.0f;

class RotateCommand : public vtkCommand
{
public:
    vtkTypeMacro(RotateCommand, vtkCommand);

    static RotateCommand * New()
    {
        return new RotateCommand;
    }

    void Execute(vtkObject * vtkNotUsed(caller),
                 unsigned long vtkNotUsed(eventId),
                 void * vtkNotUsed(callData))
    {
        cubeActor->SetOrientation(0,0,0);
        cubeActor->RotateZ(rot++);

        renWin->Render();
    }
};

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

  // Cube
  vtkSmartPointer<vtkCubeSource> cubeSource =
      vtkSmartPointer<vtkCubeSource>::New();
  cubeSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
  cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
  cubeActor = vtkActor::New();
  cubeActor->SetMapper(cubeMapper);

  // VTK Renderer
  vtkSmartPointer<vtkRenderer> leftRenderer = 
      vtkSmartPointer<vtkRenderer>::New();
  leftRenderer->AddActor(sphereActor);
  leftRenderer->AddActor(cubeActor);

  renWin = qvtkWidgetLeft->GetRenderWindow();
  vtkRenderWindowInteractor * renderWindowInteractor = qvtkWidgetLeft->GetInteractor();
  renderWindowInteractor->CreateRepeatingTimer(1);
  RotateCommand * rotateCallback =  RotateCommand::New();
  renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, rotateCallback );

  // VTK/Qt wedded
  this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);

  // Set up action signals and slots
  connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

  connect(&thread, SIGNAL(frameFinished(const unsigned char*,uint,uint)), this->label, SLOT(updateBuffer(const unsigned char*,uint,uint)));

}

void SideBySideRenderWindowsQt::slotExit() 
{
  qApp->exit();
}
