#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char remetente[50];
    char assunto[50];
    char mensagem[200];
} email;

typedef struct {
    char nome[50];
    char senha[50];
    int qtdRecebidos, qtdEnviados;
    email *recebidos;
    email *enviados;
} usuario;

int cadastrarUsuario(char *nome, char *senha) {
    usuario *Usuario;
    static int qtdUsuarios = 0;
    //printf("%d\n", qtdUsuarios);
    //Usuario.nome = NULL;
    //Usuario.senha = NULL;
    Usuario = (usuario *)realloc(Usuario, sizeof(usuario) * (qtdUsuarios+1));
    strcpy(Usuario[qtdUsuarios].nome, nome);
    strcpy(Usuario[qtdUsuarios].senha, senha);
    ++qtdUsuarios;
    return qtdUsuarios;
}


void enviarEmail(char *nomeRemetente, int *qtdUsuarios, usuario *Usuario, email *Email) {
    char destinatario[50];
    int flag = 0;
    printf("Insira o destinatario.\n");
    scanf(" %49[^\n]", destinatario);
    for(int i=0; i<*qtdUsuarios; ++i) {
        if(strcmp(destinatario, Usuario[i].nome)==0) {
            flag = 1;
            printf("Assunto:\n");
            scanf(" %49[^\n]", Email[]assunto);
            printf("Mensagem: ");
            scanf(" %199[^\n]", Email[])
        }
    }
    printf("Escre");
}

void verRecebidos(usuario *Usuario, email *Email) {
}

void verEnviados(usuario *Usuario, email *Email) {
}

void login(char *nome, char *senha, int *qtdUsuarios) {
    usuario *Usuario = NULL;
    email *Email = NULL;
    int flag = 0, m;
    char nomeRemetente[50];
    strcpy(nomeRemetente, nome);
    for(int i=0; i<*qtdUsuarios; ++i) {
        if(strcmp(nome, Usuario[i].nome)==0) {
            flag = 1;
            for(int j=0; j<*qtdUsuarios; ++j) {
                if(strcmp(senha, Usuario[j].senha)==0) {
                    flag = 2;
                    printf("Bem-vindo, %s!\nPressione 1 para enviar um e-mail.\nPressione 2 para ver sua caixa de entrada.\nPressione 3 para ver seus e-mails enviados.\nPressione 0 para sair.\n", Usuario[i].nome);
                    scanf("%d", &m);
                    while (m != 0) {
                        switch (m) {
                            case 1: {
                                enviarEmail(nomeRemetente, qtdUsuarios, Usuario, Email);
                                printf("Pressione 1 para enviar um e-mail.\nPressione 2 para ver sua caixa de entrada.\nPressione 3 para ver seus e-mails enviados.\nPressione 0 para sair.\n");
                                scanf("%d", &m);
                                break;
                            }
                            case 2: {
                                verRecebidos(Usuario, Email);
                                printf("Pressione 1 para enviar um e-mail.\nPressione 2 para ver sua caixa de entrada.\nPressione 3 para ver seus e-mails enviados.\nPressione 0 para sair.\n");
                                scanf("%d", &m);
                                break;
                            }
                            case 3: {
                                verEnviados(Usuario, Email);
                                printf("Pressione 1 para enviar um e-mail.\nPressione 2 para ver sua caixa de entrada.\nPressione 3 para ver seus e-mails enviados.\nPressione 0 para sair.\n");
                                scanf("%d", &m);
                                break;
                            }
                            default: {
                                printf("Insira um numero valido.\n");
                                printf("Pressione 1 para enviar um e-mail.\nPressione 2 para ver sua caixa de entrada.\nPressione 3 para ver seus e-mails enviados.\nPressione 0 para sair.\n");
                                scanf("%d", &m);
                                //printf("\n");
                                break;
                            } 
                        }
                    }
                }
            }
        }
        if (flag == 0) {
            printf("Usuario nao encontrado. Tente novamente.\n");
        }
        if (flag == 1) {
            printf("Senha incorreta. Tente novamente.\n");
        }
    }
}

int main() {
    int w, qtdUsuarios;
    usuario *Usuario = NULL;
    char nome[50], senha[50];
    printf("Para fazer login, pressione 1.\nPara fazer cadastro, pressione 2.\nPara fechar o programa, pressione 0.\n");
    scanf("%d", &w);
    while (w != 0) {
        switch (w) {
        case 1: {
            printf("Digite seu nome: ");
            scanf(" %49[^\n]", nome);
            printf("\nDigite sua senha: ");
            scanf(" %49[^\n]", senha);
            login(nome, senha, &qtdUsuarios);
            printf("Para fazer login, pressione 1.\nPara fazer cadastro, pressione 2.\nPara fechar o programa, pressione 0.\n");
            scanf("%d", &w);
            break;
        }
        case 2: {
            printf("Digite seu nome: ");
            scanf(" %49[^\n]", nome);
            printf("\nDigite sua senha: ");
            scanf(" %49[^\n]", senha);
            qtdUsuarios = cadastrarUsuario(nome, senha);
            printf("Para fazer login, pressione 1.\nPara fazer cadastro, pressione 2.\nPara fechar o programa, pressione 0.\n");
            scanf("%d", &w);
            break;
        }
        default: {
            printf("Insira um numero valido.\n");
            printf("Para fazer login, pressione 1.\nPara fazer cadastro, pressione 2.\nPara fechar o programa, pressione 0.\n");
            scanf("%d", &w);
            //printf("\n");
            break;
        }
        }
    }
}