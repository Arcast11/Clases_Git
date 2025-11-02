#include <iostream>

int main() {

#include <numbers> // libreria para insertar el número pi
  
  double radius;
  constexpr double PI = std::numbers::pi;

  std::cout << "inserte el radio de la circunferencia: ";
  std::cin >> radius;
  std::cout << "El perimetro de la circunferencia es : " << 2 * PI * radius << std::endl; 
  std::cout << "El Área de la circunferencia es: " << 2 * PI * radius * radius
  << std::endl;

return 0;
}   
