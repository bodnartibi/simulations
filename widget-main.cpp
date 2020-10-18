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
      double x, y;
      m = this->materials[i];
      m->getPosition(x, y);
      this->painter->drawPoint(x, y);
  }


  //draw an ellipse
  //The setRenderHint() call enables antialiasing, telling QPainter to use different
  //color intensities on the edges to reduce the visual distortion that normally
  //occurs when the edges of a shape are converted into pixels
//  this->painter->setRenderHint(QPainter::Antialiasing, true);
//  this->painter->setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap));
//  this->painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
//  this->painter->drawEllipse(this->size[0]--, this->size[1]--, this->size[2]--, this->size[3]--);
}
