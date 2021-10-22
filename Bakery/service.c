//
// Created by Andrei on 3/7/2021.
//

#include <stdlib.h>
#include "repo.c"
#include "header files/service.h"

char redo_history[100][50];
char undo_history[100][50];
int history_pos = -1;

void add_default_materials() {
    add(0, "faina", "Profi", 3, 200321);
    add(1, "lapte", "Profi", 4, 210321);
    add(2, "sare", "Auchan", 1, 210421);
    add(3, "cartofi", "Auchan", 6, 210221);
    add(4, "zahar", "MegaImage", 2, 210421);
    add(5, "seminte", "MegaImage", 8, 80421);
    add(6, "faina", "MegaImage", 1, 110321);
    add(7, "apa", "Profi", 20, 80423);
    add(8, "grau", "Auchan", 3, 90421);
    add(9, "faina", "MegaImage", 8, 120522);

    //clear_history();
}

int validate_cmd_add_update(char cmd[]) {
    int count = 0;
    for (int i = 0; i < strlen(cmd); i++) if (cmd[i] == ' ') count++;
    if (count == 4) return 1;
    return 0;
}

int validate_cmd_update_2(char cmd[]) {
    int count = 0;
    for (int i = 0; i < strlen(cmd); i++) if (cmd[i] == ' ') count++;
    if (count == 3) return 1;
    return 0;
}

int validate_cmd_remove_search(char cmd[]) {
    int count = 0;
    for (int i = 0; i < strlen(cmd); i++) if (cmd[i] == ' ') count++;
    if (count == 1) return 1;
    return 0;
}

int validate_cmd_search_supplier(char cmd[]) {
    int count = 0;
    for (int i = 0; i < strlen(cmd); i++) if (cmd[i] == ' ') count++;
    if (count == 2) return 1;
    return 0;
}

int validate_add(char name[], char supplier[], int exp_date) {
    for (int i = 0; i < materials_amount(); i++) {
        if (strcmp(getName(materials[i]), name) == 0 && strcmp(getSupplier(materials[i]), supplier) == 0 &&
            getExpDate(materials[i]) == exp_date)
            return i;
    }
    return -1;
}

void add_material(char cmd[]) {
    if (validate_cmd_add_update(cmd) == 0) {
        print_error("command");
        return;
    }
    char name[50], supplier[50];
    int quantity, exp_date;

    int i = 2;
    while (cmd[i] != ' ') {
        name[i - 2] = cmd[i];
        i++;
    }
    name[i - 2] = NULL;

    int poz = 0;
    i++;
    while (cmd[i] != ' ') {
        supplier[poz++] = cmd[i];
        i++;
    }
    printf("\n");
    supplier[poz] = NULL;

    poz = 0;
    i++;
    char str[100];
    while (cmd[i] != ' ') {
        str[poz] = cmd[i];
        i++;
        poz++;
    }
    quantity = atoi(str);

    poz = 0;
    i++;
    str[0] = '\0';
    while (cmd[i] != NULL) {
        str[poz++] = cmd[i];
        i++;
    }
    exp_date = atoi(str);

    if (validate_add(name, supplier, exp_date) == -1) {
        add(materials_amount(), name, supplier, quantity, exp_date);

        char str2[50];
        sprintf(str2, "%d %s %s %d %d1", materials_amount()-1, name, supplier, quantity, exp_date);
        strcpy(redo_history[history_pos + 1], str2);

        char str1[50];
        sprintf(str1, "%d2", materials_amount()-1);
        strcpy(undo_history[history_pos + 1], str1);

        history_pos++;
    } else materials[validate_add(name, supplier, exp_date)]->quantity += quantity;
}


void remove_material(char cmd[]) {
    if (validate_cmd_remove_search(cmd) == 0) {
        print_error("command");
        return;
    }
    for (int i = 0; i < strlen(cmd); i++) {
        cmd[i] = cmd[i + 2];
    }
    cmd[strlen(cmd) - 1] = 0;

    int position = 0;
    int ok = 0;
    for (int i = 0; i < materials_amount(); i++)
        if (strcmp(getName(materials[i]), cmd) == 0) {
            ok = 1;
            destroy(i);
            position = i;
            break;
        }
    if (ok == 0) print_error("search");
    else {

//        char name[50], supplier[50];
//        strcpy(name, getName(materials[position]));
//        strcpy(supplier, getSupplier(materials[position]));
//        int quantity = getQuantity(materials[position]), exp_date = getExpDate(materials[position]);
//
//        char str2[50];
//        sprintf(str2, "%d2", position);
//        strcpy(redo_history[history_pos + 1], str2);
//
//        char str1[50];
//        sprintf(str1, "%d %s %s %d %d1", position, name, supplier, quantity, exp_date);
//        strcpy(undo_history[history_pos + 1], str1);

        history_pos++;
    }
}


