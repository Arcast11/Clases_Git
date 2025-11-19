#include <iostream>

int main() {
  int anio_de_nacimiento;
  int anio_actual;

  std::cout << "inserte año de nacimiento ";
  std::cin >> anio_de_nacimiento;
  std::cout << "inserte año actual ";
  std::cin >> anio_actual;
 
  int edad;
  edad = anio_actual - anio_de_nacimiento;
  std::cout << "su edad es: " << edad << " años" << std::endl;

  return 0;
}
