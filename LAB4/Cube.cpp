#include "Cube.h"
#include <iostream>
#include <stdexcept>

Cube::Cube(double a) : side(a) {
    if (a <= 0)
        throw std::invalid_argument("Ребро куба має бути додатним числом");
    std::cout << "  [Конструктор] Cube(a = " << side << ")\n";
}

Cube::~Cube() {
    std::cout << "  [Деструктор]  ~Cube()\n";
}

double Cube::getSide() const { return side; }

double Cube::volume() const { return side * side * side; }

double Cube::surfaceArea() const { return 6.0 * side * side; }

void Cube::print(std::ostream& os) const {
    os << "Куб:\n"
        << "  ребро a            = " << side << "\n"
        << "  об'єм V            = " << volume() << "\n"
        << "  площа поверхні S   = " << surfaceArea() << "\n";
}
