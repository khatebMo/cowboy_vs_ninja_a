#pragma once

#include <string>
#include "Point.hpp"
namespace ariel{}
using namespace std;
class Character
{
private:
    Point location;
    int hp;
    string name;

public:
    Character(string name,const Point &lacation);
    ~Character();
    bool isAlive();
    double distance(const Character &other) const;
    void hit(int num);
    string getName();
    Point getLocation();
    virtual string print();
};