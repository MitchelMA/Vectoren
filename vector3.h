#pragma once
#include <cmath>

namespace MathVector
{
    struct Vector3
    {

    public:
        float x, y, z;
        // Initialize vector with x, y and z set to 0
        Vector3()
        {
            x = 0;
            y = 0;
            z = 0;
        };
        // Initialize vector with x, y and z set to "value"
        Vector3(float value)
        {
            x = value;
            y = value;
            z = value;
        }
        // Initialize vector with an x and a y value
        Vector3(float _x, float _y)
        {
            x = _x;
            y = _y;
            z = 0;
        }
        // Initialize vector with an x, y and z value
        Vector3(float _x, float _y, float _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }

        // Setter for all
        void set(float value) { x = value, y = value, z = value; };
        // Setter for X and Y
        void set(float _x, float _y) { x = _x, y = _y; };
        // Setter for X, Y and Z
        void set(float _x, float _y, float _z) { x = _x, y = _y, z = _z; };

        // Get the magnitude of the vector
        float magnitude(void) { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); };

        // Set the magnitude of the vector
        // Will only work if the current magnitude is not equal to 0
        void setMag(float mag)
        {
            float m = magnitude();
            if (m == 0)
                return;
            x = (x / m) * mag;
            y = (y / m) * mag;
            z = (z / m) * mag;
        }

        // Normalizes the vector
        // Will only work if the current magnitude is not equal to 0
        void normalize(void)
        {
            float m = magnitude();
            if (m == 0)
                return;
            x /= m;
            y /= m;
            z /= m;
        }

        // Returns the unit-vector of this vector
        Vector3 *normalized()
        {
            Vector3 *temp = this->copy();
            temp->normalize();
            return temp;
        }

        // Limits the magnitude of the vector
        // Will only work if the current magnitude is not equal to 0
        void limit(float max)
        {
            float m = magnitude();
            if (m == 0 || m < max)
                return;
            normalize();
            setMag(max);
        }

        // Add another vector to this vector
        void add(const Vector3 &inVector)
        {
            x += inVector.x;
            y += inVector.y;
            z += inVector.z;
        }
        // Add an input value to x, y and z
        void add(float value) { x += value, y += value, z += value; };
        // Add an x and y value
        void add(float _x, float _y) { x += _x, y += _y; };
        // Add an x, y and z value
        void add(float _x, float _y, float _z) { x += _x, y += _y, z += _z; };

        // Add another vector to this vector
        void operator+=(const Vector3 &inVector) { this->add(inVector); };
        // Add a number to the x, y and z values
        void operator+=(const float &value) { this->add(value); };

        // Get the sum of two vectors
        Vector3 &operator+(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->add(inVector);
            return *vec;
        }
        // Get the sum between a vector and a number
        Vector3 &operator+(const float &value)
        {
            Vector3 *vec = this->copy();
            vec->add(value);
            return *vec;
        }

        // Subtract a vector
        void sub(const Vector3 &inVector)
        {
            x -= inVector.x;
            y -= inVector.y;
            z -= inVector.z;
        }
        // Subtract an input value from x, y and z
        void sub(float value) { x -= value, y -= value, z -= value; };
        // Subtract an x and y value
        void sub(float _x, float _y) { x -= _x, y -= _y; };
        // Subtract an x, y and z value
        void sub(float _x, float _y, float _z) { x -= _x, y -= _y, z -= _z; };

        // Subtract a vector
        void operator-=(const Vector3 &inVector) { this->sub(inVector); };
        // Subtract a number from this vector
        void operator-=(const float &value) { this->sub(value); };
        // Get the difference between the two vectors
        Vector3 &operator-(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->sub(inVector);
            return *vec;
        }
        // Get the difference between a vector and a number
        Vector3 &operator-(const float &value)
        {
            Vector3 *vec = this->copy();
            vec->sub(value);
            return *vec;
        }

        // Multiply this vector with another vector
        void mult(const Vector3 &inVector)
        {
            x *= inVector.x;
            y *= inVector.y;
            z *= inVector.z;
        }
        // Multiply this vector with a factor
        void mult(float factor) { x *= factor, y *= factor, z *= factor; };
        // Multiply this vector's x and y value
        void mult(float xFactor, float yFactor) { x *= xFactor, y *= yFactor; };
        // Multiply this vector's x, y and z value
        void mult(float xFactor, float yFactor, float zFactor) { x *= xFactor, y *= yFactor, z *= zFactor; };

        // Multiply this vector with another vector
        void operator*=(const Vector3 &inVector) { this->mult(inVector); };
        // Multiply this vector with by a number
        void operator*=(const float &factor) { this->mult(factor); };
        // Multipliy two vectors with each other
        Vector3 &operator*(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->mult(inVector);
            return *vec;
        }
        // Multiply a vector by a value
        Vector3 &operator*(const float &factor)
        {
            Vector3 *vec = this->copy();
            vec->mult(factor);
            return *vec;
        }

        // Divide this vector by another vector
        void div(const Vector3 &inVector)
        {
            x /= inVector.x;
            y /= inVector.y;
            z /= inVector.z;
        }
        // Divide this vector by a given factor
        void div(float factor) { x /= factor, y /= factor, z /= factor; };
        // Divide this vector's x and y value
        void div(float xFactor, float yFactor) { x /= xFactor, y /= yFactor; };
        // Divide this vector's x, y and z value
        void div(float xFactor, float yFactor, float zFactor) { x /= xFactor, y /= yFactor, z /= zFactor; };

