#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include <QTimer>
#include <QList>

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

  public:
    MainHelper(int animation_time_quantum_ms, int simulation_time_quantum_ms);
    void run();

  protected:

  signals:

  public slots:
    void timeout();

};

#endif // MAIN_HELPER_H
