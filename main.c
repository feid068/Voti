#include <stdio.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"

# define MAX_SIZE 15

float voti[MAX_SIZE];
float pesi[MAX_SIZE];
float media[MAX_SIZE];
char nome[] = "materie.txt";
char path[] = "materie/";
char extention[] = ".txt";
char arrey_mat[MAX_SIZE][1024];

int menu();

int main(){
    FILE *file;

   int Menu= menu();
    while (Menu != 5){
        switch (Menu){
        case 1:
            char mat[50];
            printf("Inserisci il nome della materia\n");
            fgets(mat, 50, stdin);

            ins_materie(&file, nome, mat);
            crea_file_materie(&file, nome, path, extention, arrey_mat);
            Menu = menu();
            break;
        case 5:
            return 1;
            break;
        default:
            printf("Valore non validi\n");
            break;
        }
    }

    if(file != NULL){
        fclose(file);
    }
    return 0;
}

int menu(){
    int input;
    printf("Benvenuto, cosa vuoi fare?\n");
    printf("Per aggiungere una materia: 1\n");
    //printf("Per ossevare le materie: 2\n");
    printf("Esci: 5\n");
    scanf("%d", &input);
    fgetc(stdin);
    return input;
}