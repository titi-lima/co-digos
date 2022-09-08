org 0x7e00
jmp 0x0000:start

data:
	; Strings menu
	title db 'febre do penalti', 0
    jogarMenu db '[1] Jogar', 0
    tab times 9 db 0
    board db " 1      |2      |3      ",10,13,"        |       |       ",10,13,"        |       |       ",10,13," -------+-------+-------",10,13, " 4      |5      |6      ",10,13,"        |       |       ",10,13,"        |       |       ",10,13," -------+-------+-------",10,13," 7      |8      |9      ",10,13, "        |       |       ",10,13,"        |       |       ",10,13,0

    tutorialMenu db '[2] Comandos', 0
        tutorialStr0 db 'Aguarde sua vez e escolha', 0
        tutorialStr1 db 'uma das casinhas para jogar', 0
        tutorialStr2 db 'CONTROLES', 0
        tutorialStr3 db '1    2    3', 0
        tutorialStr4 db '4    5    6', 0
        tutorialStr5 db '7    8    9', 0

    sairMenu db '[3] Sair', 0
        telaSair db 'vlw flw', 0

    creditos db 'Grupo: alvmbv, tmsl, cvmfc 2022', 0
    DEBUGADOR_MAXIMO db 'HSGAHGDHJAGSHJDGHJSAGDGASJDGJASGDHJGASJHDGJHGJHASGJHDGASJHGDJHSAGJDHAGSJHDGJ',0

printOne:
    mov byte[board+30], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printTwo:
    mov byte[board+38], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printThree:
    mov byte[board+46], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printFour:
    mov byte[board+134], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printFive:
    mov byte[board+142], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printSix:
    mov byte[board+150], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printSeven:
    mov byte[board+238], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printEight:
    mov byte[board+246], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret
printNine:
    mov byte[board+254], ah
    mov si, board
    mov bl, 0xf
    call _printString
ret

%macro over 1
    call clear_screen
    mov al, %1
    call putchar
    jmp fim
%endmacro

pls:
    ret

xOne:
    mov dl, byte[tab]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+1]
    jne pls
    cmp dl, byte[tab+2]
    jne pls
    over byte[tab]
    jmp fim

xTwo:
    mov dl, byte[tab+3]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+4]
    jne pls
    cmp dl, byte[tab+5]
    jne pls
    over byte[tab+3]
    jmp fim

xThree:
    mov dl, byte[tab+6]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+7]
    jne pls
    cmp dl, byte[tab+8]
    jne pls
    over byte[tab+6]
    jmp fim

yOne:
    mov dl, byte[tab]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+3]
    jne pls
    cmp dl, byte[tab+6]
    jne pls
    over byte[tab]
    jmp fim

yTwo:
    mov dl, byte[tab+1]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+4]
    jne pls
    cmp dl, byte[tab+7]
    jne pls
    over byte[tab+1]
    jmp fim

yThree:
    mov dl, byte[tab+2]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+5]
    jne pls
    cmp dl, byte[tab+8]
    jne pls
    over byte[tab+2]
    jmp fim

LRDiagonal:
    mov dl, byte[tab]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+4]
    jne pls
    cmp dl, byte[tab+8]
    jne pls
    over byte[tab]
    jmp fim

RLDiagonal:
    mov dl, byte[tab+2]
    cmp dl, 0
    jz pls
    cmp dl, byte[tab+4]
    jne pls
    cmp dl, byte[tab+6]
    jne pls
    over byte[tab+2]
    jmp fim

isOver:
    call xOne
    call xTwo
    call xThree
    call yOne
    call yTwo
    call yThree
    call LRDiagonal
    call RLDiagonal
ret

successfulKey:
    mov byte[tab+bx-1-'0'], ah
    cmp al, '1'
    je printOne
    cmp al, '2'
    je printTwo
    cmp al, '3'
    je printThree
    cmp al, '4'
    je printFour
    cmp al, '5'
    je printFive
    cmp al, '6'
    je printSix
    cmp al, '7'
    je printSeven
    cmp al, '8'
    je printEight
    cmp al, '9'
    je printNine
    
getNumber:
    cmp byte[tab+bx-1-'0'], 0  ;compara al direto e ve se eh valido msm (=se n tem ngm na posicao)
    je successfulKey
    cmp ah, 'O'
    je cpuTurn
    jmp playerTurn
