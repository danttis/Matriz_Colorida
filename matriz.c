#include <stdio.h> //INCLUSÃO DA BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"//DEFINIÇÃO DAS CORES
#define BLUE "\x1b[34m"
#define PURPLE "\x1b[35m"


typedef struct campo{ // CRIAÇÃO DA SCRUCT QUE VAMOS USAR
  char *locais; //ELEMENTOS OU LOCAIS DA MATRIZ
  char *jogadores;// JOGADORES
} Campo;

void enche_matriz(Campo *matriz, char *locais[], char *jogadores[]); // FUÇÃO PARA ENCHER A STRUCT

void embaralha(Campo *matriz); // EMBARALHAR 

void textoColorido(Campo *matriz); // EXIBIR COLORIDO

int main(){
    Campo *matriz[25]; // STRUCT CAMPO
    char *camp[] = {"1","1","1","1","1"}; //ELEMENTOS INICIAIS 
    char *joga[] = {"1","2","3","4","5"}; // JOGADORES
    
    enche_matriz(*matriz, camp, joga);
   
    embaralha(*matriz);
      
    textoColorido(*matriz);
  
    return(0);	      
}
void enche_matriz(Campo *matriz, char *locais[], char *jogadores[]){
  int i;
  for(i=0;i<25;i++){
    matriz[i].locais = "1";
    matriz[i].jogadores = jogadores[i/5];
  }
}
void embaralha(Campo *matriz){
  int i , j;
  Campo aux; // AUXILIAR PARA NÃO PERDER A REFERENCIA
  for(i=0;i<24;i++){
    j = rand()%24; // RECEBER VALORES ATÉ 24 PARA EMABRALHAR VISTO QUE  INDETA DO 0
    aux = matriz[i];
    matriz[i] = matriz[j];
    matriz[j] = aux;
  }
}

void textoColorido(Campo *matriz){
  for(int i=0;i<25;i++){  
    switch(*matriz[i].jogadores){ // LER O JOGADOR EM CADA POSIÇÃO DA MATRIZ E COLORIR A POSIÇÃO DE ACORDO COM O JOGADOR
      case '1':
          printf(RED "%7s%s",matriz[i].locais,(i+1)%5?"":"\n"); //printf(RED "%S",matriz[i].locais); SERIA O SUFICIENTE O RESTO É SÓ PARA ENQUADRAMENTO
          break;
      case '2':
          printf(GREEN "%7s%s",matriz[i].locais,(i+1)%5?"":"\n");
          break;
      case '3':
          printf(YELLOW "%7s%s",matriz[i].locais,(i+1)%5?"":"\n");
          break;
      case '4':
          printf(BLUE "%7s%s",matriz[i].locais,(i+1)%5?"":"\n");
          break;
      case '5':
          printf(PURPLE "%7s%s",matriz[i].locais,(i+1)%5?"":"\n");
          break;
    }
        }
    } 
