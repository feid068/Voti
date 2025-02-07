#include <stdio.h>

#define MAX_SIZE 15

typedef struct{
    char tipo[50][MAX_SIZE];
    float voti[MAX_SIZE];
    float pesi[MAX_SIZE];
    float media;
    int linea;
}StudentVote;

//calcolo media ponderata singola materia
float media_ponderata(StudentVote *StudentVote, int size, int n_struct){
    float nominatore = 0;
    float denominatore = 0;
    float media = 0;
    for (int i = 0; i < size; i++){
        nominatore += StudentVote[n_struct].voti[i]*StudentVote[n_struct].pesi[i];
        denominatore += StudentVote[n_struct].pesi[i];
    }

    StudentVote[n_struct].media = nominatore/denominatore;

    return StudentVote[n_struct].media;
}

float media_tot(StudentVote *StudentVote){//da testare
    float nom = 0;
    float den = 0;
    for (int i = 0; i < MAX_SIZE; i++){
        if(StudentVote[i].media != 0){
            nom += StudentVote[i].media;
            den++;
        }
    }
    float ris = nom/den;
    return ris;
}