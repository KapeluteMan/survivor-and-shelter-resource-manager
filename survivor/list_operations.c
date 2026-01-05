#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list_operations.h"
#include <string.h>
#include "../insertingFunctions/inserting_functions.h"
#include "survivor_struct.h"



int id_add = 0;

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
                n->state_of_health, n->threat_level, n->status_of_survivor);
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


int check_interval(int a, int b) {
    int tmp;
    do {
        tmp = insert_int();
        if (tmp < a || tmp > b) {
            printf("!Value is out of range <%d-%d>!\n", a, b);
        }
    } while (tmp < a || tmp > b);

    return tmp;
}

int check_state_health(int value) {
    if (value >= 70) {
        return 0;
    }
    return 1;
}

struct Survivor *add_survivor(struct Survivor *head) {
    struct Survivor *n = calloc(1, sizeof(struct Survivor));

    if (n == NULL) {
        return head; //zwarca starą głowę listy
    }

    int amount = check_amount(head);
    if (amount >= 3) {
        printf("//You cannot add more survivors!\n");
        printf("Some other actions should be taken...\n");
        return head;
    }

    n->id = id_add++;

    printf("// Insert name:\n");
    insert_string(n->name);

    printf("// Insert their skill:\n");
    printf(" - 0: Medic\n - 1: Engineer\n - 2: Ordinary\n");
    n->skill = check_interval(0,2);

    printf("// Insert their demand for rations:\n");
    n->rations = check_interval(0,100);

    printf("// Insert their health (0-100):\n");
    n->health = check_interval(0,100);
    n->state_of_health = check_state_health(n->health);

    printf("// Insert their threat level (0-10):\n");
    n->threat_level = check_interval(0,10);

    n->status_of_survivor = 0;
    n->next = NULL;

    return add_last(head, n);
}

void assign_segregate(struct Survivor* a, struct Survivor* b) {
    if (a == NULL || b == NULL) {
        return;
    }
    int tmp_id = a->id;
    char tmp_name[100];
    strcpy(tmp_name, a->name);
    int tmp_skill = a->skill;
    int tmp_rations = a->rations;
    int tmp_health = a->health;
    int tmp_state = a->state_of_health;
    int tmp_threat = a->threat_level;
    int tmp_status = a->status_of_survivor;

    a->id = b->id;
    strcpy(a->name, b->name);
    a->skill = b->skill;
    a->rations = b->rations;
    a->health = b->health;
    a->state_of_health = b->state_of_health;
    a->threat_level = b->threat_level;
    a->status_of_survivor = b->status_of_survivor;

    b->id = tmp_id;
    strcpy(b->name, tmp_name);
    b->skill = tmp_skill;
    b->rations = tmp_rations;
    b->health = tmp_health;
    b->state_of_health = tmp_state;
    b->threat_level = tmp_threat;
    b->status_of_survivor = tmp_status;
}



void bubble_segregate(struct Survivor* head, int option, int type) {
    if (head == NULL) {
        return;
    }

    int swapped;
    struct Survivor* lptr = NULL;
    do {
        swapped = 0;
        struct Survivor *ptr1 = head;

        while (ptr1->next != lptr) {
            if (type == 0) {
                //name
                if (option == 0 && (strcmp(ptr1->name, ptr1->next->name) > 0)){
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //skill
                else if (option == 1 && (ptr1->skill > ptr1->next->skill))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //rations
                else if (option == 2 && (ptr1->rations > ptr1->next->rations))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //health
                else if (option == 3 && (ptr1->health > ptr1->next->health))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //threat_level
                else if (option == 4 && (ptr1->threat_level > ptr1->next->threat_level))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }

            }else if (type == 1) {
                //name
                if (option == 0 && (strcmp(ptr1->name, ptr1->next->name) < 0)){
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //skill
                else if (option == 1 && (ptr1->skill < ptr1->next->skill))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //rations
                else if (option == 2 && (ptr1->rations < ptr1->next->rations))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //health
                else if (option == 3 && (ptr1->health < ptr1->next->health))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //threat_level
                else if (option == 4 && (ptr1->threat_level < ptr1->next->threat_level))  {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }

            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


