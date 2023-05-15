#include "doctest.h"
#include "sources/Team.hpp"
#include <vector>
#include <math.h>
#include <sstream>
#include <cmath>
using namespace ariel;
using namespace std;

TEST_SUITE("Point")
{

    TEST_CASE("Testing distance between two points")
    {
        Point p1(1, 1);
        Point p2(4, 5);
        Point p3(17, 5);
        Point p4(15, 2);
        CHECK(p1.distance(p2) == 5);
        CHECK(p2.distance(p3) == 13);
        CHECK_LT(p1.distance(p3), 17);
        CHECK_GT(p1.distance(p3), 16);
        CHECK_LT(p1.distance(p2), p2.distance(p3));
        CHECK(p1.distance(p1) == 0);
    }
    // לזוז ל moveTowards מקבלת נקודת מקור, נקודת יעד ומרחק.
    //  הפונקציה מחזירה את הנקודה הקרובה ביותר לנקודת היעד,
    //  – שנמצאת כל היותר במרחק הנתון מנקודת המקור
    TEST_CASE("Testing MoveToWards function")
    {
        Point p1(0, 0);
        Point p2(12, 0);
        Point p3(15, 0);
        Point p4 = p1.moveTowards(p1, p3, 14);
        CHECK(p4.gitX() == p2.gitX());
        CHECK(p4.gitY() == p2.gitY());
    }
}

TEST_SUITE("Character")
{
    Point ninja1Location(1, 2);
    Point cowboy1Location(3, 3);
    Point ninja_2Location(1, 7);
    Point ninja_3Location(0, 0);
    Point cowboy_2Location(3, 0);
    OldNinja old_ninja("old", ninja1Location);
    YoungNinja young("young", ninja_2Location);
    TrainedNinja trained("Trained", ninja_3Location);
    Cowboy firstCowBoy("first", cowboy1Location);
    Cowboy secondCowBoy("second", cowboy_2Location);

    TEST_CASE("Testing hit() & isAlive() function")
    {
        young.hit(90);
        CHECK(young.isAlive() == true);
        young.hit(10);
        CHECK(young.isAlive() == false);
        CHECK(old_ninja.isAlive() == true);
        old_ninja.hit(100);
        CHECK(old_ninja.isAlive() == true);
        old_ninja.hit(50);
        CHECK(old_ninja.isAlive() == false);
        CHECK(firstCowBoy.isAlive() == true);
        firstCowBoy.hit(110);
        CHECK(firstCowBoy.isAlive() == false);
    }
    TEST_CASE("Testing Shoot , reload and hasboolets() cowboy's function")
    {
        CHECK(firstCowBoy.hasboolets() == true);
        for (int i = 0; i < 6; i++)
        {
            firstCowBoy.shoot(&secondCowBoy);
        }
        CHECK(firstCowBoy.hasboolets() == false);
        CHECK(secondCowBoy.isAlive() == false);
        firstCowBoy.reload();
        CHECK(firstCowBoy.hasboolets() == true);
    }

    TEST_CASE("Testing getName() and getLocation finctions")
    {
        CHECK(firstCowBoy.getName() == "first");
        Point temp = firstCowBoy.getLocation();
        CHECK(temp.gitX() == cowboy1Location.gitX());
        CHECK(temp.gitY() == cowboy1Location.gitY());
        CHECK_FALSE(firstCowBoy.getName() == secondCowBoy.getName());
    }
}
TEST_SUITE("Ninja")
{
    Point ninja1Location(1, 2);
    Point cowboy1Location(3, 3);
    Point ninja_2Location(1, 7);
    Point ninja_3Location(0, 0);
    Point cowboy_2Location(3, 0);
    OldNinja old_ninja("old", ninja1Location);
    YoungNinja young("young", ninja_2Location);
    TrainedNinja trained("Trained", ninja_3Location);
    Cowboy firstCowBoy("first", cowboy1Location);
    Cowboy secondCowBoy("second", cowboy_2Location);

    TEST_CASE("Testing Ninja move function")
    {
        double before=old_ninja.distance(young);
        old_ninja.move(&young);
        double after=old_ninja.distance(young);
        CHECK(before>after);

    }
    TEST_CASE("Testing slash() function"){
        old_ninja.slash(&trained);//first time
        old_ninja.slash(&trained);//second time 
        CHECK(trained.isAlive()==true);
        old_ninja.slash(&trained);
        CHECK(trained.isAlive()==false);

    }
}
