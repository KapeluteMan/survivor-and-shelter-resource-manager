#ifndef QUEST_LIST_OPERATIONS_H
#define QUEST_LIST_OPERATIONS_H


struct Quest *add_quest(struct Quest *head, struct Quest *toAdd);
struct Quest* copy_quest(struct Quest* from);
struct Quest* random_quest(struct Quest* head);
struct Quest *checked_finished_quest(struct Quest *head, struct Survivor *s_head, int *rations);
int check_amount_quest(struct Quest *head);

#endif //QUEST_LIST_OPERATIONS_H
