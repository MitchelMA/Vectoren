#pragma once
#include <cmath>

namespace MathVector
{
    struct Vector2
    {

    public:
        float x, y;
        // Initialize vector with x and y set to 0
        Vector2()
        {
            x = 0;
            y = 0;
        }
        // Initialize vector with a given x and y value
        Vector2(float _x, float _y)
        {
            x = _x;
            y = _y;
        }
        // Initialize vector with by given angle
        Vector2(double angleRad)
        {
            x = cos(angleRad);
            y = sin(angleRad);
        }

        // Setter for both X and Y
        void set(float value) { x = value, y = value; };

        // Get the magnitude of the vector
        float mag(void) { return sqrt(pow(x, 2) + pow(y, 2)); };

        // Set the magnitude of the vector to the input value
        // Only works if the initial magnitude of the vector is not equal to 0
        void setMag(float magnitude)
        {
            float m = mag();
            if (m == 0)
                return;
            x = (x / m) * magnitude;
            y = (y / m) * magnitude;
        }

        // Normalizes the vector
        // Only works if the initial magnitued of the vector is not equal to 0
        void norm(void)
        {
            float m = mag();
            if (m == 0)
                return;
            x /= m;
            y /= m;
        }

        // Limits the magnitude of the vector to the input value
        void limit(float max)
        {
            float m = mag();
            if (m == 0 || m < max)
                return;
            norm();
            setMag(max);
        }

        // Add another vector to this vector
        void add(Vector2 inVector) { x += inVector.x, y += inVector.y; };
        // Add an input value to both the x and y
        void add(float value) { x += value, y += value; };
        // Add an x and y value seperately to the x and y value
        void add(float _x, float _y) { x += _x, y += _y; };

        // Add another vector to this vector
        void operator+=(const Vector2 &inVector) { this->add(inVector); };
        // Add a number to this vector
        void operator+=(const float &value) { this->add(value); };
        // Get the sum of the two vectors
        Vector2 *operator+(const Vector2 &inVector)
        {
            Vector2 *vec = this->copy();
            vec->add(inVector);
            return vec;
        }
        // Get the sum between a number and a vector
        Vector2 *operator+(const float &value)
        {
            Vector2 *vec = this->copy();
            vec->add(value);
            return vec;
        }

        // Subtract a vector from this vector
        void sub(Vector2 inVector) { x -= inVector.x, y -= inVector.x; };
        // Subtract the input value form both the x and y
        void sub(float value) { x -= value, y -= value; };
        // Subtract an x and a y value from this vector
        void sub(float _x, float _y) { x -= _x, y -= _y; };

        // Subtract a vector from this vector
        void operator-=(const Vector2 &inVector) { this->sub(inVector); };
        // Subtract a number from this vector
        void operator-=(const float &value) { this->sub(value); };
        // Get the difference between the two vectors
        Vector2 *operator-(const Vector2 &inVector)
        {
            Vector2 *vec = this->copy();
            vec->sub(inVector);
            return vec;
        }
        // Get the difference between a number and a vector
        Vector2 *operator-(const float &value)
        {
            Vector2 *vec = this->copy();
            vec->sub(value);
            return vec;
        }

        // Multiply this vector with another vector
        void mult(Vector2 inVector) { x *= inVector.x, y *= inVector.y; };
        // Multiply this vector with a factor
        void mult(float fact) { x *= fact, y *= fact; };
        // Multiply this vector by a given x and y value
        void mult(float xFactor, float yFactor) { x *= xFactor, y *= yFactor; };

        // Multiply this vector with another vector
        void operator*=(const Vector2 &inVector) { this->mult(inVector); };
        // Multiply this vector by a number
        void operator*=(const float &factor) { this->mult(factor); };
        // Multiply two vectors with each other
        Vector2 *operator*(const Vector2 &inVector)
        {
            Vector2 *vec = this->copy();
            vec->mult(inVector);
            return vec;
        }
        // Multiply a vector with a number
        Vector2 *operator*(const float &factor)
        {
            Vector2 *vec = this->copy();
            vec->mult(factor);
            return vec;
        }

        // Divide this vector by another vector
        void div(Vector2 inVector) { x /= inVector.x, y /= inVector.y; };
        // Divide this vector by a given factor
        void div(float fact) { x /= fact, y /= fact; };
        // Divide this vector by a given x and y value
        void div(float xFactor, float yFactor) { x /= xFactor, y /= yFactor; };

        // Divide this vector with another vector
        void operator/=(const Vector2 &inVector) { this->div(inVector); };
        // Divide this vector by a number
        void operator/=(const float &factor) { this->div(factor); };
        // Divide two vectors by each other
        Vector2 *operator/(const Vector2 &inVector)
        {
            Vector2 *vec = this->copy();
            vec->div(inVector);
            return vec;
        }
        // Divide a vector by a number
        Vector2 *operator/(const float &factor)
        {
            Vector2 *vec = this->copy();
            vec->div(factor);
            return vec;
        }

        // returns the Dot Product of the two Vectors
        float dot(Vector2 inVector) { return (x * inVector.x) + (y * inVector.y); };
        // returns the Scalar Product of the two Vectors
        float scalar(Vector2 inVector) { return dot(inVector); }
        // returns the Dot Product with a number
        float dot(float factor) { return (x * factor) + (y * factor); };
        // returns the Scalar Product with a number
        float scalar(float factor) { return dot(factor); }
        // returns the Dot Product with two numbers
        float dot(float xFactor, float yFactor) { return (x * xFactor) + (y * yFactor); };
        // returns the Scalar Product with two numbers
        float scalar(float xFactor, float yFactor) { return dot(xFactor, yFactor); }

        // returns the angle of two vectors
        float angle(Vector2 inVector)
        {
            float dotprod = dot(inVector);
            float totMag = mag() * inVector.mag();
            return acos(dotprod / totMag);
        }

        // Get the angle in radians of the vector
        float heading(void) { return atan2(y, x); };
        // Copy this vector
        Vector2 *copy(void) { return new Vector2(x, y); };
    };
}