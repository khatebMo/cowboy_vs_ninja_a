#pragma once
#include "Character.hpp"
namespace ariel
{
}
class Ninja : public Character
{
private:
    int speed;

public:
    Ninja(string name, const Point &lacation);
    void move(Character *other);
    virtual void slash(Character *other);
};