int update_material(char cmd[]) {
    if (validate_cmd_add_update(cmd) == 0) {
        print_error("command");
        return 0;
    }
    char name[50], supplier[50];
    int quantity, exp_date;

    int i = 2;
    while (cmd[i] != ' ') {
        name[i - 2] = cmd[i];
        i++;
    }
    name[i - 2] = NULL;

    int poz = 0;
    i++;
    while (cmd[i] != ' ') {
        supplier[poz++] = cmd[i];
        i++;
    }
    printf("\n");
    supplier[poz] = NULL;

    poz = 0;
    i++;
    char str[1000];
    while (cmd[i] != ' ') {
        str[poz] = cmd[i];
        i++;
        poz++;
    }
    quantity = atoi(str);

    poz = 0;
    i++;
    str[0] = '\0';
    while (cmd[i] != NULL) {
        str[poz++] = cmd[i];
        i++;
    }
    exp_date = atoi(str);

//    printf("%d\n", validate_add(name, supplier, exp_date));
    int pos = validate_add(name, supplier, exp_date);
    if (pos == -1) {
        print_error("update");
        return -1;
    } else return pos;
}

void update_material_2(char cmd[], int pos) {
    if (validate_cmd_update_2(cmd) == 0) {
        print_error("command");
        return;
    }
    char name[50], supplier[50];
    int quantity, exp_date;

    int i = 0;
    while (cmd[i] != ' ') {
        name[i] = cmd[i];
        i++;
    }
    name[i] = NULL;

    int poz = 0;
    i++;
    while (cmd[i] != ' ') {
        supplier[poz++] = cmd[i];
        i++;
    }
    printf("\n");
    supplier[poz] = NULL;

    poz = 0;
    i++;
    char str[1000];
    while (cmd[i] != ' ') {
        str[poz] = cmd[i];
        i++;
        poz++;
    }
    quantity = atoi(str);

    poz = 0;
    i++;
    str[0] = '\0';
    while (cmd[i] != NULL) {
        str[poz++] = cmd[i];
        i++;
    }
    exp_date = atoi(str);

    update(pos, name, supplier, exp_date, quantity);

    char str2[50];
    sprintf(str2, "%d %s %s %d %d3", pos, name, supplier, quantity, exp_date);
    strcpy(redo_history[history_pos + 1], str2);

    char str1[50];
    sprintf(str1, "%d %s %s %d %d3", pos, getName(materials[pos]), getSupplier(materials[pos]),
            getQuantity(materials[pos]), getExpDate(materials[pos]));
    strcpy(undo_history[history_pos + 1], str1);

    history_pos++;
}

int check_expired(int i) {
    int date = getExpDate(materials[i]);
    int year = date % 100 * 365;
    int month = (date / 100) % 100 * 30;
    int day = date / 10000;
    if (year + month + day > CURRENT_DATE) return 1;
    return 0;
}

void search_material(char cmd[]) {
    if (validate_cmd_remove_search(cmd) == 0) {
        print_error("command");
        return;
    }
    for (int i = 0; i < strlen(cmd); i++) {
        cmd[i] = cmd[i + 2];
    }
    cmd[strlen(cmd) - 1] = 0;

    char str[1000];
    int ok = 0;
    for (int i = 0; i < materials_amount(); i++) {
        if (strstr(getName(materials[i]), cmd) != NULL && check_expired(i) == 1) {
            toString(*materials[i], str);
            print_material(str);
            ok = 1;
        }
    }
    if (ok == 0) print_error("search");
}

