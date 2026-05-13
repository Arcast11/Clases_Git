/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file sum_matrix_main.cpp
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date May 13 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include "matrix_t.hpp"

int main() {
  int N = 5;
  matrix_t<int> A(N, N);

  // Rellenamos la matriz con valores del 1 al 25
  int contador = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A.at(i, j) = contador++;
    }
  }

  // Ejecutamos la suma de la submatriz 3x3 empezando en (1, 1) [cite: 126-127]
  // Nota: (1, 1) corresponde a la segunda fila y segunda columna
  int resultado = sum_submatrix(A, 1, 1, 3);

  cout << "--- Prueba Ejercicio 2 ---" << endl;
  cout << "Suma esperada: 117" << endl;
  cout << "Suma obtenida: " << resultado << endl;

  if (resultado == 117) {
    cout << "¡Resultado CORRECTO!" << endl;
  } else {
    cout << "Error en el cálculo." << endl;
  }

  return 0;
}