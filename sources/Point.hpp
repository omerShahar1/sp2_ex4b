#pragma once

namespace ariel
{
    class Point
    {
    private:
        double x, y;

    public:
        Point(double, double); //constructor
        Point(); //empty constructor
        double getX() const;
        double getY() const;
        double distance(const Point&) const; //return distance between two points
        void print() const;
        static Point moveTowards(const Point&, const Point&, double); //return the closest point to the src relative to the given number
    };
}