        // Divide this vector by another vector
        void operator/=(const Vector3 &inVector) { this->div(inVector); };
        // Divide this vector by a number
        void operator/=(const float &factor) { this->div(factor); };
        // Divide a vector by another vector
        Vector3 &operator/(const Vector3 &inVector)
        {
            Vector3 *vec = this->copy();
            vec->div(inVector);
            return *vec;
        }
        // Divide a vector by a number
        Vector3 &operator/(const float &factor)
        {
            Vector3 *vec = this->copy();
            vec->div(factor);
            return *vec;
        }

        // Returns the Dot Product of the two vectors
        float dot(const Vector3 &inVector) { return x * inVector.x + y * inVector.y + z * inVector.z; };
        // Returns the Scalar Product of the two vectors
        float scalar(const Vector3 &inVector) { return dot(inVector); };
        // Returns the Dot Product with a number
        float dot(float factor) { return x * factor + y * factor + z * factor; };
        // returns the Scalar Product with a number
        float scalar(float factor) { return dot(factor); };
        // Returns the Dot Product with three numbers
        float dot(float xFactor, float yFactor, float zFactor) { return x * xFactor + y * yFactor + z * zFactor; };
        // Returns the Scalar Porduct with three numbers
        float scalar(float xFactor, float yFactor, float zFactor) { return dot(xFactor, yFactor, zFactor); };

        // returns the Vector cross product of the two vectors
        Vector3 *vectorProd(const Vector3 &inVector)
        {
            /*
                    | i  j  k |
            r x s = | a  b  c | = | b  c |    | a  c |    | a  b |
                    | d  e  f |   | e  f |i - | d  f |j + | d  e |k

            r x s = (bf - ce)i - (af - cd)j + (ae - bd)k
            */
            // i:
            float newX = this->y * inVector.z - this->z * inVector.y;
            // j:
            float newY = -1 * (this->x * inVector.z - this->z * inVector.x);
            // k:
            float newZ = this->x * inVector.y - this->y * inVector.x;

            return new Vector3(newX, newY, newZ);
        }

        // linear interpolation between 2 vectors at a time instance t
        Vector3 *lerp(Vector3 &inVector, float t)
        {
            Vector3 *tmp1 = this->copy();
            Vector3 *tmp2 = inVector.copy();

            tmp2->sub(*tmp1);
            tmp2->mult(t);
            tmp1->add(*tmp2);
            free(tmp2);

            return tmp1;
        }

        // returns the angle of two vectors
        float angle(Vector3 &inVector)
        {
            float dotprod = dot(inVector);
            float totMag = magnitude() * inVector.magnitude();
            return acos(dotprod / totMag);
        }

        // returns the vector rotated around the x-axis by the given angle in radians
        Vector3 *rotatedXAxis(float radians)
        {
            // this method uses the following matrix-transform:
            //|1     0           0| |Vx|
            //|0   cos θ    −sin θ| |Vy|
            //|0   sin θ     cos θ| |Vz|
            // where 0 is the angle in radians and V is the vector the method was called on

            float newY = cos(radians) * this->y + -sin(radians) * this->z;
            float newZ = sin(radians) * this->y + cos(radians) * this->z;
            return new Vector3(this->x, newY, newZ);
        }

        // returns the vector rotated around the y-axis by the given angle in radians
        Vector3 *rotatedYAxis(float radians)
        {
            // this method uses the following matrix-transform:
            //| cos θ    0   sin θ| |Vx|
            //|   0      1       0| |Vy|
            //|−sin θ    0   cos θ| |Vz|
            // where θ is the angle in radians and V the vector the method was called on

            float newX = cos(radians) * this->x + sin(radians) * this->z;
            float newZ = -sin(radians) * this->x + cos(radians) * this->z;
            return new Vector3(newX, this->y, newZ);
        }

        // returns the vector rotated around the z-axis by the given angle in radians
        Vector3 *rotatedZAxis(float radians)
        {
            // this method uses the following matrix-transform:
            //|cos θ   −sin θ   0| |Vx|
            //|sin θ    cos θ   0| |Vy|
            //|  0       0      1| |Vz|
            // where 0 is the angle in radians and V the vector the method was called on
            float newX = cos(radians) * this->x + -sin(radians) * this->y;
            float newY = sin(radians) * this->x + cos(radians) * this->y;
            return new Vector3(newX, newY, this->z);
        }

        // Returns a float array with a length of 2
        // Index 0: x-y plane direction
        // Index 1: angle from z axis to the vector itself
        float *heading(void)
        {
            static float ret[2] = {0};
            float Phi = atan2(y, x);
            // in this case: the Z is the opposite side, and the magnitude of the vector is the hypotenuse
            // using the arccosine you get the angle from the Z-axis to the vector
            float Theta = acos(z / magnitude());
            ret[0] = Phi;
            ret[1] = Theta;

            return ret;
        }

        // Copy this vector
        Vector3 *copy(void) { return new Vector3(x, y, z); };
    };
}