#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "programLaunch.h"

int main()
{
    initSupemon();
    struct player player;

    playerNickname(&player);
    starterChoice(&player);
    player.supcoins = 0;
    player.activeSupemon = 0;
    printf("Vous avez choisi %s", player.supemon[0]);

    return 0;
}
