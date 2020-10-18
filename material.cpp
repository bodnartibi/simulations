#include "material.h"

Material::Material(double mass,
                   double pos_x, double pos_y,
                   double velocity_x, double velocity_y,
                   double accelerate_x, double accelerate_y)
{
  this->mass = mass;

  this->pos_x = pos_x;
  this->pos_y = pos_y;

  this->velocity_x = velocity_x;
  this->velocity_y = velocity_y;

  this->accelerate_x = accelerate_x;
  this->accelerate_y = accelerate_y;
}

void Material::setAccelerate(double accelerate_x, double accelerate_y)
{
  this->accelerate_x = accelerate_x;
  this->accelerate_y = accelerate_y;
}

void Material::move(int step)
{
  this->pos_x += step * this->velocity_x;
  this->velocity_x += step * this->accelerate_x;

  this->pos_y += step * this->velocity_y;
  this->velocity_y += step * this->accelerate_y;
}

void Material::getPosition(double &pos_x, double &pos_y)
{
  pos_x = this->pos_x;
  pos_y = this->pos_y;
}
