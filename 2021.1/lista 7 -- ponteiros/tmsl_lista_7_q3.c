#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    float nota;
    char curso[20];
} Aluno;

int main() {
    Aluno aluno;
    aluno.matricula = 45687;
    aluno.nota = 9.0;
    strcpy(aluno.curso, "Engenharia eletrica");

    Aluno *pAluno = &aluno;
    printf("%d\n", (*pAluno).matricula);
    printf("%f\n", (*pAluno).nota);
    printf("%s\n", (*pAluno).curso);

    return 0;
}