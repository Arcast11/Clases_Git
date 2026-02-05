/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 19 2025
 * @brief Clase representación de libros
 */

#ifndef BOOK_CLASS_H
#define BOOK_CLASS_H

#include <iostream>
#include <string>

class Books {
 public:
  Books(std::string title, int publish_date, double price);
  double CalcTaxes(const double taxes);
  friend std::ostream& operator<<(std::ostream& out_stream, const Books& book);

 private:
  std::string title_;
  int publish_date_;
  double price_;
};

#endif  /// BOOK_CLASS_H