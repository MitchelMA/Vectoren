# Vectoren
Dit zijn 2d en 3d vectoren gemaakt in C++.  
Iedere Vector-soort staat in een apart bestand.  
De namespace is *MathVector*

## Gebruik
Het initializeren van een nieuwe Vector kan op 3 manieren:
```cpp
// Initializeert een vector op het nullpunt
MathVector::Vector3 MathVector::Vector3();

// Initializeert een vector met een x en y waarde
MathVector::Vector3 MathVector::Vector3(float x, float y);

// Initializeert een vector met een x, y en z waarde
MathVector::Vector3 MathVector::Vector3(float x, float y, float z);
```

Omdat de x, y en z waarde privates zijn, zijn er *Getters*:
```cpp
float MathVector::Vector3::getX(void); // returned de waarde van x
float MathVector::Vector3::getY(void); // returned de waarde van y
float MathVector::Vector3::getZ(void); // returned de waarde van z
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
Het is ook mogelijk om de Magnitude te krijgen of te setten:
```cpp
float MathVector::Vector3::mag(void);                   // Deze method returned de magnitude van de vector
MathVector::Vector3::setMag(float magnitude);       // Deze method zet de waarde van de magnitude
```
Je kan de Vector normalizeren of limiten:
```cpp
MathVector::Vector3::norm(void);           // normaliseert de vector
MathVector::Vector3::limit(float max); // Limits de vector
```
Je kan berekeninge maken met de vector:
```cpp
// De add function:
MathVector::Vector3::add(MathVector::Vector3 inVector); // deze function voegt een andere vector toe
MathVector::Vector3::add(float value);                  // deze function voegt de waarde "value" toe aan x, y en z
MathVector::Vector3::add(float x, float y);             // deze function voegt de doorgegeven waardes toe aan x en y
MathVector::Vector3::add(float x, float y, float z);    // deze function voegt de doorgegeven waardes toe aan x, y en z

// De sub function:
MathVector::Vector3::sub(MathVector::Vector3 inVector); // deze function haalt een andere vector van de waardes af
MathVector::Vector3::sub(float value);                  // deze function haalt de waarde van "value" af van x, y en z
MathVector::Vector3::sub(float x, float y);             // deze function haalt de doorgegeven waardes af van x en y
MathVector::Vector3::sub(float x, float y, float z);    // deze function haalt de doorgegeven waardes af van x, y en z

// De mult function:
MathVector::Vector3::mult(MathVector::Vector3 inVector); // deze function vermenigvuldigd twee vectoren met elkaar
MathVector::Vector3::mult(float factor);                 // deze function vermenigvuldigd de vector met een factor
MathVector::Vector3::mult(float xFactor, float yFactor); // deze function vermenigvuldigd de x en y waardes met de gegeven factoren
MathVector::Vector3::mult(float xFactor, float yFactor, float zFactor); // deze function vermenigvuldigd de x, y en z waardes met de gegeven factoren

// De div function:
MathVector::Vector3::div(MathVector::Vector3 inVector);  // deze function deelt twee vectoren door elkaar
MathVector::Vector3::div(float factor);                  // deze function deelt de vector door een gegeven factor
MathVector::Vector3::div(float xFactor, float yFactor);  // deze function deelt de x en de y waardes door de gegeven factoren
MathVector::Vector3::div(float xFactor, float yFactor, float zFactor) // deze function deelt de x, y en z door de gegeven factoren

// De dot (en scalar) function:
float MathVector::Vector3::dot(MathVector::Vector3 inVector); // deze function returned de Dot Product van twee vectoren
float MathVector::Vector3::dot(float factor);                 // deze function returned de Dot product van de vector en de gegeven factor
float MathVector::Vector3::dot(float xFactor, float yFactor, float zFactor); // deze function returned de Dot product van de vector en de x,y en z factoren
```

Het is ook mogelijk om de direction van de Vector te krijgen:
```cpp
// deze function returned een float-array waar 
// index 0: de x-y direction is en,
// index 1: de direction van de z-as naar de vector is
float* MathVector::Vector3::*heading(void) 
```

En natuurlijk kan je een vector kopiëren:
```cpp
// deze function returned een pointer naar een MathVector::Vector3 class
MathVector::Vector3* MathVector::Vector3::*copy(void) 
```

## Verschillen
Er zitten ook wat verschillen tussen de Vector3 en Vector2.  
Zo heb je, logischerwijs, geen z-as bij een Vector2; maar dat niet alleen:
```cpp
// een Vector2 kan ook op een andere manier initialized worden:
MathVector::Vector2 MathVector::Vector2(double angleRad); // deze function zal een Vector2 class initializeren met een gegeven hoek in radialen

// De heading() is geen pointer naar een float-array:
float MathVector::Vector2::heading();

// Ook kan je de hoek in graden tussen twee Vector2 berekenen:
float MathVector::Vector2::angle(MathVector::Vector2 inVector);
```