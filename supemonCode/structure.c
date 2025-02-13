#include <string.h>

#include "structure.h"

struct items potion = {
    .price = 100,
    .effectType = 3,
    .effectValue = 5
};

struct items superPotion = {
    .price = 300,
    .effectType = 3,
    .effectValue = 10
};

struct items rareCandy = {
    .price = 700,
    .effectType = 1,
    .effectValue = 5
};

struct items supeball = {
    .price = 50,
    .effectType = 0
};

struct moves Scratch = {
    .effectType = 3,
    .effectValue = 3
};

struct moves Grawl = {
    .effectType = 4,
    .effectValue = 1
};

struct moves Pound = {
    .effectType = 3,
    .effectValue = 2
};

struct moves Foliage = {
    .effectType = 6,
    .effectValue = 1
};

struct moves Shell = {
    .effectType = 5,
    .effectValue = 1
};

struct supemon supmander = {
    .lvl = 1,
    .exp = 0,
    .hp = 10,
    .HP = 10,
    .atk = 1,
    .ATK = 1,
    .def = 1,
    .DEF = 1,
    .eva = 1,
    .EVA = 1,
    .acc = 2,
    .ACC = 2,
    .spd = 1,
    .SPD = 1
};

struct supemon supasaur = {
    .lvl = 1,
    .exp = 0,
    .hp = 9,
    .HP = 9,
    .atk = 1,
    .ATK = 1,
    .def = 1,
    .DEF = 1,
    .eva = 3,
    .EVA = 3,
    .acc = 2,
    .ACC = 2,
    .spd = 2,
    .SPD = 2
};

struct supemon supirtle = {
    .lvl = 1,
    .exp = 0,
    .hp = 11,
    .HP = 11,
    .atk = 1,
    .ATK = 1,
    .def = 2,
    .DEF = 2,
    .eva = 2,
    .EVA = 2,
    .acc = 1,
    .ACC = 1,
    .spd = 2,
    .SPD = 2
};

int lengthSupemonList = 3;

struct items itemList[4];
struct supemon supemonList[3];

void initGame(struct player *player)
{
    for (int i=0; i<6; i++)
    {
        player->supemon[i].HP = 0;
    }
    for (int i=0; i<100; i++)
    {
        player->items[i].price = 0;
    }

    strcpy(potion.name, "Potion");
    strcpy(superPotion.name, "Super Potion");
    strcpy(rareCandy.name, "Rare Candy");
    strcpy(supeball.name, "Supeball");

    strcpy(Scratch.name, "Scratch");
    strcpy(Grawl.name, "Grawl");
    strcpy(Pound.name, "Pound");
    strcpy(Foliage.name, "Foliage");
    strcpy(Shell.name, "Shell");

    supmander.moves[0] = Scratch;
    supmander.moves[1] = Grawl;
    supasaur.moves[0] = Pound;
    supasaur.moves[1] = Foliage;
    supirtle.moves[0] = Pound;
    supirtle.moves[1] = Shell;

    strcpy(supmander.name, "Supmander");
    strcpy(supasaur.name, "Supasaur");
    strcpy(supirtle.name, "Supirtle");

    itemList[0] = potion;
    itemList[1] = superPotion;
    itemList[2] = rareCandy;
    itemList[3] = supeball;

    supemonList[0] = supmander;
    supemonList[1] = supasaur;
    supemonList[2] = supirtle;

    for (int i=0; i<5; i++)
    {
        player->items[i] = supeball;
    }
}
