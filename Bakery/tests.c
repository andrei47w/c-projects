//
// Created by Andrei on 3/15/2021.
//

#include <assert.h>
#include "header files/tests.h"

void run_add_tests()
{
    assert(materials_amount() == 0);

    add(0, "name", "supp", 1, 200321);
    assert(materials_amount() == 1);
    assert(strcmp(getName(materials[0]), "name") == 0);
    assert(strcmp(getSupplier(materials[0]), "supp") == 0);
    assert(getQuantity(materials[0]) == 1);
    assert(getExpDate(materials[0]) == 200321);

    add_material("1 name supp 1 200321");
    assert(materials_amount() == 1);
    assert(getQuantity(materials[0]) == 2);

    add_material("1 name supp 2 200321");
    assert(materials_amount() == 1);
    assert(getQuantity(materials[0]) == 4);

    add_material("1 name1 supp 1 200321");
    assert(materials_amount() == 2);
    assert(strcmp(getName(materials[1]), "name1") == 0);
    assert(strcmp(getSupplier(materials[1]), "supp") == 0);
    assert(getQuantity(materials[1]) == 1);
    assert(getExpDate(materials[1]) == 200321);

    assert(validate_cmd_add_update("1 name1 supp 1200321") == 0);
    assert(validate_cmd_add_update("1 name1 supp1200321") == 0);
    assert(validate_cmd_add_update("1 name1supp1200321") == 0);
    assert(validate_cmd_add_update("1name1supp1200321") == 0);

    assert(materials_amount() == 2);
}

void run_update_tests()
{
    assert(update_material("2 name supp 1 200321") == 0);
    assert(update_material("2 name1 supp 1 200321") == 1);
    assert(update_material("2 name2 supp 1 200321") == -1);
    assert(update_material("2 name1 supp2 1 200321") == -1);
    assert(update_material("2 name1 supp 1 2000321") == -1);
    assert(update_material("2 name1 supp 1 200322") == -1);

    update_material_2("name2 supp2 2 200322", 0);
    assert(strcmp(getName(materials[0]), "name2") == 0);
    assert(strcmp(getSupplier(materials[0]), "supp2") == 0);
    assert(getQuantity(materials[0]) == 2);
    assert(getExpDate(materials[0]) == 200322);

    update_material_2("name3 supp3 3 200323", 1);
    assert(strcmp(getName(materials[1]), "name3") == 0);
    assert(strcmp(getSupplier(materials[1]), "supp3") == 0);
    assert(getQuantity(materials[1]) == 3);
    assert(getExpDate(materials[1]) == 200323);

    assert(validate_cmd_add_update("2 name1 supp 1 200321") == 1);
    assert(validate_cmd_add_update("2 name1 supp 1200321") == 0);
    assert(validate_cmd_add_update("2 name1 supp1200321") == 0);
    assert(validate_cmd_add_update("2 name1supp1200321") == 0);
    assert(validate_cmd_add_update("2name1supp1200321") == 0);
}

void run_remove_tests()
{
    assert(materials_amount() == 2);

    remove_material("3 name");
    assert(materials_amount() == 2);

    remove_material("3name2");
    remove_material("3name3");
    assert(materials_amount() == 2);

    remove_material("3 name2");
    assert(materials_amount() == 2);

    remove_material("3 name3");
    assert(materials_amount() == 2);

    assert(validate_cmd_remove_search("3 name") == 1);
    assert(validate_cmd_remove_search("3name") == 0);

    assert(validate_cmd_remove_search("3 name2") == 1);
    assert(validate_cmd_remove_search("3name2") == 0);

    add_material("1 name supp 1 200321");
    assert(materials_amount() == 3);
    remove_material("3 name");
    assert(materials_amount() == 3);
}

void run_expiration_tests()
{
    add_material("1 name supp 1 200321");
    add_material("1 name supp 1 200322");
    add_material("1 name supp 1 200421");
    add_material("1 name supp 1 220421");
    add_material("1 name supp 1 221121");

    assert(check_expired(0) == 1);
    assert(check_expired(1) == 1);
    assert(check_expired(2) == 1);
    assert(check_expired(3) == 1);
    assert(check_expired(4) == 1);

    add_material("1 name supp 1 150321");
    add_material("1 name supp 1 200221");
    add_material("1 name supp 1 200320");
    add_material("1 name supp 1 110220");

    assert(check_expired(5) == 1);
    assert(check_expired(6) == 1);
    assert(check_expired(7) == 0);
    assert(check_expired(8) == 0);
}

void run_validator_tests()
{
    assert(validate_cmd_remove_search("3 name2") == 1);
    assert(validate_cmd_remove_search("3name2") == 0);

    assert(validate_cmd_remove_search("4 name2") == 1);
    assert(validate_cmd_remove_search("4name2") == 0);

    assert(validate_cmd_search_supplier("6 supp 9") == 1);
    assert(validate_cmd_search_supplier("6 supp9") == 0);
    assert(validate_cmd_search_supplier("6supp9") == 0);

    assert(validate_cmd_add_update("1 name supp 1 120321") == 1);
    assert(validate_cmd_add_update("1 name supp 1120321") == 0);
    assert(validate_cmd_add_update("1 name supp1120321") == 0);
    assert(validate_cmd_add_update("1 namesupp1120321") == 0);
    assert(validate_cmd_add_update("1namesupp1120321") == 0);

    assert(validate_cmd_add_update("2 name supp 1 120321") == 1);
    assert(validate_cmd_add_update("2 name supp 1120321") == 0);
    assert(validate_cmd_add_update("2 name supp1120321") == 0);
    assert(validate_cmd_add_update("2 namesupp1120321") == 0);
    assert(validate_cmd_add_update("2namesupp1120321") == 0);

    assert(validate_cmd_update_2("name supp 1 120321") == 1);
    assert(validate_cmd_update_2("name supp 1120321") == 0);
    assert(validate_cmd_update_2("name supp1120321") == 0);
    assert(validate_cmd_update_2("namesupp1120321") == 0);
}

void run_all_tests()
{
    printf("Running tests . . .\n");
    run_add_tests();
    run_update_tests();
    run_remove_tests();
    run_expiration_tests();
    run_validator_tests();

    deconstruct();
    printf("\n\nAll tests were successful!\n");
}
