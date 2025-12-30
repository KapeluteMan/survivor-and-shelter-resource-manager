#ifndef UNTITLED5_LISTOPERATIONS_H
#define UNTITLED5_LISTOPERATIONS_H

struct Survivor* add_survivor(struct Survivor* head);
int check_health();
int check_state_health(int value);
int threat_check();
struct Survivor* add_last(struct Survivor* head, struct Survivor* n);
int check_skill();
int check_rations();
int check_amount();
struct Survivor* delete_survivor(struct Survivor* head, int id);
void print_list(struct Survivor* head);
void short_print_list(struct Survivor* head);
void add_to_file(struct Survivor* head);


#endif //UNTITLED5_LISTOPERATIONS_H