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
#include <time.h>

#include "survivor/survivor_struct.h"
#include "quest/add_from_file.h"
#include "programStart/main_menu.h"
#include "programStart/starting_functions.h"
#include "survivor/list_operations.h"

int main() {
    srand(time(NULL));
    Survivor *head = NULL;
    int rations = 1000;
    int day = 0;
    struct Quest *q_head = NULL;
    struct Quest *quest_in_progress = NULL;
    start_program(&head, &q_head);
    show_title();
    survivor_id_update(head);
    survivor_health_status_change(head);
    main_menu(&head, &q_head, &quest_in_progress, &rations, &day);
    end_program(day, check_amount(head));

    return 0;
}
