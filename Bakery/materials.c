//
// Created by Andrei on 3/6/2021.
//

#include "header files/material.h"

Material* createMaterial(char *name, char *supplier, int quantity, int exp_date) {
    Material* material =(Material*)malloc(sizeof(Material));

//    material->name = (char*)malloc(strlen(name) * sizeof(char) +1);
//    strcpy(material->name, name);

    material->name = (char*)malloc(strlen(name) + 1);
    strcpy(material->name, name);
//        material->name = NULL;

    material->supplier = (char*)malloc(strlen(supplier) + 1);
    strcpy(material->supplier, supplier);
//    material->supplier = NULL;

    material->quantity = quantity;

    material->exp_date = exp_date;

    return material;
}

char *getName(Material *p) {
    return p->name;
}

char *getSupplier(Material *p) {
    return p->supplier;
}

int getQuantity(Material *p) {
    return p->quantity;
}

int getExpDate(Material *p) {
    return p->exp_date;
}

void toString(Material p, char str[]) {
    sprintf(str, "material: %s         supplier: %s         quantity: %d         expiration date: %d", p.name,
            p.supplier, p.quantity, p.exp_date);
}