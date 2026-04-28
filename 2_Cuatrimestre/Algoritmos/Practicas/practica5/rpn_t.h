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
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' ||
         c == 'l' || c == 'c' || c == 'm');

  int op = 0;
  int first_op = 0;
  int second_op = 0;
  int third_op = 0;

  if (c == 'r' || c == 'l' || c == 'c') {
    op = stack_.top();
    std::cout << "   Sacamos de la pila un operando: " << op << std::endl;
    stack_.pop();

  } else if (c == 'm') {
    third_op = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila el tercer operando: " << third_op
              << std::endl;

    second_op = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila el segundo operando: " << second_op
              << std::endl;

    first_op = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila el primer operando: " << first_op
              << std::endl;

  } else {
    second_op = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << second_op
              << std::endl;

    first_op = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << first_op
              << std::endl;
  }

  int result = 0;

  switch (c) {
    case '+':
      result = first_op + second_op;
      break;
    case '-':
      result = first_op - second_op;
      break;
    case '*':
      result = first_op * second_op;
      break;
    case '/':
      g++ main_rpn_t.cc - o main_rpn_t result = first_op / second_op;
      break;
    case '^':
      result = pow(first_op, second_op);
      break;
    case 'r':
      result = sqrt(op);
      break;
    case 'l':
      result = log2(op);
      break;
    case 'c':
      result = pow(2, op);
    case 'm':
      result = (first_op + second_op + third_op) / 3;
      break;
  }

  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
}

#endif  // RPNT_H_
