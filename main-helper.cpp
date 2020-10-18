#include "main-helper.h"

void MainHelper::fillList()
{
  for(int i=0; i < this->num_of_materials; i++)
  {
    this->materialList.append(
        new Material( 100,
                      qrand() % (sim_size_x + 1), qrand() % (sim_size_y + 1),
                      qrand() % (sim_size_x / 32), qrand() % (sim_size_y / 32),
                      acc_x, acc_y,
                      0, sim_size_x,
                      0, sim_size_y
                    )
    );
  }

}

MainHelper::MainHelper(int animation_time_quantum_ms, int simulation_time_quantum_ms)
{
  this->animation_time_quantum_ms = animation_time_quantum_ms;
  this->simulation_time_quantum_ms = simulation_time_quantum_ms;
  this->widget_main = new WidgetMain();
  this->widget_main->resize(sim_size_x, sim_size_y);
  this->timer = new QTimer();
  connect(this->timer, &QTimer::timeout, this, &MainHelper::timeout);

  this->fillList();

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

