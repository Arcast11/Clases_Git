/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 19 2025
 * @brief Descripción del archivo
 */

#ifndef BOOK_CLASS_H
#define BOOK_CLASS_H

#include <iostream>
#include <string>

class Books {
 public:
  Books(std::string title, int publish_date, double price)
      : title_(title), publish_date_(publish_date), price_(price) {};

  /// Getters
  std::string GetTitle() const { return title_; }
  int GetDate() const { return publish_date_; }

  /// Setters
  void SetTitle(std::string title) { title_ = title; }
  void SetDate(int publish_date) { publish_date_ = publish_date; }

  /// Metodos

 private:
  std::string title_;
  int publish_date_;
  double price_;
};

#endif  /// BOOK_CLASS_H