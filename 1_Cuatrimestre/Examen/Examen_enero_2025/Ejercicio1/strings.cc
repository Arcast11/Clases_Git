/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file strings.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Jan 05 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <fstream>
#include <iostream>
#include <string>

/** Contar las letras comunes de las dos cadenas
 * @param cadena1: primera cadena de caracteres
 * @param cadena2: segunda cadena de caracteres
 * @return números de letras comunes
 */

int Coincide(const std::string& cadena1, const std::string& cadena2) {
  size_t longitud{std::min(cadena1.length(), cadena2.length())};
  int contador{0};
  for (int i{0}; i < longitud; ++i) {
    if (cadena1[i] == cadena2[i]) {
      ++contador;
    }
  }
  return contador;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << argv[0] << " <palabra1> <palabra2>\n";
    return 1;
  }
  std::cout << Coincide(argv[1], argv[2]) << std::endl;
  return 0;
}