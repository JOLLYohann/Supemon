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
    struct supemon supemon[6];
    int activeSupemon;
    int supcoins;
    struct items items[100];
};

void initSupemon(void);

extern struct supemon supmander;
extern struct supemon supasaur;
extern struct supemon supirtle;

extern struct moves Scratch;
extern struct moves Grawl;
extern struct moves Pound;
extern struct moves Foliage;
extern struct moves Shell;

#endif // STRUCTURE_H_INCLUDED
