#include "raylib.h"
#include "raymath.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
  Vector2 posicao;
  Vector2 velocidade;
  int raio;
  bool estado;
  bool vida;
  Color cor;
  int tempo;
  int frame;
  int currentframes;
  Texture2D personagem;
  Rectangle Rec;
} bolinha;
/*bolinha* MovAleatoriobolinha(bolinha *b,int qtd_b);//atribui um movimento aleatorio a um vetor de bolinhas(eh para ser usado na parte logica)
bolinha* Initnbolinha(int qtd_b);//inicia uma quantidade  n de bolinhas e retorna um ponteiro com as n bolinhas inicializadas em posicoes distintas
DesenharnBolinha(bolinha *b,int qtd_b);//Desenha as n Bolinhas  */
int countframes=0;
bolinha bolarot(bolinha b1, int ind_aleatorio){
        srand((ind_aleatorio+1)*countframes*time(NULL));
        if(rand()%2==0){
        srand(time(NULL)*ind_aleatorio*countframes*3);
        b1.velocidade = Vector2Rotate(b1.velocidade, PI/(((rand()%4)+1)*15.0));
        b1.posicao = Vector2Add(b1.posicao,b1.velocidade);
        }else{
        srand(time(NULL)*(ind_aleatorio+1)*countframes*2);
        b1.velocidade = Vector2Rotate(b1.velocidade, -PI/(((rand()%4)+1)*15.0));
        b1.posicao = Vector2Add(b1.posicao,b1.velocidade);
        }
        if ((b1.posicao.x >= (GetScreenWidth()- b1.raio)) || (b1.posicao.x <= b1.raio)) b1.velocidade.x *= -1.0f;
        if ((b1.posicao.y >= (GetScreenHeight()- b1.raio)) || (b1.posicao.y <= b1.raio)) b1.velocidade.y *= -1.0f;
        return b1;
}

bolinha Initbolinha(bolinha b1, int ind_aleatorio){
        srand((ind_aleatorio+1)*time(NULL));
        b1.posicao.x= (rand()%(GetScreenWidth()));
        b1.posicao.y= (rand()%(GetScreenHeight()));
        b1.velocidade.x=2;
        b1.velocidade.y=2;
        b1.estado=1;
        b1.raio=10;
        b1.vida=1;
        b1.cor=BLACK;
        b1.tempo=0;
        return b1;
}

bolinha* InitnBolinha(int qtd_b){
    int i;
    bolinha *b=(bolinha*)malloc(qtd_b* sizeof(bolinha));
    if(b==NULL)exit(1);
    for(i=0;i<qtd_b;i++){
        b[i]=Initbolinha(b[i], i);
    }
    return b;
}

bolinha* MovAleatorioBolinha(bolinha *b,int qtd_b){

      for(int i=0;i<qtd_b;i++) b[i]=bolarot(b[i],i);
             for(int i=0;i<qtd_b;i++){
                for(int j=i;j<qtd_b;j++){
                  if(i!=j){
                    if(b[i].estado==1 && b[j].estado==1){
                       if(CheckCollisionCircles(b[j].posicao,b[j].raio,b[i].posicao,b[i].raio)){
                           b[i].velocidade.x *= -1.0f;
                           b[i].velocidade.y *= -1.0f;
                           b[j].velocidade.x *= -1.0f;
                           b[j].velocidade.y *= -1.0f;
                       }
                    }
                  }
                }
             }
       return b;

  }
 void DesenharnBolinha(bolinha *b,int qtd_b){
            for(int i=0;i<qtd_b;i++){
                if(b[i].estado==1) DrawCircleV(b[i].posicao,b[i].raio,b[i].cor);
            }
  }
