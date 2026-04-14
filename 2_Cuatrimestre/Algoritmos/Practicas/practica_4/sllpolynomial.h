// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;           // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  // Modificación
  double get_monomio(int);
};

bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  SllPolyNode* aux_node = get_head();
  for (int i{v.get_size() - 1}; i >= 0; i--) {
    double val{v.get_val(i)};
    if (IsNotZero(val, eps)) {
      pair_double_t aux_pair(val, i);
      aux_node = new SllPolyNode(aux_pair);
      push_front(aux_node);
    }
  }
}

// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1) os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux = get_head();
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};

    result += val * pow(x, inx);
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
                            const double eps) const {
  bool differents = false;
  SllPolyNode* aux1 = get_head();
  SllPolyNode* aux2 = sllpol.get_head();
  while (aux1 != NULL && aux2 != NULL) {
    int inx1{aux1->get_data().get_inx()};
    double val1{aux1->get_data().get_val()};
    int inx2{aux2->get_data().get_inx()};
    double val2{aux2->get_data().get_val()};

    if (IsNotZero(val1 - val2, eps) || inx1 != inx2) {
      differents = true;
    }
    aux1 = aux1->get_next();
    aux2 = aux2->get_next();
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum,
                        const double eps) {
  SllPolyNode* aux1 = get_head();
  SllPolyNode* aux2 = sllpol.get_head();

  while (aux1 != NULL || aux2 != NULL) {
    int inx1 = (aux1 != NULL) ? aux1->get_data().get_inx() : -1;
    int inx2 = (aux2 != NULL) ? aux2->get_data().get_inx() : -1;

    double sum_val = 0.0;
    int sum_inx = 0;

    if (inx1 > inx2) {
      sum_val = aux1->get_data().get_val();
      sum_inx = aux1->get_data().get_val();
      aux1 = aux1->get_next();
    } else if (aux2 > aux1) {
      sum_val = aux2->get_data().get_val();
      sum_inx = aux2->get_data().get_val();
      aux2 = aux2->get_next();
    } else {
      sum_val = aux1->get_data().get_val() + aux2->get_data().get_val();
      sum_inx = aux1->get_data().get_val();
      aux1 = aux1->get_next();
      aux2 = aux2->get_next();
    }

    if (IsNotZero(sum_val, eps)) {
      pair_double_t new_pair(sum_val, sum_inx);
      SllPolyNode* new_node = new SllPolyNode(new_pair);

      if (sllpolsum.empty()) {
        sllpolsum.push_front(new_node);
      } else {
        SllPolyNode* tail = sllpolsum.get_head();
        while (tail->get_next() != NULL) {
          tail = tail->get_next();
        }
        sllpolsum.insert_after(tail, new_node);
      }
    }
  }
}

// Módificación

double SllPolynomial::get_monomio(int grado) {
  SllPolyNode* aux_node = get_head();
  double coeficiente = 0;

  while (aux_node != NULL) {
    if (aux_node->get_data().get_inx() == grado) {
      coeficiente = aux_node->get_data().get_val();
      break;
    }
    aux_node = aux_node->get_next();
  }
  return coeficiente;
}

#endif  // SLLPOLYNOMIAL_H_
