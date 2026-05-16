/* AUTOR: Armando Jose Castro Peña
 * FECHA: 10/03/2026
 * EMAIL: armando.castro.31@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 2
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
            "C++ Programming Style Guidelines"
             https://geosoft.no/development/cppstyle.html

  */
#pragma once

#include <cassert>
#include <iostream>

#include "vector_t.hpp"

using namespace std;

template <class T>
class matrix_t {
 public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();

  void resize(const int, const int);

  // getters
  int get_m(void) const;
  int get_n(void) const;

  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);

  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

  // Ejercicio de Examen
  int sum_row(const matrix_t<T>& A, int i, int j, int n);
  int sum_submatrix(const matrix_t<T>& A, int i, int j, int n);
  int sum_submatrix_iterative(const matrix_t<T>& A, int i, int j, int n);

 private:
  int m_, n_;  // m_ filas y n_ columnas
  vector_t<T> v_;

  int pos(const int, const int) const;
};

template <class T>
matrix_t<T>::matrix_t(const int m, const int n) {
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T>
matrix_t<T>::~matrix_t() {}

template <class T>
void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T>
inline int matrix_t<T>::get_m() const {
  return m_;
}

template <class T>
inline int matrix_t<T>::get_n() const {
  return n_;
}

template <class T>
T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

template <class T>
T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template <class T>
const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

template <class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

template <class T>
void matrix_t<T>::write(ostream& os) const {
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j) os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

template <class T>
void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j) is >> at(i, j);
}

template <class T>
inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}

template <class T>
int matrix_t<T>::sum_row(const matrix_t<T>& A, int i, int j, int n) {
  // Código exacto del profesor adaptado a plantillas
  if (n == 0) return 0;
  return A.at(i, j) + sum_row(A, i, j + 1, n - 1);
}

template <class T>
int matrix_t<T>::sum_submatrix(const matrix_t<T>& A, int i, int j, int n) {
  // Código exacto del profesor adaptado a plantillas
  if (n == 0) return 0;

  return sum_row(A, i, j, n) + sum_submatrix(A, i + 1, j, n - 1);
}

template <class T>
int matrix_t<T>::sum_submatrix_iterative(const matrix_t<T>& A, int i, int j,
                                         int n) {
  int sum = 0;
  for (size_t row = 0; row < n; row++) {
    for (size_t col = 0; col < n; col++) {
      sum += A.at(row + i, col + j);
    }
  }
  return sum;
}
