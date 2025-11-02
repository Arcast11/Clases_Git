#include <iostream>

int main() {

 const double cm_per_inch = 2.54;
 double centimetros{0.0};

 std::cout << "Inserte longitud en centimetros: " << std::endl;
 std::cin >> centimetros;
 
 double inches = centimetros / cm_per_inch;

 std::cout << inches << "pulgadas"  << std::endl;

 return 0;
}
