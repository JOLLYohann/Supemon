#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "structure.h"

void effect (struct supemon *supemon, int effectType, int effectValue)
{
    if (effectType == 3)
    {
        supemon->hp += effectValue;
    }
    else if (effectType == 4)
    {
        supemon->atk += effectValue;
    }
    else if (effectType == 5)
    {
        supemon->def += effectValue;
    }
    else if (effectType == 6)
    {
        supemon->eva += effectValue;
    }
}

int chooseActivity (void)
{
    int activity = 0;

    printf("\nWhere do you want to go ?\n 1-the Wild\n 2-the Shop\n 3-the Supemon Center\n 4-Leave the Game\n");
    printf("We go to(1-4): ");
    scanf("%d", &activity);
    fflush(stdin);

    return activity;
}

 void battle (struct player *player)
{
    srand(time(NULL));
    int turn = 0;
    int action = 0;
    int move = 0;
    float probaHit = 0;
    float damage = 0;
    int supcoinsWin = 0;
    int expWin = 0;

    printf("You have choose the wild\n");
    for (int i=0; i<3; i++)
    {
        printf(" .");
        sleep(1);
    }
    struct supemon ennemy = supemonList[rand()%lengthSupemonList];
    printf("\nYou found a %s ! \nWhich Supemon will you use ?\n", ennemy.name);
    for (int i=0; i<6; i++)
    {
        if (player->supemon[i].lvl > 0)
        {
            printf(" %d-%s\n", i+1, player->supemon[i].name);
        }
    }
    printf("Choose your Supemon(1-6): ");
    scanf("%d", &player->activeSupemon);
    fflush(stdin);
    player->activeSupemon --;
    printf("You have choose: %s", player->supemon[player->activeSupemon].name);
    ennemy.lvl = player->supemon[player->activeSupemon].lvl;
    /*
    ennemy.HP += (ennemy.lvl-1)*0.1;
    ennemy.hp = ennemy.HP;
    ennemy.ATK += (ennemy.lvl-1)*0.1;
    ennemy.atk = ennemy.ATK;
    ennemy.DEF += (ennemy.lvl-1)*0.1;
    ennemy.def = ennemy.DEF;
    ennemy.EVA += (ennemy.lvl-1)*0.1;
    ennemy.eva = ennemy.EVA;
    ennemy.ACC += (ennemy.lvl-1)*0.1;
    ennemy.acc = ennemy.ACC;
    ennemy.SPD += (ennemy.lvl-1)*0.1;
    ennemy.spd = ennemy.SPD;
    */
    if (player->supemon[player->activeSupemon].spd > ennemy.spd)
    {
        turn = 1;
    }
    else if (player->supemon[player->activeSupemon].spd < ennemy.spd)
    {
        turn = 2;
    }
    else
    {
        if (rand()%2)
        {
            turn = 1;
        }
        else
        {
            turn = 2;
        }
    }
    do {
        printf("\n\n%s (ennemy)\n HP: %d/%d\n LVL: %d\n ATK: %d\n DEF: %d\n ACC: %d\n EVA: %d\n",
               ennemy.name, ennemy.hp, ennemy.HP, ennemy.lvl, ennemy.atk, ennemy.def, ennemy.acc, ennemy.eva);
        printf("%s (%s)\n HP: %d/%d\n LVL: %d\n ATK: %d\n DEF: %d\n ACC: %d\n EVA: %d\n",
               player->supemon[player->activeSupemon].name, player->nickname, player->supemon[player->activeSupemon].hp,
               player->supemon[player->activeSupemon].HP, player->supemon[player->activeSupemon].lvl, player->supemon[player->activeSupemon].atk,
               player->supemon[player->activeSupemon].def, player->supemon[player->activeSupemon].acc, player->supemon[player->activeSupemon].eva);
        if (turn == 2)
        {
            move = rand()%2;
            if (move)
            {
                effect(&ennemy, ennemy.moves[move].effectType, ennemy.moves[move].effectValue);
                printf("Ennemy Supemon did = %s", ennemy.moves[move].name);
            }
            else
            {
                if (rand()%101 < ((ennemy.acc/(ennemy.acc+player->supemon[player->activeSupemon].eva))*100)+10)
                {
                    if (((ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def)%2)
                    {
                        damage = ((ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def)+rand()%2;
                    }
                    else
                    {
                        damage = (ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def;
                    }
                    effect(&player->supemon[player->activeSupemon], ennemy.moves[move].effectType, damage);
                    printf("Ennemy Supemon did = %s", ennemy.moves[move].name);
                }
                else
                {
                    printf("Ennemy miss");
                }
            }
            turn = 1;
        }
        else
        {
            do {
                printf("\nYour turn:\nWhat will you do ?\n 1-Move\n 2-Change Supemon\n 3-Use item\n 4-Run away\nYou do: ");
                scanf("%d", &action);
                fflush(stdin);
            } while (action > 4 || action < 1);
            if (action == 1)
            {
                do {
                    printf(" 1-%s\n 2-%s\nChoose your move: ", player->supemon[player->activeSupemon].moves[0].name,
                           player->supemon[player->activeSupemon].moves[1].name);
                    scanf("%d", &move);
                    fflush(stdin);
                } while (move != 1 && move != 2);
                move --;
                if (move == 1)
                {
                    effect(&player->supemon[player->activeSupemon], player->supemon[player->activeSupemon].moves[move].effectType,
                    player->supemon[player->activeSupemon].moves[move].effectValue);
                    printf("%s did %s", player->supemon[player->activeSupemon].name, player->supemon[player->activeSupemon].moves[move].name);
                }
                else if (move == 0)
                {
                    probaHit = (((float)player->supemon[player->activeSupemon].acc/(player->supemon[player->activeSupemon].acc+ennemy.eva))*100)+10;
                    printf("\n\n/!\\ Your.ACC: %d / ennemy.EVA: %d / Result: %.1f\n\n", player->supemon[player->activeSupemon].acc, ennemy.eva, probaHit);
                    if (rand()%101 < probaHit)
                    {
                        if (((player->supemon[player->activeSupemon].atk*player->supemon[player->activeSupemon].moves[move].effectValue)/ennemy.def)%2)
                        {
                            damage = -((player->supemon[player->activeSupemon].atk*player->supemon[player->activeSupemon].moves[move].effectValue)/ennemy.def)+rand()%2;
                        }
                        else
                        {
                            damage = -(player->supemon[player->activeSupemon].atk*player->supemon[player->activeSupemon].moves[move].effectValue)/ennemy.def;
                        }
                        effect(&ennemy, player->supemon[player->activeSupemon].moves[move].effectType, damage);
                        printf("%s did %s", player->supemon[player->activeSupemon].name, player->supemon[player->activeSupemon].moves[move].name);
                    }
                    else
                    {
                        printf("%s miss", player->supemon[player->activeSupemon].name);
                    }
                }
            }
            turn = 2;
        }
    } while (player->supemon[player->activeSupemon].hp > 0 && ennemy.hp > 0 && action != 4);
    if (player->supemon[player->activeSupemon].hp < 0)
    {
        printf("\n\nYou loose...\n");
    }
    else if (ennemy.hp < 0)
    {
        printf("\n\nYou win !\n");
        supcoinsWin = (rand()%401)+100;
        expWin = ((rand()%401)+100)*ennemy.lvl;
        player->supcoins += supcoinsWin;
        player->supemon[player->activeSupemon].exp += expWin;
        printf("You win %d Supcoins and %s win %d points of experience\n", supcoinsWin, player->supemon[player->activeSupemon].name, expWin);
        printf("/!\\ EXP = %d\n", player->supemon[player->activeSupemon].exp);
        if (player->supemon[player->activeSupemon].exp >= ((player->supemon[player->activeSupemon].lvl+1) * 1000) - 1500)
        {
            player->supemon[player->activeSupemon].lvl ++;
            player->supemon[player->activeSupemon].exp -= (player->supemon[player->activeSupemon].lvl * 1000) - 1500;
            printf("%s level up! he is now lvl %d\n",player->supemon[player->activeSupemon].name, player->supemon[player->activeSupemon].lvl);
        }
    }
    else if (action == 4)
    {
        printf("\n\nYou run away...\n");
    }
}
