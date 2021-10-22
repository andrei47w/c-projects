//
// Created by Andrei on 3/8/2021.
//

#include "materials.c"
#include "header files/repo.h"

//char redo_history[100][50];
//char undo_history[100][50];
int history_pos = -1;

int materials_amount() {
    return array_size;
}

void add(int pos, char *name, char *supplier, int quantity, int exp_date) {
void clear_history() {
    history_pos = -1;
}

void add(int pos, char name[], char supplier[], int quantity, int exp_date) {
//    char str[50];
//    sprintf(str, "1 %s %s %d %d", name, supplier, quantity, exp_date);
//    strcpy(redo_history[history_pos + 1], str);
//
//    char str1[50];
//    sprintf(str1, "3 %s", name);
//    strcpy(undo_history[history_pos + 1], str1);
//
    history_pos++;

    materials[pos] = createMaterial(name, supplier, quantity, exp_date);
    array_size++;
}

void destroy(int pos) {
//    char str[50];
//    sprintf(str, "3 %s", getName(materials[pos]));
//    strcpy(redo_history[history_pos + 1], str);
//
//    char str1[50];
//    sprintf(str1, "1 %s %s %d %d", getName(materials[pos]), getSupplier(materials[pos]), getQuantity(materials[pos]),
//            getExpDate(materials[pos]));
//    strcpy(undo_history[history_pos + 1], str1);
//
    history_pos++;

    printf("\n%s\n", materials[array_size - 1]->name);
//    for (int j = pos; j <= materials_amount() - 1; j++) materials[j] = materials[j + 1];
//    materials[pos] = materials[array_size-1];
    strcpy(materials[pos]->name, materials[array_size - 1]->name);
    strcpy(materials[pos]->supplier, materials[array_size - 1]->supplier);
    materials[pos]->quantity = materials[array_size - 1]->quantity;
    materials[pos]->exp_date = materials[array_size - 1]->exp_date;
    array_size--;
    printf("%d", array_size);
    printf("\n%s\n", materials[array_size]->name);

    free(materials[array_size]);
}


void update(int pos, char name[], char supplier[], int exp_date, int quantity) {
//    char str[50];
//    sprintf(str, "4 %d %s %s %d %d", pos, name, supplier, quantity, exp_date);
//    strcpy(redo_history[history_pos + 1], str);
//
//    char str1[50];
//    sprintf(str1, "4 %d %s %s %d %d", pos, getName(materials[pos]), getSupplier(materials[pos]),
//            getQuantity(materials[pos]), getExpDate(materials[pos]));
//    strcpy(undo_history[history_pos + 1], str1);
//
    history_pos++;

    materials[pos]->quantity = quantity;
    strcpy(materials[pos]->name, name);
    strcpy(materials[pos]->supplier, supplier);
    materials[pos]->exp_date = exp_date;
}

void freeMaterial(Material* mat)
{
    free(mat->name);
    free(mat->supplier);
    free(mat);
}

void deconstruct() {
    for (int i = array_size - 1; i >= 0; i--) {
        freeMaterial(materials[i]);
//        free(materials[i]);
//        free(&materials[i]->quantity);
//        free(&materials[i]->exp_date);
//        free(materials[i]);
    }

//    for (int j = 0; j < array_size; j++){
//        printf("%s", materials[j]->name);
//        free(materials[j]->name);
//        free(materials[j]->supplier);
//        free(materials[j]->quantity);
//        free(materials[j]->exp_date);
//        free(materials[j]);
//    }
    free(materials);
    array_size = 0;
}

void destroy_default() {
    free(materials[0]);
    free(materials[1]);
    free(materials[2]);
    free(materials[3]);
    free(materials[4]);
    free(materials[5]);
    free(materials[6]);
    free(materials[7]);
    free(materials[8]);
    free(materials[9]);
//    free(materials);

}

