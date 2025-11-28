/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 25 2025
 * @brief
 */
#include <iomanip>
#include <iostream>
#include <string>

class ComplexNumbers {
 public:
  double real_part;
  double imaginary_part;

  void PrintNumber() {
    std::cout << "(" << real_part << std::showpos << imaginary_part << "i)"
              << std::noshowpos << std::endl;
  }

  ComplexNumbers(double real_part, double imaginary_part) {
    this->imaginary_part = imaginary_part;
    this->real_part = real_part;
  }
};

ComplexNumbers Sum(ComplexNumbers complex1, ComplexNumbers complex2) {
  ComplexNumbers sum =
      ComplexNumbers(complex1.real_part + complex2.real_part,
                     complex1.imaginary_part + complex2.imaginary_part);
  return sum;
}

ComplexNumbers Dif(ComplexNumbers complex1, ComplexNumbers complex2) {
  ComplexNumbers dif =
      ComplexNumbers(complex1.real_part - complex2.real_part,
                     complex1.imaginary_part - complex2.imaginary_part);
  return dif;
}

ComplexNumbers Multiplication(ComplexNumbers complex1,
                              ComplexNumbers complex2) {
  double mult_real_part = (complex1.real_part * complex2.real_part) -
                          (complex1.imaginary_part * complex1.imaginary_part);
  double mult_imaginary_part = (complex1.real_part * complex2.imaginary_part) +
                               (complex1.imaginary_part * complex2.real_part);

  ComplexNumbers mult = ComplexNumbers(mult_real_part, mult_imaginary_part);
  return mult;
}

int main() {
  ComplexNumbers complex1 = ComplexNumbers(68.04, 0.00);
  ComplexNumbers complex2 = ComplexNumbers(56.62, -21.12);

  complex1.PrintNumber();
  complex2.PrintNumber();
  ComplexNumbers sum = Sum(complex1, complex2);
  sum.PrintNumber();
  ComplexNumbers dif = Dif(complex1, complex2);
  dif.PrintNumber();
  ComplexNumbers mult = Multiplication(complex1, complex2);
  mult.PrintNumber();
  return 0;
}
