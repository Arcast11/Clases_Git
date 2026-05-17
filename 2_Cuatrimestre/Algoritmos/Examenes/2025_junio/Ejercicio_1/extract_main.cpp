/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * curso 2025-2026
 *
 * @file extract_main.cpp
 * @author Nombre Apellido email@ull.edu.es
 * @date 17 17 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <iostream>

#include "dll_t.hpp"

using namespace std;

int main() {
  dll_t<int> lista;

  // Creamos los nodos guardando sus punteros para poder extraerlos luego
  dll_node_t<int>* n1 = new dll_node_t<int>(10);  // Frente
  dll_node_t<int>* n2 = new dll_node_t<int>(20);
  dll_node_t<int>* n3 = new dll_node_t<int>(30);  // Medio
  dll_node_t<int>* n4 = new dll_node_t<int>(40);
  dll_node_t<int>* n5 = new dll_node_t<int>(50);  // Final

  // Rellenamos la lista: [10] <-> [20] <-> [30] <-> [40] <-> [50]
  lista.push_back(n1);
  lista.push_back(n2);
  lista.push_back(n3);
  lista.push_back(n4);
  lista.push_back(n5);

  cout << "--- PRUEBA EJERCICIO 1 (Examen 18.06.2025) ---" << endl;
  cout << "Lista original: ";
  lista.write();
  cout << endl;

  // --- Prueba A: Extraer del MEDIO ---
  cout << "Extrayendo el nodo del MEDIO (valor 30)..." << endl;
  lista.extract(n3);
  cout << "Resultado: ";
  lista.write();
  // Esperado: 10 20 40 50
  cout << endl;

  // --- Prueba B: Extraer del FRENTE ---
  cout << "Extrayendo el nodo del FRENTE (valor 10)..." << endl;
  lista.extract(n1);
  cout << "Resultado: ";
  lista.write();
  // Esperado: 20 40 50
  cout << endl;

  // --- Prueba C: Extraer del FINAL ---
  cout << "Extrayendo el nodo del FINAL (valor 50)..." << endl;
  lista.extract(n5);
  cout << "Resultado: ";
  lista.write();
  // Esperado: 20 40
  cout << endl;

  return 0;
}
