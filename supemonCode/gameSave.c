#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"

void saving(struct player *player) {
    char choice = 'X';
    do {
        printf("Do you wanna save your progression ? (Y/N): ");
        scanf("%c", &choice);
        fflush(stdin);
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    if (choice == 'Y' || choice == 'y') {
        FILE *file = fopen("save.txt", "w");
        if (!file) {
            printf("/!\\ Error in creation of file save /!\\\n");
            return;
        }

        fprintf(file, "%s\n", player->nickname);
        fprintf(file, "%d\n", player->supcoins);

        for (int i = 0; i < 6; i++) {
            fprintf(file, "%s\n", player->supemon[i].name);
            fprintf(file, "%d\n", player->supemon[i].lvl);
            fprintf(file, "%d\n", player->supemon[i].exp);
            fprintf(file, "%d\n", player->supemon[i].hp);
            fprintf(file, "%d\n", player->supemon[i].HP);
            fprintf(file, "%d\n", player->supemon[i].ATK);
            fprintf(file, "%d\n", player->supemon[i].DEF);
            fprintf(file, "%d\n", player->supemon[i].EVA);
            fprintf(file, "%d\n", player->supemon[i].ACC);
            fprintf(file, "%d\n", player->supemon[i].SPD);
        }
        fclose(file);
        printf("Saving successfully!\n");
    }
}

void loading(struct player *player) {
    FILE *file = fopen("save.txt", "r");

    if (!file) {
        printf("/!\\ Error opening the save file /!\\\n");
        return;
    }

    fgets(player->nickname, 50, file);
    player->nickname[strcspn(player->nickname, "\n")] = '\0';
    fscanf(file, "%d", &player->supcoins);
    fgetc(file);

    for (int i = 0; i < 6; i++) {
        fgets(player->supemon[i].name, 20, file);
        printf("%d/%s\n", i, player->supemon[i].name);
        fscanf(file, "%d", &player->supemon[i].lvl);
        fscanf(file, "%d", &player->supemon[i].exp);
        fscanf(file, "%d", &player->supemon[i].hp);
        fscanf(file, "%d", &player->supemon[i].HP);
        fscanf(file, "%d", &player->supemon[i].ATK);
        fscanf(file, "%d", &player->supemon[i].DEF);
        fscanf(file, "%d", &player->supemon[i].EVA);
        fscanf(file, "%d", &player->supemon[i].ACC);
        fscanf(file, "%d", &player->supemon[i].SPD);
        fgetc(file);

        player->supemon[i].atk = player->supemon[i].ATK;
        player->supemon[i].def = player->supemon[i].DEF;
        player->supemon[i].eva = player->supemon[i].EVA;
        player->supemon[i].acc = player->supemon[i].ACC;
        player->supemon[i].spd = player->supemon[i].SPD;
    }

    fclose(file);
    printf("Loading successfully!\n");
}



int askLoading (void)
{
    char choice = 'X';

    FILE *file = fopen("save.txt", "r");

    if (file)
    {
        do
        {
            printf("Do you wanna load your save ? (Y/N): ");
            scanf("%c", &choice);
            fflush(stdin);
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        fclose(file);
        if (choice == 'Y' || choice == 'y')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