ret
    ;cmp bl, 'O'; checa se era a cpu jogando
    ;je cpuTurn; se era a cpu jogando e ela jogou errado, vai pra a funcao dela dnv
    ;jmp playerTurn ;caso um caracter invalido seja passado, ele volta e pega outro.


start:
    xor ax, ax
    mov ds, ax
    mov es, ax

; Modo de vídeo
    mov ah, 00h
    mov al, 13h
    int 10h
    jmp print_menu

clear_screen:
    mov ah, 00h
    mov al, 13h
    int 10h
    ret

prints:
    mov bh, 00h
    mov cx, 01h
    mov ah, 02h
    int 10h
    .loop:
        lodsb
        cmp al, 0
        je .endloop
        mov ah, 09h ; printar o caractere
        mov bl, 15  ; cor: branco
        int 10h

        mov ah, 02h ; move o Cursor
        inc dl
        int 10h

        jmp .loop
    .endloop:
    ret

print_menu:
    call clear_screen

    mov dx, 050Ch
    mov si, title
    call prints

    mov dx, 0C0Fh
    mov si, jogarMenu
    call prints

    mov dx, 0E0Dh
    mov si, tutorialMenu
    call prints

    mov dx, 100Fh
    mov si, sairMenu
    call prints

    mov dx, 1605h
    mov si, creditos
    call prints

    jmp input_menu

input_menu:
    mov ah, 0 ; espera receber caractere
    int 16h

    cmp ah, 02h ; 1
    je select_1_menu

    cmp ah, 03h ; 2
    je select_2_menu

    cmp ah, 04h ; 3
    je select_3_menu

    jmp input_menu

select_1_menu:
    call clear_screen
    jmp print_board

select_2_menu:
    call clear_screen
    jmp print_tutorial

select_3_menu:
    jmp end


print_board:
    mov si, board
    call _printString
    jmp game

getchar:
    mov ah, 0x00 ; parâmetro de interrupção
    int 16h ; interrupção de teclado
    cmp al, '1' ; registrigindo input a 1-9
    jl getchar
    cmp al, '9'
    jg getchar
ret


cpuTurn:
    mov ah, 00h  ; interrupts to get system time        
    int 1ah      ; CX:DX now hold number of clock ticks since midnight      

    mov ax, dx
    xor dx, dx
    mov cx, 10    
    div cx       ; here dx contains the remainder of the division - from 0 to 9
    cmp dl, 0
    je cpuTurn
    add dl,'0'  ; to ascii from '0' to '9'
    mov al, dl

    mov ah, 'O'
    ;call clear_screen
    movzx bx, al
    call getNumber
ret

playerTurn:
    call getchar
    mov ah, 'X'
    movzx bx, al
    call getNumber
ret

game:
    call playerTurn
    call isOver
    call cpuTurn
    call isOver
    jmp game;o jogo ainda nao acabou!

print_tutorial:

    mov dx, 0108h
    mov si, tutorialStr0
    call prints

    mov dx, 0307h
    mov si, tutorialStr1
    call prints

    mov dx, 0A0Fh
    mov si, tutorialStr2
    call prints

    mov dx, 0D0Eh
    mov si, tutorialStr3
    call prints

    mov dx, 0F0Eh
    mov si, tutorialStr4
    call prints
    
    mov dx, 110Eh
    mov si, tutorialStr5
    call prints
    
    mov ah, 0
    int 16h

    ; retorna para o menu com as seguintes teclas
    cmp ah, 01h ; esc
    je print_menu

    cmp ah, 1ch ; enter
    je print_menu

    cmp ah, 39h ; spacebar
    je print_menu

    jmp print_tutorial
end:
    call clear_screen

    mov dx, 0C11h
    mov si, telaSair
    call prints

    add sp, 26 ; Desalocar os valores iniciais
    jmp fim

_printString:
    mov al, 13h
    mov ah, 0
    int 10h
    .loop:
        mov al, [si]
        inc si
        cmp al, 0
        je .endloop
        call putchar
        jmp .loop
    .endloop:
ret

putchar:
    mov ah, 0x0e ;parâmetro de interrupção
    int 10h ; interrupção de vídeo
ret

fim:
    jmp $

dw 0xaa55 ;talvez desnecessario