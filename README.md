# Vectoren
Dit zijn 2d en 3d vectoren gemaakt in C++.  
Iedere Vector-soort staat in een apart bestand.  
De namespace is *MathVector*

## Gebruik
Het initializeren van een nieuwe Vector kan op 3 manieren:
```cpp
// Initializeert een vector op het nullpunt
MathVector::Vector3();

// Initializeert een vector met een x en y waarde
MathVector::Vector3(float x, float y);

// Initializeert een vector met een x, y en z waarde
MathVector::Vector3(float x, float y, float z);
```

Omdat de x, y en z waarde privates zijn, zijn er *Getters*:
```cpp
MathVector::Vector3::getX(); // returned de waarde van x
MathVector::Vector3::getY(); // returned de waarde van y
MathVector::Vector3::getZ(); // returned de waarde van z
```
Ook zijn er *Setters*:
```cpp
// Setters for specifiek x, y en z
MathVector::Vector3::setX(float x); // zet de waarde van x
MathVector::Vector3::setY(float y); // zet de waarde van y
MathVector::Vector3::setZ(float z); // zet de waarde van z

// Andere setters
MathVector::Vector3::set(float value);               // zet x, y en z gelijk aan "value"
MathVector::Vector3::set(float x, float y);          // zet x en y gelijk aan de ingevoerde "x" en "y"
MathVector::Vector3::set(float x, float y, float z); // zet x, y en z gelijk aan de ingevoerde "x", "y" en "z"
```
Het is ook mogelijk om de Magnitude te krijgen:
```cpp
MathVector::Vector3::mag() // Deze method returned de magnitude van de vector
```