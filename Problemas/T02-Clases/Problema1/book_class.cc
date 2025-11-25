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

#ifndef BOOK_CLASS
#define BOOK_CLASS
#include <iostream>
#include <string>

class books {
 public:
  double TaxedPrice(price);
  Book(const std::string& title, int year, double price);
  double GetPriceWithTax(double tax) const;

 private:
  std::string title;
  int publish_date;
  double price;
};

#endif