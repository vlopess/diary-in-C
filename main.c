#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


char *timeNow();
int menu();
void create();
void salvar(FILE *fp_out);
void sair();


int main(){
  while(1){
    switch(menu()){
      case 1: create();
        break;  
      case 2: sair() ;
    }
  }
  return EXIT_SUCCESS;
}

char *timeNow(){
  time_t lt = time(NULL);
  struct tm *ptr = localtime(&lt);
  return asctime(ptr);
}

int menu(void){
  int option; 
  puts("\t\t\t\t\t\t\t Welcome to the Todo");
  puts("\t\t\t\t\t[1]Create Todo");
  puts("\t\t\t\t\t[2]Exit");
  printf("\t\t\t\t\t> ");
  do{
    scanf("%d", &option);
  }while(option!=1 && option!=2);
  return option;
}

void create(){
  char *pathinit = "/home/victor/diary/";
  fflush(stdin);
  char *hora = timeNow();
  puts(hora);
  int lenght = strlen(hora) + strlen(pathinit) + strlen(".txt");
  printf("%d", &lenght);
  char *path = malloc(lenght * sizeof(char));
  puts(hora);
  strcpy(path, pathinit);
  strcat(path, hora);
  strcat(path, ".txt");
  puts(path);
  FILE *fp_out = fopen(path, "w");
  char text[255];
  char *texto = NULL; 
  if(signal(SIGINT, sair) == -1){
    salvar(fp_out);
  }
  while(1){  
    fflush(stdin);
    fgets(text, sizeof(text), stdin);
    int tam = strlen(text);
    texto = realloc(texto, tam);
    strcpy(texto, text);
    fputs(text, fp_out);      
  } 
}	

void sair(){  
  int count = 0;
  while(!count){    
    printf("\t\t\t\t\t    Salvando...");
    for(int i = 0 ; i < 3; i++){
      printf(".");
    }
    count++;
  }
  puts("\n\t\t\t\t\tCreate by Victor");  
  exit(0);
}

void salvar(FILE *fp_out){
  salvar(fp_out);  
  fclose(fp_out); 
}
