#include <string.h>

#include "structure.h"

struct moves Scratch = {
    .effectType = 1,
    .effectValue = 3
};

struct moves Grawl = {
    .effectType = 2,
    .effectValue = 1
};

struct moves Pound = {
    .effectType = 1,
    .effectValue = 2
};

struct moves Foliage = {
    .effectType = 3,
    .effectValue = 1
};

struct moves Shell = {
    .effectType = 4,
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

void initSupemon(void)
{
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
}
