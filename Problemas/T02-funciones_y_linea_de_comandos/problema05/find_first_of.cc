/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file find_first_of.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 10 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>
#include <string>

int FindFirstOf(const std::string& str, char target) {
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == target) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Error: Numero incorrecto de argumentos." << std::endl;
    std::cerr << "Uso: " << argv[0] << " <cadena> <caracter>" << std::endl;
    std::cerr << "Ejemplo: " << argv[0] << " abracadabra r" << std::endl;
    return 1;
  }
  
  std::string input_string = argv[1];
  std::string char_string = argv[2];
  
  if (char_string.length() != 1) {
    std::cerr << "Error: El segundo argumento debe ser un solo caracter." << std::endl;
    return 1;
  }
  
  char target_char = char_string[0];
  int position = FindFirstOf(input_string, target_char);
  
  std::cout << position << std::endl;
  
  return 0;
}
