#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include <QtGui>
#include <QWidget>
#include <QListIterator>
#include <QList>

#include "material.h"

class WidgetMain : public QWidget
{
  Q_OBJECT

  int size[4] = {200, 80, 400, 240};
  QPainter *painter;
  QPen *pen;
  QList<Material*> materials;

  public:
    void setMaterials(QList<Material*> list);

  protected:
    void paintEvent(QPaintEvent *event);

  signals:

  public slots:

};

#endif // WIDGET_MAIN_H
