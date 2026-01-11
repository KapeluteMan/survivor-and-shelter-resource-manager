/**
    *
    *
    *    ▄█████ ▄▄ ▄▄ ▄▄▄▄▄ ▄▄   ▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ██▄  ▄██  ▄▄▄  ▄▄  ▄▄  ▄▄▄   ▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄
    *    ▀▀▀▄▄▄ ██▄██ ██▄▄  ██     ██   ██▄▄  ██▄█▄   ██ ▀▀ ██ ██▀██ ███▄██ ██▀██ ██ ▄▄ ██▄▄  ██▄█▄
    *    █████▀ ██ ██ ██▄▄▄ ██▄▄▄  ██   ██▄▄▄ ██ ██   ██    ██ ██▀██ ██ ▀██ ██▀██ ▀███▀ ██▄▄▄ ██ ██
    *
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "survivor/survivor_struct.h"
#include "quest/add_from_file.h"
#include "insertingFunctions/inserting_functions.h"
#include "programStart/starting_functions.h"
#include "survivor/list_operations.h"
#include "quest/show.h"
#include "survivor/show.h"



int main() {

    Survivor *head = NULL;
    //add_to_file(head);

    struct Quest *q_head = NULL;
    start_program(&head,&q_head);
    show_title();
    int menu = 1;
    while (menu == 1) {
        int option = 0;
        int type = 0;
        // add_one_to_file(head);
        printf(
            "Select an option:\n"
            " 1 - Add the survivor\n"
            " 2 - Check the amount of survivors \n"
            " 3 - List the survivors\n"
            " 4 - Delete a survivor via id \n"
            " 5 - Segregate \n"
            " 6 - Show Quests \n"
            " 7 - Exit\n"

            "\n");
        int wybor1 = insert_int();
        switch (wybor1) {
            case 1:
                system("cls");
                show_title();
                printf("Add the survivor:\n");
                head = add_survivor(head);
                break;
            case 2:
                system("cls");
                show_title();
                printf("Amount of survivors: %d\n", check_amount(head));
                break;
            case 3:
                system("cls");
                show_title();
                printf("List:\n");
                print_list(head);
                break;
            case 4:
                system("cls");
                show_title();
                printf("Delete a survivor:\n");
                printf("Available survivors (who are not on a mission):\n");
                short_print_list(head);
                int enter_id = insert_int();
                head = delete_by_id(head, enter_id);
                break;
            case 5:
                system("cls");
                show_title();
                printf("Choose an option: \n"
                       "0 - Sort by name\n"
                       "1 - Sort by skill\n"
                       "2 - Sort by rations\n"
                       "3 - Sort by health\n"
                       "4 - Sort bt threatLevel\n");
                option = check_interval(0,4);
                printf("\n0 - Ascending >\n1 - Descending <\n");
                type = check_interval(0,1);

                bubble_segregate(head, option, type);
                break;

            case 6:
                system("cls");
                show_title();
                printf("List:\n");
                print_quest(q_head);
                break;
            case 7:
                menu = 0;
                break;

            default:
                printf("Wrong option\n");
        }
    }


    return 0;
}
