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

#include <iostream>

#include "dll_t.hpp"

using namespace std;

int main() {
  dll_t<int> L1;
  dll_t<int> L2;

  // Construimos el número 123 en la Lista 1
  L1.push_back(new dll_node_t<int>(1));
  L1.push_back(new dll_node_t<int>(2));
  L1.push_back(new dll_node_t<int>(3));

  // Construimos el número 45 en la Lista 2
  L2.push_back(new dll_node_t<int>(4));
  L2.push_back(new dll_node_t<int>(5));

  cout << "--- PRUEBA EJERCICIO 6 (Multiplicacion de Listas) ---" << endl;

  // Mostramos los números por pantalla
  cout << "Numero A (Lista 1): ";
  L1.write();
  cout << endl;

  cout << "Numero B (Lista 2): ";
  L2.write();
  cout << endl;

  // Ejecutamos tu función multiply
  int resultado = L1.multiply(L2);

  cout << "\nMultiplicando 123 * 45..." << endl;
  cout << "Resultado esperado: 5535" << endl;
  cout << "Resultado obtenido: " << resultado << endl;

  if (resultado == 5535) {
    cout << "¡Resultado CORRECTO! La funcion va como la seda." << endl;
  } else {
    cout << "Atencion: Hay algun error en el calculo." << endl;
  }

  return 0;
}