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
#include <fstream>
#include <sstream>

std::vector<std::string> SwapNumbers(const std::string num
    std::string reversed = number;
    std::reverse(reversed.begin(), reversed.end());
    return {reversed};
}
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Se introdujo el número inorrecto de parametros";
    return 1;
  }
  std::ifstream in_file{argv[1]};
  std::string line;
  std::vector<std::string> result;
  while (std::getline(in_file, line)) {
    std::string number;    
    std::stringstream ss(line);
    while (ss >> number){
      result = SwapNumbers(number);
    }
  }
  for (auto j : result){
    std::cout << j << " ";
  }
  std::cout << std::endl;
}
