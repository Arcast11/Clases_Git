/*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso, Armando Castro.
 *               Cursos  : 2025-2026
 */

#include <string.h>

#include "grafo.h"

void pressanykey() {
  char c;
  // system("pause"); s�lo en windows
  cout << endl;
  cout << "pulsa [c] para continuar: ";
  cin >> c;
}

void menu(unsigned dirigido, char& opcion)
// Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
  cout << "Optimizacion en Grafos, 2025-2026 Armando Castro" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  if (dirigido == 0)  // Grafo no dirigido
  {
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
    cout << "r. Aplicar algoritmo de p[r]im del grafo" << endl;
  } else {
    cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
    cout << "o. Mostrar c[o]mponentes fuertemente conexas del grafo" << endl;
  };
  cout << "q. Finalizar el programa" << endl;
  cout << "Introduce la letra de la accion a ejecutar  > ";
  cin >> opcion;
};

// El principal es simplemente un gestor de menu, diferenciando acciones para
// dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char* argv[]) {
  int error_apertura;
  char nombrefichero[85], opcion;
  clrscr();
  // Si tenemos el nombre del primer fichero por argumento, es una excepcion, y
  // lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
    cout << "Introduce el nombre completo del fichero de datos" << endl;
    cin >> nombrefichero;
  };
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y "
            "formato"
         << endl;
    pressanykey();
    clrscr();
  } else {
    cout << "Grafo cargado desde el fichero " << nombrefichero << endl;
    pressanykey();
    clrscr();
    do {
      menu(G.Es_dirigido(), opcion);
      switch (opcion) {
        case 'c':
          clrscr();
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            cout << "Error en la apertura del fichero: revisa nombre y formato "
                    ": puedes volver a intentarlo"
                 << endl;
          } else {
            cout << "Fichero cargado correctamente desde " << nombrefichero
                 << endl;
          };
          pressanykey();
          clrscr();
          break;

        case 'i':
          clrscr();
          cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo();
          pressanykey();
          clrscr();
          break;

        case 'a':
          clrscr();
          cout << "Lista de Adyacencia:" << endl;
          G.Mostrar_Listas(0);
          pressanykey();
          clrscr();
          break;

        case 's':
          clrscr();
          if (G.Es_dirigido() == 1) {
            cout << "Lista de Sucesores:" << endl;
            G.Mostrar_Listas(1);
          }
          pressanykey();
          clrscr();
          break;

        case 'p':
          clrscr();
          if (G.Es_dirigido() == 1) {
            cout << "Lista de Predecesores:" << endl;
            G.Mostrar_Listas(-1);
          } else {
            cout << "El grafo no es dirigido, no tiene lista de predecesores."
                 << endl;
          }
          pressanykey();
          clrscr();
          break;

        case 'o':
          clrscr();
          if (G.Es_dirigido() == 1) {
            cout << "Componentes fuertemente conexas del grafo:";
            G.ComponentesFuertementeConexas();
          } else {
            cout << "Componentes conexas del grafo:" << endl;
            G.ComponentesConexas();
          }
          cout << endl;
          pressanykey();
          clrscr();

          break;

        case 'r':
          clrscr();
          cout << "Árbol generador mínimo del grafo: " << endl;
          G.AlgoritmoPrim();
          cout << endl;
          pressanykey();
          clrscr();
          break;

      }
    } while (opcion != 'q');
  }
  cout << "Fin del programa" << endl;
  return (0);
};
