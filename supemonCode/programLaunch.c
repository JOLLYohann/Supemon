#include <stdio.h>

#include "structure.h"

void playerNickname(struct player *player)
{
    char nicknameValidation = 'X';


    printf("+----To begin, enter a nickname:-----\n|");
    gets(player->nickname);
    printf("| Your nickname is: %-10s\n", player->nickname);
    do {
        printf("| Do you agree? (Y/N):");
        scanf(" %c", &nicknameValidation);
        fflush(stdin);
        if (nicknameValidation == 'N' || nicknameValidation == 'n')
        {
            printf("+----------------------------\n");
            printf("| Enter a nickname:");
            gets(player->nickname);
            printf("| Your nickname is: %-10s\n", player->nickname);
        }
    } while (nicknameValidation != 'Y' && nicknameValidation != 'y');
     printf("+------------------------------------------\n");
    printf("|Hi %-10s, welcome to Supemon World!\n", player->nickname);

}

void starterChoice(struct player *player)
{
    int choice = 0;


    printf("+-----Choose your starter Supemon:-----\n");
    printf("|  1 - Supmander\n");
    printf("|  2 - Supasaur\n");
    printf("|  3 - Supirtle\n");

    do {
            printf("|Choose your Supemon(1-3): ");
        scanf("%d", &choice);
        fflush(stdin);
    } while (choice < 1 || choice > 3);
    player->supemon[0] = supemonList[--choice];
    printf("+----------------------------------------------\n");
    printf("| You have chosen %-10s\n", player->supemon[0]);
    printf("| To begin your adventure, you get x5 Supeball\n");
}
