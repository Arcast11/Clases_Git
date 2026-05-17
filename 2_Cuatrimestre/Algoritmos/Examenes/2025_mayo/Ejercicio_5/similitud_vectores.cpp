/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file sum_matrix_main.cpp
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date May 13 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

 #include "vector_t.hpp"

#include <iostream>
#include "vector_t.hpp"

using namespace std;

int main() {
    // Creamos dos vectores de tamaño 3
    vector_t<double> v1(3);
    vector_t<double> v2(3);

    // Llenamos el Vector 1: [1.0, 2.0, 3.0]
    v1.at(0) = 1.0;
    v1.at(1) = 2.0;
    v1.at(2) = 3.0;

    // Llenamos el Vector 2: [2.0, 4.0, 6.0] 
    // (Es el doble que v1, así que apuntan en la misma dirección, el coseno debe dar 1)
    v2.at(0) = 2.0;
    v2.at(1) = 4.0;
    v2.at(2) = 6.0;

    cout << "--- PRUEBA EJERCICIO 5 (Similitud del Coseno) ---" << endl;
    cout << "Vector 1 -> "; v1.write();
    cout << "Vector 2 -> "; v2.write();

    // Calculamos la similitud usando tu función
    double similitud = v1.cos_sim(v2);

    cout << "\nSimilitud del coseno: " << similitud << endl;
    
    if (similitud == 1.0) {
        cout << "¡Resultado CORRECTO! Funciona a la perfeccion." << endl;
    } else {
        cout << "Hay algun error en el calculo." << endl;
    }

    return 0;
}