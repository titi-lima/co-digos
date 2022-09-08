addi x4, x4, 7
addi x5, x5, 1
addi x22, x0, 48
#x12 eh o que recebe o produto da mult de cada algarismo. x14 eh o que fica fixo pra somar. x18 eh o multiplicador
loop:
	addi x3, x3, 1
	beq x3, x4, out #se ler 6 pula fora
	lb x10, 1025(x0) #le do teclado
	beq x10, x0, out #se acabar o numero
	beq x0, x0, ctoi #pega a letra e opera
	jal x11, loop

preventZero:
	addi x13, x13, 1
	beq x0, x0, loop

ctoi:
	beq x10, x22, preventZero
	add x18, x0, x10 #copia o numero (ascii)
	addi x18, x18, -48 #ctoi de fato
	add x14, x0, x18
	addi x18, x18, -1 #a multiplicacao comeca por N-1
	add x12, x14, x0
	beq x0, x0, fact

fact:
	addi x17, x17, 10 #debug
	addi x6, x0, 1 #contador do loop de multiplicacao
	bge x5, x18, adFact #se x18 <= 2, retorna
	beq x0, x0, mult #talvez n precise
	mult:
		addi x17, x17, 1 #debug
		addi x6, x6, 1 
		add x12, x12, x14 #x14 eh constante e igual a x12 inicialmente
		bne x6, x18, mult #x18 eh o multiplicador
	addi x18, x18, -1
	add x14, x12, x0
	beq x0, x0, fact
		
	
adFact:
	add x13, x13, x12 #resposta em x13
	beq x0, x0, loop 

out: 
	lw x19, _1000000

	bge x13, x19, f1m
	lw x19, _100000

	bge x13, x19, f100k
	lw x19, _10000

	bge x13, x19, f10k
	lw x19, _1000

	bge x13, x19, f1k
	lw x19, _100

	bge x13, x19, f100
	lw x19, _10

	bge x13, x19, f10
	addi x19, x19, -9

	bge x13, x19, f1

f1m:
	xor x6, x6, x6
	loop1m:
		addi x6, x6, 1
		sub x13, x13, x19 #x13-1000000
		bge x13, x19, loop1m
		addi x6, x6, 48
		sb x6, 1024(x0) #printa o caracter
		lw x19, _100000
		beq x0, x0, f100k

f100k:
	xor x6, x6, x6
	blt x13, x19, printa100k
	loop100k:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop100k
		printa100k:
			addi x6, x6, 48
			sb x6, 1024(x0)
			lw x19, _10000
			beq x0, x0, f10k

f10k:
	xor x6, x6, x6
	blt x13, x19, printa10k
	loop10k:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop10k
		printa10k:
			addi x6, x6, 48
			sb x6, 1024(x0)
			lw x19, _1000
			beq x0, x0, f1k

f1k:
	xor x6, x6, x6
	blt x13, x19, printa1k
	loop1k:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop1k
		printa1k:
			addi x6, x6, 48
			sb x6, 1024(x0)
			lw x19, _100
			beq x0, x0, f100

f100:
	xor x6, x6, x6
	blt x13, x19, printa100
	loop100:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop100
		printa100:
			addi x6, x6, 48
			sb x6, 1024(x0)
			lw x19, _10
			beq x0, x0, f10

f10:
	xor x6, x6, x6
	blt x13, x19, printa10
	loop10:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop10
		printa10:
			addi x6, x6, 48
			sb x6, 1024(x0)
			addi x19, x0, 1
			beq x0, x0, f1

f1:
	xor x6, x6, x6
	blt x13, x19, printa1
	loop1:
		addi x6, x6, 1
		sub x13, x13, x19
		bge x13, x19, loop1
		printa1:
			addi x6, x6, 48
			sb x6, 1024(x0)


_1000000: .word 1000000 #foi necessario pq por algum motivo um comando addi reg, reg, >1000 nao roda corretamente
_100000: .word 100000
_10000: .word 10000
_1000: .word 1000
_100: .word 100
_10: .word 10
