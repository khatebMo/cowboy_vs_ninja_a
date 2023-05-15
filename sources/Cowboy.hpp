#pragma once
#include"Character.hpp"
namespace ariel{}
class Cowboy:public Character{
    private:
    int bollets;
    public:
    Cowboy(string name,const Point &lacation);
    ~Cowboy();
    void shoot(const Character* other);
    bool hasboolets();
    void reload();
    string print();
};