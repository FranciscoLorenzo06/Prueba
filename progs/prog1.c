#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define EXTENSION ".DST"

void DST(char nombre[]);

int main(){
    FILE *file1;
    FILE *file2;
    char nombre[1000];
    char character;




    printf("What file do you want to open \n");
    scanf("%s", nombre);

    file1=fopen(nombre,"r");

    if(file1==NULL){
        printf("The system could not open the file \n");
        exit(0);
    }
       

DST(nombre);

file2=fopen(nombre,"w");
if(file2==NULL){
    printf("The system could not open the file \n");
    exit(0);
}

character= fgetc(file1);
while(character!=EOF){
    fputc(character,file2);
    character=fgetc(file1);
}

printf("The text has been copied \n");
fclose(file1);
fclose(file2);
return 0;
    
    
}

void DST (char archivo[]){
    char *ext;
    int punto;
    char nombreFinal [strlen(archivo)+4];
    if((ext=strchr(archivo,'.'))== NULL){
        strcat(archivo,EXTENSION);
    }
    else{
        punto= strlen(archivo)-strlen(ext);
        strncpy(nombreFinal,archivo,punto);
        strcat(nombreFinal,EXTENSION);
        strcat(nombreFinal,ext);
        strcpy(archivo,nombreFinal);

    }
}

