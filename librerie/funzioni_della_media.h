#define MAX_SIZE 15

typedef struct{
    char tipo[50][MAX_SIZE];
    float voti[MAX_SIZE];
    float pesi[MAX_SIZE];
    float media;
    int linea;
}StudentVote;

//calcolo media ponderata singola materia
float media_ponderata(StudentVote *StudentVote, int size, int n_struct);
//calcola la media normale
float media_tot(StudentVote *StudentVote);
