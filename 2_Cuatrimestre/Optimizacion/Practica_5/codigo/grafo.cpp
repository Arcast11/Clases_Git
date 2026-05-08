/*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

void GRAFO ::destroy() {
  for (unsigned i = 0; i < n; i++) {
    LS[i].clear();  // 1. Limpiamos y preparamos el vector LP con el tamaño
                    // adecuado (n nodos)
    if (dirigido == 1) LP[i].clear();
  }
  LS.clear();
  if (dirigido == 1) LP.clear();
}

void GRAFO ::build(char nombrefichero[85], int& errorapertura) {
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile.is_open()) {
    unsigned i, j, k;
    textfile >> (unsigned&)n >> (unsigned&)m >> (unsigned&)dirigido;

    // Reservamos espacio para n nodos en LS, y, en su caso,
    LS.resize(n);

    // Leemos los m arcos
    for (k = 0; k < m; k++) {
      textfile >> (unsigned&)i >> (unsigned&)j >> (int&)dummy.c;
      i--;
      j--;

      dummy.j = j;
      LS[i].push_back(dummy);

      // Si el grafo es NO dirigido, añadimos el arco en ambas direcciones en LS
      if (dirigido == 0) {
        dummy.j = i;
        LS[j].push_back(dummy);
      }
    }
    // construimos LP
    if (dirigido == 1) {
      ListaPredecesores();
    }

    errorapertura = 0;
    textfile.close();
  } else {
    errorapertura = 1;
  }
}

GRAFO::~GRAFO() { destroy(); }
GRAFO::GRAFO(char nombrefichero[85], int& errorapertura) {
  build(nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int& errorapertura) {
  // Limpiamos la memoria dinamica asumida en la carga previa, como el
  // destructor
  destroy();
  // Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

// @return: 1 si es dirigido, 0 si no es dirigido
unsigned GRAFO::Es_dirigido() { return dirigido; }

void GRAFO::Info_Grafo() {
  std::cout << "nodos: " << n << std::endl;
  std::cout << "arcos: " << m << std::endl;
  if (Es_dirigido() == 1) {
    std::cout << "Es dirigido" << std::endl;
  } else {
    std::cout << "No es dirigido" << std::endl;
  }
}

void Mostrar_Lista(vector<LA_nodo> L) {
  for (unsigned i{0}; i < L.size(); i++) {
    cout << "Nodo [" << i + 1 << "] ->";
    for (unsigned k{0}; k < L[i].size(); k++) {
      cout << " " << L[i][k].j + 1 << " " << L[i][k].c << " | ";
    }
    cout << endl;
  }
}

void GRAFO ::Mostrar_Listas(int l) {
  if (l == 0) {  // Es no dirigido
    // Mostramos lista de adyacencia
    Mostrar_Lista(LS);
  } else if (l == 1) {
    // Mostrar lista de sucesores
    Mostrar_Lista(LS);
  } else if (l == -1) {
    // Mostrar lista de predecesores
    Mostrar_Lista(LP);
  }
}

// Recorre la lista de sucesores LS para construir
// la de predecesores, LP
void GRAFO::ListaPredecesores() {
  LP.clear();
  LP.resize(n);

  ElementoLista dummy;

  // 2. Recorremos toda la Lista de Sucesores (LS)
  for (unsigned i = 0; i < LS.size(); i++) {
    for (unsigned k = 0; k < LS[i].size(); k++) {
      // En LS, el nodo 'i' apunta a 'LS[i][k].j' con un coste 'LS[i][k].c'.
      // Para invertirlo en LP: el nodo 'LS[i][k].j' recibe una flecha desde
      // 'i'.
      dummy.j = i;
      dummy.c = LS[i][k].c;  // Mantenemos el coste original del arco

      // Lo guardamos en la lista de predecesores del nodo destino
      LP[LS[i][k].j].push_back(dummy);
    }
  }
}

void GRAFO::dfs_cc(unsigned i, vector<bool>& visitado) {
  // Este recorrido esta� hecho adhoc para mostrar el ritmo de nodos visitados,
  // para su uso en la construccion de Componentes Conexas
  visitado[i] = true;  // visitamos el nodo i + 1
  cout << i + 1;
  for (unsigned j = 0; j < LS[i].size(); j++) {
    // recorremos la adyacencia del nodo visitado, esto es, i + 1
    if (!visitado[LS[i][j].j]) {
      cout << " , ";
      GRAFO::dfs_cc(LS[i][j].j, visitado);
    }
  }
}

void GRAFO::ComponentesConexas() {
  unsigned i, componentes_conexas = 0;
  vector<bool> visitado;
  visitado.resize(n, false);
  i = 0;
  while (i < n) {
    if (!visitado[i]) {
      componentes_conexas++;
      cout << " \nComponente conexa " << componentes_conexas << "{:";
      dfs_cc(i, visitado);
      cout << " }";
    }
    i++;
  }
}

void GRAFO::dfs_cfc(unsigned i, vector<bool>& visitado) {
  // Este recorrido esta� hecho adhoc para mostrar el ritmo de nodos visitados,
  // para su uso en la construccion de Componentes fuertemente Conexas
  visitado[i] = true;  // visitamos el nodo i + 1
  cout << i + 1;
  for (unsigned j = 0; j < LP[i].size(); j++) {
    // recorremos la adyacencia del nodo visitado, esto es, i + 1
    if (!visitado[LP[i][j].j]) {
      cout << " , ";
      dfs_cfc(LP[i][j].j, visitado);
    }
  }
}

void GRAFO::dfs_postnum(unsigned i, vector<bool>& visitado,
                        vector<unsigned>& postnum, unsigned& postnum_ind) {
  // Este recorrido esta� hecho adhoc para calcular
  // el orden postnumeraci�n de los nodos
  visitado[i] = true;
  for (unsigned j = 0; j < LS[i].size(); j++) {
    // recorremos la adyacencia del nodo visitado, esto es, i + 1
    if (!visitado[LS[i][j].j]) {
      dfs_postnum(LS[i][j].j, visitado, postnum, postnum_ind);
    }
  }
  postnum[postnum_ind--] = i;
}

void GRAFO::ComponentesFuertementeConexas() {
  unsigned i, postnum_ind, componentes_fuertemente_conexas = 0;
  vector<bool> visitado;
  vector<unsigned> postnum;

  visitado.resize(n, false);
  postnum.resize(n, UERROR);

  postnum_ind = n - 1;
  i = 0;

  while (i < n) {
    if (visitado[i] == false) {
      dfs_postnum(i, visitado, postnum, postnum_ind);
    }
    i++;
  }
  visitado.assign(n, false);
  i = 0;
  while (i < n) {
    if (visitado[postnum[i]] == false) {
      componentes_fuertemente_conexas++;
      cout << "\nComponente Fuertemente Conexa "
           << componentes_fuertemente_conexas << ":{";
      dfs_cfc(postnum[i], visitado);
      cout << "}";
    }
    i++;
  }
}

void GRAFO::AlgoritmoPrim() {
  vector<bool> M(n, false);          // Nodos añadidos al árbol
  vector<int> coste(n, maxint);      // vector de costes inicializado a infinito
  vector<unsigned> pred(n, UERROR);  // T en la guia

  unsigned r;  // Nodo raiz del grafo
  cout << "introduce el nodo de partidda (1 a " << n << "): ";
  cin >> r;
  r--;  // Ajustamos el indice ya que esta guardado como vector LA

  // Inicializamos el nodo raiz
  coste[r] = 0;
  pred[r] = r;

  int coste_total = 0;

  cout << "\nConstruyendo el arbol generador de mínimo coste..." << endl;
  cout << "Nodo raiz: " << r + 1 << endl;

  unsigned u;  // nodo actual

  for (unsigned i = 0; i < n; i++) {
    int min_coste = maxint;
    u = UERROR;  // nodo actual

    unsigned nC = 0;  // Nodos Conectados
    while (nC < n) {
      if (!M[nC] && coste[nC] < min_coste) {
        min_coste = coste[nC];
        u = nC;
      }
      nC++;
    }

    if (u == UERROR) {
      cout << "El grafo no es conexo..." << endl;
      coste_total = 0;
      break;
    }

    M[u] = true;
    coste_total += coste[u];

    if (u != r) {
      cout << "Arista anadida: (" << pred[u] + 1 << ", " << u + 1
           << ") - Coste: " << coste[u] << endl;
    }
    // Actualizamos los costes en y predecesores en la lista de adyacencia
    for (unsigned j = 0; j < LS[u].size(); j++) {
      unsigned v = LS[u][j].j;
      int peso = LS[u][j].c;

      // Si v no está en M y el peso de la arista (u,v) mejora el coste actual
      if (!M[v] && coste[v] > peso) {
        coste[v] = peso;
        pred[v] = u;  // Cambiamos el nodo de conexión
      }
    }
  }
  if (u != UERROR) {
    cout << "\nCoste total del MST: " << coste_total << endl;
  }
}


void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred){
  if(i != s){
    MostrarCamino(s,pred[i],pred);
    cout << " -> " << i + 1; 
  } else {
    cout << i + 1;
  }
}

void GRAFO::TWOQ(){
  deque<unsigned> dcola1, dcola2;
  vector<int> d;
  vector<unsigned> pred;
  vector<bool> Encola;
  unsigned s;

  Encola.resize(n,false);
  d.resize(n,maxint);
  pred.resize(n,UERROR);

  cout << "Nodo de partida [1 a " << n << "]: " << endl;
  cin >> s;
  s--;

  // Buscamos los costes negativos (menor coste Cmin)
  int Cmin {0};
  for(unsigned i{0}; i < n; i++){
    for(unsigned k{0}; k < LS[i].size(); k++){
      if(LS[i][k].c < Cmin){
        Cmin = LS[i][k].c;
      }
  }
  int limite_ciclo_negativo = n * Cmin;
  
  // Inicializamos S y lo añadimos s a la cola
  d[s] = 0;
  pred[s] = s;
  dcola2.push_back(s);
  Encola[s] = true;

  while(!dcola1.empty() || !dcola2.empty()){
    unsigned k;
    if(!dcola1.empty()){
      k = dcola1.front();
      dcola1.pop_front();
    } else {
      k = dcola2.front();
      dcola2.pop_front();
    }
    Encola[k] = false;
    for(unsigned i{0}; i < LS[k].size(); i++){
      unsigned j = LS[k][i].j;
      int c_kj = LS[k][i].c;

      if(d[j] > d[k] + c_kj){
        bool nunca_en_cola = (d[j] == maxint);

        d[j] = d[k] + c_kj;
        pred[j] = k;

        if(Cmin < 0 && d[j] <= limite_ciclo_negativo){
          cout << "Existe al menos un circuito de coste negativo.";
          return;
        }
        if(!Encola[j]){
          if(nunca_en_cola){
            dcola2.push_back(j);
          } else {
            dcola1.push_back(j);
          }
          Encola[j] = true;
        }
        d[j] = d[k] + LS[i][j].c;
        pred[j] = k;
      }
    }
  }
}
}