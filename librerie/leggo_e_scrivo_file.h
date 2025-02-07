#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 15

//crea un file
void creaFile(char nome[]);
//cancella un file
void eliminaFile(char nome[]);
//prende i valori in un file e li mette in una lista
void crea_file_materie(char nome[], char path[], char extention[],char arrey_mat[15][1024]);
//prende i voti e li inserisce nel file adeguato
void ins_voti(char fileName[], float voto, float peso, char tipo[], int riga);
//prende i le materie e le inserisce nel file adeguato
void ins_materie(char fileName[], char input[]);
//prende i nomi all'interno di un file
void prende_nomi(char nome[], char arrey_mat[15][1024]);
//prende i nome della materia e aiunge una directori e una estensione
void path(char nome[], char path[], char extention[],char arrey_mat[15][1024]);
//elimina una materia
int elimina_mat(char fileName[], int delete_line);
//crea una cartella
int make_dir(char *folderName);
//prende i voti dal file
int prendi_voti(StudentVote *StudentVote, char fileName[], int n_struct);
//cambia un valore in un file .csv
void modifica_valore_csv(const char *nome_file, int riga, int colonna, const char *nuovo_valore);
//prende il numero di linee in un file
int righe_in_file(char nome_file[]);
//elimina un voto e il suo peso
int elimina_voto(int DeliteLine, char file_Name[],char extention[], char path[]);
