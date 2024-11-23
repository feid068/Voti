#include <stdio.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"

# define MAX_SIZE 25

float voti[MAX_SIZE];
float pesi[MAX_SIZE];
float media[MAX_SIZE];
char nome[] = "materie/eletronica.txt";

int main(){
    FILE *file;
    char a[50];

    input(a);
    ins(&file, "materie.txt", a);

    //prende_i_voti(&file, nome, voti, pesi);
    //int size = sizeof(voti)/sizeof(voti[0]); 
    //media_ponderata(voti, pesi, media, size);
//for (int i = 0; i < sizeof(media)/sizeof(media[0]); i++){
        //printf("La media è %.2f\n", media[i]);
    //}
    
    if(file != NULL){
        fclose(file);
    }
    return 0;
}