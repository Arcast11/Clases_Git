/** Universidad de la Laguna
 * Escuela superior de Ingenieria
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Armando Castro
 *
 **/

#include <fstream>
#include <iostream>

/** Función factorial
 * @param valor entero positivo
 * @return Factorial de dicho valor
 */

int Factorial(int numero) {
  int factorial{1};
  for (int i{1}; i <= numero; i++) {
    factorial *= i;
  }
  return factorial;
}

/** Cálculo de coeficiente binomial
 * @param n: cardinal de conjunto de valores a escojer
 * @param k número de elemntos a escojer de dicho conjunto
 * @return Número de posibles selecciones sin repetición
 */

int CoeficienteBinomial(int n, int k) {
  if (n < k) {
    return 0;
  } else if (k <= 0) {
    return 1;
  } else {
    return Factorial(n) / (Factorial(k) * Factorial(n - k));
  }
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << argv[0] << "<fichero> <numero1> <numero2>\n";
  }
  std::ofstream fichero{argv[1], std::ios::app};
  if (!fichero) {
    std::cerr << "No se pudo abrir el fichero " << argv[1] << std::endl;
    return 2;
  }
  fichero << CoeficienteBinomial(atoi(argv[2]), atoi(argv[3])) << std::endl;
  return 0;
}