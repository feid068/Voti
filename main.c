#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"


# define MAX_SIZE 15

char nome[] = "materie.csv";
char Path[] = "materie/";
char extention[] = ".csv";
char arrey_mat[MAX_SIZE][1024] = {"\0"};
char temp_arrey_mat[MAX_SIZE][1024] = {"\0"};
int a = 0;
float Media_tot = 0;

int menu(float Media_tot);
float media();;

int main(){
    FILE *file;

    StudentVote VOti[MAX_SIZE] = {0};

    int Menu = 0;

    while (Menu != 8){
        Media_tot = media(VOti, nome, Path, extention, arrey_mat);
        Menu = menu(Media_tot);
        switch (Menu){
        case 1:
            char mat[50];
            printf("Inserisci il nome della materia\n");
            fgets(mat, 50, stdin);

            ins_materie(nome, mat);
            crea_file_materie(nome, Path, extention, arrey_mat);

            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");
                printf("%s\n", arrey_mat[i]);
            }
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 2:
            int count = 0;
            prende_nomi(nome,arrey_mat);
            path(nome, Path, extention, temp_arrey_mat);
            for (size_t i = 0; i < MAX_SIZE; i++){
                if(strlen(temp_arrey_mat[i]) > 1){
                    count++;
                }
            }
            
            for (int i = 0; i < count; i++){
                prendi_voti(VOti, temp_arrey_mat[i], i);
            }

            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s ", arrey_mat[i]);
                    printf(" %.2f\n", media_ponderata(VOti, MAX_SIZE, i));
                }
            }
            sleep(2);
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 3:
            float Voti = 0;
            float Pesi = 0;
            char tipo[50];
            a = 0;
            
            printf("In che materia vuoi aggiungere i voti?\n");
            
            prende_nomi(nome,arrey_mat);
            
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            
            path(nome, Path, extention, arrey_mat);
            
            scanf("%d", &a);
            printf("che tipo di voto è\n");
            scanf("%s", tipo);
            printf("Inserisci il voto\n");
            scanf("%f", &Voti);
            printf("Inserisci il peso\n");
            scanf("%f", &Pesi);
            
            a = a - 1;
            
            int line = righe_in_file(arrey_mat[a]);
            if(line == 1000000000){
                return 1;
            }
            
            ins_voti(arrey_mat[a], Voti, Pesi, tipo, line);
            
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 4:
            a = 0;
            
            printf("Che materia vuoi guardare?\n");
            
            prende_nomi(nome,arrey_mat);
            
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            
            path(nome, Path, extention, arrey_mat);
            
            scanf("%d", &a);
            
            if(a < 0|| a > 14){
                printf("valori non validi\n");
                return 1;
            }

            a--;

            prendi_voti(VOti, arrey_mat[a], a);
            
            for(int i = 0; i < 15; i++){
                if(VOti[a].voti[i] != 0){
                    printf("%.2f al %.2f%%\n", VOti[a].voti[i], VOti[a].pesi[i]);
                }else{
                    printf("Voti finiti in questa materia\n");
                    break;
                }
            }

            sleep(5);
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 5:
            a = 0;
            char path_mat[255];
            char temp_arr_mat[MAX_SIZE][1024] = {"\0"};
            
            printf("Che materia vuoi eliminare?\n");
            
            prende_nomi(nome,temp_arr_mat);
            
            for(int i = 0; i < MAX_SIZE; i++){
                if(strlen(temp_arr_mat[i]) > 1){
                    printf("%s: %d\n",temp_arr_mat[i],i+1);
                }
            }
            
            scanf("%d", &a);
            
            elimina_mat(nome, a);

            a--;

            for (int i = 0; i < MAX_SIZE; i++){
                if(strlen(temp_arr_mat[i]) > 1){
                    snprintf(arrey_mat[i], 1024, "%s%s%s", Path, temp_arr_mat[i], extention);
                }
            }
            
            eliminaFile(arrey_mat[a]);
            
            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");  
                strcpy(temp_arr_mat[i], "\0"); 
            }
            
            printf("Materia eliminata: %s\n", temp_arr_mat[a]);
            
            sleep(5);
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 6:
            a = 0;
            int d = 0;//seleziona il voto
            char temp_arr_mat2[MAX_SIZE][50] = {"\0"};

            printf("In che materia vuoi togliere i voti?\n");
            
            prende_nomi(nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            scanf("%d", &a);
            a--;
            
            strcpy(temp_arr_mat2[a], arrey_mat[a]);
            path(nome, Path, extention, arrey_mat);

            prendi_voti(VOti, arrey_mat[a], a);

            for (int i = 0; i < MAX_SIZE; i++){
                if(VOti[a].voti[i] != 0){
                    printf("%.2f  %d\n", VOti[a].voti[i], i+1);
                }
            }
            printf("Che voto vuoi eliminare?\n");
            
            scanf("%d", &d);

            if(elimina_voto(d, temp_arr_mat2[a], extention, Path) != 0){
                return 1;
            }

            file = fopen(arrey_mat[a], "r");

            int collonna = 4;
            char buffer[255];
            int i = 1;
            char ai[15];
            int current_line = 1;

            while (fgets(buffer, sizeof(buffer), file)){
                sprintf(ai, "%d", i);
                modifica_valore_csv(arrey_mat[a],current_line,4,ai);
                i++;
                current_line++;
            }

            if(file != NULL){
                fclose(file);
            }

            printf("Voto eliminato!\n");

            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");
            }
            sleep(1);
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 7:
            a = 0;
            char nuovo_valore[50];
            int c = 0;
            int b = 0;

            printf("In che materia voui cambiare voto,peso,tipo?\n");

            prende_nomi(nome,arrey_mat);

            for(int i = 0; i < 15; i++){ 
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s  %d\n",arrey_mat[i], i+1);
                }
            }

            //Decidi in quale materia cambiare voto,peso,tipo
            scanf("%d", &a);
            a--;

            printf("Cosa vuoi modificare?\n");
            printf("Voto 1\n");
            printf("Peso 2\n");
            printf("Tipo 3\n");
            
            scanf("%d", &b);
            
            switch (b){
            case 1:
                path(nome, Path, extention, arrey_mat);

                printf("Che voto vuoi cambiare?\n");

                prendi_voti(VOti, arrey_mat[a], a);

                for (int i = 0; i < MAX_SIZE; i++){
                    if(VOti[a].voti[i] != 0){
                        printf("%.2f  %d\n", VOti[a].voti[i], i+1);
                    }
                }

                scanf("%d", &c);

                printf("Inserisci il nuovo valore!\n");
                
                scanf("%s", nuovo_valore);

                modifica_valore_csv(arrey_mat[a], c, 2, nuovo_valore);

                printf("Valore cambiato\n");

                break;
            case 2:
                path(nome, Path, extention, arrey_mat);

                printf("Che peso vuoi cambiare?\n");

                prendi_voti(VOti, arrey_mat[a], a);

                for (int i = 0; i < MAX_SIZE; i++){
                    if(VOti[a].pesi[i] != 0){
                        printf("%.2f  %d\n", VOti[a].pesi[i], i+1);
                    }
                }

                scanf("%d", &c);

                printf("Inserisci il nuovo valore!\n");
                scanf("%s", nuovo_valore);

                modifica_valore_csv(arrey_mat[a], c, 3, nuovo_valore);

                printf("Valore cambiato\n");

                break;
            case 3:
                path(nome, Path, extention, arrey_mat);

                printf("Che tipo di tipo vuoi cambiare?\n");

                prendi_voti(VOti, arrey_mat[a], a);

                for (int i = 0; i < MAX_SIZE; i++){
                    if(strlen(VOti[a].tipo[i]) > 1){
                        printf("%s  %d", VOti[a].tipo[i], i+1);
                    }
                }

                printf("\n");

                scanf("%d", &c);

                printf("Inserisci il nuovo valore!\n");
                scanf("%s", nuovo_valore);

                printf("%s", nuovo_valore);
                
                modifica_valore_csv(arrey_mat[a], c, 1, nuovo_valore);

                printf("Valore cambiato\n");

                break;
            default:
                printf("Valore non valido!\n");
                break;
            }

            sleep(2);
            system("clear");
            Media_tot = media(VOti, nome, Path, extention, arrey_mat);
            Menu = menu(Media_tot);
            break;
        case 8:
            return 0;
            break;
        default:
            Menu = 8;
            printf("Valore non validi\n");
            break;
        }
        for (int i = 0; i < MAX_SIZE; i++){
            strcpy(arrey_mat[i], "\0"); 
        }
    }
    return 0;
}

