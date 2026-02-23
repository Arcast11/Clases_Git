/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file scalar_product.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Feb 09 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */
#include <cstdlib>

int ScalarProduct(const int* vector_a, const int* vector_b, const size_t size) {
  int product{0};
  for (size_t i = 0; i < size; i++) {
    product = vector_a[i] * vector_b[i];
  }
  return product;
}