/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file next_letter.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 10 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>
#include <string>

char NextLetter(char c) {
    // Si es una letra minúscula
  if (c >= 'a' && c <= 'z') {
    if (c == 'z'){
      c = 'a';
    }else{
      c++;
    }
    return c; 
  }else if (c >= 'A' && c <= 'Z') {
    if (c == 'Z'){
      c = 'A';
    }else{
      c++;  
    }
  }
  return c;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Uso: " << argv[0] << " <cadena>" << std::endl;
    std::cout << "Ejemplo: " << argv[0] << " abecedario" << std::endl;
    return 1;
  }

  std::string input  = argv[1];
  
  for (char character : input) {
    std::cout << NextLetter(character);
  }
  std::cout << std::endl;
  return 0;
}
