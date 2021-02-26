#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>


void DST(char nombre[]);
void invertir(char linia[]);

int main(){
    FILE *file2;
	FILE *file1;
	char linea [800];
	char nombre[1000];


	printf("What file do you want to open?");
	scanf("%s", nombre);
	file1 = fopen(nombre, "r");
	 DST(nombre);
	if (file1 == NULL){
        printf("The system could not open the file \n");
        exit(0);
	}
	file2 = fopen(nombre, "w");
	if (file2 == NULL){
        printf("The system could not open the file \n");
        exit(0);
	}

	while (fgets(linea, sizeof(linea), file1) != NULL){
        invertir(linea);
        fputs(linea, file2);
        fputs("\n", file2);
	}

	printf("Text has been reversed \n");


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

void invertir(char linia[]){
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


