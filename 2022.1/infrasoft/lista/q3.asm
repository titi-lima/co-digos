org 0x7c00
jmp 0x0000:main

data:
    color times 13 db 0

    blue db 'azul', 0
    green db 'verde', 0
    red db 'vermelho', 0
    yellow db 'amarelo', 0
    else db 'nao existe', 0

%macro checkColor 2
    mov di, color
    mov si, %2
    call _strcmp
    mov si, %2
    mov bl, %1
    je _printString
%endmacro

main:
    xor ax, ax
    xor bx, bx
    xor cx, cx
    mov ds, ax
    mov es, ax

    mov al, 13h
    mov ah, 0
    int 10h

    mov di, color
    call gets

    checkColor 1, blue
    checkColor 10, green
    checkColor 4, red
    checkColor 14, yellow

    mov bl, 5
    mov si, else
    call _printString

putchar:
    mov ah, 0x0e ;parâmetro de interrupção
    int 10h ; interrupção de vídeo
ret

getchar:
    mov ah, 0x00 ; parâmetro de interrupção
    int 16h ; interrupção de teclado
ret

delchar:
    mov al, 0x08
    call putchar

    mov al,''
    call putchar

    mov al, 0x08
    call putchar
ret


gets: ; ler string
    xor cx, cx

    .loop1:
        call getchar
        cmp al, 0x08 ;0x08==backspace
        je .backspace
        cmp al, 0x0d
        je .done
        cmp cl, 50
        je .loop1
        stosb
        inc cl
        mov bh, 0
        mov bl, 15
        call putchar
        jmp .loop1

        .backspace:
            cmp cl, 0
            je .loop1
            dec di
            dec cl
            mov byte[di], 0
            call delchar
            jmp .loop1
    .done:
        mov al, 0
        stosb
        mov al, 0x0a
        call putchar
        mov al, 0x0d
        call putchar
ret

_strcmp:
    .loop1:
        lodsb
        cmp byte[di], 0
        jne .continue
        cmp al, 0
        jne .done
        stc
        jmp .done
        
        .continue:
            cmp al, byte[di]
                jne .done
            clc
                inc di
                jmp .loop1

        .done:
            mov edi, blue
            ret

_printString:
    mov al, 13h
    mov ah, 0
    int 10h
    .loop:
        mov al, [si]
        inc si
        sub al, 32
        cmp al, -32
        je .endloop
        call putchar
        jmp .loop
    .endloop:
        add al, 32
        jmp end
ret

end:
    jmp $

times 510 - ($-$$) db 0
dw 0xaa55