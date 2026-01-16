#include "main_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii_titles.h"
#include "../logicFunctions/logic_functions.h"
#include "../survivor/list_operations.h"
#include "../survivor/show.h"
#include "../survivor/survivor_struct.h"


void segragate_filtr_menu(struct Survivor **head) {
    survivor_deleting_title();
    int menu = 1;
    int option = 0;
    int type = 0;
    while (menu == 1) {
        printf("\n"
               "______________________________"
               "|   1 - Segregate            |\n"
               "\n"
               "|   2 - Filter               |\n"
               "\n"
               "|   0 - Exit                 |\n"
               "------------------------------\n");

        printf("\nChoose your option: \n");
        int wybor = check_interval(0, 2);

        switch (wybor) {
            case 1:
                system("cls");
                printf("Choose an option: \n"
                       "|0 - Sort by name\n"
                       "|1 - Sort by skill\n"
                       "|2 - Sort by rations\n"
                       "|3 - Sort by health\n"
                       "|4 - Sort by threatLevel\n");
                option = check_interval(0,4);
                system("cls");
                printf("\n|0 - Ascending >\n|1 - Descending <\n");
                type = check_interval(0,1);

                bubble_segregate(*head, option, type);
                break;
            case 2:
                system("cls");
                break;
            case 0:
                printf("\nExiting S.M.A.R.T.\n");
                menu = 0;
            default:
                printf("Sorry, you selected an invalid option.\n");
        }
    }
}

struct Survivor* survivor_deleting_menu(struct Survivor *head){
    survivor_deleting_title();
    int menu = 1;
    int tmp = 0;
    while (menu == 1) {
        printf("\n"
               "______________________________"
               "|   1 - ID                   |\n"
               "\n"
               "|   2 - NAME                 |\n"
               "\n"
               "|   3 - SKILL                |\n"
               "\n"
               "|   4 - RATIONS              |\n"
               "\n"
               "|   5 - STATE OF HEALTH      |\n"
               "\n"
               "|   6 - THREAT LEVEL         |\n"
               "\n"
               "|   0 - Exit                 |\n"
               "------------------------------\n");

        printf("\nChoose your option: \n");
        int wybor = check_interval(0, 6);
        int enter_id = 0;

        switch (wybor) {
            case 1:
                system("cls");
                printf("Delete a survivor:\n");
                printf("Survivors:\n");
                short_print_list(head);
                printf("Enter ID: \n");
                enter_id = insert_int();
                head = delete_by_id(head, enter_id);
                break;
            case 2:
                system("cls");
                char name[100];
                printf("Enter name: \n");
                insert_string(name);

                printf("Choose mode:\n"
                       "|0 - Look for the exact name\n"
                       "|1 - Search by Prefix\n");
                tmp = check_interval(0,1);
                head = delete_by_name(head, name,tmp);
                break;
            case 3: {
                system("cls");
                printf("Delete by skill\n");
                printf("Choose skill:\n");
                printf("0 - MEDIC\n");
                printf("1 - ENGINEER\n");
                printf("2 - HUNTER\n");
                printf("3 - ORDINARY\n");

                tmp = check_interval(0, 3);
                //head = delete_by_skill(head, tmp);
                break;
            }
            case 4: {
                system("cls");
                int rations = 0;

                printf("Delete by rations\n");
                printf("Enter rations value:\n");
                rations = insert_int();

                printf("Choose mode:\n");
                printf("1 - equal\n");
                printf("2 - less than\n");
                printf("3 - greater than\n");

                tmp = check_interval(1, 3);
                head = delete_by_rations(head, rations, tmp);
                break;
            }
            case 5: {
                system("cls");
                printf("Delete by state of health\n");
                printf("0 - HEALTHY\n");
                printf("1 - WEAKEN\n");
                printf("2 - SICK\n");
                printf("3 - DYING\n");

                tmp = check_interval(0, 3);
                //head = delete_by_state_of_health(head, tmp);
                break;
            }
            case 6: {
                system("cls");
                int threat = 0;

                printf("Delete by threat level\n");
                printf("Enter threat level:\n");
                threat = insert_int();

                printf("Choose mode:\n");
                printf("1 - equal\n");
                printf("2 - less than\n");
                printf("3 - greater than\n");

                tmp = check_interval(1, 3);
                head = delete_by_threat_level(head, threat, tmp);
                break;
            }
            case 0:
                printf("\nExiting Trashing Program\n");
                menu = 0;
            default:
                printf("Sorry, you selected an invalid option.\n");
        }
    }

    return head;
}

void survivor_menu(struct Survivor **head) {
    int menu = 1;
    while (menu == 1) {
        survivor_editing_title();
        printf("\n"
               "______________________________"
               "|   1 - Add the Survivor     |\n"
               "\n"
               "|   2 - List the Survivors   |\n"
               "\n"
               "|   3 - Edit                 |\n"
               "\n"
               "|   4 - Check amount         |\n"
               "\n"
               "|   5 - DELETE               |\n"
               "\n"
               "|   0 - Exit                 |\n"
               "------------------------------\n");

        printf("\nChoose your option: \n");
        int wybor = check_interval(0, 5);

        switch (wybor) {
            case 1:
                system("cls");
                printf("Add the survivor:\n");
                *head = add_survivor(*head);
                break;
            case 2:
                system("cls");
                break;
            case 3:
                break;
            case 4:
                system("cls");
                printf("Amount of survivors: %d\n", check_amount(*head));
                break;
            case 5:
                system("cls");
                *head = survivor_deleting_menu(*head);
                break;
            case 0:
                printf("\nExiting S.M.A.R.T.\n");
                menu = 0;
            default:
                printf("Sorry, you selected an invalid option.\n");
        }
    }
}