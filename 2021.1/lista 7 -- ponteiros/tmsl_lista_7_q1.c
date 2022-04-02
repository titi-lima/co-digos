#include <stdio.h>
int main() {
    char c = 'a';
    char *pc = &c;
    printf("a) Ponteiro de c: %p; valor guardado por ele: %c.\n", &c, c);
    printf("b) Valor de pc: %p; valor guardado no endereco apontado: %c.\n", pc, *pc);
    printf("c) Endereco de pc: %p.\n", &pc);
    printf("d) Endereco do valor guardado no endereco apontado por pc: %p;\n   Valor guardado no endereco de pc: %p.\n", &*pc, *&pc);
    printf("e) &*pc se refere ao endereco do valor, enquanto *&pc se refere ao valor do endereco. como ambos se referem a(crase) mesma variavel, o valor imprimido eh o mesmo.");

    return 0;
}