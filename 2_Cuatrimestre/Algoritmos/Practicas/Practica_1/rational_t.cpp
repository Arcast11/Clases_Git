/* AUTOR: Armando Castro
 * FECHA: 10/02/2026
 * EMAIL: armando.castro.31@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 1
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
 *           "C++ Programming Style Guidelines"
 *            https://geosoft.no/development/cppstyle.html
 */

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
int rational_t::get_num() const { return num_; }

int rational_t::get_den() const { return den_; }

void rational_t::set_num(const int n) { num_ = n; }

void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

double rational_t::value() const { return double(get_num()) / get_den(); }

// comparaciones

// Devuelve verdadero si ambos racionales son iguales
bool rational_t::is_equal(const rational_t& r, const double precision) const {
  if ((abs(rational_t::value() - r.value())) < precision) {
    return true;
  } else {
    return false;
  }
}

// Devuelve verdadero si el primer número es mayor que el segundo
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  if ((rational_t::value() - r.value()) > precision) {
    return true;
  } else {
    return false;
  }
}

// Devuelve verdadero si el primer número es menor que el segundo
bool rational_t::is_less(const rational_t& r, const double precision) const {
  if ((r.value() - rational_t::value()) - precision) {
    return true;
  } else {
    return false;
  }
}

// operaciones

// Suma de dos número racionales
rational_t rational_t::add(const rational_t& r) {
  int result_numerator = ((rational_t::get_num() * r.get_den()) +
                          (rational_t::get_den() * r.get_num()));
  int result_denominator = (rational_t::get_den() * r.get_den());
  return {result_numerator, result_denominator};
}

// Resta de dos números racionales
rational_t rational_t::substract(const rational_t& r) {
  int result_numerator = ((rational_t::get_num() * r.get_den()) -
                          (rational_t::get_den() * r.get_num()));
  int result_denominator = (rational_t::get_den() * r.get_den());
  return {result_numerator, result_denominator};
}

// Multiplicación de dos números racionale
rational_t rational_t::multiply(const rational_t& r) {
  return {rational_t::get_num() * r.get_num(),
          rational_t::get_den() * r.get_den()};
}

// División de dos números racionales
rational_t rational_t::divide(const rational_t& r) {
  return {rational_t::get_num() * r.get_den(),
          rational_t::get_den() * r.get_num()};
}

// E/S
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
