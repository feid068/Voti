#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

# define MAX_SIZE 15

typedef struct{
    char tipo[50][MAX_SIZE];
    float voti[MAX_SIZE];
    float pesi[MAX_SIZE];
    float media;
    int linea;
}StudentVote;


void creaFile(char nome[]){
    FILE *file;
    if(file = fopen(nome, "r")){
        printf("file gia creato");
        fclose(file);
    }else if(file = fopen(nome, "w")){
        printf("file cerato\n");
    }
}

void eliminaFile(char nome[]){
    FILE *file;
    if(file = fopen(nome, "r")){
        remove(nome);
        printf("file eliminato\n");
        fclose(file);
    }else{
        printf("file gia eliminato\n");
    }
}

void crea_file_materie(char nome[], char path[], char extention[],char arrey_mat[15][1024]){
    FILE *file;
    if((file = fopen(nome, "r")) != NULL){
        char buffer[255];

        char result[1024];
        int i = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL){
            
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
        fclose(file);
    }else{
        perror("Impossibile aprire il file");
    }
}

void ins_voti(char fileName[], float voto, float peso, char tipo[], int riga){//da sistemare:aggiunta linea al fprintf
    FILE *file;
    if(voto > 10 || voto < 0 && peso >100 || peso < 0){
        printf("Valori non validi\n");
    }else{
        if(file = fopen(fileName, "r")){
            file = fopen(fileName, "a");
            fprintf(file, "%s,%.2f,%.2f,%d\n",tipo,voto, peso, (riga+1));
            fflush(file);
            fclose(file);
        }else{
            perror("Impossibile aprire il file");
        }
    }
}

void ins_materie(char fileName[], char input[]){
    FILE *file;
    if ((file = fopen(fileName, "r")) != NULL){
        char buffer[255];

        bool matDoppia = false;
        while(fgets(buffer, sizeof(buffer), file) != NULL){
            if(strcasecmp(buffer, input) == 0){
                matDoppia = true;
                break;
            }
        }
        
        if(matDoppia == false){
            file = fopen(fileName, "a");
            fprintf(file, input);
            fflush(file);
            printf("materia aggiunta\n");
        }else{
            printf("Materia doppia\n");
            matDoppia = false;
        }
        fclose(file);
    }else{
        perror("impossibile aprire il file");
    }
}

void prende_nomi(char nome[], char arrey_mat[15][1024]){
    FILE *file;
    if((file = fopen(nome,"r")) != NULL){
        char buffer[255];

        int i = 0;
        while(fgets(buffer, sizeof(buffer), file) != NULL){
            buffer[strlen(buffer)-1] = '\0';
            if(i < 15){
                strcpy(arrey_mat[i], buffer);
                arrey_mat[i][1024 - 1] = '\0';
                i++;  
            }else{
                printf("arrey riempito\n");
            }
        }
        fclose(file);
    }else{
        perror("Impossibile aprire il file");
    }
}

void path(char nome[], char path[], char extention[],char arrey_mat[15][1024]){
    FILE *file;
    if((file = fopen(nome, "r")) != NULL){
        char buffer[255];

        char result[1024];
        int i = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL){
            
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
        fclose(file);
    }
}

