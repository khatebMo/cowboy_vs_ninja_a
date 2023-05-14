#include "Character.hpp"
#include "Point.hpp"
namespace ariel{}
Character::Character(string name,const Point &location) : name(name), location(location)
{
}
bool Character::isAlive()
{
    return true;
}
double Character::distance(const Character &other) const
{
    return 0;
}
void Character::hit(int num) {

}
string Character::getName(){
    return this->name;
}
Point Character::getLocation(){
    Point temp(1.1,2.2);
    return temp;
}
string Character::print(){
    return "";
}
