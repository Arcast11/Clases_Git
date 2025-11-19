/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @file ofstream.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 19 2025
 * @brief Prueba de funcionamiento ofstream
 * @bug There are no known bugs
 * @see
 */

#include <fstream>
#include <iostream>

int main() {
  std::ofstream outf{"Sample.txt"};
  outf << "Coño mano que lo que\n";
  outf << "Dimelo mi loco";
  return 0;
}