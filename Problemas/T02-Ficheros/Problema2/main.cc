/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 18 2025
 * @brief
 * @bug There are no known bugs
 * @see
 */

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Se introdujo el número inorrecto de parametros";
  }
  std::ifstream in_file{argv[1]};
  std::string line;
  while (std::getline(in_file, line)) {
    std::sstring(line);
    while
  }
}
