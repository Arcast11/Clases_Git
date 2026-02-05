/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 19 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <iostream>
#include <string>

#include "book_class.h"

int main(int argc, char* argv[]) {
  double taxes = std::stoi(argv[1]);

  Books book1("El Quijote de la mancha", 1605, 21);
  Books book2("El Lazarillo de Tormes", 1554, 18);
  Books book3("Los Pilares de la Tierra", 1989, 27);

  std::cout << book1 << ", " << book1.CalcTaxes(taxes) << std::endl;
  std::cout << book2 << ", " << book2.CalcTaxes(taxes) << std::endl;
  std::cout << book3 << ", " << book3.CalcTaxes(taxes) << std::endl;

  return 0;
}