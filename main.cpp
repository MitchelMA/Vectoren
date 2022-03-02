#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "vector2.h"

using namespace std;
using namespace MathVector;

int main(void)
{
     // instanciate a Vector with a given x and y
     Vector2 testVector_one = Vector2(1, 10);
     cout << "X value: " << testVector_one.getX() << endl
          << "Y value: " << testVector_one.getY() << endl
          << "Magnitude: " << testVector_one.mag() << endl
          << "Direction in radians: " << testVector_one.heading() << endl
          << endl;

     // instanciate a Vector with a given angle in radians
     Vector2 testVector_two = Vector2(4);
     cout << "X value: " << testVector_two.getX() << endl
          << "Y value: " << testVector_two.getY() << endl
          << "Magnitude: " << testVector_two.mag() << endl
          << "Direction in radians: " << testVector_two.heading() << endl;

     return 0;
}