# // Principio de Computadores.
# // Operaciones con funciones y direccionamiento indirecto
# // Autores: Carlos Martín Galán y Alberto Hamilton Castro
# // Fecha última modificación: 2025-04-11
# #include <iostream>

# const int n1 = 10;
# double v1[n1] = {10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0};
# const int n2 = 5;
# double v2[n2] = {5.5, 4.5, 4.25, 2.5, 2.5 };
# const int n3 = 4;
# double v3[n3] = {7.0, 5.0, 2.0, 1.0};


# void printvec(double* v, const int n) {
#     std::cout << "\nVector con dimension " << n << '\n';
#     for (int i = 0; i < n; i++)
#         std::cout << v[i] << " ";

#     std::cout << "\n";
#     return;
# }

# int ordenado(double* v, const int n) {
#     int resultado = 1;
#     int i = 0;
#     while (i < n-1) {
#         if (v[i+1] >= v[i]) {
#             resultado = 0;
#             break;
#         }
#         i++;
#     }
#     return resultado;
# }

# void merge(double* v1, const int n1,double* v2, const int n2) {

#     int  o1 = ordenado(v1,n1);
#     if (o1 == 0) {
#       std::cout << "Primer vector no ordenado. NO se puede mezclar\n";
#       return;
#     }
#     int o2 = ordenado(v2,n2);
#     if (o2 == 0) {
#       std::cout << "Segundo vector no ordenado. NO se puede mezclar\n";
#       return;
#     }
#     int i = 0; // índice para recorrer el v1
#     int j = 0; // índice para recorrer el v2
#     while ( ( i < n1) && (j < n2) ) {
#         if (v1[i] >= v2[j]) {
#             std::cout << v1[i] << ' ';
#             i++;
#         }
#         else {
#             std::cout << v2[j] << ' ';
#             j++;
#         }
#     }
#     while ( i < n1) {
#         std::cout << v1[i] << ' ';
#         i++;
#     }
#     while ( j < n2) {
#         std::cout << v2[j] << ' ';
#         j++;
#     }
#     std::cout << '\n';
#     return;
# }

# int main(void) {
#   std::cout << "\nPrograma de mezcla de vectores\n";

#   printvec(v1,n1);
#   printvec(v2,n2);
#   printvec(v3,n3);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v1,n1,v2,n2);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v1,n1,v3,n3);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v2,n2,v3,n3);

#   std::cout << "\nFIN DEL PROGRAMA\n";
#   return 0;
# }

sizeD = 8

    .data
n1:     .word 10
v1:     .double 10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0
n2:     .word 5
v2:     .double 5.5, 4.5, 4.25, 2.5, 2.5
n3:     .word 4
v3:     .double 7.0, 5.0, 2.0, 1.0

cad0:	.asciiz	"\nPrograma de mezcla de vectores\n"
cad1:   .asciiz "\nVector con dimension "
cad51:	.asciiz	"Primer vector no ordenado. NO se puede mezclar\n"
cad52:	.asciiz	"Segundo vector no ordenado. NO se puede mezclar\n"
cad2:   .asciiz "\nIntentando mezcla con dos vectores ...\n"
cad3:   .asciiz "\nFIN DEL PROGRAMA\n"


	.text

# void printvec(double* v, const int n) {
##### Párametros de entrada ########
# double* v	→ $a0 → $s0
# const int n	→ $a0 → $s1

# La estafunción usa el syscall: SE NECESITA USAR LA PILA
#### Parámetros de salida ####
# NO APLICA
### Asignación de registros ###
# int i		→ $s2
# 

printvec:

	# push	
	addi	$sp,$sp, -16
	sw	$ra,0($sp)
	sw	$s0,4($sp)
	sw	$s1,8($sp)
	sw	$s2,12($sp)

	move	$s0,$a0
	move	$s1,$a1
	
#     std::cout << "\nVector con dimension " << n << '\n';
	li	$v0,4
	la 	$a0,cad1
	syscall
	
	li	$v0,1
	move	$a0,$s1
	syscall
	
	li	$v0,11
	li	$a0, '\n'
	syscall
	
#     for (int i = 0; i < n; i++)
	move 	$s2,$zero

printvec_for:
	bge	$s2,$s1, printvec_for_fin
	
	## $f12 = v[i]
	mul	$t0,$s2,sizeD
	add	$t1,$t0,$s0
	
	l.d	$f12,0($t1)
	
#         std::cout << v[i] << " ";
	li	$v0,3
	syscall
	
	li	$v0,11
	li 	$a0,' '
	syscall

	addi	$s2,$s2,1
	b	printvec_for
printvec_for_fin:

#     std::cout << "\n";
	li	$v0,11
	li	$a0, '\n'
	syscall

#     return;
	# POP
	lw	$ra,0($sp)
	lw	$s0,4($sp)
	lw	$s1,8($sp)
	lw	$s2,12($sp)
	addi	$sp,$sp, 16
	
	jr	$ra
# }
printvec__MARCAFIN:

##############################################################################################

# int ordenado(double* v, const int n) {
##### Párametros de entrada ########
# double* v		→ $a0
# const int n		→ $a1

# La estafunción no llama a otra: NO SE USA LA PILA
#### Parámetros de salida ####
# int resultado		→ $t0 → $v0

### Tabla de asignación de registros ###
# int i			→ $t1

ordenado:

#     int resultado = 1;
	li	$t0,1
#     int i = 0;
	move	$t1, $zero
	
#     while (i < n-1) {
	addi	$t2,$a1,-1	# $t2 = n-1
	
ordenado_while:
	
	bge	$t1,$t2,ordenado_while_fin
	
