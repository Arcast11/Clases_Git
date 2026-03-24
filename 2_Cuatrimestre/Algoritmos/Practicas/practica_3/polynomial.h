/** AUTOR: Armando Castro
 *  FECHA: 10/10/2023
 *  EMAIL: armando.castro@ull.edu.es
 *  VERSION: 1.0
 *  ASIGNATURA: Algoritmos y Estructuras de Datos
 *  PRÁCTICA Nº: 3
 *  ESTILO: Google C++ Style Guide
 *  COMENTARIOS:
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>

#include "pair_t.h"
#include "sparse_vector_t.h"
#include "vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {};  // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;

  // Modigicación
  double get_monomio(int i);

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
         << (i > 1      ? " x^"
             : (i == 1) ? " x"
                        : "");
      if (i > 1) os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};

  for (int i{0}; i < get_size(); i++) {
    result += at(i) * pow(x, i);
  }

  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;

  // Variable min size para evitar el assert
  size_t min_size;

  // Asignamos a la min_size el tamaño del polynomio mas pequeño
  if (get_size() <= pol.get_size()) {
    min_size = get_size();
  } else {
    min_size = pol.get_size();
  }

  // bucle para recorrer el polynomio. Si son diferentes, para
  for (int i{0}; i < min_size && !differents; i++) {
    if (IsNotZero(fabs(at(i) - pol.at(i)), eps)) {
      differents = true;
    }
  }

  // Como tenemos verdadero cuando son diferentes, la retornamos negada
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;  // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1      ? " x^"
           : (inx == 1) ? " x"
                        : "");
    if (inx > 1) os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};

  for (int i{0}; i < get_nz(); i++) {
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores
// dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol,
                               const double eps) const {
  bool differents = false;
  // poner el código aquí
  if (spol.get_nz() != get_nz()) {
    return differents;
  }
  for (size_t i{0}; i < get_nz() && !differents; i++) {
    if (IsNotZero(fabs(spol.at(i).get_val() - at(i).get_val()), eps)) {
      differents = true;
    }
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;

  // 1. Verificar que todos los elementos del disperso coincidan con el denso
  for (int i = 0; i < get_nz() && !differents; i++) {
    int index = at(i).get_inx();
    double value = at(i).get_val();

    if (index < pol.get_size()) {
      // Si el índice existe en el denso, comparamos valores
      if (!IsNotZero(fabs(value - pol.at(index)), eps)) {
        // Son iguales en este punto, seguimos
      } else {
        differents = true;
      }
    } else {
      // Si el disperso tiene un grado que el denso no tiene,
      // y ese valor es no nulo, no pueden ser iguales.
      if (IsNotZero(value, eps)) {
        differents = true;
      }
    }
  }

  // 2. Verificar que el denso no tenga valores extra donde el disperso es
  // "cero" Recorremos el polinomio denso por completo
  for (int i = 0; i < pol.get_size() && !differents; i++) {
    // Buscamos si este índice 'i' está en nuestro vector disperso
    bool found_in_sparse = false;
    for (int j = 0; j < get_nz(); j++) {
      if (at(j).get_inx() == i) {
        found_in_sparse = true;
        break;
      }
    }

    // Si el índice NO está en el disperso, el valor en el denso DEBE ser cero
    if (!found_in_sparse) {
      if (IsNotZero(pol.at(i), eps)) {
        differents = true;
      }
    }
  }

  return !differents;
}

double SparsePolynomial::get_monomio(int i) {
  for (int j = 0; j < get_nz(); j++) {
    if (at(j).get_inx() == i) {
      return at(j).get_val();
    }
  }
  return 0.0;
}

#endif  // POLYNOMIAL_H_
