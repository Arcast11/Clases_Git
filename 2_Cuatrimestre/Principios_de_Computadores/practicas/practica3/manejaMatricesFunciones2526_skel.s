# // Manejo de matrices con funciones

# #include <iostream>
# #include <iomanip>
# #include <tuple>

# typedef struct {
#   int nFil;
#   int nCol;
#   double elementos[];
# } structMat;


# structMat mat0 {
#   6,
#   6,
#   {
#     11.125, 12.125, 13.125, 14.125, 15.125, 16.125,
#     21.125, 22.125, 23.125, 24.125, 25.375, 26.375,
#     31.375, 32.375, 33.375, 34.375, 35.375, 36.375,
#     41.375, 42.375, 43.375, 44.375, 45.375, 46.375,
#     51.625, 52.625, 53.625, 54.625, 55.625, 56.625,
#     61.625, 62.625, 63.625, 64.625, 65.625, 66.625,

#   }
# };

# structMat mat1 {
#   10,
#   7,
#   {
#     -36.9375, -58.1875, 78.65625, 19.09375, -50.8125, 33.96875, -59.5625,
#     12.34375, 57.28125, -1.96875, -86.8125, -81.8125, 54.59375, -22.5625,
#     88.21875, 64.34375, 52.90625, 47.90625, -83.5625, 19.03125, 4.265625,
#     -31.9375, 82.53125, 27.40625, 56.53125, 39.46875, 18.40625, 97.03125,
#     76.90625, 14.59375, 67.78125, -9.84375, -97.9375, 32.34375, -18.4375,
#     -43.4375, 39.84375, 87.65625, -31.9375, -17.8125, 30.09375, 87.65625,
#     -6.90625, 64.59375, -85.0625, 70.53125, -48.8125, -62.6875, -60.1875,
#     -5.53125, 84.34375, -51.6875, 93.15625, -10.8125, 32.09375, 98.34375,
#     69.46875, 73.84375, 3.734375, 57.21875, -41.5625, -17.4375, -64.1875,
#     -71.3125, -97.9375, 7.109375, -79.0625, 33.84375, 63.53125, -96.1875,

#   }
# };

# structMat mat2 {
#   1,
#   8,
#   {
#     -36.75, 35.375, 79.125, -58.75, -55.25, -19.25, -88.75, -93.75,
#   }
# };

# structMat mat3 {
#   16,
#   1,
#   {
#     -90.75, -65.25, -58.25, -73.25, -89.25, -79.25, 16.875, 66.375,
#     -96.25, -97.25, -24.75, 5.3125, -33.75, -13.25, 27.125, -74.75,

#   }
# };

# structMat mat4 {
#   1,
#   1,
#   { 78.875 }
# };

# structMat mat5 {
#   0,
#   0,
#   { 0 }
# };

# #define NUM_MATRICES  6
# structMat* matrices[NUM_MATRICES]={&mat0, &mat1, &mat2, &mat3, &mat4, &mat5};

# void print_mat(structMat* mat) {
#   int nFil = mat->nFil;
#   int nCol = mat->nCol;
#   double* datos = mat->elementos;
#   std::cout << "\n\nLa matriz tiene dimension " << nFil
#       << 'x' << nCol << '\n';
#   for(int f = 0; f < nFil; f++) {
#     for(int c = 0; c < nCol; c++) {
#       std::cout << datos[f*nCol + c] << ' ';  // datos[f][c]
#     }
#     std::cout << '\n';
#   }
#   std::cout << '\n';
# }

# void change_elto(structMat* mat, int indF, int indC, double valor) {
#   int numCol = mat->nCol;
#   double* datos = mat->elementos;
#   datos[indF * numCol + indC] = valor;  // datos[indF][indC]
# }

# void swap(double* e1, double* e2) {
#   double temp1 = *e1;
#   double temp2 = *e2;
#   *e1 = temp2;
#   *e2 = temp1;
# }

# void intercambia(structMat* mat, int indF, int indC) {
#   int numCol = mat->nCol;
#   int numFil = mat->nFil;
#   double* datos = mat->elementos;
#   // e1 = &(datos[indF][indC]);
#   double* e1 = datos + (indF * numCol + indC);
#   int indFilaOpuesta = (numFil - indF - 1);
#   int indColOpuesta = (numCol - indC - 1);
#   // e1 = &(datos[indFilaOpuesta][indColOpuesta])
#   double* e2 = datos + (indFilaOpuesta * numCol + indColOpuesta);
#   swap(e1, e2);
# }

# void procesa_cols(structMat* mat, int indC1, int indC2) {
#   int numCol = mat->nCol;
#   int numFil = mat->nFil;
#   double* datos = mat->elementos;
#   for(int fa = 0; fa < numFil; fa++) {
#     // e1 = &(datos[fa][indC1]);
#     double* e1 = datos + (fa * numCol + indC1);
#     // e2 = &(datos[fa][indC2]);
#     double* e2 = datos + (fa * numCol + indC2);
#     double val1 = *e1;
#     double val2 = *e2;
#     if(val1 > val2) {
#       *e1 = val1 / 2.0;
#     } else {
#       swap(e1, e2);
#     }
#     *e2 = *e2 + 0.5625;
#   }
# }

