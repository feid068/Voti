#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//crea un file
void creaFile(FILE **file, char nome[]);
//cancella un file
void eliminaFile(FILE **file, char nome[]);
//prende i valori in un file e li mette in una lista
void crea_file_materie(FILE **file, char nome[], char path[], char extention[],char arrey_mat[15][1024]);
//prende i voti dal file e li mette nelle corrispettive liste
void prende_i_voti(FILE **file,
char nome[],
float *voti,
float *pesi);
//prende gli input
void input(char input[],int size);
//inserisce gli input in un file
void ins(FILE **file,
char fileName[],
char input[]);
