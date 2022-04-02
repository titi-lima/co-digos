#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char remetente[50];
    char assunto[50];
    char mensagem[200];
}Email;

typedef struct{
    char nome[50];
    char senha[50];
    int qntdRecebidos, qntdEnviados;
    Email *recebidos;
    Email *enviados;
}Usuario;

void enviarEmail(char *nomeRemetente){
    char destinatario[50], assunto[50], mensagem[200];
    printf("Quem eh o destinatario?\n");
    scanf(" %s", destinatario);
    printf("Assunto:\n");
    scanf(" %s", assunto);
    printf("Digite sua mensagem:\n");
    scanf(" %[^\n]", mensagem);

    FILE *arquivo = fopen("users.bin", "rb");

    if(arquivo == NULL){
        printf("Algo de errado nao esta certo\n");
        exit(0);
    }

    Usuario *users = NULL;
    Usuario temp;
    int tam = 0, i = 0;

    while(fread(&temp, sizeof(Usuario), 1, arquivo) != 0){
        users = (Usuario*) realloc(users, sizeof(Usuario)*(tam + 1));
        users[tam] = temp;
        tam++;
    }
    fclose(arquivo);

    for(i = 0; i < tam; i++){
        if(strcmp(users[i].nome, destinatario) == 0){
            if(users[i].qntdRecebidos == 0){
                users[i].recebidos = NULL;
            }
            users[i].recebidos = (Email*) realloc(users[i].recebidos, sizeof(Email)*(users[i].qntdRecebidos + 1));
            strcpy(users[i].recebidos[users[i].qntdRecebidos].mensagem, mensagem);
            strcpy(users[i].recebidos[users[i].qntdRecebidos].assunto, assunto);
            strcpy(users[i].recebidos[users[i].qntdRecebidos].remetente, nomeRemetente);
            users[i].qntdRecebidos++;
            i = tam;
        }
    }

    for(i = 0; i < tam; i++){
        if(strcmp(users[i].nome, nomeRemetente) == 0){
            if(users[i].qntdEnviados == 0){
                users[i].enviados = NULL;
            }
            users[i].enviados = (Email*) realloc(users[i].enviados, sizeof(Email)*(users[i].qntdEnviados + 1));
            strcpy(users[i].enviados[users[i].qntdEnviados].mensagem, mensagem);
            strcpy(users[i].enviados[users[i].qntdEnviados].assunto, assunto);
            strcpy(users[i].enviados[users[i].qntdEnviados].remetente, nomeRemetente);
            users[i].qntdEnviados++;
            i = tam;
        }
    }

    arquivo = fopen("users.bin", "wb");
    if(arquivo == NULL){
        printf("Algo de errado nao esta certo\n");
        exit(0);
    }
    fwrite(users, sizeof(Usuario), tam, arquivo);
    fclose(arquivo);
    free(users);
}

void verRecebidos(Usuario usuario){
    int i = 0;
    if(usuario.qntdRecebidos == 0){
        printf("Caixa de entrada vazia\n");
    }
    else{
        printf("Emails recebidos\n\n");
    }
    for(i = 0; i < usuario.qntdRecebidos; i++){
        printf("Remetente: %s\n", usuario.recebidos[i].remetente);
        printf("Assunto: %s\n", usuario.recebidos[i].assunto);
        printf("Mensagem: %s\n\n", usuario.recebidos[i].mensagem);
    }
}

void verEnviados(Usuario usuario){
    int i = 0;
    if(usuario.qntdEnviados == 0){
        printf("Nenhum email enviado\n");
    }
    else{
        printf("Emails enviados\n\n");
    }
    for(i = 0; i < usuario.qntdEnviados; i++){
        printf("Remetente: %s\n", usuario.enviados[i].remetente);
        printf("Assunto: %s\n", usuario.enviados[i].assunto);
        printf("Mensagem: %s\n\n", usuario.enviados[i].mensagem);
    }
}

void cadastrarUsuario(char *nome, char *senha){
    Usuario temp;
    strcpy(temp.nome, nome);
    strcpy(temp.senha, senha);
    temp.qntdEnviados = 0;
    temp.qntdRecebidos = 0;

    FILE *arquivo = fopen("users.bin", "ab");
    if(arquivo == NULL){
        printf("Algo de errado nao esta certo");
        exit(0);
    }
    fwrite(&temp, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);
}

void login(char *nome, char *senha){
    FILE *arquivo = fopen("users.bin", "rb");
    if(arquivo == NULL){
        printf("Algo de errado nao esta certo");
        exit(0);
    }

    Usuario *users = NULL;
    Usuario temp;
    int tam = 0;

    while(fread(&temp, sizeof(Usuario), 1, arquivo) != 0){
        users = (Usuario*) realloc(users, sizeof(Usuario)*(tam + 1));
        if(users == NULL){
            printf("Algo de errado nao esta certo");
            exit(0);
        }
        users[tam] = temp;
        tam++;
    }
    fclose(arquivo);
    int autenticado = 0, i;
    while(!autenticado){
        for(i = 0; i < tam; i++){
            if((strcmp(nome, users[i].nome) == 0) && (strcmp(senha, users[i].senha) == 0)){
                autenticado = 1;
                temp = users[i];
                i = tam;
            }
        }
        if(!autenticado){
            printf("Digite nome e senha validos\n");
            scanf(" %s %s", nome, senha);
        }
    }
    int menu, loop = 1;
    while(loop){
        printf("\n==================== Acmail ====================\n");
        printf("Digite 1 para ver e-mails recebidos\nDigite 2 para ver e-mails enviados\nDigite 3 para enviar um e-mail\nDigite 4 para sair do menu\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                verRecebidos(temp);
                break;
            case 2:
                verEnviados(temp);
                break;
            case 3:
                enviarEmail(nome);
                break;
            case 4:
                printf("Menu encerrado!\n");
                loop = 0;
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        printf("=================================================\n");
    }
    free(users);
}






int main(){
    int menu, loop = 1;
    char nome[50], senha[50];
    FILE *arquivo = fopen("users.bin", "wb");
    fclose(arquivo);

    while(loop){
        printf("\n==================== Acmail ====================\n");
        printf("Digite 1 para se cadastrar\nDigite 2 para fazer login\nDigite 3 para sair do menu\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Digite o nome e a senha do usuario a ser cadastrado\n");
                scanf(" %s %s", nome, senha);
                cadastrarUsuario(nome, senha);
                break;
            case 2:
                printf("Digite o nome e a senha do usuario para fazer login\n");
                scanf(" %s %s", nome, senha);
                login(nome, senha);
                break;
            case 3:
                printf("Menu encerrado!\n");
                loop = 0;
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
        printf("=================================================\n");
    }
    return 0;
}