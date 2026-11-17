#pragma once
#ifndef SPHEREINCUBE_H
#define SPHEREINCUBE_H

#include "Sphere.h"
#include "Cube.h"
#include <ostream>

class SphereInCube : public Sphere, public Cube {
private:
    static double validateSide(double a);  

public:
    explicit SphereInCube(double a = 1.0); 
    ~SphereInCube();                  

    double emptyVolume() const;        
    double fillRatio() const;         
    void print(std::ostream& os) const;   
};

#endif