int menu(float Media_tot){
    printf("Media totale: %.2f\n", Media_tot);
    int input;
    printf("Benvenuto, cosa vuoi fare?\n");
    printf("Per aggiungere una materia: 1\n");
    printf("Per ossevare le materie: 2\n");
    printf("Per aggiungere un voto: 3\n");
    printf("Per guardale i voti di una materia: 4\n");
    printf("Per eliminare una materia: 5\n");
    printf("Per eliminare un voto: 6\n");
    printf("per modificare un voto,peso,tipo: 7\n");
    printf("Esci: 8\n");
    scanf("%d", &input);
    fgetc(stdin);
    return input;
}

float media(StudentVote *VOti, char *nome, char *Path, char *extention, char arrey_mat[MAX_SIZE][1024]){
    FILE *file;
    
    float media_TOT = 0;

    prende_nomi(nome, arrey_mat);
    path(nome, Path, extention, arrey_mat);

    int count = 0;

    for (size_t i = 0; i < MAX_SIZE; i++){
        if(strlen(arrey_mat[i]) > 1){
            count++;
        }
    }

    for (int i = 0; i < count; i++){
        prendi_voti(VOti, arrey_mat[i], i);
        media_ponderata(VOti, MAX_SIZE, i);
    }

    media_TOT = media_tot(VOti);

    return media_TOT;
}