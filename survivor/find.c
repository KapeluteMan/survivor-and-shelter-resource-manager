#include "survivorStruct.h"
#include "listOperations.h"

#include "find.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//zwraca wakżnik na znaleziony element (niepowtarzalny id)
struct Survivor *findById(struct Survivor *head, const int id) {
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
struct Survivor *findByName(struct Survivor *head, const char *name) {
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
struct Survivor *findFirstByPrefixName(struct Survivor *head, const char *prefix) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        if (strncmp(current->name, prefix, strlen(prefix)) == 0) {
            newSurvivor = calloc(1, sizeof(struct Survivor));
            copySurvivor(current, newSurvivor);
            if (newSurvivor != NULL) {
                newHead = add_last(newHead, newSurvivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return newHead;
            }
        }
        current = current->next;
    }
    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *findBySkill(struct Survivor *head, const enum SpecialistSkill skill) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        if (current->skill == skill) {
            newSurvivor = calloc(1, sizeof(struct Survivor));
            copySurvivor(current, newSurvivor);
            if (newSurvivor != NULL) {
                newHead = add_last(newHead, newSurvivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return newHead;
            }
        }
    }

    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *findByRations(struct Survivor *head, const int rations, const int mode) {

    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->rations == rations) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 2:
                if (current->rations < rations) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 3:
                if (current->rations > rations) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return newHead;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *findByHealth(struct Survivor *head, const int health, const int mode) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;

    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->health == health) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 2:
                if (current->health < health) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 3:
                if (current->health > health) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return newHead;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *findByHealthState(struct Survivor *head, const enum StateOfHealth stateOfHealth) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        if (current->stateOfHealth == stateOfHealth) {
            newSurvivor = calloc(1, sizeof(struct Survivor));
            copySurvivor(current, newSurvivor);
            if (newSurvivor != NULL) {
                newHead = add_last(newHead, newSurvivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return newHead;
            }
        }
    }

    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
// mode: 1->dokładna wartość, 2 -> mniejsza niż, 3 -> większa niż
struct Survivor *findByThreatLevel(struct Survivor *head, const int threatLevel, const int mode) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        switch (mode) {
            case 1:
                if (current->threatLevel == threatLevel) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 2:
                if (current->threatLevel < threatLevel) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor\n");
                        return newHead;
                    }
                }
                break;
            case 3:
                if (current->threatLevel > threatLevel) {
                    newSurvivor = calloc(1, sizeof(struct Survivor));
                    copySurvivor(current, newSurvivor);
                    if (newSurvivor != NULL) {
                        newHead = add_last(newHead, newSurvivor);
                    } else {
                        printf("Niepowodzenie w tworzeniu: Survivor");
                        return newHead;
                    }
                }
                break;

            default:
                printf("Źle wybrany tryb szukania -> ma być [1,3]\n");
                break;
        }
        current = current->next;
    }

    return newHead;
}

//zwraca wskanik na head listy znalezionych (może być NULL)
struct Survivor *findFirstByStatus(struct Survivor *head, const enum StatusOfSurvivor status) {
    struct Survivor *current = head;
    struct Survivor *newHead = NULL;
    struct Survivor *newSurvivor = NULL;
    while (current != NULL) {
        if (current->statusOfSurvivor == status) {
            newSurvivor = calloc(1, sizeof(struct Survivor));
            copySurvivor(current, newSurvivor);
            if (newSurvivor != NULL) {
                newHead = add_last(newHead, newSurvivor);
            } else {
                printf("Niepowodzenie w tworzeniu: Survivor\n");
                return newHead;
            }
        }
    }

    return newHead;
}
