#pragma once
#include <cmath>

namespace MathVector
{
    class Vector3
    {
    private:
        float _x, _y, _z;

    public:
        // Initialize vector with x, y and z set to 0
        Vector3()
        {
            _x = 0;
            _y = 0;
            _z = 0;
        };
        // Initialize vector with x, y and z set to "value"
        Vector3(float value)
        {
            _x = value;
            _y = value;
            _z = value;
        }
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
        // Setter for all
        void set(float value) { _x = value, _y = value, _z = value; };
        // Setter for X and Y
        void set(float x, float y) { _x = x, _y = y; };
        // Setter for X, Y and Z
        void set(float x, float y, float z) { _x = x, _y = y, _z = z; };
        // set the x, y and z value of the vector
        void operator=(const float &value) { _x = value, _y = value, _z = value; };

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
            mult(2);
        }

        // Add another vector to this vector
        void add(Vector3 inVector)
        {
            _x += inVector._x;
            _y += inVector._y;
            _z += inVector._z;
        }
        // Add an input value to x, y and z
        void add(float value) { _x += value, _y += value, _z += value; };
        // Add an x and y value
        void add(float x, float y) { _x += x, _y += y; };
        // Add an x, y and z value
        void add(float x, float y, float z) { _x += x, _y += y, _z += z; };

        // Add another vector to this vector
        void operator+=(const Vector3 &inVector) { this->add(inVector); };
        // Add a number to the x, y and z values
        void operator+=(const float &value) { this->add(value); };

        // Get the sum of two vectors
        Vector3 *operator+(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->add(inVector);
            return vec;
        }
        // Get the sum between a vector and a number
        Vector3 *operator+(const float &value)
        {
            Vector3 *vec = this->copy();
            vec->add(value);
            return vec;
        }

        // Subtract a vector
        void sub(Vector3 inVector)
        {
            _x -= inVector._x;
            _y -= inVector._y;
            _z -= inVector._z;
        }
        // Subtract an input value from x, y and z
        void sub(float value) { _x -= value, _y -= value, _z -= value; };
        // Subtract an x and y value
        void sub(float x, float y) { _x -= x, _y -= y; };
        // Subtract an x, y and z value
        void sub(float x, float y, float z) { _x -= x, _y -= y, _z -= z; };

        // Subtract a vector
        void operator-=(const Vector3 &inVector) { this->sub(inVector); };
        // Subtract a number from this vector
        void operator-=(const float &value) { this->sub(value); };
        // Get the difference between the two vectors
        Vector3 *operator-(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->sub(inVector);
            return vec;
        }
        // Get the difference between a vector and a number
        Vector3 *operator-(const float &value)
        {
            Vector3 *vec = this->copy();
            vec->sub(value);
            return vec;
        }

        // Multiply this vector with another vector
        void mult(Vector3 inVector)
        {
            _x *= inVector._x;
            _y *= inVector._y;
            _z *= inVector._z;
        }
        // Multiply this vector with a factor
        void mult(float factor) { _x *= factor, _y *= factor, _z *= factor; };
        // Multiply this vector's x and y value
        void mult(float xFactor, float yFactor) { _x *= xFactor, _y *= yFactor; };
        // Multiply this vector's x, y and z value
        void mult(float xFactor, float yFactor, float zFactor) { _x *= xFactor, _y *= yFactor, _z *= zFactor; };

        // Multiply this vector with another vector
        void operator*=(const Vector3 &inVector) { this->mult(inVector); };
        // Multiply this vector with by a number
        void operator*=(const float &factor) { this->mult(factor); };
        // Multipliy two vectors with each other
        Vector3 *operator*(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->mult(inVector);
            return vec;
        }
        // Multiply a vector by a value
        Vector3 *operator*(const float &factor)
        {
            Vector3 *vec = this->copy();
            vec->mult(factor);
            return vec;
        }

        // Divide this vector by another vector
        void div(Vector3 inVector)
        {
            _x /= inVector._x;
            _y /= inVector._y;
            _z /= inVector._z;
        }
        // Divide this vector by a given factor
        void div(float factor) { _x /= factor, _y /= factor, _z /= factor; };
        // Divide this vector's x and y value
        void div(float xFactor, float yFactor) { _x /= xFactor, _y /= yFactor; };
        // Divide this vector's x, y and z value
        void div(float xFactor, float yFactor, float zFactor) { _x /= xFactor, _y /= yFactor, _z /= zFactor; };

        // Divide this vector by another vector
        void operator/=(const Vector3 &inVector) { this->div(inVector); };
        // Divide this vector by a number
        void operator/=(const float &value) { this->div(value); };
        // Divide a vector by another vector
        Vector3 *operator/(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->div(inVector);
            return vec;
        }
        // Divide a vector by a number
        Vector3 *operator/(const float &factor)
        {
            Vector3 *vec = this->copy();
            vec->div(factor);
            return vec;
        }

        // Returns the Dot Product of the two vectors
        float dot(Vector3 inVector) { return _x * inVector._x + _y * inVector._y + _z * inVector._z; };
        // Returns the Scalar Product of the two vectors
        float scalar(Vector3 inVector) { return dot(inVector); };
        // Returns the Dot Product with a number
        float dot(float factor) { return _x * factor + _y * factor + _z * factor; };
        // returns the Scalar Product with a number
        float scalar(float factor) { return dot(factor); };
        // Returns the Dot Product with three numbers
        float dot(float xFactor, float yFactor, float zFactor) { return _x * xFactor + _y * yFactor + _z * zFactor; };
        // Returns the Scalar Porduct with three numbers
        float scalar(float xFactor, float yFactor, float zFactor) { return dot(xFactor, yFactor, zFactor); };

        // Returns a float array with a length of 2
        // Index 0: x-y plane direction
        // Index 1: angle from z axis to the vector itself
        float *heading(void)
        {
            static float ret[2] = {0};
            float Phi = atan2(_y, _x);
            float x_yMag = sqrt(pow(_x, 2) + pow(_y, 2));
            float Theta = 3.14159265359 / 2 - atan2(_z, x_yMag);
            ret[0] = Phi;
            ret[1] = Theta;

            return ret;
        }

        // Copy this vector
        Vector3 *copy(void) { return new Vector3(_x, _y, _z); };
    };
}