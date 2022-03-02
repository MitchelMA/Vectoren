#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

namespace MathVector
{
    class Vector3
    {
    private:
        float _x, _y, _z;

    public:
        Vector3(float x, float y)
        {
            _x = x;
            _y = y;
            _z = 0;
        }
        Vector3(float x, float y, float z)
        {
            _x = x;
            _y = y;
            _z = z;
        }
        // returns a float array with a length of 2
        // index 0: x-y plane direction
        // index 1: angle from z axis to the vector itself
        float *heading()
        {
            static float ret[2] = {0};
            float Phi = atan2(_y, _x);
            float x_yMag = sqrt(pow(_x, 2) + pow(_y, 2));
            float Theta = M_PI_2 - atan2(_z, x_yMag);
            ret[0] = Phi;
            ret[1] = Theta;

            return ret;
        }
    };
}