void bubble_sort(int array[]) {
//    for (int i = 0; array[i]; i++) printf("%d ", array[i]);

    char *tmp;
    int i, j;
    for (int i = 0; array[i]; i++) {
        for (int j = 0; array[j]; j++) {
            if (strcmp(getSupplier(materials[array[i] - 1]), getSupplier(materials[array[j] - 1])) > 0) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
//    for (int i = 0; array[i]; i++) printf("%d ", array[i]);

    char str[1000];
    for (i = 0; array[i]; i++) {
        toString(*materials[array[i] - 1], str);
        print_material(str);
    }
//        printf("%s\n", getName(&materials[array[i]-1]));
}

void extra_function(char cmd[]) {
    for (int i = 0; i < strlen(cmd); i++) {
        cmd[i] = cmd[i + 2];
    }
    cmd[strlen(cmd) - 1] = 0;

    int poz = 0;
    int array[100];
    int ok = 0;
    for (int i = 0; i < materials_amount(); i++) {
        if (strstr(getName(materials[i]), cmd) != NULL) {
            array[poz++] = i + 1;
            ok = 1;
        }
    }
    array[poz] = 0;
    if (ok == 0) {
        print_error("search");
        return;
    }

    bubble_sort(array);
}

void search_supplier(char cmd[]) {
    if (validate_cmd_search_supplier(cmd) == 0) {
        print_error("command");
        return;
    }
    char supplier[1000];
    int i = 2;
    while (cmd[i] != ' ') {
        supplier[i - 2] = cmd[i];
        i++;
    }
    supplier[i - 2] = NULL;

    int poz = 0;
    i++;
    char str[1000];
    while (cmd[i] != ' ') {
        str[poz] = cmd[i];
        i++;
        poz++;
    }
    int quantity = atoi(str);

    int ok = 0;
    for (int i = 0; i < materials_amount(); i++) {
        if (strstr(getSupplier(materials[i]), supplier) != NULL && quantity >= getQuantity(materials[i])) {
            toString(*materials[i], str);
            print_material(str);
            ok = 1;
        }
    }
    if (ok == 0) print_error("search");
}

void undo() {
    if (history_pos < 0) print_error("undo");

<<<<<<< HEAD
    printf("--=%s=--", undo_history[history_pos]);

    int fct_type = undo_history[history_pos][strlen(undo_history[history_pos]) - 1];
    undo_history[history_pos][strlen(undo_history[history_pos]) - 1] = '\0';

    if (fct_type == '2') {
        int pos, quantity, exp_date;
        char name[50], supplier[50];
        sscanf(undo_history[history_pos], "%d %s %s %d %d", &pos, name, supplier, &quantity, &exp_date);
        add(pos, name, supplier, quantity, exp_date);
    }
    if (fct_type == '1') {
        int pos;
        sscanf(undo_history[history_pos], "%d2", &pos);
        destroy(pos);
    }
    if (fct_type == '3') {
        int pos, quantity, exp_date;
        char name[50], supplier[50];
        sscanf(undo_history[history_pos], "%d %s %s %d %d3", &pos, name, supplier, &quantity, &exp_date);
        update(pos, name, supplier, quantity, exp_date);
    }

    history_pos--;
=======
//
    if(history_pos < 0) print_error("undo");
        else history_pos--;
//
//    printf("--=%s=--", undo_history[history_pos]);
//
//    if (undo_history[history_pos][0] == '1') add_material(undo_history[history_pos]);
//    if (undo_history[history_pos][0] == '3') {remove_material(undo_history[history_pos]);}
//    if (undo_history[history_pos][0] == '4') {
//        char cmd[50];
//        strcpy(cmd, undo_history[history_pos]);
//
//        for (int i = 0; i < strlen(cmd); i++) {
//            cmd[i] = cmd[i + 2];
//        }
//        cmd[strlen(cmd) - 1] = 0;
//
//        printf("\n%s\n", cmd);
//
//        char name[50], supplier[50];
//        int quantity, exp_date, position;
//
//        int i = 0;
//        int poz = 0;
//        char str[100];
//        while (cmd[i] != ' ') str[poz++] = cmd[i++];
//        position = atoi(str);
//
//        poz = 0;
//        while (cmd[i] != ' ') name[poz++] = cmd[i++];
//        name[i - 2] = NULL;
//
//        poz = 0;
//        i++;
//        while (cmd[i] != ' ') supplier[poz++] = cmd[i++];
//        printf("\n");
//        supplier[poz] = NULL;
//
//        poz = 0;
//        i++;
//        str[0] = '\0';
//        while (cmd[i] != ' ') str[poz++] = cmd[i++];
//        quantity = atoi(str);
//
//        poz = 0;
//        i++;
//        str[0] = '\0';
//        while (cmd[i] != NULL) str[poz++] = cmd[i++];
//        exp_date = atoi(str);
//
//        printf("%d %s %s %d %d", position, name, supplier, quantity, exp_date);
//    }
//
//    history_pos--;
>>>>>>> f4955b3360e3823a4a0ea0c9090359838db87237
}

void redo() {
    if(history_pos < 0) print_error("redo");
    else history_pos--;
}