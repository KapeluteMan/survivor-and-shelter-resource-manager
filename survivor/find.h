//
// Created by wojte on 30.12.2025.
//

#ifndef UNTITLED5_FIND_H
#define UNTITLED5_FIND_H

struct Survivor *find_by_id(struct Survivor *head, int id);

struct Survivor *find_by_name(struct Survivor *head, const char *name);

struct Survivor *find_by_skill(struct Survivor *head, enum specialist_skill skill);

struct Survivor *find_by_rations(struct Survivor *head, int rations, int mode);

struct Survivor *find_by_health(struct Survivor *head, int health, int mode);

struct Survivor *find_by_threat_level(struct Survivor *head, int threat_level,int mode);

struct Survivor *find_first_by_status(struct Survivor *head, enum status_of_survivor status);

#endif //UNTITLED5_FIND_H
