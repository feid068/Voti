#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//crea un file
void creaFile(FILE **file, char nome[]);
//cancella un file
void eliminaFile(FILE **file, char nome[]);
//prende i valori in un file e li mette in una lista
void crea_file_materie(FILE **file, char nome[], char path[], char extention[]);
//prende i voti dal file e li mette nelle corrispettive liste
void prende_i_voti(FILE **file,char nome[], float *voti, float *pesi);
//prende i voti e li inserisce nel file adeguato
void ins_voti(FILE **file, char fileName[], float voto, float peso);
//prende i le materie e le inserisce nel file adeguato
void ins_materie(FILE **file, char fileName[], char input[]);