#         if (v[i+1] >= v[i]) {
ordenado_if:
	addi 	$t4,$t1,1

	mul	$t3,$t4,sizeD
	add	$t3,$t3,$a0
	
	l.d	$f4,0($t3)
	
	mul	$t5,$t1,sizeD
	add	$t5,$t5,$a0
	
	l.d	$f6,0($t5)
	
	c.lt.d	$f4,$f6
	bc1t	ordenado_if_fin

#             resultado = 0;
	move	$t0, $zero
	
#             break;
	b	ordenado_while_fin
#         }

ordenado_if_fin:

#         i++;
	addi 	$t1,$t1,1
	b	ordenado_while
	
#     }
ordenado_while_fin:

#     return resultado;
	move	$v0,$t0
	jr	$ra
# }
ordenado__MARCAFIN:

####################################################################################

# void merge(double* v1, const int n1,double* v2, const int n2) {
##### Párametros de entrada ########
# double* v1	→ $a0 → $s0
# const int n1	→ $a1 → $s1
# double* v2	→ $a2 → $s2
# const int n2	→ $a3 → $s3

# La estafunción llama a otra: DEBE USAR LA PILA

#### Parámetros de salida ####
# NO APLICA

### Tabla de asignación de registros ###
# int o1	→ $t0
# int o2	→ $t1
# int i		→ $s4
# int j	→	→ $s5

merge:
	
	# PUSH
	addi	$sp, $sp, -24
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	sw	$s5, 24($sp)
	
	move	$s0, $a0
	move	$s1, $a1
	move	$s2, $a2
	move	$s3, $a3

#     int  o1 = ordenado(v1,n1);

	jal	ordenado
	move	$t0,$v0

#     if (o1 == 0) {
merge_if_o1:
	bnez	$t0, merge_if_o1_fin
	
#       std::cout << "Primer vector no ordenado. NO se puede mezclar\n";
	li	$v0,4
	la	$a0,cad51
	syscall
	
#       return;
	b	return
#     }
merge_if_o1_fin:

#     int o2 = ordenado(v2,n2);
	move	$a0,$s2
	move	$a1,$s3
	jal	ordenado
	move	$t1,$v0
	
#     if (o2 == 0) {
	bnez	$t1, merge_if_o2_fin
	
#       std::cout << "Segundo vector no ordenado. NO se puede mezclar\n";
	li	$v0,4
	la	$a0,cad52
	syscall
	
#       return;
	b	return
#     }
merge_if_o2_fin:

#     int i = 0; // índice para recorrer el v1
	move	$s4,$zero
#     int j = 0; // índice para recorrer el v2
	move	$s5,$zero

#     while ( ( i < n1) && (j < n2) ) {
merge_while_ij_lt_n1n2:
	bge	$t0,$s4,$s1, merge_while_ij_lt_n1n2_fin
	bge	$t1,$s5,$s3, merge_while_ij_lt_n1n2_fin
	
	
#         if (v1[i] >= v2[j]) {
merge_if_v1_v2:
	mul	$t2,$s4,sizeD
	add	$t2,$t2,$s0
	l.d 	$f4,0($t2)
	
	mul	$t3,$s5,sizeD
	add	$t3,$t3,$s2
	l.d	$f6,0($t3)
	
	c.lt.d	$f4,$f6
	bc1t	merge_if_v1_v2_else

#             std::cout << v1[i] << ' ';
	li	$v0,3
	mov.d	$f12,$f4
	syscall
	
#             i++;
	addi $s4,$s4,1
	b	merge_if_v1_v2_fin
#         }
#         else {
merge_if_v1_v2_else:
#             std::cout << v2[j] << ' ';
	li	$v0,3
	mov.d	$f12,$f6
	syscall
	
#             j++;
	addi $s5,$s5,1
#         }

merge_if_v1_v2_fin:

#     }
	b	merge_while_ij_lt_n1n2

merge_while_ij_lt_n1n2_fin:

#     while ( i < n1) {
merge_while_i:
	bge	$s4,$s1,merge_while_i_fin

	mul	$t3,$s4,sizeD
	add	$t3,$t3,$s0

#         std::cout << v1[i] << ' ';
	l.d	$f12,0($t3)
	li	$v0,3
	syscall
	
	li	$v0,11
	li	$a0, ' '
	syscall

#         i++;
	addi	$s4,$s4,1
#     }
	b	merge_while_i

merge_while_i_fin:

#     while ( j < n2) {
merge_while_j:
	bge	$s5,$s3,merge_while_j_fin

	mul	$t4,$s5,sizeD
	add	$t4,$t4,$s2

#         std::cout << v2[j] << ' ';
	l.d	$f12,0($t4)
	li	$v0,3
	syscall
	
	li	$v0,11
	li	$a0, ' '
	syscall

#         j++;
	addi	$s5,$s5,1
#     }
	j	merge_while_j

merge_while_j_fin:

#     std::cout << '\n';
	li	$v0,11
	li	$a0, '\n'
	syscall

#     return;
return:
	#POP

	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	lw	$s4, 20($sp)
	lw	$s5, 24($sp)
	addi	$sp, $sp, 24
	
	jr	$ra
# }
merge__MARCAFIN:

# int main(void) {
#   std::cout << "\nPrograma de mezcla de vectores\n";

#   printvec(v1,n1);
#   printvec(v2,n2);
#   printvec(v3,n3);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v1,n1,v2,n2);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v1,n1,v3,n3);

#   std::cout << "\nIntentando mezcla con dos vectores ...\n";
#   merge(v2,n2,v3,n3);

#   std::cout << "\nFIN DEL PROGRAMA\n";
#   return 0;
# }