# double find_max(structMat* mat) {
#   int numCol = mat->nCol;
#   int numFil = mat->nFil;
#   double* datos = mat->elementos;
#   double max = datos[0];
#   for(int f = 0; f < numFil; f++) {
#     for(int c = 0; c < numCol; c++) {
#       double valor = datos[f * numCol + c];  // datos[f][c]
#       if (valor > max) {
#         max = valor;
#         std::cout << "\nNuevo maximo " << max;
#       }
#     }
#   }
#   return max;
# }

# int leeFila(int numFilas) {
#   int indFil;
#   std::cin >> indFil;
#   if ((indFil < 0) || (indFil >= numFilas)) {
#     std::cout << "Error: Numero de fila incorrecto\n";
#     return -1;
#   }
#   return indFil;
# }

# int leeColumna(int numColumnas) {
#   int indCol;
#   std::cin >> indCol;
#   if ((indCol < 0) || (indCol >= numColumnas)){
#     std::cout << "Error: Numero de columna incorrecto\n";
#     return -1;
#   }
#   return indCol;
# }

# std::tuple<int, int> pideFilaYColumna(structMat* mat) {
#   std::cout << "\nIndice de fila: ";
#   int indFil = leeFila(mat->nFil);
#   if (indFil < 0) {
#     return {-1, -1};
#   }
#   std::cout << "Indice de columna: ";
#   int indCol = leeColumna(mat->nCol);
#   if (indCol < 0) {
#     return {-1, -1};
#   }
#   return {indFil, indCol};
# }

# int main() {
#   std::cout << std::setprecision(18); // Ignorar
#   std::cout << "\nComienza programa manejo matrices con funciones";

#   structMat* matTrabajo = matrices[0];
#   int opcion;
#   do {
#     print_mat(matTrabajo);
#     std::cout <<
#     "(0) Terminar el programa\n"
#     "(1) Cambiar la matriz de trabajo\n"
#     "(3) Cambiar el valor de un elemento\n"
#     "(4) Intercambiar un elemento con su opuesto\n"
#     "(5) Procesa columnas\n"
#     "(7) Encuentra maximo\n"
#     "\nIntroduce opción elegida: ";

#     std::cin >> opcion;

#     int indFil;
#     int indCol;
#     switch (opcion) {
#       // Opción 0 //////////////////////////////////////////////////////////
#       case 0:
#         std::cout << "\nEligida opción de salir";
#         break; // salimos del switch
#       // Opción 1 //////////////////////////////////////////////////////////
#       case 1:
#         std::cout << "\nElije la matriz de trabajo: ";
#         int matT;
#         std::cin >> matT;
#         if ((matT < 0) || (matT >= NUM_MATRICES)) {
#           std::cout << "Numero de matriz de trabajo incorrecto\n";
#           break; // salimos del switch
#         }
#         matTrabajo = matrices[matT];
#         break; // salimos del switch

#       // Opción 3 //////////////////////////////////////////////////////////
#       case 3:
#         std::tie(indFil, indCol) = pideFilaYColumna(matTrabajo);
#         if (indFil < 0)
#           break; // salimos del switch
#         std::cout << "Nuevo valor para el elemento: ";
#         double valor;
#         std::cin >> valor;

#         change_elto(matTrabajo, indFil, indCol, valor);

#         break; // salimos del switch

#       // Opción 4 //////////////////////////////////////////////////////////
#       case 4:
#         std::tie(indFil, indCol) = pideFilaYColumna(matTrabajo);
#         if (indFil < 0)
#           break; // salimos del switch

#         intercambia(matTrabajo, indFil, indCol);

#         break; // salimos del switch

#       // Opción 5 //////////////////////////////////////////////////////////
#       case 5:
#         std::cout << "\nPrimera columna a procesar: ";
#         int indC1;
#         indC1 = leeColumna(matTrabajo->nCol);
#         if (indC1 < 0) {
#           break; // salimos del switch
#         }
#         std::cout << "Segunda columna a procesar: ";
#         int indC2;
#         indC2 = leeColumna(matTrabajo->nCol);
#         if (indC2 < 0) {
#           break;  // salimos del switch
#         }

#         procesa_cols(matTrabajo, indC1, indC2);
#         break;  // salimos del switch

#       // Opción 7 //////////////////////////////////////////////////////////
#       case 7:
#         double maximo;
#         maximo = find_max(matTrabajo);
#         std::cout << "\nEl valor maximo en la matriz es " << maximo;
#         break; // salimos del switch

#       default:
#         // Opción Incorrecta ////////////////////////////////////////////////
#         std::cout << "Error: opcion incorrecta\n";
#     }  // fin del switch
#     std::cout << "\nTerminada la opción " << opcion;
#   } while (opcion != 0);
#   std::cout << "\n\nTermina el programa\n";
# }
    .data
