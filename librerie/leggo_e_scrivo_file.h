#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//crea un file
void creaFile(FILE **file, char nome[]);
//cancella un file
void eliminaFile(FILE **file, char nome[]);
//prende degli input e li inserisce in un file
void ins_materie(FILE **file, char fileName[], char input[]);
//prende i valori in un file e li mette in una lista
void crea_file_materie(FILE **file, char fileName[], char path[], char extention[]);
//prende gli input e li mette in un file con il nome della materia
void ins_voti(FILE **file, char fileName[],  int voto, int peso);
//prende i voti dal file e li mette nelle corrispettive liste
void prende_i_voti(FILE **file, char fileName[], float *voti, float *pesi);
