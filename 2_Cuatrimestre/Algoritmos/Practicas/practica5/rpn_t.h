// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T>
class rpn_t {
 public:
  // constructor
  rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private:
  T stack_;
  void operate_(const char operador);
};

// operaciones
template <class T>
const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  int result;
  while (!q.empty()) {
    char c = q.front();

    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
                << "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  result = stack_.top();
  return result;
}

template <class T>
void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/');

  int first_digit = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << first_digit
            << std::endl;

  int second_digit = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila otro operando: " << second_digit
            << std::endl;

  int result = 0;

  switch (c) {
    case '+':
      result = first_digit + second_digit;
      break;
    case '-':
      result = second_digit - first_digit;
      break;
    case '*':
      result = first_digit * second_digit;
      break;
    case '/':
      result = second_digit / first_digit;
      break;
    case '^':
      result = pow(second_digit, first_digit);
      break;
    case 'r':
      result = sqrt(second_digit, first_digit);
    break : case 'l':
      result = log2(first_digit);
      break;
    case 'c':
      result = pow(2, first_digit);
  }

  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
}

#endif  // RPNT_H_
