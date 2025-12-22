/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 20 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */
#include <iostream>

#include "class_complex.h"

int main() {
  ComplexNumber complex1{68.04, 0};
  ComplexNumber complex2{56.62, -21.12};
  std::cout << complex1 << std::endl;
  std::cout << complex2 << std::endl;
  std::cout << "suma: " << complex1 + complex2 << std::endl;
  std::cout << "resta: " << complex1 - complex2 << std::endl;
  std::cout << "multiplicación:" << complex1 * complex2 << std::endl;
  std::cout << "división: " << complex1 / complex2 << std::endl;
}