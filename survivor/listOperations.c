#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listOperations.h"
#include "../insertingFunctions/insertingFunctions.c"
#include "survivorStruct.h"


int id_add = 0;


////////////////////////////////////////////////////////

struct Survivor *add_last(struct Survivor *head, struct Survivor *n) {
    if (head == NULL) {
        return n;
    }

    struct Survivor *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = n;
    return head;
}


void add_to_file(struct Survivor *head) {
    FILE *f = fopen("survivor.txt", "w");
    if (!f) {
        perror("Error opening survivor.txt");
        return;
    }

    struct Survivor *n = head;

    while (n != NULL) {
        fprintf(f, "%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", n->id, n->name, n->skill, n->rations, n->health,
                n->stateOfHealth, n->threatLevel, n->statusOfSurvivor);
        n = n->next;
    }

    fclose(f);
}

struct Survivor *delete_survivor(struct Survivor *head, int id) {
    if (head == NULL) {
        return head;
    }

    if (head->id == id) {
        struct Survivor *new_head = head->next;
        free(head);
        head = new_head;
        return head;
    }

    struct Survivor *prev = head;
    struct Survivor *curr = head->next;

    while (curr != NULL) {
        if (curr->id == id) {
            prev->next = curr->next;
            free(curr);
            return head;
        }

        prev = curr;
        curr = curr->next;
    }
    printf("//A survivor not found\n");
    return head;
}

int check_amount(struct Survivor *head) {
    struct Survivor *n = head;
    int i = 0;

    while (n != NULL) {
        i++;
        n = n->next;
    }
    return i;
}


int check_rations() {
    int tmp;
    do {
        tmp = insertInt();
        if (tmp < 0) {
            printf("Wrong amount\n");
        }
    } while (tmp < 0);
    return tmp;
}

int check_skill() {
    int tmp;
    do {
        tmp = insertInt();
        if (tmp < 0 || tmp > 2) {
            printf("!Wrong class!\n");
        }
    } while (tmp < 0 || tmp > 2);
    return tmp;
}


int check_health() {
    int tmp;
    do {
        tmp = insertInt();
        if (tmp < 0 || tmp > 100) {
            printf("!The health value is out of range (0-100)!\n");
        }
    } while (tmp < 0 || tmp > 100);

    return tmp;
}


int check_state_health(int value) {
    if (value >= 70) {
        return 0;
    }
    return 1;
}

int threat_check() {
    int threat_tmp;
    do {
        threat_tmp = insertInt();
        if (threat_tmp < 0 || threat_tmp > 10) {
            printf("!The threat value is out of range (0-10)!\n");
        }
    } while (threat_tmp < 0 || threat_tmp > 10);

    return threat_tmp;
}


struct Survivor *add_survivor(struct Survivor *head) {
    struct Survivor *n = calloc(1, sizeof(struct Survivor));

    if (n == NULL) {
        return head; //zwarca starą głowę listy
    }

    int amount = check_amount(head);
    if (amount >= 2) {
        printf("//You cannot add more survivors!\n");
        printf("Some other actions should be taken...\n");
        return head;
    }

    n->id = id_add++;

    printf("// Insert name:\n");
    insertString(n->name);

    printf("// Insert their skill:\n");
    printf(" - 0: Medic\n - 1: Engineer\n - 2: Ordinary\n");
    n->skill = check_skill();

    printf("// Insert their demand for rations:\n");
    n->rations = check_rations();

    printf("// Insert their health (0-100):\n");
    n->health = check_health();
    n->stateOfHealth = check_state_health(n->health);

    printf("// Insert their threat level (0-10):\n");
    n->threatLevel = threat_check();

    n->statusOfSurvivor = 0;
    n->next = NULL;

    return add_last(head, n);
}

void print_list(struct Survivor *head) {
    struct Survivor *n = head;

    while (n != NULL) {
        char classes_tab[3][10] = {"Medic", "Engineer", "Ordinary"};
        char stateofhealth_tab[2][10] = {"Healthy", "Weaken"};
        char status_tab[2][10] = {"Waiting", "On Mission"};
        printf("Id: %d\n", n->id);
        printf("Name: %s\n", n->name);
        printf("Class: %s\n", classes_tab[n->skill]);
        printf("Demand for rations: %d\n", n->rations);
        printf("Health: %d\n", n->health);
        printf("State of health: %s\n", stateofhealth_tab[n->stateOfHealth]);
        printf("Status: %s\n", status_tab[n->statusOfSurvivor]);
        printf("Threat level: %d\n----------------------\n\n", n->threatLevel);
        n = n->next;
    }
}

void short_print_list(struct Survivor *head) {
    struct Survivor *n = head;

    while (n != NULL) {
        add_to_file(head);
        if (n->statusOfSurvivor == 0) {
            char stateofhealth_tab[2][10] = {"Healthy", "Weaken"};
            printf("/ %d / %s / State of Health: %s / Threat level: %d /\n", n->id, n->name,
                   stateofhealth_tab[n->stateOfHealth], n->threatLevel);
        }

        n = n->next;
    }
}


// int main() {
//     struct Survivor *head = NULL;
//     //add_to_file(head);
//
//     int menu = 1;
//
//     while (menu == 1) {
//         add_to_file(head);
//         printf(
//             "Select an option:\n 1 - Add the survivor\n 2 - Check the amount of survivors \n 3 - List the survivors\n 4 - Delete a survivor via id \n 5 - Exit\n");
//         int wybor1 = insertInt();
//         switch (wybor1) {
//             case 1:
//                 printf("Add the survivor:\n");
//                 head = add_survivor(head);
//                 break;
//             case 2:
//                 printf("Amount of survivors: %d\n", check_amount(head));
//                 break;
//             case 3:
//                 printf("List:\n");
//                 print_list(head);
//                 break;
//             case 4:
//                 printf("Delete a survivor:\n");
//                 printf("Available survivors (who are not on a mission):\n");
//                 short_print_list(head);
//                 int enter_id = insertInt();
//                 head = delete_survivor(head, enter_id);
//                 break;
//             case 5:
//                 menu = 0;
//                 break;
//
//             default:
//                 printf("Wrong option\n");
//         }
//     }
//
//
//     return 0;
// }
