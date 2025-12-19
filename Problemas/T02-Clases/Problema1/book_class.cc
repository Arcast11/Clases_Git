/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 25 2025
 * @brief Descripción del archivo
 */

#include "book_class.h"

/// Metodos
double Books::CalcTaxes(Books book, const double taxes) {
  return book.price_ * (taxes / 100);
}

/// Operator overloading
std::ostream& operator<<(std::ostream& out_stream, const Books& book) {
  out_stream << book.GetTitle() << " Se publicó en " << book.GetDate()
             << " y vale " << book.Getprice() << ", con impuestos: ";
  return out_stream;
}