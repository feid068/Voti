#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void creaFile(FILE **file, char nome[]){
    if(*file = fopen(nome, "r")){
        printf("file gia creato");
    }else if(*file = fopen(nome, "w")){
        printf("file cerato\n");
    }
}

void eliminaFile(FILE **file, char nome[]){
    if(*file = fopen(nome, "r")){
        remove(nome);
        printf("file eliminato\n");
    }else{
        printf("file gia eliminato\n");
    }
}

void crea_file_materie(FILE **file, char nome[], char path[], char extention[]){
    if(file == NULL){
        printf("Inpossibile aprire il file\n");
    }else{
        *file = fopen(nome, "r");
        char buffer[255];

        char result[1024];
        while (fgets(buffer, sizeof(buffer), *file) != NULL){
            
            snprintf(result, sizeof(result), "%s%s%s", path, buffer, extention);
            fopen(result, "w");
        }
    }
}

void prende_i_voti(FILE **file, char nome[], float *voti, float *pesi){
    if(*file = fopen(nome, "r")){
        char buffer[50];
        char *endptr;

        int i;
        while (fgets(buffer, sizeof(buffer), *file) != NULL){
            buffer[strcspn(buffer, "\n")] = '\0';
            voti[i] = strtof(buffer, NULL);
            
            if (voti[i] == 0 && buffer[0] != '0') {  // Se non è un numero valido
                printf("Errore nella lettura del voto alla linea %d\n", i+1);
                break;  // Esce dal ciclo se c'è un errore
            }
            if (fgets(buffer, sizeof(buffer), *file) != NULL) {
                pesi[i] = strtof(buffer, NULL);
                
                if (pesi[i] == 0 && buffer[0] != '0') {  // Se non è un numero valido
                    printf("Errore nella lettura del peso alla linea %d\n", i+1);
                    break;  // Esce dal ciclo se c'è un errore
                }
            }
            i++;
        }
    }else{
        perror("Impossibile aprire il file");
    }
}

void input(char *input){
    fgets(input, sizeof(input),stdin);
}

void ins(FILE **file, char fileName[], char input[]){
    if (*file = fopen(fileName, "r")){
        *file = fopen(fileName, "a");
        fprintf(*file, input); 
    }else{
        perror("impossibile aprire il file");
    }
}