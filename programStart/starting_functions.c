#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "../quest/quest_struct.h"
#include "../quest/add_from_file.h"
#include "../quest/list_operations.h"

#include "../survivor/file_operations.h"
#include "../survivor/survivor_struct.h"
#include "../survivor/list_operations.h"


#include "../logicFunctions/logic_functions.h"

#include "starting_functions.h"


void spaces(int length) {
    int pocz = (133-length)/2;
    for (int i=0;i<pocz;i++) {
        printf(" ");
    }
}

void show_title() {
    // printf("   ______ ________ _____________    __  ________  _____  ____________  \n");
    // printf("  / __/ // / __/ //_  __/ __/ _ \\  /  |/  / __/ |/ / _ |/ ___/ __/ _ \\ \n");
    // printf(" _\\ \\/ _  / _// /__/ / / _// , _/ / /|_/ / _//    / __ / (_ / _// , _/ \n");
    // printf("/___/_//_/___/____/_/ /___/_/|_| /_/  /_/___/_/|_/_/ |_\\___/___/_/|_|  \n");
    // printf("\n");
    // printf("   _____ _          _ _              __  __                                   \n");
    // printf("  / ____| |        | | |            |  \\/  |                                  \n");
    // printf(" | (___ | |__   ___| | |_ ___ _ __  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ \n");
    // printf("  \\___ \\| '_ \\ / _ \\ | __/ _ \\ '__| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\n");
    // printf("  ____) | | | |  __/ | ||  __/ |    | |  | | (_| | | | | (_| | (_| |  __/ |   \n");
    // printf(" |_____/|_| |_|\\___|_|\\__\\___|_|    |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   \n");
    // printf("                                                               __/ |          \n");
    // printf("                                                              |___/       \n");
    //
    // printf("\n");
    // printf("\n");
    // printf("\n");


    printf("      @@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@@@@@  @@@@@@@@  @@@@@@@      @@@@@@@@@@    @@@@@@   @@@  @@@   @@@@@@    @@@@@@@@  @@@@@@@@  @@@@@@@   \n");
    printf("     @@@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@@@@@  @@@@@@@@  @@@@@@@@     @@@@@@@@@@@  @@@@@@@@  @@@@ @@@  @@@@@@@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@  \n");
    printf("     !@@       @@!  @@@  @@!       @@!         @@!    @@!       @@!  @@@     @@! @@! @@!  @@!  @@@  @@!@!@@@  @@!  @@@  !@@        @@!       @@!  @@@  \n");
    printf("     !@!       !@!  @!@  !@!       !@!         !@!    !@!       !@!  @!@     !@! !@! !@!  !@!  @!@  !@!!@!@!  !@!  @!@  !@!        !@!       !@!  @!@  \n");
    printf("     !!@@!!    @!@!@!@!  @!!!:!    @!!         @!!    @!!!:!    @!@!!@!      @!! !!@ @!@  @!@!@!@!  @!@ !!@!  @!@!@!@!  !@! @!@!@  @!!!:!    @!@!!@!   \n");
    printf("      !!@!!!   !!!@!!!!  !!!!!:    !!!         !!!    !!!!!:    !!@!@!       !@!   ! !@!  !!!@!!!!  !@!  !!!  !!!@!!!!  !!! !!@!!  !!!!!:    !!@!@!    \n");
    printf("          !:!  !!:  !!!  !!:       !!:         !!:    !!:       !!: :!!      !!:     !!:  !!:  !!!  !!:  !!!  !!:  !!!  :!!   !!:  !!:       !!: :!!   \n");
    printf("         !:!   :!:  !:!  :!:        :!:        :!:    :!:       :!:  !:!     :!:     :!:  :!:  !:!  :!:  !:!  :!:  !:!  :!:   !::  :!:       :!:  !:!  \n");
    printf("     :::: ::   ::   :::   :: ::::   :: ::::     ::     :: ::::  ::   :::     :::     ::   ::   :::   ::   ::  ::   :::   ::: ::::   :: ::::  ::   :::  \n");
    printf("     :: : :     :   : :  : :: ::   : :: : :     :     : :: ::    :   : :      :      :     :   : :  ::    :    :   : :   :: :: :   : :: ::    :   : :  \n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void loading_for(char text[130], bool success) {
    system("cls");
    show_title();
    const int pom= 300;
    int length = strlen(text);
    spaces(length);
    printf("%s [........]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [*.......]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [**......]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [***.....]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [****....]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [*****...]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [******..]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [*******.]\r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [********]\r",text);
    _sleep(pom+300);
    if (success==true) {
        spaces(length);
        printf("%s  success            \r",text);
        _sleep(pom+300);
        system("cls");
    } else {
        spaces(length);
        printf("%s  error\a\a\a               \r",text);
        _sleep(pom+300);
    }

}

void save_time() {
    FILE *f = fopen("../files/graveyard.txt", "a");
    if (!f) {
        perror("Error opening survivor.txt");
        return;
    }
    time_t time_to_save;
    time(&time_to_save);
    char formated_time[80];
    struct tm *local_time = localtime(&time_to_save);
    strftime(formated_time, sizeof(formated_time), "%d/%m/%Y %H:%M:%S", local_time);
    fprintf(f,"Start of session: %s\n",formated_time);
    fclose(f);
}

Survivor* load_survivors(Survivor *head) {
    Survivor* new_survivor = NULL;
    new_survivor = calloc(1,sizeof(Survivor));
    strcpy(new_survivor->name,"Bożydar");
    new_survivor->rations = 5;
    new_survivor->health = 70;
    new_survivor->threat_level = 3;
    head = add_last(head, new_survivor);
    return head;
}

Quest* load_quests(Quest *head) {
    Quest* new_quest = NULL;
    new_quest = calloc(1,sizeof(Quest));
    new_quest->quest_length=9;
    new_quest->succession_rate=70;
    head= add_quest(head,new_quest);
    return head;
}


void start_program(Survivor** survivor_head, Quest** quest_head) {
    save_time();
    show_title();
    loading_for("Building shelter",true);
    loading_for("Gathering rations",true);
    printf("Do you want to enter survivors manually?\n");
    printf("0 - NO\n");
    printf("1 - YES\n");
    int answer = insert_int();
    while (answer != 1 && answer !=0) {
        printf("Enter again\n");
        answer = insert_int();
    }
    if (answer == 0) {
        *survivor_head = add_survivors_from_file();
        if (*survivor_head!=NULL) {
            loading_for("Loading survivors from file",true);
        } else {
            loading_for("Loading survivors from file",false);
            loading_for("Loading survivors from memory",true);
            *survivor_head = load_survivors(*survivor_head);
        }
    } else {
        for (int i=0;i<3;i++) {
            *survivor_head = add_survivor(*survivor_head);
        }
        loading_for("Loading inserted survivors", true);
    }

    show_title();
    *quest_head = add_quest_from_file();
    if (*quest_head!=NULL) {
        loading_for("Loading quests from file",true);
    } else {
        loading_for("Loading quests from file",false);
        loading_for("Loading quests from memory",true);
        *quest_head = load_quests(*quest_head);
    }

    loading_for("Loading user",true);
}
