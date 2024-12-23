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

int menu();

int main(){
    FILE *file, *temp;

    StudentVote VOti[15];

    int Menu= menu();
    while (Menu != 8){
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
            char tipo[50];
            printf("In che materia vuoi aggiungere i voti?\n");
            prende_nomi(&file, nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            path(&file, nome, Path, extention, arrey_mat);
            int a = 0;
            scanf("%d", &a);
            printf("che tipo di voto è\n");
            scanf("%s", tipo);
            printf("Inserisci il voto\n");
            scanf("%f", &Voti);
            printf("Inserisci il peso\n");
            scanf("%f", &Pesi);
            a = a - 1;
            int line = righe_in_file(&file, arrey_mat[a]);
            ins_voti(&file, arrey_mat[a], Voti, Pesi, tipo, line);
            system("clear");
            Menu = menu();
            break;
        case 4:
            int b = 0;
            prende_nomi(&file, nome,arrey_mat);
            printf("Che materia vuoi guardare?\n");
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            
            path(&file, nome, Path, extention, arrey_mat);
            scanf("%d", &b);
            if(b < 0|| b > 14){
                printf("valori non validi\n");
                return 1;
            }
            b = b - 1;

            prendi_voti(VOti, &file, arrey_mat[b]);
            
            for(int i = 0; i < 15; i++){
                if(VOti[i].voti[i] != 0){
                    printf("%.2f al %.2f%%\n", VOti[i].voti[i], VOti[i].pesi[i]);
                }else{
                    printf("Voti finiti in questa materia\n");
                    break;
                }
            }
            sleep(5);
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
            sleep(5);
            system("clear");
            Menu = menu();
            break;
        case 6:
            int c = 0;//selziona la materia
            int d = 0;//seleziona il voto
            char temp_arr_mat2[MAX_SIZE][50] = {"\0"};

            printf("In che materia vuoi togliere i voti?\n");
            
            prende_nomi(&file, nome,arrey_mat);
            for(int i = 0; i < 15; i++){
                if(strlen(arrey_mat[i]) > 1){
                    printf("%s: %d\n",arrey_mat[i],i+1);
                }
            }
            scanf("%d", &c);
            c = c - 1;
            
            strcpy(temp_arr_mat2[c], arrey_mat[c]);
            path(&file, nome, Path, extention, arrey_mat);

            prendi_voti(VOti, &file, arrey_mat[c]);

            for (int i = 0; i < MAX_SIZE; i++){
                if(VOti[i].voti[i] != 0){
                    printf("%.2f  %d\n", VOti[i].voti[i], i+1);
                }
            }
            printf("Che voto vuoi eliminare?\n");
            
            scanf("%d", &d);
            d = d - 1;
            
            char VOTO[255];
            sprintf(VOTO, "%s,%.2f,%.2f,%d", VOti[d].tipo,VOti[d].voti[d],VOti[d].pesi[d],VOti[d].linea);

            int collonna = 4;
            if(elimina_voto(&file, &temp, VOTO, temp_arr_mat2[c], extention, Path) != 0){
                return 1;
            }
            file = fopen(arrey_mat[c], "r");
            char buffer[255];
            int i = 1;
            char ai[15];
            int current_line = 1;
            while (fgets(buffer, sizeof(buffer), file)){
                sprintf(ai, "%d", i);
                modifica_valore_csv(arrey_mat[c],current_line,4,ai);
                i++;
                current_line++;
            }
            if(file != NULL){
                fclose(file);
            }

            printf("Voto eliminato!\n");

            for (int i = 0; i < MAX_SIZE; i++){
                strcpy(arrey_mat[i], "\0");
                VOti[i].voti[i] = 0;
            }
            sleep(1);
            system("clear");
            Menu = menu();
            break;
        case 7:
            break;
        case 8:
            return 0;
            break;
        default:
            Menu = 8;
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
    printf("per modificare un voto o peso: 7\n");
    printf("Esci: 8\n");
    scanf("%d", &input);
    fgetc(stdin);
    return input;
}