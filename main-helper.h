#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include <QTimer>
#include <QList>
#include <QGlobal.h>

#include "widget-main.h"
#include "material.h"

class MainHelper : public QObject
{
  Q_OBJECT

  QTimer *timer;
  WidgetMain *widget_main;

  QList<Material*> materialList;

  unsigned int animation_time_quantum_ms;
  unsigned int simulation_time_quantum_ms;

  unsigned int time_spent;

  int num_of_materials = 10;

  int sim_size_x = 800, sim_size_y = 600;
  double acc_x = 0, acc_y = 1;

  void fillList();
  void simulate();
  void animate();

  public:
    MainHelper(int animation_time_quantum_ms = 50, int simulation_time_quantum_ms = 5);
    void run();

  protected:

  signals:

  public slots:
    void timeout();

};

#endif // MAIN_HELPER_H