mat0:   .word 6, 6
    .double 11.125, 12.125, 13.125, 14.125, 15.125, 16.125
    .double 21.125, 22.125, 23.125, 24.125, 25.375, 26.375
    .double 31.375, 32.375, 33.375, 34.375, 35.375, 36.375
    .double 41.375, 42.375, 43.375, 44.375, 45.375, 46.375
    .double 51.625, 52.625, 53.625, 54.625, 55.625, 56.625
    .double 61.625, 62.625, 63.625, 64.625, 65.625, 66.625

mat1:   .word 10, 7
    .double -36.9375, -58.1875, 78.65625, 19.09375, -50.8125, 33.96875, -59.5625
    .double 12.34375, 57.28125, -1.96875, -86.8125, -81.8125, 54.59375, -22.5625
    .double 88.21875, 64.34375, 52.90625, 47.90625, -83.5625, 19.03125, 4.265625
    .double -31.9375, 82.53125, 27.40625, 56.53125, 39.46875, 18.40625, 97.03125
    .double 76.90625, 14.59375, 67.78125, -9.84375, -97.9375, 32.34375, -18.4375
    .double -43.4375, 39.84375, 87.65625, -31.9375, -17.8125, 30.09375, 87.65625
    .double -6.90625, 64.59375, -85.0625, 70.53125, -48.8125, -62.6875, -60.1875
    .double -5.53125, 84.34375, -51.6875, 93.15625, -10.8125, 32.09375, 98.34375
    .double 69.46875, 73.84375, 3.734375, 57.21875, -41.5625, -17.4375, -64.1875
    .double -71.3125, -97.9375, 7.109375, -79.0625, 33.84375, 63.53125, -96.1875

mat2:   .word 1, 8
    .double -36.75, 35.375, 79.125, -58.75, -55.25, -19.25, -88.75, -93.75

mat3:   .word 16, 1
    .double -90.75, -65.25, -58.25, -73.25, -89.25, -79.25, 16.875, 66.375
    .double -96.25, -97.25, -24.75, 5.3125, -33.75, -13.25, 27.125, -74.75

mat4:   .word 1, 1
    .double 78.875
mat5:   .word 0, 0
    .double 0.0

# #define NUM_MATRICES  6
NUM_MATRICES = 6
tamD=8  # tamaño de un double en bytes
tamP=4  # tamaño de una palabra (dirección) en bytes
nFil=0  # desplazamiento para acceder a nFil en la estructura
nCol=4  # desplazamiento para acceder a nCol en la estructura
elementos=8  # desplazamiento para acceder a elementos en la estructura
# structMat* matrices[NUM_MATRICES]={&mat0, &mat1, &mat2, &mat3, &mat4, &mat5};
matrices:       .word mat0, mat1, mat2, mat3, mat4, mat5
cadTitulo:      .asciiz "\nComienza programa manejo matrices con funciones"
cadMenu:        .ascii "(0) Terminar el programa\n"
                .ascii "(1) Cambiar la matriz de trabajo\n"
                .ascii "(3) Cambiar el valor de un elemento\n"
                .ascii "(4) Intercambiar un elemento con su opuesto\n"
                .ascii "(5) Procesa columnas\n"
                .ascii "(7) Encuentra maximo\n"
                .asciiz "\nIntroduce opción elegida: ";
cadDim:         .asciiz "\n\nLa matriz tiene dimension "
cadErrorFila:   .asciiz "Error: Numero de fila incorrecto\n"
cadErrorCol:    .asciiz "Error: Numero de columna incorrecto\n"
pideFila:       .asciiz "\nIndice de fila: "
pideCol:        .asciiz "Indice de columna: "
cadNuevoMax:    .asciiz "\nNuevo maximo "
cadSalir:       .asciiz "\nElegida opción de salir"
cadEligeMat:    .asciiz "\nElije la matriz de trabajo: "
cadErrorMat:    .asciiz "Numero de matriz de trabajo incorrecto\n"
cadNuevoValor:  .asciiz "Nuevo valor para el elemento: "
cadTerOpc:      .asciiz "\nTerminada la opción "
cadErrorOpcion: .asciiz "Error: opcion incorrecta\n"
cadPrimCol:     .asciiz "\nPrimera columna a procesar: "
cadSegCol:      .asciiz "Segunda columna a procesar: "
cadMax:         .asciiz "\nEl valor maximo en la matriz es "
cadFin:         .asciiz "\n\nTermina el programa\n"


	.text

# void print_mat(structMat* mat) {
# Parámetros de entrada
# structMat* mat → $a0 → $s0
# parametros de salida: ninguno

# Esta función llama a otra: NECESITA USAR LA PILA
# Tabla de asignación de registros
# int nFil → $s1
# int nCol → $s2
# double* datos → $s4
# int f → $s5
# int c → $s8

print_mat:

	#PUSH: $RA, $S0, $S1, $S2, $S4, $S5, $S8: 7 * 4 = 28
	addi	$sp,$sp, -28
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s4, 16($sp)
	sw	$s5, 20($sp)
	sw	$s8, 24($sp)

	move	$s0,$a0

#   int nFil = mat->nFil;
	lw	$s1,nFil($s0)

#   int nCol = mat->nCol;
	lw	$s2,nCol($s0)

#   double* datos = mat->elementos;
	la	$s4,elementos($s0)

