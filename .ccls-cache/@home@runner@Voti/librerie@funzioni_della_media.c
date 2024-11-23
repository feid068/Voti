//calcolo media ponderata singola materia
void media_ponderata(float voti[], float pesi[], float *Media,int size){
    float nominatore = 0;
    float denominatore = 0;
    float media;
    for (int i = 0; i < size; i++){
        nominatore += voti[i]*pesi[i];
        denominatore += pesi[i];
        media = nominatore/denominatore;
    }
    for (int i = 0; i < sizeof(Media)/sizeof(Media[0]); i++){
        Media[i] = media;
    }
}