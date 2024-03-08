#include<time.h>
#include<stdio.h>
#include<stdlib.h>


char *timeNow();
int menu();
void create();
void salvar(FILE *file);
void sair();

int main(){
  while(1){
    switch(menu()){
      case 1: create();
        break;
      case 2: sair();
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
  system("cls");
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
  char *pathinit = "/home/victor/diary";
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
  FILE *fp_out = fopen(path, "w");
  char text[255];
  do{
    fgets(text, sizeof(text), stdin);
    fputs(text, fp_out);   
  }while(!strcmp(text, "666"));
  salvar(fp_out);  
  fclose(fp_out);
  free(text);
}	

void sair(){
  int count = 0;
  while(!count){
    system("cls");
    printf("\t\t\t\t\t    Saindo");
    for(int i = 0 ; i < 3; i++){
      printf(".");
      sleep(1);
    }
    count++;
  }
  puts("\n\t\t\t\t\tCreate by Victor");
  sleep(1);
  exit(0);
}

void salvar(FILE *file){
  int count = 0;
  while(!count){
    system("cls");
    printf("\t\t\t\t\t   Salvando");
    for(int i = 0 ; i < 3; i++){
      printf(".");
      sleep(1);
    }   
    count++;
  }
}
