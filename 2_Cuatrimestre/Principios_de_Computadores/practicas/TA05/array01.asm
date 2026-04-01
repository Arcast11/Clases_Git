#include <iostream>

#define N 10

	.data 
strval:	.asciiz "Extraemos el indice 0 \n"
vec:
	.word	3, 9, 5, 7

	.text
	
############# Tabla de asignación de variables ###########
# 	indice → $s0
	
#int main() {
main:

#  int vect[N] = {7, 2, 6, 8, 1, 9, 10, 3, 4, 5};
	la	$t0,vec
	
#  int indice = 3;  
#  vect[indice] = 0;
	lw	$s1,0($t0)
	
	li	$v0,4
	la	$a0,strval
	syscall

	li	$v0,1
	move	$a0,$s1
	syscall
	
	li	$v0,10
	syscall
	
#} 
