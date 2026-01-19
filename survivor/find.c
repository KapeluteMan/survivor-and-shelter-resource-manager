#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "survivor_struct.h"
#include "list_operations.h"

#include "find.h"

//zwraca wakżnik na znaleziony element (niepowtarzalny id)
struct Survivor *find_by_id(struct Survivor *head, const int id) {
    struct Survivor *current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

//zwraca wakżnik na znaleziony element (niepowtarzalny name)
struct Survivor *find_by_name(struct Survivor *head, const char *name) {
    struct Survivor *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *find_by_prefix_name(struct Survivor *head, const char *prefix) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        if (strncmp(current->name, prefix, strlen(prefix)) == 0) {
            new_survivor = calloc(1, sizeof(struct Survivor));
            copy_survivor(current, new_survivor);
            if (new_survivor != NULL) {
                new_head = add_last(new_head, new_survivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return new_head;
            }
        }
        current = current->next;
    }
    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *find_by_skill(struct Survivor *head, const enum specialist_skill skill) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        if (current->skill == skill) {
            new_survivor = calloc(1, sizeof(struct Survivor));
            copy_survivor(current, new_survivor);
            if (new_survivor != NULL) {
                new_head = add_last(new_head, new_survivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return new_head;
            }
        }
        current=current->next;
    }

    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *find_by_rations(struct Survivor *head, const int rations, const int mode) {

    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->rations == rations) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 2:
                if (current->rations < rations) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 3:
                if (current->rations > rations) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return new_head;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *find_by_health(struct Survivor *head, const int health, const int mode) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;

    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->health == health) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 2:
                if (current->health < health) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 3:
                if (current->health > health) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return new_head;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *find_by_health_state(struct Survivor *head, const enum state_of_health state_of_health) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        if (current->state_of_health == state_of_health) {
            new_survivor = calloc(1, sizeof(struct Survivor));
            copy_survivor(current, new_survivor);
            if (new_survivor != NULL) {
                new_head = add_last(new_head, new_survivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return new_head;
            }
        }
        current=current->next;
    }

    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *find_by_threat_level(struct Survivor *head, const int threat_level, const int mode) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->threat_level == threat_level) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 2:
                if (current->threat_level < threat_level) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return new_head;
                    }
                }
                break;
            case 3:
                if (current->threat_level > threat_level) {
                    new_survivor = calloc(1, sizeof(struct Survivor));
                    copy_survivor(current, new_survivor);
                    if (new_survivor != NULL) {
                        new_head = add_last(new_head, new_survivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return new_head;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return new_head;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *find_first_by_status(struct Survivor *head, const enum status_of_survivor status) {
    struct Survivor *current = head;
    struct Survivor *new_head = NULL;
    struct Survivor *new_survivor = NULL;
    while (current != NULL) {
        if (current->status_of_survivor == status) {
            new_survivor = calloc(1, sizeof(struct Survivor));
            copy_survivor(current, new_survivor);
            if (new_survivor != NULL) {
                new_head = add_last(new_head, new_survivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return new_head;
            }
        }
        current=current->next;
    }

    return new_head;
}
