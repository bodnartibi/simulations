#include "main-helper.h"

void MainHelper::fillList()
{
  for(int i=0; i < this->num_of_materials; i++)
  {
    this->materialList.append(
        new Material( 100,
                      qrand() % (sim_size_x + 1), qrand() % (sim_size_y + 1),
                      qrand() % (sim_size_x / 256), qrand() % (sim_size_y / 256),
                      acc_x, acc_y,
                      0, sim_size_x,
                      0, sim_size_y,
                      10
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

  for ( int i = 0; i < list_size; i++ ) {
    double x1, y1, r1, x2, y2, r2;

    this->materialList[i]->getPosition(x1, y1);
    this->materialList[i]->getRadius(r1);

    for ( int j = i + 1; j < list_size; j++)
    {
      this->materialList[j]->getPosition(x2, y2);
      this->materialList[j]->getRadius(r2);

      double distance = qSqrt(pow((x2-x1),2) + pow((y2-y1),2));

      if (distance <= (r1+r2))
      {
        this->materialList[i]->elasticCollision(this->materialList[j]);

        double nx1, ny1, nx2, ny2;

        nx1 = x1 + (x1 - x2)/2.0;
        nx2 = x2 + (x2 - x1)/2.0;
        ny1 = y1 + (y1 - y2)/2.0;
        ny2 = y2 + (y2 - y1)/2.0;

        this->materialList[i]->setPosition(nx1, ny1);
        this->materialList[j]->setPosition(nx2, ny2);
      }
    }
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

