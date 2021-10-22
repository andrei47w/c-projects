//
// Created by Andrei on 3/7/2021.
//



#define MAX_SIZE 100
#define CURRENT_DATE 7771
#define MATERIAL_COUNT 110



void print_menu() {
    printf("\n--------------------------------------------------------------------------\n"
           "add material: 1 <name> <supplier> <quantity> <expiration_date>\n"
           "update material: 2 <name> <supplier> <quantity> <expiration_date>\n"
           "                 <name> <supplier> <quantity> <expiration_date>\n"
           "remove material: 3 <name>\n"
           "search materials: 4 <string>\n"
           "* search and sort: 5 <string>\n"
           "materials from a given supplier: 6 <supplier> <quantity>\n"
           "undo: 7\n"
           "redo: 8\n"
           "print all: 9\n"
           "exit: 10\n"
           "--------------------------------------------------------------------------\n");
}

void print_error(char error[]) {
    if (strcmp(error, "update") == 0) printf("There is no matching material!");
    if (strcmp(error, "search") == 0) printf("There is no such material!");
    if (strcmp(error, "command") == 0) printf("Invalid command layout!");
    if (strcmp(error, "undo") == 0) printf("There is no undo to me done!");
    if (strcmp(error, "redo") == 0) printf("There is no redo to me done!");
}

void print_material(char str[]) {
    printf("%s\n", str);
}

#include "service.c"
#include "tests.c"

void print_all() {
    char str[1000];
    for (int i = 0; i < materials_amount(); i++) {
        toString(*materials[i], str);
        printf("%s\n", str);
    }
}


void start() {
//    run_all_tests();
<<<<<<< HEAD
=======
    clear_history();
>>>>>>> f4955b3360e3823a4a0ea0c9090359838db87237

    char cmd[100];
    add_default_materials();
    while (1) {
        print_menu();
        fgets(cmd, MAX_SIZE, stdin);
        if (cmd[0] == '1' && cmd[1] == '0') {
//            destroy_default();
            deconstruct();
            break;
        }
        else if (cmd[0] == '1') add_material(cmd);
        else if (cmd[0] == '2') {
            int pos = update_material(cmd);
            if (pos != -1) {
                printf("Give the new values: ");
                fgets(cmd, MAX_SIZE, stdin);
                update_material_2(cmd, pos);
            }
        } else if (cmd[0] == '3') remove_material(cmd);
        else if (cmd[0] == '4') search_material(cmd);
        else if (cmd[0] == '9') print_all();
        else if (cmd[0] == '5') extra_function(cmd);
        else if(cmd[0] == '6') search_supplier(cmd);
        else if(cmd[0] == '7') undo();
        else if(cmd[0] == '8') redo();
        else printf("Invalid input!");
    }
}