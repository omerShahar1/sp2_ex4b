#include <iostream>
#include "Point.hpp"
#include "math.h"

using namespace std;
using namespace ariel;

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::distance(const Point &temp) const
{
    return sqrt(pow((this->x - temp.getX()), 2) + pow((this->y - temp.getY()), 2));
}

void Point::print() const
{
    cout << "(" << x << "," << y << ")" << endl;
}

Point Point::moveTowards(const Point &start, const Point &end, double number)
{
    if (number < 0)
    {
        throw invalid_argument("Distance is negative");
    }

    double new_dist = start.distance(end);
    if (new_dist <= number) // if the current distance is smaller or equel to the given number we return the end point
    {
        return end;
    }
    
    return Point(start.getX() + ((number / new_dist) * (end.getX() - start.getX())),  start.getY() + ((number / new_dist) * (end.getY() - start.getY())));
}
