#include "Cowboy.hpp"
#include "Point.hpp"
#include "Character.hpp"
namespace ariel{}
Cowboy::Cowboy(string name, const Point &location) : Character(name, location), bollets(6)
{
}
Cowboy::~Cowboy(){}
void Cowboy::shoot(const Character *other)
{
}
bool Cowboy::hasboolets()
{
    return true;
}
void Cowboy::reload()
{
}
string Cowboy::print(){
 return"";
}