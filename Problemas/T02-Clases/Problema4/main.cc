/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 25 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */
#include <algorithm>
#include <iostream>
#include <vector>

#include "shape.h"

int main() {
  std::vector<Shape> shapes{Square{1.0}, Circle{0.5}, Triangle{1.0, 1.0},
                            Triangle{2.0, 2.0}};
  std::sort(shapes.begin(), shapes.end());
  for (const auto& shape : shapes) {
    std::cout << shape << ' ';
  }
  std::cout << std::endl;
  return 0;
}