int elimina_mat(char fileName[], int delete_line){
    FILE *file;
    FILE *temp;

   char tem_fileName[1024];
   char buffer[2048];

    strcpy(tem_fileName, "temp____");
    strcat(tem_fileName, fileName);

    file = fopen(fileName, "r");
    temp = fopen(tem_fileName, "w");

    if(file == NULL || temp == NULL){
        perror("Error opening file(s)");
        return 1;
    }

    bool keep_reading = true;
    int current_Line = 1;
    do{
        fgets(buffer, 2048, file);

        if(feof(file)) {
            keep_reading = false;
        }else if (current_Line != delete_line){
            fputs(buffer, temp);
        }
        current_Line++;
        
    }while (keep_reading);
    
    fclose(file);
    fclose(temp);

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

int prendi_voti(StudentVote *StudentVote,char fileName[], int n_struct){
    FILE *file;
    
    file = fopen(fileName, "r");
    if (file == NULL){
        perror("Impossibile aprire il file");
        return 1;
    }

    int read = 0;
    int i = 0;
    do
    {
        //read = 
        fscanf(file,
                        "%49[^,],%f,%f,%d",
                        StudentVote[n_struct].tipo[i],
                        &StudentVote[n_struct].voti[i],
                        &StudentVote[n_struct].pesi[i],
                        &StudentVote[n_struct].linea
                    );
        i++;
    } while (!feof(file));

    fclose(file);
}

void modifica_valore_csv(const char *nome_file, int riga, int colonna, const char *nuovo_valore) {
    FILE *file = fopen(nome_file, "r");  // Apre il file in modalità lettura
    if (file == NULL) {
        perror("Errore nell'aprire il file");
        return;
    }

    char line[1024];
    char temp[1024] = "\0";  // Buffer temporaneo per ogni riga
    int riga_corrente = 1;

    // Prima, leggiamo tutte le righe e salviamo il contenuto in un array temporaneo
    while (fgets(line, sizeof(line), file)) {
        if (riga_corrente == riga) {
            // Se siamo nella riga da modificare
            char campo[255];
            int colonna_corrente = 1;
            char *token = strtok(line, ",");
            int posizione = 0;  // La posizione del token (campo)

            // Copia la riga modificata nel buffer temporaneo
            while (token != NULL) {
                if (colonna_corrente == colonna) {
                    // Sostituisci il valore nella colonna desiderata
                    snprintf(campo, sizeof(campo), "%s", nuovo_valore);
                    strcat(temp, campo);
                } else {
                    // Copia il valore originale se non è la colonna da modificare
                    strcat(temp, token);
                }

                token = strtok(NULL, ",");
                colonna_corrente++;

                // Aggiungi la virgola se non siamo all'ultimo campo
                if (token != NULL) {
                    strcat(temp, ",");
                }
            }
        } else {
            // Copia la riga non modificata
            strcat(temp, line);
        }
        riga_corrente++;
    }

    fclose(file);  // Chiudiamo il file dopo aver letto tutto

    // Ora scriviamo il contenuto modificato nel file
    file = fopen(nome_file, "w");  // Apre il file in modalità scrittura
    if (file == NULL) {
        perror("Errore nell'aprire il file per la scrittura");
        return;
    }

    fprintf(file, "%s", temp);  // Scrive il contenuto modificato nel file

    fclose(file);  // Chiudiamo il file dopo aver scritto
}

int righe_in_file(char nome_file[]){
    FILE *file;
    if((file = fopen(nome_file, "r")) == NULL){
        perror("Impossibile aprire il file:");
        return 1000000000;
    }
    int tot_line = 0;
    char buffer[255];
    while (fgets(buffer, sizeof(buffer), file) != NULL){
        tot_line++;
    }
    return tot_line;
}

int elimina_voto(int DeliteLine, char file_Name[],char extention[], char path[]){
    FILE *file, *temp;
    
    char tem_file_Name[1024];
    char tem_fileName[1024];
    char buffer[2048];
    char fileName[255];
    char votoDopio[15][255];

    strcpy(tem_file_Name, "temp____");
    strcat(tem_file_Name, file_Name);
    snprintf(fileName, sizeof(fileName), "%s%s%s", path, file_Name, extention);
    snprintf(tem_fileName, sizeof(tem_fileName), "%s%s%s", path, tem_file_Name, extention);

    file = fopen(fileName, "r");
    temp = fopen(tem_fileName, "w");

    if(file == NULL || temp == NULL){
        perror("Error opening file(s)");
        return 1;
    }

    bool keep_reading = true;
    int current_line = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        //buffer[strcspn(buffer, "\n")] = '\0';  // Rimuovi il newline alla fine

        // Scrivi la riga nel file temporaneo solo se non è la riga da eliminare
        if (current_line != DeliteLine) {
            fprintf(temp, "%s\n", buffer);
        }
        
        current_line++;
    }
    
    fclose(file);
    fclose(temp);

    remove(fileName);
    rename(tem_fileName, fileName);
}