#include "material.h"

Material::Material(double mass,
                   double pos_x, double pos_y,
                   double velocity_x, double velocity_y,
                   double accelerate_x, double accelerate_y,
                   int border_x_min, int border_x_max, int border_y_min, int border_y_max)
{
  this->mass = mass;

  this->pos_x = pos_x;
  this->pos_y = pos_y;

  this->velocity_x = velocity_x;
  this->velocity_y = velocity_y;

  this->accelerate_x = accelerate_x;
  this->accelerate_y = accelerate_y;

  this->border_x_min = border_x_min;
  this->border_x_max = border_x_max;
  this->border_y_min = border_y_min;
  this->border_y_max = border_y_max;
}

void Material::setAccelerate(double accelerate_x, double accelerate_y)
{
  this->accelerate_x = accelerate_x;
  this->accelerate_y = accelerate_y;
}

void Material::move(const int step)
{
  pos_x += step * velocity_x;
  velocity_x += step * accelerate_x;

  pos_y += step * velocity_y;
  velocity_y += step * accelerate_y;

  if (pos_x < border_x_min)
  {
    pos_x = border_x_min + (border_x_min - pos_x);
    velocity_x = -velocity_x;
  }
  else if (pos_x > border_x_max)
  {
    pos_x = border_x_max - (pos_x - border_x_max);
    velocity_x = -velocity_x;
  }


  if (pos_y < border_y_min)
  {
    pos_y = border_y_min + (border_y_min - pos_y);
    velocity_y = -velocity_y;
  }
  if (pos_y > border_y_max)
  {
    pos_y = border_y_max - (pos_y - border_y_max);
    velocity_y = -velocity_y;
  }
}

void Material::getPosition(double &pos_x, double &pos_y)
{
  pos_x = this->pos_x;
  pos_y = this->pos_y;
}
