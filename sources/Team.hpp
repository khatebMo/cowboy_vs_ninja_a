#pragma once
#include "Character.hpp"
#include <vector>
#include"Point.hpp"
#include"Ninja.hpp"
#include"Cowboy.hpp"
#include"OldNinja.hpp"
#include"TrainedNinja.hpp"
#include"YoungNinja.hpp"
namespace ariel{}
class Team
{
private:
    vector<Character> team;
   // Character *leader;

public:
Team(Character *leader);
~Team();
void add(const Character *hero);
void attack(Team *other);
int stillAlive();
void print();

};