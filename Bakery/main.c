/*
 * Mary runs her family's bakery, “Bread'n Bagel”. Every day she struggles with keeping up to date with available stocks of raw materials and would like a program to help her manage the business more effectively. Each Material used in the bakery must have: a name, a supplier, a quantity and the expiration date. Mary wants a software application that helps her in the following ways:
(a) Add, delete and update a material. A raw material is uniquely identified by its name, supplier and expiration date. If a material that already exists is added, its quantity will be modified (the new quantity is added to the existing one).
(b) See all available materials past their expiration date, containing a given string (if the string is empty, all materials past their expiration date will be considered).
 */

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <crtdbg.h>
#include "header files/material.h"
Material** materials;
int array_size = 0;
#include "UI.c"

int main() {
    materials = malloc(MATERIAL_COUNT * sizeof(Material*));
    start();

    _CrtCheckMemory();
    printf("%d", _CrtDumpMemoryLeaks());
    return 0;
}