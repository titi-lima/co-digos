while1:
	lh x10, 1031(x0) #temperatura em A0
	addi x13, x0, 204
	blt x10, x13, LRed
	addi x13, x0, 306
	blt x10, x13, LYellow
	addi x13, x0, 408
	blt x10, x13, RYellow
	addi x13, x0, 510
	blt x10, x13, LGreen
	addi x13, x0, 612
	blt x10, x13, RGreen
	beq x0, x0, RRed

LRed:
	addi x12, x0, 3
	beq x11, x12, turnOnLR #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnLR:
		addi x11, x0, 3
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	
	
LYellow:
	addi x12, x0, 6
	beq x11, x12, turnOnLY #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnLY:
		addi x11, x0, 6
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	

RYellow:
	addi x12, x0, 9
	beq x11, x12, turnOnRY #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnRY:
		addi x11, x0, 9
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	

LGreen:
	addi x12, x0, 10
	beq x11, x12, turnOnLG #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnLG:
		addi x11, x0, 10
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	

RGreen:
	addi x12, x0, 11
	beq x11, x12, turnOnRG #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnRG:
		addi x11, x0, 11
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	

RRed:
	addi x12, x0, 5
	beq x11, x12, turnOnRR #as duas linhas seguintes apagam o led anterior
	addi x12, x0, -1000
	sb x12, 1034(x0) #apaga o led anterior
	turnOnRR:
		addi x11, x0, 5
		sb x11, 1033(x0) #guarda a porta do led
		addi x12, x0, 1000
		sb x12, 1034(x0) #acende o led
		beq x0, x0, while1	


