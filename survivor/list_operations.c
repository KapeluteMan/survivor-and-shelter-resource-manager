#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "../logicFunctions/logic_functions.h"
#include "survivor_struct.h"
#include "file_operations.h"

#include "list_operations.h"


Survivor *add_last(Survivor *head, Survivor *n) {
    if (head == NULL) {
        return n;
    }

    Survivor *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = n;
    return head;
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

    printf("// Insert name:\n");
    insert_string(n->name);

    printf("// Insert their skill:\n");
    printf(" - 0: Medic\n - 1: Engineer\n - 2: Ordinary\n");
    n->skill = check_interval(0, 2);

    printf("// Insert their demand for rations:\n");
    n->rations = check_interval(0, 100);

    printf("// Insert their health (0-100):\n");
    n->health = check_interval(0, 100);
    n->state_of_health = check_state_health(n->health);

    printf("// Insert their threat level (0-10):\n");
    n->threat_level = check_interval(0, 10);

    n->status_of_survivor = 0;
    n->next = NULL;

    return add_last(head, n);
}

int check_amount(Survivor *head) {
    Survivor *n = head;
    int i = 0;

    while (n != NULL) {
        i++;
        n = n->next;
    }
    return i;
}

int check_state_health(int value) {
    if (value >= 70) {
        return 0;
    }
    return 1;
}

void survivor_health_status_change(Survivor* head) {
    if (head==NULL) {
        return;
    }

    Survivor *n = head;
    while (n!=NULL) {
        if (n->health>79) {
            n->state_of_health=HEALTHY;
        } else {
            if (n->health>49) {
                n->state_of_health=WEAKEN;
            } else {
                if (n->health>19) {
                    n->state_of_health=SICK;
                } else {
                    n->state_of_health=DYING;
                }
            }
        }

        n = n->next;
    }
}

void assign_segregate(struct Survivor *a, struct Survivor *b) {
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

void bubble_segregate(struct Survivor *head, int option, int type) {
    if (head == NULL) {
        return;
    }

    int swapped;
    struct Survivor *lptr = NULL;
    do {
        swapped = 0;
        struct Survivor *ptr1 = head;

        while (ptr1->next != lptr) {
            if (type == 0) {
                //name
                if (option == 0 && (strcmp(ptr1->name, ptr1->next->name) > 0)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //skill
                else if (option == 1 && (ptr1->skill > ptr1->next->skill)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //rations
                else if (option == 2 && (ptr1->rations > ptr1->next->rations)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //health
                else if (option == 3 && (ptr1->health > ptr1->next->health)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //threat_level
                else if (option == 4 && (ptr1->threat_level > ptr1->next->threat_level)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
            } else if (type == 1) {
                //name
                if (option == 0 && (strcmp(ptr1->name, ptr1->next->name) < 0)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //skill
                else if (option == 1 && (ptr1->skill < ptr1->next->skill)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //rations
                else if (option == 2 && (ptr1->rations < ptr1->next->rations)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //health
                else if (option == 3 && (ptr1->health < ptr1->next->health)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
                //threat_level
                else if (option == 4 && (ptr1->threat_level < ptr1->next->threat_level)) {
                    assign_segregate(ptr1, ptr1->next);
                    swapped = 1;
                }
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void survivor_id_update(Survivor* head) {
    if (head == NULL) {
        return;
    }

    int indeks = 1;
    Survivor *n = head;

    while (n != NULL) {
        n->id = indeks;
        indeks++;
        n = n->next;
    }

}

Survivor *delete_by_id(Survivor *head, int id) {
    if (head == NULL) {
        return head;
    }

    if (head->id == id) {
        if (head->status_of_survivor==MISSING || head-> status_of_survivor==ON_MISSION) {
            printf("Nie możesz usunąć surviviora o nazwie : %s\n",head->name);
            return head;
        }
        Survivor *new_head = head->next;
        add_one_to_file(head);
        free(head);
        head = new_head;
        return head;
    }

    Survivor *prev = head;
    Survivor *curr = head->next;

    while (curr != NULL) {
        if (curr->id == id) {
            if (curr->status_of_survivor==MISSING || curr-> status_of_survivor==ON_MISSION) {
                printf("Nie możesz usunąć surviviora o nazwie : %s\n",curr->name);
                return head;
            }
            prev->next = curr->next;
            add_one_to_file(curr);
            free(curr);
            return head;
        }

        prev = curr;
        curr = curr->next;
    }
    printf("//A survivor not found\n");
    return head;
}

// 0 - dokładny, 1 - perix
Survivor *delete_by_name(Survivor *head, char name[100],int mode) {
    Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;
    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            if (mode == 0) {
                if (strcmp(name,next->name)==0) {
                    to_delete[pom]=next->id;
                    break;
                }
            } else {
                if (strncmp(name,next->name,strlen(name))==0) {
                    to_delete[pom]=next->id;
                    pom++;
                }
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

Survivor *delete_by_skill(Survivor *head, enum specialist_skill skill) {
    struct Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;
    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            if (skill == next->skill) {
                to_delete[pom]=next->id;
                pom++;
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

// 1-> takie same jak, 2-> mniejsze niż, 3-> więsze niż

Survivor *delete_by_rations(Survivor *head, int const rations, int const mode) {
    Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;

    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            switch (mode) {
                case 1:
                    if (rations == next->rations) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 2:
                    if (rations>next->rations) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 3:
                    if (rations<next->rations) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                default:
                    printf("Wrong mode\n");
                    break;
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

// 1-> takie same jak, 2-> mniejsze niż, 3-> więsze niż

Survivor *delete_by_health(Survivor *head, int const health, int const mode) {
    Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;

    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            switch (mode) {
                case 1:
                    if (health == next->health) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 2:
                    if (health>next->health) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 3:
                    if (health<next->health) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                default:
                    printf("Wrong mode\n");
                    break;
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

Survivor *delete_by_state_of_health(Survivor *head, enum state_of_health state_of_health) {
    Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;
    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            if (state_of_health == next->state_of_health) {
                to_delete[pom]=next->id;
                pom++;
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

// 1-> takie same jak, 2-> mniejsze niż, 3-> więsze niż

Survivor *delete_by_threat_level(Survivor *head, int const threat_level, int const mode) {
    Survivor *next = head;
    int to_delete[20]={0};
    int pom=0;

    while (next != NULL) {
        if(next->status_of_survivor!=MISSING || next-> status_of_survivor!=ON_MISSION){
            switch (mode) {
                case 1:
                    if (threat_level == next->threat_level) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 2:
                    if (threat_level>next->threat_level) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                case 3:
                    if (threat_level<next->threat_level) {
                        to_delete[pom]=next->id;
                        pom++;
                    }
                    break;
                default:
                    printf("Wrong mode\n");
                    break;
            }
        }
        next=next->next;
    }

    for (int i=0;i<pom;i++) {
        head = delete_by_id(head, to_delete[i]);
    }

    return head;
}

void free_list(Survivor *head) {
    Survivor *next = NULL;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
    head = NULL;
}

