#include <stdio.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"

# define MAX_SIZE 25

float voti[MAX_SIZE];
float pesi[MAX_SIZE];
float media[MAX_SIZE];
//char nome[]="materie/eletronica.txt";

int main(){
    FILE *file;
    
    if(file != NULL){
        fclose(file);
    }
    return 0;
}