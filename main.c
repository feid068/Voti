#include <stdio.h>
#include "funzioni_della_media.h"
#include "leggo_e_scrivo_file.h"

float voti[15];
float pesi[15];
float media[1];

int main(){
    FILE *file;
    /*voti[0] = 7.5;
    voti[1] = 7.5;
    voti[2] = 7.75;
    pesi[0] = 100;
    pesi[1] = 50;
    pesi[2] = 100;


    int size = sizeof(voti)/sizeof(voti[0]); 
    media_ponderata(voti, pesi, media, size);

    for (int i = 0; i < sizeof(media)/sizeof(media[0]); i++){
        printf("La media è %.2f\n", media[i]);
    }*/
   creaFile(&file, "dfhd");
    
    if(file != NULL){
        fclose(file);
    }

    return 0;
}