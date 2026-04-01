#include <iostream>
# 
#define N 10

	.data
strsalto:	.asciiz "\n"
vec:
		.word 7, 2, 6, 8, 1, 9, 10, 3, 4, 5
# Constante de tiempo de ensamblado
tamW = 4

	.text

 #int main() {
 main:
 #  int vect[N] = {7, 2, 6, 8, 1, 9, 10, 3, 4, 5};
	la	$s1,vec

 #  int indice = 3;
	li	$s5,3
	
	# $t2 = desplazamiento = indice * tamaño de dato
	mul	$t2,$s5,tamW
	add	$t2, $t2, $s1

 #  int valor = vect[indice];
	lw	$s0,0($t2)
 
 #  std::cout << valor << "\n";
 	li	$v0,1
 	move	$a0, $s0
 	syscall
 	
 	li	$v0,4
 	la	$a0,strsalto
 	syscall
 
 #  valor = vect[6];

	lw	$s0,24($s1)

 #  std::cout << valor << "\n";
 	li	$v0,1
 	move	$a0, $s0
 	syscall
 	
 	li	$v0,4
 	la	$a0,strsalto
 	syscall
 	
 	li	$v0,10
 	syscall
#}

