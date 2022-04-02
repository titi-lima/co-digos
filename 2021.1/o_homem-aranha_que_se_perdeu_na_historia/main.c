#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "movaleatorio.h"
#define largura 800
#define altura 600
#define direcao rand()%2?-1:1
#define nb 5   //numero de bolinhas

//***************FUNCOES***************************************

void DesenharBarrinha(int vida,Vector2 posicao_agiota);
void atacar(bolinha *bola, Vector2 posicao_agiota, int *vida) ;
Color mudancaDeCor(Color *nova) ;
void movimentobolinha(Vector2 *posicao_agiota) ;
void qtdBolasVermelhas(bolinha *bola, int qtdBolasVer) ;
void InicializarPersonagens(bolinha *p, int qtd);
void DescarregarPersonagens(bolinha *p, int qtd);
void DesenharPrincipal(Rectangle *Rec, Vector2 posicao_agiota, Texture2D personagem);
void DesenharPersonagens(bolinha *p, int qtd);
void tempoBolaVer(bolinha *bola, int tempoBolaVermelha, int *vida);
void FimDoJogo(bolinha *bola, bool *fimDoJogo);

//**********VARIAVEIS GLOBAIS***********************************

int currentframes=0;
int frame=0;
int nivel = 0;
Texture2D life;
Texture2D relampago;
Sound raioS;
Music trilha;
Music nivan;
//************MAIN***********************************************
int main(){
  InitWindow(largura, altura, "O HOMEM ARANHA QUE SE PERDEU NA HISTÓRIA");
  srand(time(0));
  
  InitAudioDevice();
  trilha = LoadMusicStream("trilhaSonora.mp3");
  PlayMusicStream(trilha);
  nivan = LoadMusicStream("AudioNivan.mp3");
  PlayMusicStream(nivan);
  int tempoBolaVermelha = 5;
  int qtdBolasVer = 2;
  int vida = 3;
  int aux;
  int aux2;
  int cont=0;
  bool fimDoJogo = false;
  bool iniciarjogo=false;
  bool historia = true;
  //inicializa as bolinhas pretas na tela
  bolinha *bola = InitnBolinha(nb);
  //coloca o agiota no meio da tela
  Vector2 posicao_agiota = {largura/2.0, altura/2.0};
  char buff[100];
  //inicializando textura
  Texture2D personagem= LoadTexture("person.png");
  Texture2D homiranha = LoadTexture("homiranha1.png");
  Rectangle Rec = {0,0,homiranha.width/3,homiranha.height/4};
  SetTargetFPS(30);
  InicializarPersonagens(bola,nb);

  while(!WindowShouldClose()) {
    SetMusicVolume(trilha, 0.4);
    UpdateMusicStream(trilha); 
    countframes++;
    currentframes++;
    sprintf(buff, "minutos: %d segundos : %d",countframes/(30*60), (countframes/30)%60);
    // LOGICA:
    movimentobolinha(&posicao_agiota);
    MovAleatorioBolinha(bola,nb+2*nivel);
    qtdBolasVermelhas(bola, qtdBolasVer);
    atacar(bola, posicao_agiota, &vida);
    tempoBolaVer(bola, tempoBolaVermelha, &vida);
    FimDoJogo(bola, &fimDoJogo);
    //DESENHANDO:
    BeginDrawing();
    if(historia==true) {
      if(countframes<2500 && !IsKeyPressed(KEY_ENTER) && !IsKeyPressed(KEY_C)){
      BeginDrawing();
      DrawText("O HOMEM ARANHA QUE PERDEU SUA HISTÓRIA: ",20,GetScreenHeight()+200-countframes/3,30,RED);
      DrawText("No ano 2122, quando as máquinas finalmente se tornam verdadeiramente ",20,GetScreenHeight()+20-countframes/3,20,WHITE);
      DrawText("inteligentes, todos se tornam obsoletos: cozinheiros, artistas, fotógrafos… e até ",20,GetScreenHeight()+40-countframes/3,20,WHITE);
      DrawText("… e até mesmo super-heróis. Todos, menos ele, o real protagonista dessa ",20,GetScreenHeight()+60-countframes/3,20,WHITE);
      DrawText("história : o dinheiro. O homem-aranha, que já foi,",20,GetScreenHeight()+80-countframes/3,20,WHITE);
      DrawText("voltou e desistiu de casa, decide tornar-se um agiota para sobreviver.  ",20,GetScreenHeight()+100-countframes/3,20,WHITE);
      DrawText("Ajude-o a capturar seus devedores.",20,GetScreenHeight()+120-countframes/3,20,WHITE);
      }else historia =false;
      EndDrawing();
      countframes++;
    }
    else if(historia==false) {
      if(iniciarjogo==false) {
        ClearBackground(WHITE);
        DrawText("Agiota do multiverso",20,20,30,(Color){80,0,50,200});
        DrawText("-Utilize as teclas W A S D para se movimentar e",20,70,20,(Color){80,0,50,200});
        DrawText(" P para matar os personagens vermelhos que aparecerem na tela",20,110,20,(Color){80,0,50,200});
        DrawText("-[Pressione espaço ou enter para iniciar]",20,400,20,(Color){80,0,50,200});
        DrawRectangle(10,10,GetScreenWidth()-20,GetScreenHeight()-50,(Color){0,0,0,150});
        if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)){
          iniciarjogo=true;
        }
      }
      else if(iniciarjogo == true) {
        if (fimDoJogo == false) {
          if (nivel == 0 && vida > 0) {
            DrawText("Nivel 1",10,10,15,RED);
          }
          else if (nivel == 1 && vida > 0) {
            DrawText("Nivel 2",10,10,15,RED);
          }
          else if (nivel == 2 && vida > 0) {
            DrawText("Nivel 3",10,10,15,RED);
          }
          else if (nivel == 3 && vida > 0) {
            DrawText("Nivel 4",10,10,15,RED);
          }
          if (vida > 0) {
            DesenharPersonagens(bola,nb+2*nivel);
            DesenharBarrinha(vida, posicao_agiota);
            DesenharPrincipal(&Rec,posicao_agiota, homiranha);
          } 
          else {
            if(cont==0) {
              aux = countframes;
              aux2 = countframes+115;
            }
            if(aux!=aux2) {
              UpdateMusicStream(nivan);
              aux = countframes;
            }
            StopMusicStream(trilha);
            DrawText("GAME OVER",250,altura/2-20, 40,BLACK);
            DrawText("O miranha nao conseguiu",275,altura/2+30, 16,BLACK);
            DrawText("cobrar a todos devedores :(",260,altura/2+50, 16,BLACK);
            ClearBackground(DARKGRAY);
            ++cont;
          }
        }
        else if (fimDoJogo == true) {
          if (nivel == 3) {
            ClearBackground(DARKBLUE);
            DrawText("Parabens!!",310,250, 40,BLACK);
            DrawText("Voce conseguiu derrotar", 280, 300, 20, BLACK);
            DrawText("todos os devedores.", 305, 320, 20, BLACK);

          }
          else {
            nivel++;
            bola = InitnBolinha(nb+2*nivel);
            InicializarPersonagens(bola, nb+2*nivel);
            qtdBolasVer += nivel;
            fimDoJogo = false;
          }
        }
      }
      EndDrawing();
    }
  }
  UnloadTexture(relampago);
  UnloadMusicStream(trilha);
  DescarregarPersonagens(bola,nb);
  UnloadTexture(personagem);
  CloseWindow();
  CloseAudioDevice();
  return 0;
}

