lb x11, 1025(x0)
addi x13, x0, 48
addi x19, x0, 1

beq x11, x13, l0
	l1:
		lb x11, 1025(x0)
		beq x11, x13, l10
		l11:
			add x12, x0, x0 #limpa
			sb x0, 1029(x0)
			sb x0, 1027(x0)
			beq x0, x0, end

		l10:
			lb x11, 1025(x0)
			lb x11, 1025(x0)
			beq x11, x13, l1000
			l1001:
				addi x12, x0, 39 #9
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
			
			l1000:
				addi x12, x0, 63 #8
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
				
l0:
	lb x11, 1025(x0)
	beq x11, x13, l00
	l01:
		lb x11, 1025(x0)
		beq x11, x13, l010
		l011:
			lb x11, 1025(x0)
			beq x11, x13, l0110
			l0111:
				addi x12, x0, 7 #7
				sb x12, 1029(x0)
				sb x0, 1027(x0)
				beq x0, x0, end
			l0110:
				addi x12, x0, 61 #6
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end

		l010:
			lb x11, 1025(x0)
			beq x11, x13, l0100
			l0101:
				addi x12, x0, 45 #5
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
			
			l0100:
				addi x12, x0, 38 #4
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
		
	l00:
		lb x11, 1025(x0)
		beq x11, x13, l000
		l001:
			lb x11, 1025(x0)
			beq x11, x13, l0010
			l0011:
				addi x12, x0, 15 #3
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
			l0010:
				addi x12, x0, 27 #2
				sb x12, 1029(x0)
				sb x19, 1027(x0)
				beq x0, x0, end
		l000:
			lb x11, 1025(x0)
			beq x11, x13, l0000
			l0001:
				addi x12, x0, 6 #1
				sb x12, 1029(x0)
				sb x0, 1027(x0)
				beq x0, x0, end
			l0000:
				addi x12, x0, 63 #0
				sb x12, 1029(x0)
				sb x0, 1027(x0)
				beq x0, x0, end
end:
	xor x11, x11, x11
