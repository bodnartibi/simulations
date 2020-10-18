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

  int animation_time_quantum_ms;
  int simulation_time_quantum_ms;

  int num_of_materials = 10;

  int sim_size_x = 800, sim_size_y = 600;
  double acc_x = 0, acc_y = 1;

  void fillList();

  public:
    MainHelper(int animation_time_quantum_ms, int simulation_time_quantum_ms);
    void run();

  protected:

  signals:

  public slots:
    void timeout();

};

#endif // MAIN_HELPER_H
