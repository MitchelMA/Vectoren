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
        // Initialize vector with an x and a y value
        Vector3(float x, float y)
        {
            _x = x;
            _y = y;
            _z = 0;
        }
        // Initialize vector with an x, y and z value
        Vector3(float x, float y, float z)
        {
            _x = x;
            _y = y;
            _z = z;
        }

        // Getter for X
        float getX(void) { return _x; };
        // Getter for Y
        float getY(void) { return _y; };
        // Getter for Z
        float getZ(void) { return _z; };

        // Setter for X
        void setX(float x) { _x = x; };
        // Setter for Y
        void setY(float y) { _y = y; };
        // Setter for Z
        void setZ(float z) { _z = z; };
        // Setter for X and Y
        void set(float x, float y)
        {
            _x = x;
            _y = y;
        };
        // Setter for X, Y and Z
        void set(float x, float y, float z)
        {
            _x = x;
            _y = y;
            _z = z;
        }

        // Get the magnitude of the vector
        float mag(void) { return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2)); };

        // Set the magnitude of the vector
        // Will only work if the current magnitude is not equal to 0
        void setMag(float magnitude)
        {
            float m = mag();
            if (m == 0)
                return;
            _x = (_x / m) * magnitude;
            _y = (_y / m) * magnitude;
            _z = (_z / m) * magnitude;
        }

        // Normalizes the vector
        // Will only work if the current magnitude is not equal to 0
        void norm(void)
        {
            float m = mag();
            if (m == 0)
                return;
            _x /= m;
            _y /= m;
            _z /= m;
        }

        // Limits the magnitude of the vector
        // Will only work if the current magnitude is not equal to 0
        void limit(float max)
        {
            float m = mag();
            if (m == 0)
                return;
            norm();
            // mult(2);
        }

        // Add another vector to this vector
        void add(Vector3 vector)
        {
            _x += vector.getX();
            _y += vector.getY();
            _z += vector.getZ();
        }
        // Add an input value to x, y and z
        void add(float value) { _x, _y, _z += value; };
        // Add an x and y value
        void add(float x, float y)
        {
            _x += x;
            _y += y;
        }
        // Add an x, y and z value
        void add(float x, float y, float z)
        {
            _x += x;
            _y += y;
            _z += z;
        }

        // Subtract a vector
        void sub(Vector3 vector)
        {
            _x -= vector.getX();
            _y -= vector.getY();
            _z -= vector.getZ();
        }
        // Subtract an input value from x, y and z
        void sub(float value) { _x, _y, _z -= value; };
        // Subtract an x and y value
        void sub(float x, float y)
        {
            _x -= x;
            _y -= y;
        }
        // Subtract an x, y and z value
        void sub(float x, float y, float z)
        {
            _x -= x;
            _y -= y;
            _z -= z;
        }

        // Multiply this vector with another vector
        void mult(Vector3 vector)
        {
            _x *= vector.getX();
            _y *= vector.getY();
            _z *= vector.getZ();
        }
        // Multiply this vector with a factor
        void mult(float factor) { _x, _y, _z *= factor; };
        // Multiply this vector's x and y value
        void mult(float xFactor, float yFactor)
        {
            _x *= xFactor;
            _y *= yFactor;
        }
        // Multiply this vector's x, y and z value
        void mult(float xFactor, float yFactor, float zFactor)
        {
            _x *= xFactor;
            _y *= yFactor;
            _z *= zFactor;
        }

        // Divide this vector by another vector
        void div(Vector3 vector)
        {
            _x /= vector.getX();
            _y /= vector.getY();
            _z /= vector.getZ();
        }
        // Divide this vector by a given factor
        void div(float factor) { _x, _y, _z /= factor; };
        // Divide this vector's x and y value
        void div(float xFactor, float yFactor)
        {
            _x /= xFactor;
            _y /= yFactor;
        }
        // Divide this vector's x, y and z value
        void div(float xFactor, float yFactor, float zFactor)
        {
            _x /= xFactor;
            _y /= yFactor;
            _z /= zFactor;
        }

        // Returns the Dot Product of the two vectors
        float dot(Vector3 vector) { return _x * vector.getX() + _y * vector.getY() + _z * vector.getZ(); };
        // Returns the Scalar Product of the two vectors
        float scalar(Vector3 vector) { return dot(vector); };

        // Returns a float array with a length of 2
        // Index 0: x-y plane direction
        // Index 1: angle from z axis to the vector itself
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