#   std::cout << "\n\nLa matriz tiene dimension " << nFil
#       << 'x' << nCol << '\n';
	li	$v0,4
	la	$a0,cadDim
	syscall			#Imprime la cadena cadDim
	
	li	$v0,1
	move	$a0, $s1
	syscall			# Imprime nfil
	
	li	$v0,11
	li	$a0,'x'
	syscall			# Imprime el carácter x
	
	li	$v0,1
	move	$a0, $s2
	syscall			# Imprime ncol
	
	li	$v0,11
	li	$a0,'\n'
	syscall

#   for(int f =: 0; f < nFil; f++) {
	move $s5,$zero

print_mat_for_f:
	bge	$s5, $s1,print_mat_for_f_fin

#     for(int c = 0; c < nCol; c++) {
	move $s8,$zero
	
print_mat_for_c:
	bge	$s8,$s2,print_mat_for_c_fin

#       std::cout << datos[f*nCol + c] << ' ';  // datos[f][c]

	# dirección datos[f][c] → $t1
	mul	$t1,$s5,$s2
	add	$t1,$t1,$s8
	mul	$t1,$t1,tamD
	add	$t1,$s4,$t1

	li	$v0,3
	l.d	$f12,0($t1)
	syscall
	
	li	$v0,11
	li	$a0,' '
	syscall
	
	addi	$s8,$s8,1
	b	print_mat_for_c
        
#     }
print_mat_for_c_fin:
#     std::cout << '\n';
	li	$v0,11
	li	$a0,'\n'
	syscall
	
	addi	$s5,$s5,1
	b	print_mat_for_f
#   }
print_mat_for_f_fin:

#   std::cout << '\n';
	li	$v0,11
	li	$a0,'\n'
	syscall
# }

	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s4, 16($sp)
	lw	$s5, 20($sp)
	lw	$s8, 24($sp)
	addi	$sp,$sp, 28

	jr	$ra

print_mat__MARCAFIN:

# void change_elto(structMat* mat, int indF, int indC, double valor) {
# Parámetros de entrada:
# structMat* mat → $a0
# int indF → $a1
# int indC → $a2
# double valor → $f12
# Parámetros de salida: ninguno

# Función no llama a otra: NO NECESITA USAR LA PILA
# Tabla de variables a registros
# int numCol → $t0
# double* datos → $t1

change_elto:

#   int numCol = mat->nCol;
	lw	$t0,nCol($a0)
#   double* datos = mat->elementos;
	la	$t1,elementos($a0)
#   datos[indF * numCol + indC] = valor;  // datos[indF][indC]

	#Dirección de datos → $t1
	mul	$t4,$a1,$t0
	add	$t4,$t4,$a2
	mul	$t4,$t4,tamD
	add	$t4,$t1,$t4
	
	s.d	$f12,0($t4)
# }
	jr	$ra
change_elto__MARCAFIN:

# void swap(double* e1, double* e2) {
# Parámetros de entrada:
# double* e1 → $a0
# double* e2 → $a1
# Parámetros de salida: ninguno

# Función NO llama a otra: NO NECESITA USAR LA PILA
# Tabla de variables a registros 
# double temp1 → $f10
# double temp2 → $f18

swap:

#   double temp1 = *e1;
	l.d	$f10,0($a0)
#   double temp2 = *e2;
	l.d	$f18,0($a1)
	
#   *e1 = temp2;
	s.d 	$f18,0($a0)
#   *e2 = temp1;
	s.d 	$f10,0($a1)
# }
	jr	$ra
swap__MARCAFIN:

# void intercambia(structMat* mat, int indF, int indC) {
# Parámetros de entrada:
# structMat* mat	→ $a0 → $s0
# int indF		→ $a1 → $s1
# int indC		→ $a2 → $s2

# Esta función llama a otra: NECESITA USAR LA PILA
# Tabla de asignación de registros
# int numCol		→ $t6
# int numFil		→ $t7
# double* datos		→ $t8
# double* e1		→ $t4
# double* e2		→ $t5

intercambia:
    # PUSH: $ra, $s0, $s1, $s2, $s3, $s4, $s5 (7 registros * 4 bytes = 28 bytes)
   
	addi	$sp, $sp, -16
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)


	move	$s0, $a0	# mat*
	move	$s1, $a1	# indF
	move	$s2, $a2	# indC

#   int numCol = mat->nCol;
	lw	$t6, nCol($s0)

#   int numFil = mat->nFil;
	lw	$t7, nFil($s0)
    
#   double* datos = mat->elementos;
	la	$t8,elementos($s0)

#   // e1 = &(datos[indF][indC]);
#   double* e1 = datos + (indF * numCol + indC);
	mul	$t0, $s1, $t6	# $t0 = indF * numCol
	add	$t0, $t0, $s2	# $t0 = indF * numCol + indC
	mul	$t0, $t0, tamD	# 
	add	$t4, $t8, $t0	# $t4 = dirección de memoria de e1

#   int indFilaOpuesta = (numFil - indF - 1);
	sub	$t1, $t7, $s1	# numFil - indF
	addi	$t1, $t1, -1	# indFilaOpuesta

