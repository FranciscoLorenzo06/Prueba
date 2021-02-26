#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>


void DST(char nombre[]);
int girarTodo(char text[]);
void girar(char linea[]);

int main(){
 
	FILE *file1;
	FILE *file2;
	char linea [800];
	char nombre[1000];
	int numLinea =1;

	printf("What file do you want to reverse? \n");
	scanf("%s", nombre);

	file1 = fopen(nombre, "r");
	if (file1 == NULL){
        printf("The system could not open the file \n");
        exit(0);
	}

    DST(nombre);
	file2 = fopen(nombre, "w");
	if (file2 == NULL){
        printf("The file could not open the file \n");
        exit(0);
	}

	while (fgets(linea, sizeof(linea), file1) != NULL){
        int palabra = girarTodo(linea);
        fputs(linea, file2);
        fputs("\n", file2);
        printf("Line %d", numLinea);
        printf(": %d\n", palabra);
        numLinea++;
	}

	printf("\nText has been reversed \n");


	fclose(file1);
	fclose(file2);
	return 0;
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
int girarTodo(char nombre[]){
    char texto[strlen(nombre)];
    char *palabra = strtok(nombre, " ");
    strcpy(texto, "");
    int cont = 0;
    if(palabra != NULL){
        while(palabra != NULL){
            cont++;
            girar(palabra);
            strcat(texto, palabra);
            palabra= strtok(NULL, " ");
            if(palabra != NULL){
                strcat(texto, " ");
            }
        }
    }
    strcpy(nombre,texto);
    return cont;
}
void girar(char linia[]){
    char liniaFinal[strlen(linia)];
    int cont = 0;
    int i =0;
    for(i = strlen(linia);i>0;i--){
            if(linia[i-1]!='\n'){
        liniaFinal[cont] = linia[i-1];
        cont++;
            }
    }
    liniaFinal[cont] = '\0';
strcpy(linia, liniaFinal);

}