//****************FUNCOES********************************************************
void tempoBolaVer (bolinha *bola, int tempoBolaVermelha, int *vida) {
  int i;
  for (i=0; i<nb; i++) {
    if (countframes % 60 == 0 && bola[i].cor.r == 200 && bola[i].estado == true) bola[i].tempo++;
  }
  for (i=0; i<nb; i++) {
    if (bola[i].tempo > tempoBolaVermelha && bola[i].estado == true) {
      bola[i].estado = false;
      (*vida)--;
    }
  }
}

void FimDoJogo(bolinha *bola, bool *fimDoJogo) {
  static bool flag = true;
  int i = 0;
  if (*fimDoJogo == false ) {
    for (i=0; i<nb; i++) {
      if (bola[i].cor.r != 0 && bola[i].estado == true) {
        flag = true;
      }
    }
    if (flag == false) {
      *fimDoJogo = true;
    }
    else flag = false;
  }
}

void qtdBolasVermelhas(bolinha *bola, int qtdBolasVer) {
  int i;
  for (i=0; i<qtdBolasVer; i++) {
    if (countframes % 1 == 0 && i % 2 == 0) {
      if (bola[i].cor.r != 200) bola[i].cor.r++;
    }
    if (countframes % 11 == 0) {
      if (bola[i].cor.r != 200) bola[i].cor.r++;
    }
    if (countframes % 11 == 0 && i % 3 == 0) {
      if (bola[i].cor.r != 200) bola[i].cor.r++;
    }
  }
}

