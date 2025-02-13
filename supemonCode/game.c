#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "structure.h"

void effect (struct supemon *supemon, int effectType, int effectValue)
{
    if (effectType == 3)
    {
        supemon->hp += effectValue;
        if (supemon->hp < 0)
        {
            supemon->hp = 0;
        }
        else if (supemon->hp > supemon->HP)
        {
            supemon->hp = supemon->HP;
        }
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
    int changeSupemon = 0;
    int useItem = 0;
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
        if (player->supemon[i].HP > 0)
        {
            printf(" %d-%s\n", i+1, player->supemon[i].name);
        }
    }
    do
    {
        printf("Choose your Supemon(1-6): ");
        scanf("%d", &player->activeSupemon);
        fflush(stdin);
    } while (player->activeSupemon < 1 || player->activeSupemon > 6);
    player->activeSupemon --;
    printf("You have choose: %s", player->supemon[player->activeSupemon].name);
    ennemy.lvl = player->supemon[player->activeSupemon].lvl;
    ennemy.HP *= pow(1.3, ennemy.lvl-1);
    ennemy.hp = ennemy.HP;
    ennemy.ATK *= pow(1.3, ennemy.lvl-1);
    ennemy.atk = ennemy.ATK;
    ennemy.DEF *= pow(1.3, ennemy.lvl-1);
    ennemy.def = ennemy.DEF;
    ennemy.EVA *= pow(1.3, ennemy.lvl-1);
    ennemy.eva = ennemy.EVA;
    ennemy.ACC *= pow(1.3, ennemy.lvl-1);
    ennemy.acc = ennemy.ACC;
    ennemy.SPD *= pow(1.3, ennemy.lvl-1);
    ennemy.spd = ennemy.SPD;
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
                if (rand()%101 < (((float)ennemy.acc/(ennemy.acc+player->supemon[player->activeSupemon].eva))*100)+10)
                {
                    if (((ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def)%2)
                    {
                        damage = -((ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def)+rand()%2;
                    }
                    else
                    {
                        damage = -(ennemy.atk*ennemy.moves[move].effectValue)/player->supemon[player->activeSupemon].def;
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
                    printf(" 1-%s\n 2-%s\n 3-Cancel\nChoose your move: ", player->supemon[player->activeSupemon].moves[0].name,
                           player->supemon[player->activeSupemon].moves[1].name);
                    scanf("%d", &move);
                    fflush(stdin);
                } while (move < 1 || move > 3);
                move --;
                if (move == 1)
                {
                    effect(&player->supemon[player->activeSupemon], player->supemon[player->activeSupemon].moves[move].effectType,
                    player->supemon[player->activeSupemon].moves[move].effectValue);
                    printf("%s did %s", player->supemon[player->activeSupemon].name, player->supemon[player->activeSupemon].moves[move].name);
                    turn = 2;
                }
                else if (move == 0)
                {
                    if (rand()%101 < (((float)player->supemon[player->activeSupemon].acc/(player->supemon[player->activeSupemon].acc+ennemy.eva))*100)+10)
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
                    turn = 2;
                }
            }
            else if (action == 2)
            {
                for (int i=0; i<6; i++)
                {
                    if (player->supemon[i].HP != 0)
                    {
                        printf(" %d-%s\n", i+1, player->supemon[i]);
                    }
                }
                do
                {
                    printf("Choose your Supemon(1-6), Cancel (7): ");
                    scanf("%d", &changeSupemon);
                    fflush(stdin);
                } while (changeSupemon < 1 || changeSupemon > 7);
                if (changeSupemon != 7)
                {
                    changeSupemon --;
                    if (player->supemon[changeSupemon].HP != 0)
                    {
                        player->supemon[player->activeSupemon].atk = player->supemon[player->activeSupemon].ATK;
                        player->supemon[player->activeSupemon].def = player->supemon[player->activeSupemon].DEF;
                        player->supemon[player->activeSupemon].eva = player->supemon[player->activeSupemon].EVA;
                        player->supemon[player->activeSupemon].acc = player->supemon[player->activeSupemon].ACC;
                        player->supemon[player->activeSupemon].spd = player->supemon[player->activeSupemon].SPD;
                        player->activeSupemon = changeSupemon;
                        printf("You have choose: %s", player->supemon[player->activeSupemon].name);
                        turn = 2;
                    }
                }
            }
            else if (action == 3)
            {
                for (int i=0; i<99; i++)
                {
                    if (player->items[i].price != 0)
                    {
                        printf("%d-%s\n", i+1, player->items[i].name);
                    }
                }
                do
                {
                    printf("Which item will you use: ");
                    scanf("%d", &useItem);
                    fflush(stdin);
                } while (useItem < 1 || useItem > 99);
                useItem --;
                if (player->items[useItem].price == 0)
                {
                    printf("This pocket is empty...");
                }
                else if (player->items[useItem].effectType == 0)
                {
                    player->items[useItem].price = 0;
                    if (rand()%101 < ((((float)ennemy.HP-ennemy.hp)/ennemy.HP)-0.5)*100)
                    {
                        for (int i=0; i<6; i++)
                        {
                            if (player->supemon[i].HP == 0)
                            {
                                player->supemon[i] = ennemy;
                                ennemy.hp = 0;
                                printf("You capture %s\n", ennemy.name);
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("Your Supeball fail...");
                    }
                    turn = 2;
                }
                else
                {
                    player->items[useItem].price = 0;
                    effect(&player->supemon[player->activeSupemon], player->items[useItem].effectType, player->items[useItem].effectValue);
                    turn = 2;
                }
            }
            else if (action == 4)
            {
                if (rand()%101 > ((float)player->supemon[player->activeSupemon].spd/(player->supemon[player->activeSupemon].spd+ennemy.spd))*100)
                {
                    printf("\nYou failed to run away");
                    action = 0;
                    turn = 2;
                }
            }
        }
    } while (player->supemon[player->activeSupemon].hp > 0 && ennemy.hp > 0 && action != 4);
    if (player->supemon[player->activeSupemon].hp <= 0)
    {
        printf("\nYou loose...\n");
    }
    else if (ennemy.hp <= 0)
    {
        printf("\nYou win !\n");
        supcoinsWin = (rand()%401)+100;
        expWin = ((rand()%401)+100)*ennemy.lvl;
        player->supcoins += supcoinsWin;
        player->supemon[player->activeSupemon].exp += expWin;
        printf("You win %d Supcoins and %s win %d points of experience\n", supcoinsWin, player->supemon[player->activeSupemon].name, expWin);
        if (player->supemon[player->activeSupemon].exp >= ((player->supemon[player->activeSupemon].lvl+1) * 1000) - 1500)
        {
            player->supemon[player->activeSupemon].lvl ++;
            player->supemon[player->activeSupemon].exp -= (player->supemon[player->activeSupemon].lvl * 1000) - 1500;
            printf("%s level up! he is now lvl %d\n",player->supemon[player->activeSupemon].name, player->supemon[player->activeSupemon].lvl);
            if (fmod(player->supemon[player->activeSupemon].ATK * 1.3, 1.0) > 0)
            {
                player->supemon[player->activeSupemon].ATK *= 1.3 + rand()%2;
            }
            else
            {
                player->supemon[player->activeSupemon].ATK *= 1.3;
            }
            if (fmod(player->supemon[player->activeSupemon].DEF * 1.3, 1.0) > 0)
            {
                player->supemon[player->activeSupemon].DEF *= 1.3 + rand()%2;
            }
            else
            {
                player->supemon[player->activeSupemon].DEF *= 1.3;
            }
            if (fmod(player->supemon[player->activeSupemon].EVA * 1.3, 1.0) > 0)
            {
                player->supemon[player->activeSupemon].EVA *= 1.3 + rand()%2;
            }
            else
            {
                player->supemon[player->activeSupemon].EVA *= 1.3;
            }
            if (fmod(player->supemon[player->activeSupemon].ACC * 1.3, 1.0) > 0)
            {
                player->supemon[player->activeSupemon].ACC *= 1.3 + rand()%2;
            }
            else
            {
                player->supemon[player->activeSupemon].ACC *= 1.3;
            }
            if (fmod(player->supemon[player->activeSupemon].SPD * 1.3, 1.0) > 0)
            {
                player->supemon[player->activeSupemon].SPD *= 1.3 + rand()%2;
            }
            else
            {
                player->supemon[player->activeSupemon].SPD *= 1.3;
            }
        }
    }
    else if (action == 4)
    {
        printf("\nYou run away...\n");
    }
    player->supemon[player->activeSupemon].atk = player->supemon[player->activeSupemon].ATK;
    player->supemon[player->activeSupemon].def = player->supemon[player->activeSupemon].DEF;
    player->supemon[player->activeSupemon].eva = player->supemon[player->activeSupemon].EVA;
    player->supemon[player->activeSupemon].acc = player->supemon[player->activeSupemon].ACC;
    player->supemon[player->activeSupemon].spd = player->supemon[player->activeSupemon].SPD;
}

void shop (struct player *player)
{
    int action = 0;
    int choice = 0;

    do
    {
        printf("\nWelcome in the Shop %s\n 1-Buy items\n 2-Sell items\nYou do: ", player->nickname);
        scanf("%d", &action);
        fflush(stdin);
    } while (action != 1 && action != 2);
    if (action == 1)
    {
        printf("\nYou have %d Supcoins\n", player->supcoins);
        for (int i=0; i<4; i++)
        {
            printf(" %d-%s (%d Supcoins)\n", i+1, itemList[i].name, itemList[i].price);
        }
        do
        {
            do
            {
                printf("Select item(1-4), or Cancel (5): ");
                scanf("%d", &choice);
                fflush(stdin);
            } while (choice < 1 || choice > 5);
            choice--;
            if (choice != 4)
            {
                if (itemList[choice].price < player->supcoins)
                {
                    player->supcoins -= itemList[choice].price;
                    for (int i=0; i<99; i++)
                    {
                        if (player->items[i].price == 0)
                        {
                            player->items[i] = itemList[choice];
                            printf("You have choose %s\n", player->items[i].name);
                            break;
                        }
                    }
                }
                else
                {
                    printf("You don't have enought money, you need %d Supcoins\n", itemList[choice].price - player->supcoins);
                }
            }
        } while (choice != 4);
        printf("Your now leaving the Shop\n");
    }
    else
    {
        do
        {
            printf("\nYou have %d Supcoins\n 0-Cancel\n", player->supcoins);
            for (int i=0; i<99; i++)
            {
                if (player->items[i].price != 0)
                {
                    printf(" %d-%s\n", i+1, player->items[i].name);
                }
            }
            printf("Which item would you sell: ");
            scanf("%d", &choice);
            fflush(stdin);
            if (player->items[choice].price > 0)
            {
                choice -- ;
                player->supcoins += player->items[choice].price/2;
                player->items[choice].price = 0;
                choice ++ ;
            }
        } while (choice != 0);
        printf("Your now leaving the Shop\n");
    }
}

void supemonCenter (struct player *player)
{
    char healing = 'X';

    printf("\nWelcome in the Supemon Center %s\n", player->nickname);
    for (int i=0; i<6; i++)
    {
        if (player->supemon[i].HP > 0)
        {
            printf(" %d-%s HP: %d/%d\n", i+1, player->supemon[i].name, player->supemon[i].hp, player->supemon[i].HP);
        }
    }
    do {
        printf("Do you want to heal your Supemon ? (Y/N): ");
        scanf("%c", &healing);
        fflush(stdin);
    } while (healing != 'Y' && healing != 'y' && healing != 'N' && healing != 'n');
    if (healing == 'Y' || healing == 'y')
    {
        for (int i=0; i<6; i++)
        {
            player->supemon[i].hp = player->supemon[i].HP;
        }
        printf("All your Supemon have been heal\n");
    }
    printf("Your now leaving the Supemon Center\n");
}
