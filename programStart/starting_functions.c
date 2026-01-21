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
    int pocz = (157-length)/2;
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

    printf("   ========================================================================================================================================================\n");
    printf("   |                                                                                                                                                      |\n");
    printf("   |    @@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@@@@@  @@@@@@@@  @@@@@@@      @@@@@@@@@@    @@@@@@   @@@  @@@   @@@@@@    @@@@@@@@  @@@@@@@@  @@@@@@@    |\n");
    printf("   |   @@@@@@@   @@@  @@@  @@@@@@@@  @@@       @@@@@@@  @@@@@@@@  @@@@@@@@     @@@@@@@@@@@  @@@@@@@@  @@@@ @@@  @@@@@@@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@   |\n");
    printf("   |   !@@       @@!  @@@  @@!       @@!         @@!    @@!       @@!  @@@     @@! @@! @@!  @@!  @@@  @@!@!@@@  @@!  @@@  !@@        @@!       @@!  @@@   |\n");
    printf("   |   !@!       !@!  @!@  !@!       !@!         !@!    !@!       !@!  @!@     !@! !@! !@!  !@!  @!@  !@!!@!@!  !@!  @!@  !@!        !@!       !@!  @!@   |\n");
    printf("   |   !!@@!!    @!@!@!@!  @!!!:!    @!!         @!!    @!!!:!    @!@!!@!      @!! !!@ @!@  @!@!@!@!  @!@ !!@!  @!@!@!@!  !@! @!@!@  @!!!:!    @!@!!@!    |\n");
    printf("   |    !!@!!!   !!!@!!!!  !!!!!:    !!!         !!!    !!!!!:    !!@!@!       !@!   ! !@!  !!!@!!!!  !@!  !!!  !!!@!!!!  !!! !!@!!  !!!!!:    !!@!@!     |\n");
    printf("   |        !:!  !!:  !!!  !!:       !!:         !!:    !!:       !!: :!!      !!:     !!:  !!:  !!!  !!:  !!!  !!:  !!!  :!!   !!:  !!:       !!: :!!    |\n");
    printf("   |       !:!   :!:  !:!  :!:        :!:        :!:    :!:       :!:  !:!     :!:     :!:  :!:  !:!  :!:  !:!  :!:  !:!  :!:   !::  :!:       :!:  !:!   |\n");
    printf("   |   :::: ::   ::   :::   :: ::::   :: ::::     ::     :: ::::  ::   :::     :::     ::   ::   :::   ::   ::  ::   :::   ::: ::::   :: ::::  ::   :::   |\n");
    printf("   |   :: : :     :   : :  : :: ::   : :: : :     :     : :: ::    :   : :      :      :     :   : :  ::    :    :   : :   :: :: :   : :: ::    :   : :   |\n");
    printf("   |                                                                                                                                                      |\n");
    printf("   ========================================================================================================================================================\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void loading_for(char text[130], bool success) {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    show_title();
    const int pom= 5;
    int length = strlen(text);
    spaces(length);
    printf("%s [........]         \r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [*.......]         \r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [**......]          \r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [***.....]          \r",text);
    _sleep(pom);
    spaces(length);
    printf("%s [****....]          \r",text);
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

Survivor* load_survivors(Survivor *head, int n) {
    Survivor* new_survivor = NULL;
    char name_tab[20][100] = {
        "Filip", "Yuliia", "Inga", "Marcin", "Nadia", "Aleksander", "Joanna", "Weronika", "Karolina", "Alicja",
        "Grzegorz", "Dariusz", "Krzysztof", "Sabina", "Maciej", "Maria", "Oliver", "Renata", "Paulina", "Hubert",
    };
    for (int i=0;i<n;i++) {
        new_survivor = calloc(1,sizeof(Survivor));
        strcpy(new_survivor->name,name_tab[i]);
        new_survivor->rations = rand()%10+1;
        new_survivor->health = rand()%100+1;
        new_survivor->threat_level = rand()%10+1;
        new_survivor->skill=rand()%4;
        head = add_last(head,new_survivor);
    }
    return head;
}

Quest* load_quests(Quest *head, int n) {
    Quest* new_quest = NULL;
    for (int i=0;i<n;i++) {
        new_quest = calloc(1,sizeof(Quest));
        new_quest->quest_length=rand()%10+1;
        new_quest->succession_rate=rand()%100+1;
        head= add_quest(head,new_quest);
    }

    return head;
}


void start_program(Survivor** survivor_head, Quest** quest_head) {
    save_time();
    show_title();
    loading_for("Building shelter",true);
    loading_for("Gathering rations",true);
    show_title();
    printf("Do you want to enter survivors manually?\n");
    printf("1 - YES\n");
    printf("0 - NO\n");
    int answer = check_interval(0,1);
    if (answer == 0) {
        *survivor_head = add_survivors_from_file();
        if (*survivor_head!=NULL) {
            loading_for("Loading survivors from file",true);
        } else {
            loading_for("Loading survivors from file",false);
            loading_for("Loading survivors from memory",true);
        }
    } else {
        for (int i=0;i<20;i++) {
            *survivor_head = add_survivor(*survivor_head);
        }
        loading_for("Loading inserted survivors", true);
    }
    int pom=check_amount(*survivor_head);
    if (pom < 20) {
        *survivor_head=load_survivors(*survivor_head,20-pom);
    }

    show_title();
    *quest_head = add_quest_from_file();
    if (*quest_head!=NULL) {
        loading_for("Loading quests from file",true);
    } else {
        loading_for("Loading quests from file",false);
        loading_for("Loading quests from memory",true);
    }
    pom = check_amount_quest(*quest_head);
    if (pom<20) {
        *quest_head=load_quests(*quest_head,20-pom);
    }

    loading_for("Loading user",true);
}
