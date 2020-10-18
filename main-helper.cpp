#include "main-helper.h"

MainHelper::MainHelper(int animation_time_quantum_ms, int simulation_time_quantum_ms)
{
  this->animation_time_quantum_ms = animation_time_quantum_ms;
  this->simulation_time_quantum_ms = simulation_time_quantum_ms;
  this->widget_main = new WidgetMain();
  this->timer = new QTimer();
  connect(this->timer, &QTimer::timeout, this, &MainHelper::timeout);

  this->materialList.append(new Material(100, 200, 200, 5, 1));
  this->materialList.append(new Material(150, 250, 500, 1, 1));
  this->materialList.append(new Material(180, 280, 400, 2, 0));
  this->materialList.append(new Material(150, 300, 300, -2, -1));
  this->materialList.append(new Material(150, 400, 250, -1, -1));
  this->materialList.append(new Material(180, 550, 200, -5, 0));
  this->materialList.append(new Material(180, 580, 170));

  this->widget_main->setMaterials(this->materialList);
}

void MainHelper::timeout()
{
  QListIterator<Material *> i(this->materialList);
  Material *m;
  for ( int i = 0; i < this->materialList.size(); i++ ) {
    m = this->materialList[i];
    m->move(1);
  }

  this->widget_main->setMaterials(this->materialList);
  widget_main->update();
  this->timer->start(this->animation_time_quantum_ms);
}

void MainHelper::run()
{
  this->widget_main->show();
  this->timer->start(this->animation_time_quantum_ms);
}

