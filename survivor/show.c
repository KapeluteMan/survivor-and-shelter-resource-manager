#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "list_operations.h"

#include "survivor_struct.h"


void print_list(struct Survivor *head) {
    struct Survivor *n = head;

    if (head == NULL) {
        printf("There is no survivors");
        return;
    }

    while (n != NULL) {
        char classes_tab[4][10] = {"Medic", "Engineer", "Hunter", "Ordinary"};
        char state_of_health_tab[4][10] = {"Healthy", "Weaken", "Sick", "Dying"};
        char status_tab[5][11] = {"Waiting", "Wounded", "On Mission", "Missing", "Dead"};
        printf("Id: %d\n", n->id);
        printf("Name: %s\n", n->name);
        printf("Class: %s\n", classes_tab[n->skill]);
        printf("Demand for rations: %d\n", n->rations);
        printf("Health: %d\n", n->health);
        printf("State of health: %s\n", state_of_health_tab[n->state_of_health]);
        printf("Status: %s\n", status_tab[n->status_of_survivor]);
        printf("Threat level: %d\n----------------------\n\n", n->threat_level);
        n = n->next;
    }
}

void short_print_list(struct Survivor *head) {
    struct Survivor *n = head;

    if (head == NULL) {
        printf("There is no survivors");
        return;
    }

    while (n != NULL) {

        char state_of_health_tab[4][10] = {"Healthy", "Weaken", "Sick", "Dying"};
        printf("/ %d / %s / State of Health: %s / Threat level: %d /\n", n->id, n->name,
        state_of_health_tab[n->state_of_health], n->threat_level);
        }

        n = n->next;
    }
}
