/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @file ifstream.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 20 2025
 * @brief Pruebas para usar ifstream
 * @bug There are no known bugs
 * @see
 */

#include <fstream>
#include <iostream>

int main() {
  // Funciona como si estuvieramos declarando una variable
  std::ifstream maicol{"sample.txt"};

  std::string str_input{};
  while (std::getline(maicol, str_input)) {
    std::cout << str_input << '\n';
  }
  return 0;
}