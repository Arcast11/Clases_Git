/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Jan 05 2026
 * @brief Descripción del archivo
 */

#include <iostream>
#include <string>

class Rey {
 public:
  Rey() = default;

  /// Atributos de acceso (Getters)
  std::string GetNombre() const { return nombre_; }
  int GetInicio() const { return inicio_; }
  int GetFinal() const { return final_; }

  /// Atributos de asignación (Setters)
  void SetNombre(const std::string& nombre) { nombre_ = nombre; }
  void GetInicio(int inicio) { inicio_ = inicio; }
  void GetFinal(int final) { final_ = final; }

  int DuracionReinado() const;

 private:
  std::string nombre_;
  int inicio_;
  int final_;
};
/// sobrecarga de operadores
bool operador < (const Rey& rey1, const Rey& rey2);
std::ostream operator<<(std::ostream& out_stream, const Rey& rey);
std::istream operator>>(std::istream& in_stream, Rey& rey);