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
// Asegúrate de que el nombre coincida con tu archivo
#include "dll_t.hpp"

using namespace std;

int main() {
  dll_t<int> L1;
  dll_t<int> L2;

  // Rellenamos la L1 (usando 'new' porque pide punteros a nodo)
  L1.push_back(new dll_node_t<int>(1));
  L1.push_back(new dll_node_t<int>(2));
  L1.push_back(new dll_node_t<int>(3));

  // Rellenamos la L2
  L2.push_back(new dll_node_t<int>(4));
  L2.push_back(new dll_node_t<int>(5));
  L2.push_back(new dll_node_t<int>(6));

  cout << "--- PRUEBA EJERCICIO 4 ---" << endl;
  cout << "Lista 1 original: ";
  L1.write();  // Tu función write() imprimirá los nodos
  cout << endl;

  cout << "Lista 2 original: ";
  L2.write();
  cout << endl;

  // Ejecutamos la concatenación inversa
  cout << "Concatenando Lista 2 al reves en Lista 1..." << endl;
  L1.rev_concat(L2);

  cout << "Lista 1 resultado final: ";
  L1.write();
  cout << endl;

  cout << "Lista 2 (deberia estar vacia): ";
  L2.write();
  cout << endl;

  return 0;
}
