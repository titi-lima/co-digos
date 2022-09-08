org 0x7c00
jmp 0x0000:main

main:
   jmp $ 

times 510 - ($-$$) db 0
dw 0xaa55