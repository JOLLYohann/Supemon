#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "programLaunch.h"
#include "game.h"

int main()
{
    int activity = 0;

    struct player player;
    initGame(&player);

    playerNickname(&player);
    starterChoice(&player);
    player.supcoins = 0;

    do {
        activity = chooseActivity();
        if (activity == 1)
        {
            battle(&player);
        }
        else if (activity == 2)
        {
            shop(&player);
        }
        else if (activity == 3)
        {
            supemonCenter(&player);
        }
    } while (activity != 4);

    return 0;
}
