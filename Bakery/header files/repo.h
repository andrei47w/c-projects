//
// Created by Andrei on 3/14/2021.
//

#pragma once

/*
 * returns the current amount of materials in the array
 */
int materials_amount();

/*
 * dynamically add a new material to the array
 * <param> position, name, supplier, quantity, expiration date
 */
void add(int pos, char name[], char supplier[], int quantity, int exp_date);

/*
 * removes the material on position pos from the array
 * <param> position
 */
void destroy(int pos);

/*
 * updates the material on position pos with the new given values
 * <param> position, name, supplier, expiration date, quantity
 */
void update(int pos, char name[], char supplier[], int exp_date, int quantity);

/*
 * deconstructs the dynamically allocated array to avoid any memory leaks
 */
void deconstruct();




