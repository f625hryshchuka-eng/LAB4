#pragma once
#ifndef CUBE_H
#define CUBE_H

#include <ostream>

class Cube {
protected:
    double side;                     

public:
    explicit Cube(double a = 1.0);   
    ~Cube();                          

    double getSide() const;
    double volume() const;           
    double surfaceArea() const;       
    void print(std::ostream& os) const;
};

#endif
