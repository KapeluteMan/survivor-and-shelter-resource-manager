//
// Created by wojte on 30.12.2025.
//

#ifndef UNTITLED5_FIND_H
#define UNTITLED5_FIND_H

struct Survivor *findById(struct Survivor *head, int id);

struct Survivor *findByName(struct Survivor *head, const char *name);

struct Survivor *findBySkill(struct Survivor *head, enum SpecialistSkill skill);

struct Survivor *findByRations(struct Survivor *head, int rations, int mode);

struct Survivor *findByHealth(struct Survivor *head, int health, int mode);

struct Survivor *findByThreatLevel(struct Survivor *head, int threatLevel,int mode);

struct Survivor *findFirstByStatus(struct Survivor *head, enum StatusOfSurvivor status);

#endif //UNTITLED5_FIND_H
