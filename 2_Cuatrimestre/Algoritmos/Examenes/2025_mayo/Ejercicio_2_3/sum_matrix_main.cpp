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
  int contador = 1;                 // Empezar desde 1 según el comentario
  for (int i = 1; i <= N; i++) {    // i = 1..5
    for (int j = 1; j <= N; j++) {  // j = 1..5
      A.at(i, j) = contador++;
    }
  }

  // La submatriz 3x3 empezando en (1,1) suma:
  // fila1: 1+2+3=6, fila2: 6+7+8=21, fila3: 11+12+13=36 → total = 63
  // O desde (1,1) con tamaño 3: posiciones (1,1),(1,2),(1,3),(2,1),...,(3,3)
  // Valores: 1,2,3,6,7,8,11,12,13 = 63

  int resultado = A.sum_submatrix(A, 1, 1, 3);
  int result_iterative = A.sum_submatrix_iterative(A, 1, 1, 3);

  cout << "--- Prueba Ejercicio 2 ---" << endl;
  cout << "Suma esperada: 63" << endl;  // Corregido
  cout << "Suma obtenida (recursiva): " << resultado << endl;
  cout << "Suma obtenida (iterativa): " << result_iterative << endl;

  if (result_iterative == 63) {
    cout << "¡Resultado CORRECTO!" << endl;
  } else {
    cout << "Error en el cálculo." << endl;
  }

  return 0;
}