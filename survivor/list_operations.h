#ifndef SURVIVOR_LIST_OPERATIONS_H
#define SURVIVOR_LIST_OPERATIONS_H

struct Survivor* add_last(struct Survivor* head, struct Survivor* n);

struct Survivor* add_survivor(struct Survivor* head);

struct Survivor *add_survivor_name(struct Survivor *head);

int check_amount(struct Survivor *head);

int check_state_health(int value);

void survivor_health_status_change(struct Survivor* head);

void assign_segregate(struct Survivor* a, struct Survivor* b);

void bubble_segregate(struct Survivor* head, int option, int type);

void survivor_id_update(struct Survivor* head);

void edit_survivor(struct Survivor *head);

struct Survivor* delete_by_id(struct Survivor* head, int id);

struct Survivor *delete_by_name(struct Survivor *head, char name[100],int mode);

struct Survivor *delete_by_skill(struct Survivor *head, enum specialist_skill skill);

struct Survivor *delete_by_rations(struct Survivor *head, int rations, int mode);

struct Survivor *delete_by_health(struct Survivor *head, int health, int mode);

struct Survivor *delete_by_state_of_health(struct Survivor *head, enum state_of_health state_of_health);

struct Survivor *delete_by_threat_level(struct Survivor *head, int threat_level, int mode);

void free_list(struct Survivor * head);

#endif //SURVIVOR_LIST_OPERATIONS_H