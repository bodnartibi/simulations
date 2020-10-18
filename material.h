#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
  double pos_x, pos_y;
  double velocity_x, velocity_y;
  double accelerate_x, accelerate_y;
  double mass;

  int border_x_min, border_x_max, border_y_min, border_y_max;

  void reboundFromBorder();

  public:
    Material(double mass,
             double pos_x, double pos_y,
             double velocity_x = 0, double velocity_y = 0,
             double accelerate_x = 0, double accelerate_y = 0,
             int border_x_min = 0, int border_x_max = 800, int border_y_min = 0, int border_y_max = 600);

    void setAccelerate(double accelerate_x, double accelerate_y);

    void move(const int step);

    void getPosition(double &pos_x, double &pos_y);
};

#endif // MATERIAL_H
