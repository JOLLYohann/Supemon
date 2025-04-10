#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

struct items
{
    char name[20];
    int price;
    int effectType;
    int effectValue;
};

struct moves
{
    char name[20];
    int effectType;
    int effectValue;
};

struct supemon
{
    char name[20];
    int lvl;
    int exp;
    struct moves moves[2];
    int hp;
    int HP;
    int atk;
    int ATK;
    int def;
    int DEF;
    int eva;
    int EVA;
    int acc;
    int ACC;
    int spd;
    int SPD;
};

struct player
{
    char nickname[50];
    struct supemon supemon[5];
    int activeSupemon;
    int supcoins;
    struct items items[99];
};

void initGame(struct player *player);

extern int lengthSupemonList;
extern struct items itemList[4];
extern struct supemon supemonList[3];
extern struct supemon supmander;
extern struct supemon supasaur;
extern struct supemon supirtle;

#endif // STRUCTURE_H_INCLUDED
