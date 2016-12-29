#include "point.h"

using namespace point;

Point::Point(double x, double y)
{
    Point::x=x;
    Point::y=y;
}

double Point::GetX()
{
    return Point::x;
}

double Point::GetY()
{
    return Point::y;
}
