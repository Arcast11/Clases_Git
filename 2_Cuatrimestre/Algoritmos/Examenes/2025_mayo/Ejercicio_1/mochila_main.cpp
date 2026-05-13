/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file mochila.cpp
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date May 13 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <iostream>

#include "vector_t.hpp"

using namespace std;

// --------- Datos del problema ------------------
// --- Datos del problema (Variables Globales) ---
const int weights_out[] = {4, 6, 2, 8, 1, 3, 4, 3};  // Pesos de los 8 objetos
const int prize[] = {14, 1, 4, 7, 3, 2, 5, 6};  // Beneficios de los objetos
const int MaxWeight = 15;                       // Capacidad máxima

int best_value = -1;      // Almacena el mejor beneficio encontrado
vector_t<int> best_x(8);  // Almacena la mejor combinación de objetos

// Al ser por fuerza bruta, se construye un árbol con todas las posibilidades
void generate(vector_t<int>& x, int i, int n, int weight_in, int value) {
  // Caso base: se han evaluado todos los objeteos
  if (i == n) {
    // Esta parte decide cual de todas las combinaciones es la óptima
    if (weight_in <= MaxWeight && value > best_value) {
      best_value = value;  // Asignamos el mejor valor
      for (int j = 0; j < n; j++) {
        best_x[j] = x[j];  // Se guarda la mejor combinación
      }
    }
  } else {
    // Opción 0: El objeto analizado no se mete en la mochila
    x[i] = 0;
    generate(x, i + 1, n, weight_in, value);

    // Opción 1: El objeto analizado no se mete en la mochilla
    x[i] = 1;
    generate(x, i + 1, n, weight_in + weights_out[i], value + prize[i]);
  }
}

// --- Programa Principal ---
void generate_all(void) {
  vector_t<int> x(8);  // Vector para la combinación actual

  // Llamada inicial: índice 0, total 8, peso inicial 0, valor inicial 0
  generate(x, 0, 8, 0, 0);

  // Salida de resultados
  cout << "Mejor valor: " << best_value << endl;
  cout << "Mejor mochila: ";
  for (int i = 0; i < 8; i++) {
    cout << best_x[i] << " ";
  }
  cout << endl;
}

int main() {
  generate_all();
  return 0;
}