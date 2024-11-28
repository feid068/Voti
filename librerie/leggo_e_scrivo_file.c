#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

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

void crea_file_materie(FILE **file, char nome[], char path[], char extention[],char arrey_mat[15][1024]){
    if((*file = fopen(nome, "r")) != NULL){
        char buffer[255];

        char result[1024];
        int i = 0;
        while (fgets(buffer, sizeof(buffer), *file) != NULL){
            
            buffer[strlen(buffer)-1] = '\0';
            snprintf(result, sizeof(result), "%s%s%s", path, buffer, extention);
            
            if(fopen(result, "r") != NULL){
                if(i < 15){
                    strncpy(arrey_mat[i], result, 1024);
                    arrey_mat[i][1023] = '\0';  // Ensure null termination
                    i++;
                }else{
                    perror("Arrivato al limite di numeri");
                    break;
                }
            }else{
                fopen(result, "w");
            }
        }
    }else{
        perror("Impossibile aprire il file");
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

void ins_voti(FILE **file, char fileName[], float voto, float peso){
    if(voto > 10 || voto < 0 && peso >100 || peso < 0){
        printf("Valori non validi\n");
    }else{
        if(*file = fopen(fileName, "r")){
            *file = fopen(fileName, "a");
            fprintf(*file, "%.2f\n",voto);
            fprintf(*file, "%.2f\n",peso); 
        }else{
            perror("Impossibile aprire il file");
        }
    }
}

void ins_materie(FILE **file, char fileName[], char input[]){
    if ((*file = fopen(fileName, "r")) != NULL){
        char buffer[255];

        bool matDoppia = false;
        while(fgets(buffer, sizeof(buffer), *file) != NULL){
            if(strcasecmp(buffer, input) == 0){
                matDoppia = true;
            }
        }
        //printf("%d\n", matDoppia);
        if(matDoppia == false){
            printf("dentro l' if\n");
            while (fgets(buffer, sizeof(buffer), *file) != NULL){
                *file = fopen(fileName, "a");
                fprintf(*file, input);
                fflush(*file);
                printf("materia aggiunta\b");
            }
       }else{
            printf("Materia doppia\n");}
        matDoppia = false;

    }else{
        perror("impossibile aprire il file");
    }
}