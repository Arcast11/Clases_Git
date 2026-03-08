// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <cmath>
#include <iostream>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "vector_t.hpp"

using namespace std;

int main() {
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a + b).write();

  cout << "b - a: ";
  (b - a).write();

  cout << "a * b: ";
  (a * b).write();

  cout << "a / b: ";
  (a / b).write();

  cout << endl;

  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();

  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl
       << endl;

  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();

  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y)
       << endl
       << endl;

  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();

  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  // Modificación
  matrix_t<int> matriz;
  vector_t<int> vector, result_mod;

  matriz.read(), matriz.write();
  vector.read(), vector.write();

  matriz.multiply_vector(vector, result_mod);
  cout << "matriz x vector: " << endl;
  result_mod.write();

  return 0;
}