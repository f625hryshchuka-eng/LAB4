#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include <ostream>

class Sphere {
protected:
    double radius;          

public:
    explicit Sphere(double r = 0.5); 
    ~Sphere();                       

    double getRadius() const;
    double volume() const;           
    double surfaceArea() const;      
    void print(std::ostream& os) const;
};

#endif
