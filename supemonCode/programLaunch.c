#include <stdio.h>

#include "structure.h"

void playerNickname(struct player *player)
{
    char nicknameValidation = 'X';

    printf("To begin you need to enter a nickname: ");
    gets(player->nickname);
    printf("Your nickname is: %s\n", player->nickname);
    do {
        printf("Do you agree ? (Y/N): ");
        scanf("%c", &nicknameValidation);
        fflush(stdin);
        if (nicknameValidation == 'N' || nicknameValidation == 'n')
        {
            printf("Enter a nickname: ");
            gets(player->nickname);
            printf("Your nickname is: %s\n", player->nickname);
        }
    } while (nicknameValidation != 'Y' && nicknameValidation != 'y');
    printf("Hi %s, welcome in Supemon world !\n", player->nickname);
}

void starterChoice(struct player *player)
{
    int choice = 0;

    printf("Now choose your starter to begin your adventure:\n 1-Supmander\n 2-Supasaur\n 3-Supirtle\n");
    do {
            printf("Choose your Supemon(1-3): ");
        scanf("%d", &choice);
        fflush(stdin);
    } while (choice < 1 || choice > 3);
    if (choice == 1)
    {
        player->supemon[0] = supmander;
    }
    else if (choice == 2)
    {
        player->supemon[0] = supasaur;
    }
    else if (choice == 3)
    {
        player->supemon[0] = supirtle;
    }
    printf("You have choose %s\n", player->supemon[0]);
}
