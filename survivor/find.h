#ifndef SURVIVOR_FIND_H
#define SURVIVOR_FIND_H

struct Survivor *find_by_id(struct Survivor *head, int id);

struct Survivor *find_by_name(struct Survivor *head, const char *name);

struct Survivor *find_by_skill(struct Survivor *head, enum specialist_skill skill);

struct Survivor *find_by_rations(struct Survivor *head, int rations, int mode);

struct Survivor *find_by_health(struct Survivor *head, int health, int mode);

struct Survivor *find_by_threat_level(struct Survivor *head, int threat_level,int mode);

struct Survivor *find_first_by_status(struct Survivor *head, enum status_of_survivor status);

struct Survivor *find_by_prefix_name(struct Survivor *head, const char *prefix);

struct Survivor *find_by_health_state(struct Survivor *head, const enum state_of_health state_of_health);

#endif //SURVIVOR_FIND_H
