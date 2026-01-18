/**
    *
    *
    *    ▄█████ ▄▄ ▄▄ ▄▄▄▄▄ ▄▄   ▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ██▄  ▄██  ▄▄▄  ▄▄  ▄▄  ▄▄▄   ▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄
    *    ▀▀▀▄▄▄ ██▄██ ██▄▄  ██     ██   ██▄▄  ██▄█▄   ██ ▀▀ ██ ██▀██ ███▄██ ██▀██ ██ ▄▄ ██▄▄  ██▄█▄
    *    █████▀ ██ ██ ██▄▄▄ ██▄▄▄  ██   ██▄▄▄ ██ ██   ██    ██ ██▀██ ██ ▀██ ██▀██ ▀███▀ ██▄▄▄ ██ ██
    *
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "survivor/survivor_struct.h"
#include "quest/add_from_file.h"
#include "logicFunctions/logic_functions.h"
#include "programStart/main_menu.h"
#include "programStart/starting_functions.h"
#include "quest/list_operations.h"
#include "quest/quest_struct.h"
#include "survivor/list_operations.h"
#include "quest/show.h"
#include "survivor/show.h"
#include "survivor/file_operations.h"



int main() {
    srand(time(NULL));
    Survivor *head = NULL;
    //add_to_file(head);

    struct Quest *q_head = NULL;
    struct Quest *quest_in_progress = NULL;
    start_program(&head,&q_head);
    show_title();
    survivor_id_update(head);
    int menu = 1;
    add_all_to_file(head);
    survivor_health_status_change(head);
    while (menu == 1) {
        main_menu(&head, &q_head, &quest_in_progress);
        break;
    }


    return 0;
}
