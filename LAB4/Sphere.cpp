#include "Sphere.h"
#include <iostream>
#include <stdexcept>

static const double PI = 3.14159265358979323846;

Sphere::Sphere(double r) : radius(r) {
    if (r <= 0)
        throw std::invalid_argument("Радіус сфери має бути додатним числом");
    std::cout << "  [Конструктор] Sphere(r = " << radius << ")\n";
}

Sphere::~Sphere() {
    std::cout << "  [Деструктор]  ~Sphere()\n";
}

double Sphere::getRadius() const { return radius; }

double Sphere::volume() const { return 4.0 / 3.0 * PI * radius * radius * radius; }

double Sphere::surfaceArea() const { return 4.0 * PI * radius * radius; }

void Sphere::print(std::ostream& os) const {
    os << "Сфера:\n"
        << "  радіус r           = " << radius << "\n"
        << "  об'єм V            = " << volume() << "\n"
        << "  площа поверхні S   = " << surfaceArea() << "\n";
}
