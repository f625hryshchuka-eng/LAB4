#include "SphereInCube.h"
#include <iostream>
#include <stdexcept>

double SphereInCube::validateSide(double a) {
    if (a <= 0)
        throw std::invalid_argument("Ребро куба має бути додатним числом");
    return a;
}

SphereInCube::SphereInCube(double a)
    : Sphere(validateSide(a) / 2.0), Cube(a) {
    std::cout << "  [Конструктор] SphereInCube(a = " << a << ")\n";
}

SphereInCube::~SphereInCube() {
    std::cout << "  [Деструктор]  ~SphereInCube()\n";
}

double SphereInCube::emptyVolume() const {
    return Cube::volume() - Sphere::volume();
}

double SphereInCube::fillRatio() const {
    return Sphere::volume() / Cube::volume();  
}

void SphereInCube::print(std::ostream& os) const {
    os << "=== Сфера, вписана у куб ===\n";
    Sphere::print(os);
    Cube::print(os);
    os << "Додатково:\n"
        << "  V(сфери) / V(куба)             = " << fillRatio() << "  (= pi/6)\n"
        << "  вільний об'єм між кубом і сферою = " << emptyVolume() << "\n";
}
