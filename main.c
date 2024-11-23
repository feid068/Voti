#include <stdio.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"

# define MAX_SIZE 25

float voti[MAX_SIZE];
float pesi[MAX_SIZE];
float media[MAX_SIZE];
char nome[] = "materie.txt";
char path[] = "materie/";
char extention[] = ".txt";

int main(){
    FILE *file;

    //printf("Inserisci il nome della materia che vuoi aggiungere\n");
    //char nomeMat[50];
    //input(nomeMat, 50);
    //ins(&file, nome, nomeMat);
    char a[15][1024];
    crea_file_materie(&file, nome, path, extention, a);
    
    prende_i_voti(&file, a[1], voti, pesi);

    if(file != NULL){
        fclose(file);
    }
    return 0;
}