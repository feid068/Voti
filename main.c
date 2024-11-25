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
    
    int a = menu();

    while (a != 5){
        switch (a){
        case 1:
            printf("Inserisci il nome della materia\n");
            char mat[50];
            fgets(mat, 50, stdin);
            ins_materie(&file, nome, mat);
            crea_file_materie(&file, nome, path, extention, arrey_mat);
            a = menu();
            break;
        case 2:
            a = menu();
            break;
        case 3:
            a = menu();
            break;
        case 4:
            a = menu();
            break;
        case 5:
            return 1;
            break;
        default:
            printf("Valore non validi\n");
            a = 5;
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
    printf("Per ossevare le materie: 2\n");
    printf("Esci: 5\n");
    scanf("%d", &input);
    fgetc(stdin);
    return input;
}