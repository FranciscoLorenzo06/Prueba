#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void DST(char archivo[]);
void p1(char nombre[],FILE *file1);
int main(void){
    DIR *direct1;
    struct dirent *direct;
    FILE *file1;
    char *c;
    char nombre[255];
    char directorio[700];

    printf("What directory do you want to open? \n");
	scanf("%s", directorio);
   direct1 = opendir(directorio);
    if (direct1){
        while ((direct = readdir(direct1)) != NULL){
        file1 = fopen(direct->d_name, "r");
		if (file1 != NULL){
            strcpy(nombre, direct->d_name);
            c =strrchr(nombre,'.');
            if(c!=NULL){
            if(strcmp(c,".txt")==0||strcmp(c,".TXT")==0)
            p1(nombre,file1);
            }
        }
    }
    closedir(direct1);
    return(0);
    }
}

void p1(char nombre[],FILE *file1){
	FILE *file2;
	char caracter;

  DST(nombre);
	file2 = fopen(nombre, "w");
	if (file2 == NULL){
	 printf("The system could not open the file \n");
	 exit(0);
	}
	caracter = fgetc(file1);
	while (caracter != EOF){
		fputc(caracter, file2);
		caracter = fgetc(file1);
	}
    fclose(file2);
	fclose(file1);
	printf("\nText has been copied  \n");
}

void DST(char archivo[]){
    char *ext;
    char nombreFinal[strlen(archivo)+4];

    if((ext = strchr(archivo,'.'))==NULL){
        strcat(archivo,".DST");
    }
    else{
        int Punto = strlen(archivo)-strlen(ext);
        strncpy(nombreFinal,archivo,Punto);
        strcat(nombreFinal,".DST");
        strcat(nombreFinal,ext);
        strcpy(archivo,nombreFinal);
    }
}
