#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
  double pos_x, pos_y;
  double velocity_x, velocity_y;
  double accelerate_x, accelerate_y;
  double mass;

  public:
    Material(double mass,
             double pos_x, double pos_y,
             double velocity_x = 0, double velocity_y = 0,
             double accelerate_x = 0, double accelerate_y = 0);

    void setAccelerate(double accelerate_x, double accelerate_y);

    void move(int step);

    void getPosition(double &pos_x, double &pos_y);
};

#endif // MATERIAL_H
