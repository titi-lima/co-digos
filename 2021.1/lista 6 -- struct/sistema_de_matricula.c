#include <stdio.h>
#include <string.h>

typedef struct {
    char id[31];
    char nome[501];
    int idade;
    int sexo;
    float nota;
} aluno[10];

typedef struct {
    char id[26];
    char nome[101];
    char aluno[10][501];
    int nalunos;
} curso[10];

int main() {
    int k, aux, aux2=0, aux3=0, flag=0, aux4, aux2m1, qtdmasc=0, qtdfem=0, qtd7=0;
    float media=0, media7=0;
    char idaluno[31], idcurso[26], auxaluno[501];
    aluno aluno;
    curso curso;
    scanf("%d", &aux);
    for(k=0; k<aux; ++k) {
        scanf(" %31[^\n]", aluno[k].id);
        scanf(" %501[^\n]", aluno[k].nome);
        scanf("%d", &aluno[k].idade);
        scanf("%d", &aluno[k].sexo);
        if(aluno[k].sexo == 0) {
            qtdfem++;
        }
        else qtdmasc++;
        scanf("%f", &aluno[k].nota);
        media+=aluno[k].idade;
        if(aluno[k].nota > 7.5) {
            ++qtd7;
            media7+=aluno[k].idade;
        }
    }
    media/=aux;
    scanf("%d", &aux);
    for(k=0; k<aux; ++k) {
        scanf(" %26[^\n]", curso[k].id);
        scanf(" %101[^\n]", curso[k].nome);
        curso[k].nalunos=0;
    } // aux indica o numero de cursos
    for(k=0; k<aux; ++k) { // cada k eh um curso diferente
        for(aux2=k+1; aux2<aux; ++aux2) {
            if(strcmp(curso[k].nome, curso[aux2].nome)>0) {
                strcpy(auxaluno, curso[k].id);
                strcpy(curso[k].id, curso[aux2].id);
                strcpy(curso[aux2].id, auxaluno);
                strcpy(auxaluno, curso[k].nome);
                strcpy(curso[k].nome, curso[aux2].nome);
                strcpy(curso[aux2].nome, auxaluno);
            }
        }
    }
    //blz ordenei os cursos
    aux2=0;
    scanf("%d", &aux4);
    for(k=0; k<aux4; ++k) {
        scanf(" %s %s", idaluno, idcurso);
        while(flag != 1) {
            if(strcmp(idaluno, aluno[aux2].id) == 0) {
                //printf("1: %s\n", aluno[aux2].nome);
                while(strcmp(idcurso, curso[aux3].id) != 0) {
                    ++aux3;
                }
                //printf("1: %s -> %s\n", aluno[aux2].id, curso[aux3].id);
                strcpy(curso[aux3].aluno[curso[aux3].nalunos], aluno[aux2].nome); // nesse ponto, aux2 representa o aluno referido e aux3 representa o curso referido.
                curso[aux3].nalunos++;
                flag=1; 
            }
            ++aux2;
        }
        aux2=0;
        aux3=0;
        flag=0;
        idaluno[0] = '\0';
        idcurso[0] = '\0';
    }
    /*for(k=0; k<aux; ++k) { // cada for eh um curso diferente
        for(aux2=0; aux2<curso[k].nalunos; ++aux2) {
            printf("Curso %s:\n", curso[k].nome);
            printf("%s\n", curso[k].aluno[aux2]);
        }
    }*/
    //se tudo deu certo, nesse ponto, o nome de cada aluno deve estar no seu correspondente curso
    for(k=0; k<aux; ++k) { // cada for eh um curso diferente
        for(aux2=0; aux2<curso[k].nalunos; ++aux2) {
            for(aux2m1=aux2+1; aux2m1<curso[k].nalunos; ++aux2m1) {
                if(strcmp(curso[k].aluno[aux2], curso[k].aluno[aux2m1])>0) {
                    strcpy(auxaluno, curso[k].aluno[aux2]); 
                    strcpy(curso[k].aluno[aux2], curso[k].aluno[aux2m1]); 
                    strcpy(curso[k].aluno[aux2m1], auxaluno);
                }
            }
        }
    }
    //teoricamente, ta todos os nomes ordenados aqui.
    printf("%d\n%d\n", qtdmasc, qtdfem);
    printf("%.2f\n%.2f\n", media, media7/qtd7);
    for(k=0; k<aux; ++k) {
        printf("%s\n", curso[k].nome);
        printf("%d\n", curso[k].nalunos);
        for(aux2=0; aux2<curso[k].nalunos; ++aux2) {
            printf("%s\n", curso[k].aluno[aux2]);
        }
        
    }



    return 0;
}