/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file compare_double.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Feb 09 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <cmath>
#include <cstdlib>

bool Equal(double value_a, double value_b, double tolerancy) {
  bool equal{false};
  if (abs(value_a - value_b) < tolerancy) {
    equal = true;
  }
  return equal;
}

size_t CountEqual(const double* vector, const size_t size, const double value,
                  const double tolerancy) {
  size_t count{0};
  for (size_t i{0}; i < size; i++) {
    if (Equal(vector[i], value, tolerancy)) {
      count++;
    }
  }
  return count;
}