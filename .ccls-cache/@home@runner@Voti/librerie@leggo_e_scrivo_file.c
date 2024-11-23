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

void ins_materie(FILE **file, char fileName[], char input[]){
    if (*file = fopen(fileName, "r")){
        *file = fopen(fileName, "a");
        fprintf(*file, input); 
    }else{
        perror("impossibile aprire il file");
    }
}

void crea_file_materie(FILE **file, char fileName[], char path[], char extention[]){
    if(file == NULL){
        printf("Inpossibile aprire il file\n");
    }else{
        *file = fopen(fileName, "r");
        char buffer[255];

        char result[1024];
        while (fgets(buffer, sizeof(buffer), *file) != NULL){
            buffer[strcspn(buffer, "\n")] = '\0';
            snprintf(result, sizeof(result), "%s%s%s", path, buffer, extention);
            fopen(result, "w");
        }
    }
}

void ins_voti(FILE **file, char fileName[], int voto, int peso){
    if(voto > 10 || voto < 0 && peso >100 || peso < 0){
        printf("Valori non validi\n");
    }else{
        if(*file = fopen(fileName, "r")){
            *file = fopen(fileName, "a");
            fprintf(*file, "%d\n",voto);
            fprintf(*file, "%d\n",peso); 
        }   else{
            perror("Impossibile aprire il file");
        }
    }
}

void prende_i_voti(FILE **file, char fileName[], float *voti, float *pesi){
    if(*file = fopen("materie/eletronica.txt", "r")){
        char buffer[50];
        char *endptr;

        int i;
        while (fgets(buffer, sizeof(buffer), *file) != NULL){
            
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