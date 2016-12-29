#ifndef POINT_H
#define POINT_H

namespace point
{

class Point //Представляет точку
{
public:
    Point(double x, double y);
    double GetX(); //Получение координаты
    double GetY(); //...
private:
    double x; //Координаты точки
    double y; //...
};

}


#endif // POINT_H
