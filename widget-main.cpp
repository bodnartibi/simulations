#include "widget-main.h"

void WidgetMain::setMaterials(QList<Material*> list)
{
  this->materials = list;
}

void WidgetMain::paintEvent(QPaintEvent *event)
{

  this->painter = new QPainter(this);
  this->pen = new QPen(Qt::red, 2, Qt::SolidLine);
  this->painter->setPen(*this->pen);

  QListIterator<Material *> i(this->materials);
  Material *m;
  for ( int i = 0; i < this->materials.size(); i++ ) {
      double x, y, r;
      m = this->materials[i];
      m->getPosition(x, y);
      m->getRadius(r);
      this->painter->drawEllipse(QPointF(x,y), r, r);
  }

}
