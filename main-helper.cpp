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

  this->time_spent = 0;
}

void MainHelper::simulate()
{
  int list_size = this->materialList.size();

  for ( int i = 0; i < list_size; i++ ) {
    this->materialList[i]->move(0.1);
  }

}

void MainHelper::animate()
{
  this->widget_main->setMaterials(this->materialList);
  widget_main->update();
}

void MainHelper::timeout()
{
  this->simulate();
  if (animation_time_quantum_ms > simulation_time_quantum_ms)
  {
    time_spent += simulation_time_quantum_ms;
    if (time_spent > animation_time_quantum_ms)
    {
      this->animate();
      time_spent = 0;
    }
  }
  else
  {
    this->animate();
  }
  this->timer->start(simulation_time_quantum_ms);
}

void MainHelper::run()
{
  this->widget_main->show();
  this->timer->start(this->simulation_time_quantum_ms);
}

