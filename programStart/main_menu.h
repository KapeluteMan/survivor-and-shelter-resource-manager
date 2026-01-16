//
// Created by silve on 15.01.2026.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H
struct Survivor;


void segragate_filtr_menu(struct Survivor **head);
void main_menu();
struct Survivor* survivor_deleting_menu(struct Survivor *head);
void survivor_menu(struct Survivor **head);

#endif //MAIN_MENU_H