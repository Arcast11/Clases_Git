/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file MaximoComunDivisor.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date oct 28 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>
#include "funciones.h"

int Maximo_Comun_divisor(int valor_a, int valor_b){

  if (valor_a <= valor_b){
    std::cout << "no se puede realizar" << std::endl;
  }else{
    while ((valor_a % valor_b) != 0){
    int resto = valor_a % valor_b;
    valor_a = valor_b;
    valor_b = resto;
    }
  }
  return valor_b;
}


