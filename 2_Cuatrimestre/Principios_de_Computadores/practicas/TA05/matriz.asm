
tamD = 8
## define NumFil
NumFil = 3
## define NumCol
NumCol = 4

	.data
	# double mat[NumFil][NumCol] = {
	# {  1.5,  2.9,  1.8, -3.3 }
	# { -1.4, 0.12,  3.7,  8.1 }
	# { 0.25, 90.2, -2.77, 1.1 }
	# };
mat:	.double 1.5,  2.9,  1.8, -3.3
	.double -1.4, 0.12,  3.7,  8.1
	.double 0.25, 90.2, -2.77, 1.1
	
.text

######################
# Relación de variables a registros
# f 	→ $s0
# c 	→ $s1
# elem 	→ $f22

#	int main () {

main: 	
	#for(int f = 0; f < Numfil; f++){
	li $s0, 0
for_f:
	bge	$s0,NumCol,for_f_fin
	#	for(int c = 0; c < NumCol; c++){
	li	$s1, 0 
for c:
	bge	$s1, NumCol, for_c_fin
	#t0 = direccion de mat [t] [c]
	la	$t1, mat 	# t1 = dirección base mat
	mul	$t0, $s0, NumCo
	add	$t0, $t0, $s1
	mul 	$t0, $t0, tamD
	add	$t0,$t1, $t0
	
	#	double elem = mat[f][c];
	l.d	$f22, 0($t0)
	
	#	elem = elem * 2.0;
	li.d	$f16, 2.0
	mul.d	$f22, $f22, $f16
	
	#	mat[f][c] = elem;
	s.d	$f22, 0($t0)
	#	}
	
	addi	$s1,1
	b	for_c

for_c_fin:

	addi	$s0,1
	b	for_f
	
for_f_fin:

	li	$v0,10
	syscall
	
	
	
	
	
	
	
	
	