#   int indColOpuesta = (numCol - indC - 1);
	sub	$t2, $t6, $s2	# numCol - indC
	addi	$t2, $t2, -1	# indColOpuesta

#   // e2 = &(datos[indFilaOpuesta][indColOpuesta])
#   double* e2 = datos + (indFilaOpuesta * numCol + indColOpuesta);
	mul	$t3, $t1, $t6	# indFilaOpuesta * numCol
	add	$t3, $t3, $t2	# + indColOpuesta
	mul	$t3, $t3, tamD	
	add	$t5, $t8, $t3

#   swap(e1, e2);
	# Paso como parametros e1 y e2
	move	$a0, $t4	# Paso dirección de e1
	move	$a1, $t5	# Paso dirección de e2
	jal	swap		# Llamo a la función swap

# }
	# POP: $ra, $s0, $s1, $s2, $s3, $s4, $s5

	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	addi	$sp, $sp, 16

	jr	$ra

intercambia__MARCAFIN:

# void procesa_cols(structMat* mat, int indC1, int indC2) {
# Parámetros de Entrada
# structMat* mat	→ $a0 → $s0
# int indC1		→ $a1 → $s1
# int indC2		→ $a2 → $s2

# Esta función llama a otra: Necesita usar la pila
# Tabla de asignación de registros
# int numCol		→ $s3
# int numFil		→ $s4
# double* datos		→ $s5
# int fa		→ $s6
# double* e1		→ $s7
# double* e2		→ $s8
# double val1		→ $f20
# double val2		→ $f22

procesa_cols:

	# PUSH: $ra, $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7 
	addi	$sp, $sp, -56
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	sw	$s5, 24($sp)
	sw	$s6, 28($sp)
	sw	$s7, 32($sp)
	sw	$s8, 36($sp)
	s.d	$f20,40($sp)
	s.d	$f22,48($sp)
	
	move	$s0, $a0	# mat
	move	$s1, $a1	# indC1
	move	$s2, $a2	# indC2
	
#   int numCol = mat->nCol;
	lw	$s3,nCol($s0)
	
#   int numFil = mat->nFil;
	lw	$s4,nFil($s0)
	
#   double* datos = mat->elementos;
	la	$s5,elementos($s0)
	
#   for(int fa = 0; fa < numFil; fa++) {
	move	$s6,$zero
procesa_cols_for_fa:
	bge	$s6,$s4, procesa_cols_for_fa_fin

#     // e1 = &(datos[fa][indC1]);
#     double* e1 = datos + (fa * numCol + indC1);
	mul	$t0,$s6,$s3	# fa * numCol
	add	$t0,$t0,$s1	# + indC1
	mul	$t0,$t0,tamD
	add	$s7,$t0,$s5	# + datos

#     // e2 = &(datos[fa][indC2]);
#     double* e2 = datos + (fa * numCol + indC2);
	mul	$t0,$s6,$s3	# fa * numCol
	add	$t0,$t0,$s2	# + indC2
	mul	$t0,$t0,tamD
	add	$s8,$t0,$s5	# + datos
	
#     double val1 = *e1;
	l.d	$f20,0($s7)
	
#     double val2 = *e2;
	l.d	$f22,0($s8)

#     if(val1 > val2) {
procesa_cols_if_val1_val2:
	c.le.d	$f20,$f22
	bc1t	procesa_cols_else_val1_val2
#       *e1 = val1 / 2.0;
	li.d	$f16,2.0
	div.d	$f20,$f20,$f16
	s.d	$f20,0($s7)
	j	procesa_cols_if_val1_val2_fin
	
#     } else {
procesa_cols_else_val1_val2:
#       swap(e1, e2);
	move	$a0,$s7
	move	$a1,$s8
	jal 	swap
	l.d	$f22,0($s8)
#     }


procesa_cols_if_val1_val2_fin:


#     *e2 = *e2 + 0.5625;
	li.d	$f18,0.5625
	# val2 = val2 + 0.5625
	add.d	$f22,$f22,$f18 
	s.d	$f22,0($s8)
	
	addi	$s6,$s6,1
	b	procesa_cols_for_fa
#   }
procesa_cols_for_fa_fin:
# }
	# POP: $ra, $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7 (9 * 4 = 36)
	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	lw	$s4, 20($sp)
	lw	$s5, 24($sp)
	lw	$s6, 28($sp)
	lw	$s7, 32($sp)
	lw	$s8, 36($sp)
	l.d	$f20,40($sp)
	l.d	$f22,48($sp)
	addi	$sp, $sp, 56

	jr	$ra
procesa_cols__MARCAFIN:

# double find_max(structMat* mat) {
# Parámetros de Entrada
# structMat* mat	→ $a0	$s0

# Esta función llama al syscall: Debe usar la pila
# Tabla de asignación de variables
# int numCol		→ $s1
# int numFil		→ $s2
# double* datos		→ $s3
# int f			→ $s4
# int c			→ $s5
# double max		→ $f20
# double valor		→ $f22

# Parámetros de Salida
# double max		→ $f0

