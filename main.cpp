#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "vector2.h"
#include "vector3.h"

using namespace std;
using namespace MathVector;

int main(void)
{
     Vector3 *myVec = new Vector3(3, 4, 6);
     Vector2 *my2 = new Vector2(3, 4);
     cout << (myVec->heading()[1] * 180 / M_PI) << endl;
     cout << my2->heading() << endl;
     return 0;
}