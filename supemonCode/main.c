#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "programLaunch.h"
#include "game.h"

int main()
{
    initSupemon();
    struct player player;

    playerNickname(&player);
    starterChoice(&player);
    player.supcoins = 0;
    player.activeSupemon = 0;

    chooseActivity();

    return 0;
}
