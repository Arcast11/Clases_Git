/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * curso 2025-2026
 *
 * @file int_to_bin.cpp
 * @author Armando Castro
 * @email: armando.castro.31@ull.edu.es
 * @date 17 17 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <iostream>

#include "stack_l_t.hpp"
#include "vector_t.hpp"

using namespace std;

vector_t<unsigned> to_base(const unsigned n, const unsigned short b) {
  assert(n > 0);

  stack_l_t<unsigned> pila;
  unsigned resto = 0;
  unsigned n_ = n;
  size_t i = 0;

  while (n_ >= b) {
    resto = n_ % b;
    pila.push(resto);
    n_ = n_ / b;
    i++;
  }
  pila.push(n_);
  i++;

  vector_t<unsigned> v(i);
  i = 0;

  while (!pila.empty()) {
    v.at(i) = pila.top();
    pila.pop();
    i++;
  }
  return v;
}

int main() {
  cout << "--- PRUEBA EJERCICIO 2 (Examen 18.06.2025) ---" << endl;

  // --- Prueba 1: Base 2 (Ejemplo del examen) ---
  unsigned numero1 = 100;
  unsigned base1 = 2;
  cout << "Convirtiendo el numero " << numero1 << " a base " << base1 << "..."
       << endl;

  vector_t<unsigned> resultado1 = to_base(numero1, base1);

  cout << "Resultado esperado: 1 1 0 0 1 0 0" << endl;
  cout << "Resultado obtenido: ";
  for (int i = 0; i < resultado1.get_size(); i++) {
    cout << resultado1.at(i) << " ";
  }
  cout << "\n" << endl;

  // --- Prueba 2: Base 8 ---
  unsigned numero2 = 100;
  unsigned base2 = 8;
  cout << "Convirtiendo el numero " << numero2 << " a base " << base2 << "..."
       << endl;

  vector_t<unsigned> resultado2 = to_base(numero2, base2);

  // 100 dividido entre 8 = 12 (resto 4)
  // 12 dividido entre 8 = 1 (resto 4)
  // 1 dividido entre 8 = 0 (resto 1) -> Leido al reves: 144
  cout << "Resultado esperado: 1 4 4" << endl;
  cout << "Resultado obtenido: ";
  for (int i = 0; i < resultado2.get_size(); i++) {
    cout << resultado2.at(i) << " ";
  }
  cout << endl;

  return 0;
}