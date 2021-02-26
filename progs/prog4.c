#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void p1(char filename[]);
void p2(char filename[]);
void p3(char filename[]);
void DST(char archivo[]);
int girarTodo(char nombre[]);
void girar(char linia[]);

int main()
{
    char nombre[100];
    printf("Enter the filename to open for reading \n");
	scanf("%s", nombre);
	int choose = 0;
	do{
	printf("Chose the program that do you want to execute: '1,2,3'\n");
	scanf("%d", &choose);
    if(choose == 1){
        p1(nombre);
    }else if(choose == 2){
        p2(nombre);
    }else if(choose == 3){
    p3(nombre);
    }
	}while(choose<0||choose>3);
	return 0;
}
void p1(char nombre[]){
	FILE *file1;
	FILE *file2;
	char caracter;

	file1 = fopen(nombre, "r");
	DST(nombre);
	if (file1 == NULL){
			printf("The system could not open the file \n");
			exit(0);
	}
	file2 = fopen(nombre, "w");
	if (file2 == NULL){
	 printf("The system could not open the file\n");
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
void p2(char nombre[]){
    FILE *file2;
	FILE *file1;
	char linea [800];

	file1 = fopen(nombre, "r");
	 DST(nombre);
	if (file1 == NULL){
        printf("The system could not open the file \n");
        exit(0);
	}
	file2 = fopen(nombre, "w");
	if (file2 == NULL){
        printf("The system could not open the file\n");
        exit(0);
	}

	while (fgets(linea, sizeof(linea), file1) != NULL){
        girar(linea);
        fputs(linea, file2);
        fputs("\n", file2);
	}

	printf("Text has been reversed \n");

	fclose(file1);
	fclose(file2);
}
void p3(char nombre[]){
   FILE *file1;
	FILE *file2;
	char linea [800];
	int numLinea =1;
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
