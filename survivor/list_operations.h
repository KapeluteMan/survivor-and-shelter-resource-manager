#ifndef SURVIVOR_LIST_OPERATIONS_H
#define SURVIVOR_LIST_OPERATIONS_H

struct Survivor* add_survivor(struct Survivor* head);
int check_state_health(int value);
struct Survivor* add_last(struct Survivor* head, struct Survivor* n);
int check_amount(struct Survivor *head);
struct Survivor* delete_by_id(struct Survivor* head, int id);
void free_list(struct Survivor * head);
void add_all_to_file(struct Survivor* head);
void add_one_to_file(struct Survivor *to_add);
void bubble_segregate(struct Survivor* head, int option, int type);
void assign_segregate(struct Survivor* a, struct Survivor* b);
int check_interval(int a, int b);
void survivor_id_update(struct Survivor* head);

#endif //SURVIVOR_LIST_OPERATIONS_H