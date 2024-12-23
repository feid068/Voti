#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 15

typedef struct{
    char tipo[50];
    float voti[MAX_SIZE];
    float pesi[MAX_SIZE];
    int linea;
}StudentVote;

//crea un file
void creaFile(FILE **file, char nome[]);
//cancella un file
void eliminaFile(FILE **file, char nome[]);
//prende i valori in un file e li mette in una lista
void crea_file_materie(FILE **file, char nome[], char path[], char extention[],char arrey_mat[15][1024]);
//prende i voti e li inserisce nel file adeguato
void ins_voti(FILE **file, char fileName[], float voto, float peso, char tipo[], int riga);
//prende i le materie e le inserisce nel file adeguato
void ins_materie(FILE **file, char fileName[], char input[]);
//prende i nomi all'interno di un file
void prende_nomi(FILE **file, char nome[], char arrey_mat[15][1024]);
//prende i nome della materia e aiunge una directori e una estensione
void path(FILE **file, char nome[], char path[], char extention[],char arrey_mat[15][1024]);
//elimina una materia
int elimina_mat(FILE **file, FILE **temp, char fileName[], int delete_line);
//crea una cartella
int make_dir(char *folderName);
//elimina un voto e il suo peso
int elimina_voto(FILE **file, FILE **temp, char DeliteLine[], char fileName[],char extention[], char path[]);
//prende i voti dal file
int prendi_voti(StudentVote voti[15], FILE **file, char fileName[]);
//cambia un valore in un file .csv
void modifica_valore_csv(const char *nome_file, int riga, int colonna, const char *nuovo_valore);
//prende il numero di linee in un file
int righe_in_file(FILE **file, char nome_file[]);