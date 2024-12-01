#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "librerie/funzioni_della_media.h"
#include "librerie/leggo_e_scrivo_file.h"

# define MAX_SIZE 15

float voti[MAX_SIZE] = {0};
float pesi[MAX_SIZE] = {0};
float media[MAX_SIZE];
char nome[] = "materie.txt";
char Path[] = "materie/";
char extention[] = ".txt";
char arrey_mat[MAX_SIZE][1024] = {"\0"};

int menu();

int main(){
    FILE *file, *temp;

    int Menu= menu();
    while (Menu != 7){
        switch (Menu){
        case 1:
            char mat[50];
            printf("Inserisci il nome della materia\n");
            fgets(mat, 50, stdin);

            ins_materie(&file, nome, mat);
            crea_file_materie(&file, nome, Path, extention, arrey_mat);
            system("clear");
            Menu = menu();
            break;
        case 2:
            prende_nomi(&file, nome,arrey_mat);

            for(int i = 0; i < 15; i++){
                
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s\n",arrey_mat[i]);
                }
            }
            sleep(2);
            system("clear");
            Menu = menu();
            break;
        case 3:
            float Voti = 0;
            float Pesi = 0;
            printf("In che materia vuoi aggiungere i voti?\n");
            prende_nomi(&file, nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            path(&file, nome, Path, extention, arrey_mat);
            int a = 0;
            printf("inserisci voto e peso:\n");
            scanf("%d", &a);
            printf("Inserisci il voto\n");
            scanf("%f", &Voti);
            printf("Inserisci il peso\n");
            scanf("%f", &Pesi);
            a = a - 1;
            ins_voti(&file, arrey_mat[a], Voti, Pesi);
            
            system("clear");
            Menu = menu();
            break;
        case 4:
            int b = 0;
            prende_nomi(&file, nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            
            path(&file, nome, Path, extention, arrey_mat);
            printf("Che materia vuoi guardare?\n");
            scanf("%d", &b);
            if(b < 0|| b > 14){
                printf("valori non validi\n");
                return 1;
            }
            b = b - 1;
            prende_i_voti(&file, arrey_mat[b], voti, pesi);
            for(int i = 0; i < 15; i++){
                if(voti[i] != 0){
                    printf("%.2f al %.2f%%\n", voti[i], pesi[i]);
                }else{
                    printf("Nessun voto in questa materia\n");
                    break;
                }
            }
            system("clear");
            Menu = menu();
            break;
        case 5:
            int delete_line = 0;
            char path_mat[255];
            char temp_arr_mat[MAX_SIZE][1024] = {"\0"};
            prende_nomi(&file, nome,temp_arr_mat);
            printf("Che materia vuoi eliminare?\n");
            for(int i = 0; i < 15; i++){
                if(strlen(temp_arr_mat[i]) > 1){
                    printf("%s: %d\n",temp_arr_mat[i],i+1);
                }
            }
            scanf("%d", &delete_line);
            
            elimina_mat(&file, &temp, nome, delete_line);
            
            delete_line = delete_line - 1;

            for (int i = 0; i < MAX_SIZE; i++){
                if(strlen(temp_arr_mat[i]) > 1){
                    snprintf(arrey_mat[i], sizeof(arrey_mat), "%s%s%s", Path, temp_arr_mat[i], extention);
                }
            }
            
            eliminaFile(&file, arrey_mat[delete_line]);
            
            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");   
            }
            
            printf("Materia eliminata: %s\n", temp_arr_mat[delete_line]);
            system("clear");
            Menu = menu();
            break;
        case 6:
            float VOti = 0;
            float PEsi = 0;
            int c = 0;
            char Temp_arr_mat[MAX_SIZE][1024] = {"\0"};
            printf("In che materia vuoi togliere i voti?\n");
            prende_nomi(&file, nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            scanf("%d", &c);
            int d = c;
            c = c - 1;

            path(&file, nome, Path, extention, arrey_mat);

            elimina_voto(&file, &temp, d);

            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");   
            }
            sleep(5);
            system("clear");
            Menu = menu();
            break;
        case 7:
            return 1;
            break;
        default:
            Menu = 7;
            printf("Valore non validi\n");
            break;
        }
    }
    return 0;
}

int menu(){
    int input;
    printf("Benvenuto, cosa vuoi fare?\n");
    printf("Per aggiungere una materia: 1\n");
    printf("Per ossevare le materie: 2\n");
    printf("Per aggiungere un voto: 3\n");
    printf("Per guardale i voti di una materia: 4\n");
    printf("Per eliminare una materia: 5\n");
    printf("Per eliminare un voto: 6\n");
    printf("Esci: 7\n");
    scanf("%d", &input);
    fgetc(stdin);
    return input;
}