//
// Created by Andrei on 3/6/2021.
//

#pragma once

typedef struct {
    char* name;
    char* supplier;
    int quantity;
    int exp_date;
}Material;

/*
 * dynamically creates a new material with the gives values
 * <param> name, supplier, quantity, expiration date
 * <return> Material type pointer to the new element
 */
Material* createMaterial(char* name, char* supplier, int quantity, int exp_date);

/*
 * gets a material's name
 * <param> Material pointer
 * <return> name
 */
char *getName(Material *p);

/*
 * gets a material's supplier
 * <param> Material pointer
 * <return> supplier
 */
char *getSupplier(Material *p);

/*
 * gets a material's quantity
 * <param> Material pointer
 * <return> quantity
 */
int getQuantity(Material *p);

/*
 * gets a material's expiration date
 * <param> Material pointer
 * <return> expiration date
 */
int getExpDate(Material *p);

/*
 * puts a readable string containing all the information about a certain material
 * <param> Material, string
 */
void toString(Material p, char str[]);

