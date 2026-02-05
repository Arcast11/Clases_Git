/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @file number_secuency.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 24 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string IsOdd(const std::string& line) {
  std::string is_odd;
  std::istringstream ss(line);
  int number;

  while (ss >> number) {
    if (number % 2 != 0) {
      is_odd += std::to_string(number) + " ";
    }
  }

  return is_odd;
}

std::string IsEven(const std::string& line) {
  std::string is_even;
  std::istringstream ss(line);
  int number;

  while (ss >> number) {
    if (number % 2 == 0) {
      is_even += std::to_string(number) + " ";
    }
  }
  return is_even;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "El programa debe recibir como argumento: " << argv[0]
              << " <nombre_del_programa>";
    return 1;
  }
  std::ifstream in_file{argv[1]};

  if (!in_file) {
    std::cerr << "No se ha podido abrir el archivo" << std::endl;
  }
  std::string line;
  std::ofstream odd_numbers{"odd.txt"};
  std::ofstream even_numbers{"even.txt"};
  while (std::getline(in_file, line)) {
    odd_numbers << IsOdd(line);
    even_numbers << IsEven(line);
  }
  return 0;
}