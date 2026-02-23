/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmo y estructura de Datos
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Feb 23 2026
 * @brief funciones para fusión de dos vectores ordenados
 */

#include <cstdlib>

void merge_v_10(const int a[], const size_t a_sz, const int b[],
                const size_t b_sz, int c[], size_t c_sz) {
  c_sz = 0;

  // Recorre el vector a y lo introduce en c a partir de la última posición
  for (size_t i{0}; i < a_sz; i++) {
    c[c_sz] = a[i];
    c_sz++;
  }
  // Recorre el vector b y lo introduce en c a partir de la última posición
  for (size_t i{0}; i < b_sz; i++) {
    c[c_sz] = b[i];
    c_sz++;
  }
}

void merge_v_20(const int a[], const size_t a_sz, const int b[],
                const size_t b_sz, int c[], size_t c_sz) {
  size_t i{0}, j{0}, k{0};

  while ((i < a_sz) && (j < b_sz)) {
    if (a[i] <= b[j]) {
      c[k] = a[i];
      i++;
    } else {
      c[k] = b[j];
      j++;
    }
    k++;
  }
  while (i < a_sz) {
    c[k] = a[i];
    i++;
    k++;
  }
  while (j < b_sz) {
    c[k] = a[j];
    j++;
    k++;
  }
}

void merge_v_21(const int a[], const size_t a_sz, const int b[],
                const size_t b_sz, int c[], size_t c_sz) {
  size_t i{0}, j{0};

  for (size_t k{0}; k <= a_sz + b_sz; k++) {
    if (a[i] <= b[i]) {
      c[k] = a[i];
      i++;
    } else {
      c[k] = b[j];
      j++;
    }
  }
}