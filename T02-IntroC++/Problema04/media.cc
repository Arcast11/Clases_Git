#include <iostream>

int main (){

 	double value1, value2, value3, value4;

	std::cout << "Inserte el primer valor: ";
	std::cin >> value1;
	std::cout << "Inserte el segundo valor: ";
	std::cin >> value2;
	std::cout << "Inserte el tercer valor: ";
	std::cin >> value3;
	std::cout << "Inserte el cuarto valor: ";
	std::cin >> value4;
	
	double average = (value1 + value2 + value3 + value4) / 4;

	std::cout << "La media es: " << average << std::endl;

return 0;

}
	
