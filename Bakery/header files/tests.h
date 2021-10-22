//
// Created by Andrei on 3/15/2021.
//

#pragma once

/*
 * assert type tests for adding a material
 */
void run_add_tests();

/*
 * assert type tests for updating a material
 */
void run_update_tests();

/*
 * assert type tests for removing a material
 */
void run_remove_tests();

/*
 * assert type tests for expiated materials
 */
void run_expiration_tests();

/*
 * assert type tests for all validators
 */
void run_validator_tests();

/*
 * runs all tests (add, remove, update, expiration and validator)
 * and deconstructs the dynamic array
 */
void run_all_tests();