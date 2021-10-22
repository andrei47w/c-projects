//
// Created by Andrei on 3/15/2021.
//

#pragma once

/*
 * adds 10 default materials to the array
 */
void add_default_materials();

/*
 * checks if the command for adding/updating a material is correct
 * <param> command
 * <return> 1 or 0
 */
int validate_cmd_add_update(char cmd[]);

/*
 * checks if the command for part 2 of updating a material is correct
 * <param> command
 * <return> 1 or 0
 */
int validate_cmd_update_2(char cmd[]);

/*
 * checks if the command for removing/searching a material is correct
 * <param> command
 * <return> 1 or 0
 */
int validate_cmd_remove_search(char cmd[]);

/*
 * checks if adding a material is possible
 * <param> command
 * <return> 1 or 0
 */
int validate_add(char name[], char supplier[], int exp_date);

/*
 * adds a new material to the array
 * <param> command
 */
void add_material(char cmd[]);

/*
 * removes a material from the array
 * <param> command
 */
void remove_material(char cmd[]);

/*
 * part 1 of updating a material from the array
 * (searches for the material which will mbe updated)
 * <param> command
 * <return> selected material's position
 */
int update_material(char cmd[]);

/*
 * checks if the command for searching a supplier is correct
 * <param> command
 * <return> 1 or 0
 */
int validate_cmd_search_supplier(char cmd[]);

/*
 * part 1 of updating a material from the array
 * (updates the values of the selected material)
 * <param> command, position
 */
void update_material_2(char cmd[], int pos);

/*
 * checks if a material is expired
 * <param> position
 * <return> 1 or 0
 */
int check_expired(int i);

/*
 * searches for a material in the array
 * <param> command
 */
void search_material(char cmd[]);

/*
 * bubble sort for sorting the suppliers alphabetically
 * <param> array
 */
void bubble_sort(int array[]);

/*
 * searches for materials which have in their supplier's name a given string and they are past their expiration date
 * <param> command
 */
void extra_function(char cmd[]);

/*
 * searches for materials which have in their supplier's name a given string and are in lower quantities than a given value
 * <param> command
 */
void search_supplier(char cmd[]);

/*
 * undoes the latest action
 */
void undo();

/*
 * redoes the latest undo
 */
void redo();
