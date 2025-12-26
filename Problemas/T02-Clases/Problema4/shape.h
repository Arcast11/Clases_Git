/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file geometric.h
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 22 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

const double kpi{3.14159265359};

class Shape {
 public:
  Shape(std::string graph, double area) : graph_{graph}, area_{area} {}
  double GetArea() const { return area_; }
  friend std::ostream& operator<<(std::ostream& out_stream, const Shape& shape);
  bool operator<(const Shape& Shape) const;

 private:
  double area_;
  std::string graph_;
};

/**Clase que representa cuadrados */
class Square : public Shape {
 public:
  Square(double side = 1.0) : Shape{"[]", side * side} {}
};

/**Clase que representa triángulos */
class Triangle : public Shape {
 public:
  Triangle(double base = 1.0, double height = 1.0)
      : Shape{"/\\", 0.5 * base * height} {}
};

/**Clase que representa circulos */
class Circle : public Shape {
 public:
  Circle(double radius = 1.0) : Shape{"()", kpi * radius * radius} {}
};

#endif