find_max:
	# PUSH $s0,$s1,$s2,$s3,$f20,$f22 (reservar 48)
	addi $sp,$sp,-48
	sw	$ra,0($sp)
	sw	$s0,4($sp)
	sw	$s1,8($sp)
	sw	$s2,12($sp)
	sw	$s3,16($sp)
	sw	$s4,20($sp)
	sw	$s5,24($sp)
	s.d	$f20,32($sp)
	s.d	$f22,40($sp)
	
	move	$s0,$a0		#*mat
	
#   int numCol = mat->nCol;
	lw	$s1,nCol($s0)
	
#   int numFil = mat->nFil;
	lw	$s2,nFil($s0)
	
#   double* datos = mat->elementos;
	la	$s3,elementos($s0)
	
#   double max = datos[0];
	l.d	$f20,0($s3)
	
	
#   for(int f = 0; f < numFil; f++) {
	
	move	$s4,$zero
for_f_find_max:
	bge	$s4,$s2,for_f_find_max_fin
	
#     for(int c = 0; c < numCol; c++) {
	move	$s5,$zero
for_c_find_max:
	bge	$s5,$s1,for_c_find_max_fin
	
#       double valor = datos[f * numCol + c];  // datos[f][c]
	mul	$t0,$s4,$s1	# f * numCol
	add	$t0,$t0,$s5	# + c
	mul	$t0,$t0,tamD	# * 8
	add 	$t0,$t0,$s3	# movemos la dirección a la posición del dato
	
	l.d	$f22,0($t0)
	
#       if (valor > max) {
if_find_max:
	c.lt.d	$f20,$f22
	bc1f	if_find_max_fin

#         max = valor;
	mov.d	$f20,$f22
	
#         std::cout << "\nNuevo maximo " << max;
	li	$v0,4
	la	$a0,cadNuevoMax
	syscall
	
	li	$v0,3
	mov.d	$f12,$f20
	syscall
	
#       }
if_find_max_fin:

#     }
	addi	$s5,$s5,1
	b	for_c_find_max
for_c_find_max_fin:

#   }
	addi	$s4,$s4,1
	b	for_f_find_max
for_f_find_max_fin:

#   return max;
	mov.d	$f0,$f20
	
	#POP:
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	lw	$s1,8($sp)
	lw	$s2,12($sp)
	lw	$s3,16($sp)
	lw	$s4,20($sp)
	lw	$s5,24($sp)
	l.d	$f20,32($sp)
	l.d	$f22,40($sp)
	addi $sp,$sp,48

# }
	jr	$ra
find_max__MARCAFIN:

# int leeFila(int numFilas) {
# Parámetros de entrada
# int numFilas		→ $a0 → $s0

# Esta función llama al syscall: Debe usar la pila
# Tabla de asignación de variables
# int indFil		→ $t0

leeFila:
	# PUSH
	addi 	$sp,$sp,-8
	sw	$ra,0($sp)
	sw	$s0,4($sp)
	
	move	$s0,$a0
	
#   int indFil;
#   std::cin >> indFil;
	li	$v0,5
	syscall
	move	$t0,$v0
	
#   if ((indFil < 0) || (indFil >= numFilas)) {
if_leeFila:
	bltz	$t0, if_leeFila_then		# $t0 = indFil < 0
	bge	$t0,$s0, if_leeFila_then	# $t1 = indFil >= numFilas
	b	if_leeFila_fin
	
if_leeFila_then:
#     std::cout << "Error: Numero de fila incorrecto\n";
	li	$v0,4
	la	$a0, cadErrorFila
	syscall

#     return -1;
	li	$v0,-1
	
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	addi 	$sp,$sp,8
	
	jr	$ra
#   }

if_leeFila_fin:
#   return indFil;
	move	$v0,$t0
# }
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	addi 	$sp,$sp,8
	
	jr	$ra

leeFila__MARCAFIN:

# int leeColumna(int numColumnas) {

leeColumna:
	addi 	$sp,$sp,-8
	sw	$ra,0($sp)
	sw	$s0,4($sp)
	
	move	$s0,$a0
#   int indCol;
#   std::cin >> indCol;
	li	$v0,5
	syscall
	move	$t0,$v0
	
#   if ((indCol < 0) || (indCol >= numColumnas)){
leeColumna_if:
	bltz	$t0, leeColumna_if_then		# $t0 = indCol < 0
	bge	$t0,$s0, leeColumna_if_then	# $t1 = indCol >= numColumnas
	b	leeColumna_if_fin

leeColumna_if_then:
#     std::cout << "Error: Numero de columna incorrecto\n";
	li	$v0,4
	la	$a0, cadErrorCol
	syscall
	
#     return -1;
	li	$v0,-1
	
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	addi 	$sp,$sp,8
	
	jr	$ra
#   }
leeColumna_if_fin:
#   return indCol;
	move	$v0,$t0
# }
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	addi 	$sp,$sp,8
	
	jr	$ra
	
leeColumna__MARCAFIN:

# std::tuple<int, int> pideFilaYColumna(structMat* mat) {
# Parámetros de entrada
# strucMat* mat		→ $a0 → $s0