void movimentobolinha(Vector2 *posicao_agiota) {
  if (IsKeyDown(KEY_D) && posicao_agiota->x < largura) posicao_agiota->x += 3.0f;
  if (IsKeyDown(KEY_A) && posicao_agiota->x > 0) posicao_agiota->x -= 3.0f;
  if (IsKeyDown(KEY_W) && posicao_agiota->y > 0) posicao_agiota->y -= 3.0f;
  if (IsKeyDown(KEY_S) && posicao_agiota->y < altura) posicao_agiota->y += 3.0f;

}

Color mudancaDeCor(Color *nova) {
  //aumentado o Red gradativamente(aparentemente  min = 0 e o max =255)
  if(countframes % 3 ==0){
    if(nova->r!=200) nova->r++;
  }
  return *nova;
}

void atacar(bolinha *bola, Vector2 posicao_agiota, int *vida) {
  int distanciaDoAtaque = 50; //CASO PRECISE ALTERAR O RANGE DO ATAQUE DO AGIOTA
  int aux, aux2;
  float maisproximo = 10000; // inicializado como numero arbitrariamente alto o bastante que a primeira condicao sempre seja verdadeira

  float distancia[nb+2*nivel];
  //CALCULAR A DISTANCIA ENTRE O JOGADOR E A BOLINHA
  for(aux = 0; aux<nb+2*nivel; ++aux) {
    distancia[aux] = sqrt(pow(bola[aux].posicao.x - posicao_agiota.x, 2) + pow(bola[aux].posicao.y - posicao_agiota.y, 2)); //PITAGORAS
  }
  for(aux = 0; aux<nb+2*nivel; ++aux) {
    if(aux == (nb+2*nivel-1)) {
      if(distancia[aux]<maisproximo) {
        maisproximo = distancia[aux];
        aux2 = aux;
      }
    }
    else if(distancia[aux]<maisproximo) {
      maisproximo = distancia[aux];
      aux2 = aux;
    }
  }
  //TESTAR SE A TECLA 'P' FOI APERTADA E COMPARAR A 'distanciaDoAtaque' COM A DISTANCIA DO JOGADIR PARA A BOLINHA
  if (IsKeyDown(KEY_P) && maisproximo < distanciaDoAtaque && bola[aux2].estado == true) {
    if (bola[aux2].cor.a == 255 && bola[aux2].cor.r == 0 && bola[aux2].cor.g == 0 &&  bola[aux2].estado == true) {
      Vector2 posicaoRelampago;
      //ataca o proprio agiota
        posicaoRelampago.x=posicao_agiota.x-20;
        posicaoRelampago.y=posicao_agiota.y-20;
        bola[aux2].estado = false;
        relampago = LoadTexture("raio.png");
        SetSoundVolume(raioS, 0.5);
        raioS = LoadSound("raiocortado.mp3");
        PlaySound(raioS);
        DrawTextureEx(relampago,posicaoRelampago,0,0.10,WHITE);
      *vida = *vida - 1;
    } // ATRIBUINDO FALSO AO ESTADO DA BOLA
    else {
      //ataca o inimigo
      Vector2 posicaoRelampago;
      posicaoRelampago.x=bola[aux2].posicao.x-20;
      posicaoRelampago.y=bola[aux2].posicao.y-20;
      bola[aux2].estado = false;
      relampago = LoadTexture("raio.png");
      SetSoundVolume(raioS, 0.5);
      raioS = LoadSound("raiocortado.mp3");
      PlaySound(raioS);
      DrawTextureEx(relampago,posicaoRelampago,0,0.10,WHITE);
    }
    ClearBackground(WHITE);
  }
  else ClearBackground(BLACK);
}

void InicializarPersonagens(bolinha *p, int qtd){
    for(int i=0;i<qtd;i++){
      p[i].personagem = LoadTexture("person.png");
      p[i].Rec.height = p[i].personagem.height/4;
      p[i].Rec.width = p[i].personagem.width/4;
      p[i].Rec.x=0;
      p[i].Rec.y=0;
      p[i].currentframes=0;
      p[i].frame=0;
    }
}

