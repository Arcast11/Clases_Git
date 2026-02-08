#include <iostream>

int main() {
  int suma = 0;
  int maximo = 100;
  int numero;
  do {
    std::cin >> numero;
    suma += numero;
    std::cout << "suma: " << suma << std::endl;
  } while (suma < maximo);

  return 0;
}