# Esta función llama a otra: Debemos 
# Parámetros de salida
# int indFil		→ $s1
# int indCol		→ $s2

pideFilaYColumna:

	#PUSH
	addi	$sp,$sp,-16
	sw	$ra,0($sp)
	sw	$s0,4($sp)
	sw	$s1,8($sp)
	sw	$s2,12($sp)

	move	$s0,$a0

#   std::cout << "\nIndice de fila: ";
	li	$v0,4
	la	$a0, pideFila
	syscall
	
#   int indFil = leeFila(mat->nFil);
	lw	$a0,nFil($s0)	#$a0 = indFil
	jal	leeFila
	move	$s1,$v0

#   if (indFil < 0) {
	bltz	$s1,pideFilaYColumna_if_indFil
	j	pideFilaYColumna_if_indFil_fin
pideFilaYColumna_if_indFil:
#     return {-1, -1};
	li	$v0,-1
	li	$v1,-1
	
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	lw	$s1,8($sp)
	lw	$s2,12($sp)
	addi	$sp,$sp,16
	
	jr	$ra

#   }
pideFilaYColumna_if_indFil_fin:

#   std::cout << "Indice de columna: ";
	li	$v0,4
	la	$a0, pideCol
	syscall
	

#   int indCol = leeColumna(mat->nCol);
	lw	$a0,nCol($s0)	#$a0 = indFil
	jal	leeColumna
	move	$s2,$v0

#   if (indCol < 0) {
	bltz	$s2,pideFilaYColumna_if_indCol
	j	pideFilaYColumna_if_indCol_fin
pideFilaYColumna_if_indCol:


#     return {-1, -1};
	li	$v0,-1
	li	$v1,-1

	lw	$ra,0($sp)
	lw	$s0,4($sp)
	lw	$s1,8($sp)
	lw	$s2,12($sp)
	addi	$sp,$sp,16
	
	jr	$ra


#   }
pideFilaYColumna_if_indCol_fin:
#   return {indFil, indCol};
	move	$v0,$s1
	move	$v1,$s2

	lw	$ra,0($sp)
	lw	$s0,4($sp)
	lw	$s1,8($sp)
	lw	$s2,12($sp)
	addi	$sp,$sp,16
# }
	jr	$ra
pideFilaYColumna__MARCAFIN:


# int main() {
main:
# Tabla de asignación de variables
# structMat* matTrabajo	→ $s0
# int opcion 		→ $s1
# int indFil		→ $s2
# int indCol		→ $s3
# int indC1		→ $s4
# int indC2		→ $s5


#   std::cout << "\nComienza programa manejo matrices con funciones";
	li	$v0,4
	la	$a0,cadTitulo
	syscall

#   structMat* matTrabajo = matrices[0];
	la	$t0,matrices
	lw	$s0,0($t0)
	
#   int opcion;
#   do {
bucle_do:

#     print_mat(matTrabajo);
	move	$a0,$s0
	jal	print_mat
	
#     std::cout <<
#     "(0) Terminar el programa\n"
#     "(1) Cambiar la matriz de trabajo\n"
#     "(3) Cambiar el valor de un elemento\n"
#     "(4) Intercambiar un elemento con su opuesto\n"
#     "(5) Procesa columnas\n"
#     "(7) Encuentra maximo\n"
#     "\nIntroduce opción elegida: ";

	li	$v0,4
	la	$a0,cadMenu
	syscall

#     std::cin >> opcion;
	li	$v0,5
	syscall
	move	$s1,$v0

#     int indFil;
#     int indCol;
#     switch (opcion) {
switch:
	li	$t0,0
	li	$t1,1
	li	$t2,2
	li	$t3,3
	li	$t4,4
	li	$t5,5
	li	$t6,6
	li	$t7,7
	
	beq	$s1,$t0,switch_caso0
	beq	$s1,$t1,switch_caso1
	beq	$s1, $t3, switch_caso3
	beq	$s1, $t4, switch_caso4
	beq	$s1, $t5, switch_caso5
	beq	$s1, $t7, switch_caso7
	j	default
	
#       // Opción 0 //////////////////////////////////////////////////////////
#       case 0:
switch_caso0:
#         std::cout << "\nEligida opción de salir";
	li	$v0,4
	la	$a0,cadSalir
	syscall
	
#         break; // salimos del switch
	j	bucle_while_fin
	
#       // Opción 1 //////////////////////////////////////////////////////////
#       case 1:
switch_caso1:

#         std::cout << "\nElije la matriz de trabajo: ";
	li	$v0,4
	la	$a0,cadEligeMat
	syscall
	
#         int matT;	# int matT → $t0
#         std::cin >> matT;
	li	$v0,5
	syscall
	move	$t0,$v0

#         if ((matT < 0) || (matT >= NUM_MATRICES)) {
switch_caso1_if:
	li	$t1,NUM_MATRICES
	
	bltz	$t0,switch_caso1_if_then
	bge	$t0,$t1,switch_caso1_if_then
	j	switch_caso1_if_fin
switch_caso1_if_then:

#           std::cout << "Numero de matriz de trabajo incorrecto\n";
	li	$v0,4
	la	$a0,cadErrorMat
	syscall
	
#           break; // salimos del switch
	j	switch_fin

#         }
switch_caso1_if_fin:

#         matTrabajo = matrices[matT];


	la	$t1, matrices	# Dirección base de la matriz
	
	mul	$t0, $t0, tamP 	# D
	add	$t1, $t1,$t0
	
	lw	$s0, 0($t1)
	
#         break; // salimos del switch
	j	switch_fin

#       // Opción 3 //////////////////////////////////////////////////////////
#       case 3:
switch_caso3:

#         std::tie(indFil, indCol) = pideFilaYColumna(matTrabajo);
	move 	$a0,$s0
	jal	pideFilaYColumna
	move	$s2,$v0
	move	$s3,$v1

#         if (indFil < 0)
switch_caso3_if:
	bgez	$s2,switch_caso3_if_fin
#           break; // salimos del switch
	j	switch_fin
	
switch_caso3_if_fin:

#         std::cout << "Nuevo valor para el elemento: ";
	li	$v0,4
	la	$a0,cadNuevoValor
	syscall
	
#         std::cin >> valor;
	li	$v0,7
	syscall
	mov.d	$f12,$f0 # parametro de entrada

#         change_elto(matTrabajo, indFil, indCol, valor);
	move	$a0,$s0
	move	$a1,$s2
	move	$a2,$s3
	
	jal	change_elto

	j	switch_fin
#         break; // salimos del switch

#       // Opción 4 //////////////////////////////////////////////////////////
#       case 4:
switch_caso4:

#         std::tie(indFil, indCol) = pideFilaYColumna(matTrabajo);
	move 	$a0,$s0
	jal	pideFilaYColumna
	move	$s2,$v0
	move	$s3,$v1
	
#         if (indFil < 0)

switch_caso4_if:

	bgez	$s2,switch_caso4_if_fin

#           break; // salimos del switch
	j	switch_fin

switch_caso4_if_fin:

#         intercambia(matTrabajo, indFil, indCol);
	move	$a0,$s0
	move	$a1,$s2
	move	$a2,$s3
	
	jal	intercambia
	
#         break; // salimos del switch
	j	switch_fin


#       // Opción 5 //////////////////////////////////////////////////////////
#       case 5:
switch_caso5:

#         std::cout << "\nPrimera columna a procesar: ";
	li	$v0,4
	la	$a0,cadPrimCol
	syscall

#         int indC1;
#         indC1 = leeColumna(matTrabajo->nCol);
	lw	$a0,nCol($s0)
	jal	leeColumna
	move	$s4,$v0
	
#         if (indC1 < 0) {
switch_caso5_if_indC1:
	bgez	$s4,switch_caso5_if_indC1_fin
	
#           break; // salimos del switch
	j	switch_fin
#         }
switch_caso5_if_indC1_fin:

#         std::cout << "Segunda columna a procesar: ";
	li	$v0,4
	la	$a0,cadSegCol
	syscall

#         int indC2;
#         indC2 = leeColumna(matTrabajo->nCol);
	lw	$a0,nCol($s0)
	jal	leeColumna
	move	$s5,$v0

#         if (indC2 < 0) {
switch_caso5_if_indC2:
	bgez	$s5,switch_caso5_if_indC2_fin
	
#           break;  // salimos del switch
	j	switch_fin
	
#         }
switch_caso5_if_indC2_fin:

#         procesa_cols(matTrabajo, indC1, indC2);
	move	$a0,$s0
	move	$a1,$s4
	move	$a2,$s5
	jal	procesa_cols
	
#         break;  // salimos del switch
	j	switch_fin

#       // Opción 7 //////////////////////////////////////////////////////////
#       case 7:
switch_caso7:

#         double maximo;
#         maximo = find_max(matTrabajo);
	move	$a0,$s0
	jal	find_max
	
	mov.d	$f20,$f0
	
#         std::cout << "\nEl valor maximo en la matriz es " << maximo;
	li	$v0,4
	la	$a0,cadMax
	syscall
	
	li	$v0, 3
	mov.d	$f12, $f20
	syscall
#         break; // salimos del switch
	j	switch_fin

#       default:
default:
#         // Opción Incorrecta ////////////////////////////////////////////////
#         std::cout << "Error: opcion incorrecta\n";
	li	$v0,4
	la	$a0,cadErrorOpcion
	syscall
#     }  // fin del switch
switch_fin:

#     std::cout << "\nTerminada la opción " << opcion;
	li	$v0,4
	la	$a0,cadTerOpc
	syscall
	
	li	$v0, 1
	move	$a0, $s1
	syscall
	
#   } while (opcion != 0);
	bnez	$s1,bucle_do
	
bucle_while_fin:

#     std::cout << "\nTerminada la opción " << opcion;
	li	$v0,4
	la	$a0,cadTerOpc
	syscall
	
	li	$v0, 1
	move	$a0, $s1
	syscall

#   std::cout << "\n\nTermina el programa\n";
	li	$v0,4
	la	$a0,cadFin
	syscall

	
	li	$v0,10
	syscall
# }