void DesenharPersonagens(bolinha *p, int qtd){
  for(int i=0;i<qtd;i++){
    if(p[i].estado==true){
      p[i].currentframes++;
      if(p[i].velocidade.y>=0){
        p[i].Rec.y= p[i].Rec.height*0;
        if(p[i].currentframes>=4){
          if(p[i].frame<=3){
            p[i].Rec.x=p[i].Rec.width*p[i].frame;
            DrawTextureRec(p[i].personagem,p[i].Rec,(Vector2){p[i].posicao.x-(p[i].personagem.width/4)/2,p[i].posicao.y-(p[i].personagem.height/4)/2},p[i].cor);
            if(p[i].frame==3)p[i].frame=0;
            else p[i].frame++;
          }
          p[i].currentframes=0;
        }
    }
    if(p[i].velocidade.y<=0) {
      p[i].Rec.y= p[i].Rec.height*1;
      if(p[i].currentframes>=4) {
        if(p[i].frame<=3) {
          p[i].Rec.x=p[i].Rec.width*p[i].frame;
          DrawTextureRec(p[i].personagem,p[i].Rec,(Vector2){p[i].posicao.x-(p[i].personagem.width/4)/2,p[i].posicao.y-(p[i].personagem.height/4)/2},p[i].cor);
          if(p[i].frame==3)p[i].frame=0;
          else p[i].frame++;
        }
        p[i].currentframes=0;
      }
    }
    DrawTextureRec(p[i].personagem,p[i].Rec,(Vector2){p[i].posicao.x-(p[i].personagem.width/4)/2,p[i].posicao.y-(p[i].personagem.height/4)/2},p[i].cor);
    }
  }
}

void DescarregarPersonagens(bolinha *p, int qtd) {
  for(int i=0;i<qtd;i++){
    UnloadTexture(p[i].personagem);
  }
}

void DesenharBarrinha(int vida,Vector2 posicao_agiota) {
  if (vida == 3) {
    life = LoadTexture("Barrinhas de Vida - COMPLETA.png");
    DrawTextureEx(life,(Vector2){posicao_agiota.x-27,posicao_agiota.y-55},0,0.14,WHITE);
  }
  else if (vida == 2) {
    life = LoadTexture("Barrinhas de Vida - METADE.png");
    DrawTextureEx(life,(Vector2){posicao_agiota.x-27,posicao_agiota.y-55},0,0.14,WHITE);
  }
  else if (vida == 1) {
    life = LoadTexture("Barrinhas de Vida - FIM.png");
    DrawTextureEx(life,(Vector2){posicao_agiota.x-27,posicao_agiota.y-55},0,0.14,WHITE);
  }
}

void DesenharPrincipal(Rectangle *Rec, Vector2 posicao_agiota, Texture2D personagem) {
  if (IsKeyDown(KEY_S)) {
    Rec->y=Rec->height*0;
    if(currentframes>=4){
      if(frame<=2){
        Rec->x=Rec->width*frame;
        DrawTextureRec(personagem,*Rec,(Vector2){posicao_agiota.x-(personagem.width/4)/2,posicao_agiota.y-(personagem.height/4)/2},WHITE);
        if(frame==2)frame=0;
        else frame++;
      }
      currentframes=0;
    }
  }
  if (IsKeyDown(KEY_W)){
    Rec->y=Rec->height*3;
    if(currentframes>=4){
      if(frame<=2){
        Rec->x=Rec->width*frame;
        DrawTextureRec(personagem,*Rec,(Vector2){posicao_agiota.x-(personagem.width/4)/2,posicao_agiota.y-(personagem.height/4)/2},WHITE);
        if(frame==2)frame=0;
        else frame++;
      }
      currentframes=0;
    }
  }
  if (IsKeyDown(KEY_A)){
    Rec->y=Rec->height*1;
    if(currentframes>=4){
      if(frame<=2){
        Rec->x=Rec->width*frame;
        DrawTextureRec(personagem,*Rec,(Vector2){posicao_agiota.x-(personagem.width/4)/2,posicao_agiota.y-(personagem.height/4)/2},WHITE);
        if(frame==2)frame=0;
        else frame++;
      }
      currentframes=0;
    }
  }
  if (IsKeyDown(KEY_D)) {
    Rec->y=Rec->height*2;
    if(currentframes>=4){
      if(frame<=2){
          Rec->x=Rec->width*frame;
          DrawTextureRec(personagem,*Rec,(Vector2){posicao_agiota.x-(personagem.width/4)/2,posicao_agiota.y-(personagem.height/4)/2},WHITE);
          if(frame==2)frame=0;
          else frame++;
      }
      currentframes=0;
    }
  }
  DrawTextureRec(personagem,*Rec,(Vector2){posicao_agiota.x-(personagem.width/4)/2,posicao_agiota.y-(personagem.height/4)/2},WHITE);
}