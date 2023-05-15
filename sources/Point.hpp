#pragma once

namespace ariel{}
// using namespace std;
class Point
{
private:
    double x;
    double y;

public:
    // const
    Point(double x, double y);
    //~Point();
    double gitX();
    double gitY();


    double distance(const Point &other) const;
    void print();
    Point moveTowards(Point location, Point newLocation, double dist);
};