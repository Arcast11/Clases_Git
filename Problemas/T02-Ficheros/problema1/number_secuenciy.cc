#include <iostream>
#include <string>
#include <fstream>

std::string IsOdd(const std::string& numbers){
    std::string is_odd;

    for (char c : number){
        if (c % 2 == 0){
            is_odd += c;
         }
    }
} return is_odd;

std::string IsEven(const std::string& numbers){
    std::string is_even;

    for 
}

int main(int argc, char argv[]){
    if (argc != 2){
        std::cerr << "El programa debe recibir como argumento: " argv[0]
                  << " <nombre_del_programa>";
        reeturn 1;
    }
    std::in_file {"test.txt"};

    if (!in_file){
        std::cerr << "No se ha podido abrir el archivo" << std::endl;
    }
    std::string numbers;
    while (std::getline(in_file, numbers)){
        std::cout << numbers << std::endl;
    }
    return 0;
}