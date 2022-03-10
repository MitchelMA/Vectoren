#include <cstdio>
#include <iostream>
#include <cmath>
#include "vector2.h"
#include "vector3.h"

#define PI 3.14159265359

using namespace std;
using namespace MathVector;

// prototypes to print out cords
void cordsPrint(Vector3 *vector);
void cordsPrint(Vector2 *vector);

int main(void)
{
     // initialize a Vector3 (3d vector: x, y, z) with x: 0, y: 0, z: 0
     Vector3 *MyVec3One = new Vector3();
     cout << "Vector3 cords:" << endl;
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Add 3 to the x:" << endl;
     MyVec3One->x += 3;
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Add 4 to the y:" << endl;
     MyVec3One->y += 4;
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Add 5 to the z:" << endl;
     MyVec3One->z += 5;
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Get the Dot (or scalar) Product of the vector:" << endl;
     cout << MyVec3One->dot(*MyVec3One) << endl;
     cout << MyVec3One->scalar(*MyVec3One) << endl;
     cout << endl;

     cout << "Get the magnitude of the vector:" << endl;
     cout << MyVec3One->mag() << endl;
     cout << sqrt(MyVec3One->dot(*MyVec3One)) << endl;
     cout << endl;

     cout << "Get the two directions of the vector (in degrees):" << endl;
     cout << (MyVec3One->heading()[0] * 180 / PI) << endl;
     cout << (MyVec3One->heading()[1] * 180 / PI) << endl;
     cout << endl;

     cout << "Multiply the vector by 2:" << endl;
     MyVec3One->mult(2);
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Then add 2 to all:" << endl;
     MyVec3One->add(2);
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Devide the vector by 2:" << endl;
     MyVec3One->div(2);
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Subtract 2 from the vector:" << endl;
     MyVec3One->sub(2);
     cordsPrint(MyVec3One);
     cout << endl;

     cout << "Set the magnitude of the vector to 10: " << endl;
     MyVec3One->setMag(10);
     cordsPrint(MyVec3One);
     cout << "Magnitude: " << MyVec3One->mag() << endl;
     cout << endl;

     cout << "Normalize the vector: " << endl;
     MyVec3One->norm();
     cordsPrint(MyVec3One);
     cout << "Magnitude: " << MyVec3One->mag() << endl;

     return 0;
}

void cordsPrint(Vector3 *vector)
{
     printf("(%0.2f, %0.2f, %0.2f)\n", vector->x, vector->y, vector->z);
}
void cordsPrint(Vector2 *vector)
{
     printf("(%0.2f, %0.2f)\n", vector->x, vector->y);
}