#pragma once
#include <cmath>

class Vector
{
private:
    float x;
    float y;

public:
    // Initialize vector with a given x and y value
    Vector(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    // Initialize vector with by given angle
    Vector(double angleRad)
    {
        x = cos(angleRad);
        y = sin(angleRad);
    }

    // Getter for X;
    float getX(void)
    {
        return x;
    }
    // Getter for Y
    float getY(void)
    {
        return y;
    }
    // Setter for X
    void setX(float _x)
    {
        x = _x;
    }
    // Setter for Y
    void setY(float _y)
    {
        y = _y;
    }
    // Setter for X and Y
    void set(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    // Get the magnitude of the vector
    float mag(void)
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
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
        if (m < max)
            return;
        norm();
        mult(2);
    }
    // Add another vector to this vector
    void add(Vector inputVector)
    {
        x += inputVector.getX();
        y += inputVector.getY();
    }
    // Add an input value to both the x and y
    void add(float value)
    {
        x += value;
        y += value;
    }
    // Add an x and y value seperately to the x and y value
    void add(float _x, float _y)
    {
        x += _x;
        y += _y;
    }
    // Subtract a vector from this vector
    void sub(Vector inputVector)
    {
        x -= inputVector.getX();
        y -= inputVector.getY();
    }
    // Subtract the input value form both the x and y
    void sub(float value)
    {
        x -= value;
        y -= value;
    }
    // Subtract an x and a y value from this vector
    void sub(float _x, float _y)
    {
        x -= _x;
        y -= _y;
    }
    // Multiply this vector with another vector
    void mult(Vector vector)
    {
        x *= vector.getX();
        y *= vector.getY();
    }
    // Multiply this vector with a factor
    void mult(float fact)
    {
        x *= fact;
        y *= fact;
    }
    // Multiply this vector by a given x and y value
    void mult(float xFactor, float yFactor)
    {
        x *= xFactor;
        y *= yFactor;
    }
    // Divide this vector by another vector
    void div(Vector vector)
    {
        x /= vector.getX();
        y /= vector.getY();
    }
    // Divide this vector by a given factor
    void div(float fact)
    {
        x /= fact;
        y /= fact;
    }
    // Divide this vector by a given x and y value
    void div(float xFactor, float yFactor)
    {
        x /= xFactor;
        y /= yFactor;
    }
    // Get the angle in radians of the vector
    float heading(void)
    {
        return atan(y / x);
    }
    // Copy this vector
    Vector *copy(void)
    {
        return new Vector(x, y);
    }
};