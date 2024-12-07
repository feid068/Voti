#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

void creaFile(FILE **file, char nome[]){
    if(*file = fopen(nome, "r")){
        printf("file gia creato");
        fclose(*file);
    }else if(*file = fopen(nome, "w")){
        printf("file cerato\n");
    }
}

void eliminaFile(FILE **file, char nome[]){
    if(*file = fopen(nome, "r")){
        remove(nome);
        printf("file eliminato\n");
        fclose(*file);
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
        fclose(*file);
    }else{
        perror("Impossibile aprire il file");
    }
}

void prende_i_voti(FILE **file, char *nome, float *voti, float *pesi){
    if((*file = fopen(nome, "r")) != NULL){
        char buffer[50];

        int i = 0;
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
        fclose(*file);
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
            fflush(*file);
            fprintf(*file, "%.2f\n",peso); 
            fflush(*file);
            fclose(*file);
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
                break;
            }
        }
        
        if(matDoppia == false){
            *file = fopen(fileName, "a");
            fprintf(*file, input);
            fflush(*file);
            printf("materia aggiunta\n");
        }else{
            printf("Materia doppia\n");
            matDoppia = false;
        }
        fclose(*file);
    }else{
        perror("impossibile aprire il file");
    }
}

void prende_nomi(FILE **file, char nome[], char arrey_mat[15][1024]){
    if((*file = fopen(nome,"r")) != NULL){
        char buffer[255];

        int i = 0;
        while(fgets(buffer, sizeof(buffer), *file) != NULL){
            buffer[strlen(buffer)-1] = '\0';
            if(i < 15){
                strcpy(arrey_mat[i], buffer);
                arrey_mat[i][1024 - 1] = '\0';
                i++;  
            }else{
                printf("arrey riempito\n");
            }
        }
        fclose(*file);
    }else{
        perror("Impossibile aprire il file");
    }
}

void path(FILE **file,char nome[], char path[], char extention[],char arrey_mat[15][1024]){
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
            }
        }
        fclose(*file);
    }
}

int elimina_mat(FILE **file, FILE **temp, char fileName[], int delete_line){

   char tem_fileName[1024];
   char buffer[2048];

    strcpy(tem_fileName, "temp____");
    strcat(tem_fileName, fileName);

    *file = fopen(fileName, "r");
    *temp = fopen(tem_fileName, "w");

    if(*file == NULL || *temp == NULL){
        perror("Error opening file(s)");
        return 1;
    }

    bool keep_reading = true;
    int current_Line = 1;
    do{
        fgets(buffer, 2048, *file);

        if(feof(*file)) {
            keep_reading = false;
        }else if (current_Line != delete_line){
            fputs(buffer, *temp);
        }
        current_Line++;
        
    }while (keep_reading);
    
    fclose(*file);
    fclose(*temp);

    remove(fileName);
    rename(tem_fileName, fileName);
}

int make_dir(char *folderName){
    if (mkdir(folderName, 0700) == -1) {
        perror("Errore nella creazione della cartella");
        return 1;
    }

    printf("Cartella '%s' creata con successo!\n", folderName);
}

int elimina_voto(FILE **file, FILE **temp, char DeliteLine[], char file_Name[],char extention[], char path[]){
    char tem_file_Name[1024];
    char tem_fileName[1024];
    char buffer[2048];
    char fileName[255];
    char votoDopio[15][255];

    strcpy(tem_file_Name, "temp____");
    strcat(tem_file_Name, file_Name);
    snprintf(fileName, sizeof(fileName), "%s%s%s", path, file_Name, extention);
    snprintf(tem_fileName, sizeof(tem_fileName), "%s%s%s", path, tem_file_Name, extention);

    *file = fopen(fileName, "r");
    *temp = fopen(tem_fileName, "w");

    if(*file == NULL || *temp == NULL){
        perror("Error opening file(s)");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), *file) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, DeliteLine) != 0){
            strcat(buffer, "\n");
            fputs(buffer, *temp);
        }
    }
    
    fclose(*file);
    fclose(*temp);

    remove(fileName);
    rename(tem_fileName, fileName);
}