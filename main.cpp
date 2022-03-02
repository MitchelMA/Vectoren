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
     Vector3 *myVec = new Vector3(3, 4, 5);
     Vector3 *my3 = new Vector3(3, 4, 5);
     cout << myVec->dot(*my3) << endl;
     cout << myVec->mag() << endl;
     cout << pow(myVec->scalar(*my3), 0.5) << endl;
     cout << myVec->getX() << endl;
     cout << myVec->getY() << endl;
     cout << myVec->getZ() << endl;
     return 0;
}