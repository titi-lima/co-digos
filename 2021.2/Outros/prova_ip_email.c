#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char remetente[50];
    char assunto[50];
    char mensagem[200];
} email;

typedef struct{
    char nome[50];
    char senha[50];
    int qtdRecebidos, qtdEnviados;
    email *recebidos;
    email *enviados;
} Usuario;


void cadastrarUsuario(char *nome, char *senha){
  FILE *f;
  fopen("users.bin", "ab");
  Usuario novoUsuario;
  strcpy(novoUsuario.nome, nome);
  strcpy(novoUsuario.senha, senha);
  novoUsuario.qtdRecebidos = 0;
  novoUsuario.qtdEnviados = 0;
  novoUsuario.recebidos = NULL;
  novoUsuario.enviados = NULL;
  fwrite(&novoUsuario, sizeof(Usuario), 1, f); //malloc da vida
  fclose(f);
}

void enviarEmail(Usuario *remetente){
  email torpedo;
  char nomeDestinatario[50];
  printf("Insira o nome do destinatario: \n");
  scanf(" %s", nomeDestinatario);
  FILE *f;
  f = fopen("users.bin", "rb");
  int encontrou = 0;
  Usuario *destinatario;
  while(!feof(f) && encontrou == 0) {
    fread(destinatario, sizeof(Usuario), 1, f);
    if(strcmp(destinatario->nome, nomeDestinatario) == 0) {
      printf("pai ta on\n");
      encontrou = 1;
    }
  }
  if(encontrou==0) {
    printf("Usuario invalido.\n"); // questao nao pede para pedir o nome de novo, so retorna
    return;
  }
  printf("Insira o assunto:\n");
  scanf(" %49[^\n]", torpedo.assunto);
  printf("Insira a mensagem:\n");
  scanf(" %199[^\n]", torpedo.mensagem);
  strcpy(torpedo.remetente, remetente->nome);
  remetente->qtdEnviados++;
  destinatario->qtdRecebidos++;
  
  remetente->enviados = (email*) realloc(remetente->enviados, remetente->qtdEnviados*sizeof(email));
  remetente->enviados[remetente->qtdEnviados-1] = torpedo;
  
  destinatario->recebidos = (email*) realloc(destinatario->recebidos, destinatario->qtdRecebidos*sizeof(email));
  destinatario->recebidos[destinatario->qtdRecebidos-1] = torpedo;
}

void verRecebidos(Usuario usuario){
  
}

void verEnviados(Usuario usuario){
  
}

void login(char *nome, char *senha){
  FILE *f;
  f = fopen("users.bin", "rb");
  int encontrou = 0;
  Usuario usuario;
  while(!feof(f) && encontrou == 0) {
    fread(&usuario, sizeof(Usuario), 1, f); 
    if(strcmp(usuario.nome, nome) == 0 && strcmp(usuario.senha, senha) == 0){
       printf("pai ta on\n");
      encontrou = 1;
    }
  }
  fclose(f);
  if(encontrou == 0) {
    printf("Insira o nome do usuario: \n");
    scanf(" %s", nome);
    printf("Insira a senha do usuario: \n");
    scanf(" %s", senha);
    return login(nome, senha); //como é uma função é válido pq não retorna nada, recursão 
  }
  int op = 0;
  printf("*********LOGADO*********\n");
  printf("Enviar e-mail: 0\nVer e-mail's recebidos: 1\nVer e-mail's enviados: 2\n");
  scanf("%d", &op);
  switch(op) {
    case 0:
      enviarEmail(&usuario);
    break;
    case 1:
      verRecebidos(usuario);
    break;
    case 2:
      verEnviados(usuario);
    break;
    default:
    break;
  }
}

int main(){
  char nome[50], senha[50];  
  int op = 0;
  printf("Bem-vindo ao correio eletronico!\n");
  printf("Cadastrar usuario: 0\nFazer login: 1\n");
  scanf("%d", &op);
  while(op != 2) {
  switch(op){
    case 0:
      printf("Insira o nome do usuario: \n");
      scanf(" %s", nome);
      printf("Insira a senha do usuario: \n");
      scanf(" %s", senha);
      cadastrarUsuario(nome, senha);
    break;
    case 1:
      printf("Insira o nome do usuario: \n");
      scanf(" %s", nome);
      printf("Insira a senha do usuario: \n");
      scanf(" %s", senha);
      login(nome, senha);
    break;
    default:
    break;
    } 
  }
  return 0;
}