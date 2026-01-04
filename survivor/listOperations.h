#ifndef UNTITLED5_LISTOPERATIONS_H
#define UNTITLED5_LISTOPERATIONS_H

struct Survivor* add_survivor(struct Survivor* head);
int check_state_health(int value);
struct Survivor* add_last(struct Survivor* head, struct Survivor* n);
int check_amount();
struct Survivor* delete_survivor(struct Survivor* head, int id);
void add_to_file(struct Survivor* head);
void bubble_segregate(struct Survivor* head, int option, int type);
void assign_segregate(struct Survivor* a, struct Survivor* b);
int check_interval(int a, int b);

#endif //UNTITLED5_LISTOPERATIONS_H