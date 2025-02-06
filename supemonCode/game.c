#include <stdio.h>

int chooseActivity (void)
{
    int activity = 0;

    printf("Where do you want to go ?\n 1-the Wild\n 2-the Shop\n 3-the Supemon Center\n 4-Leave the Game\n");
    printf("We go to(1-4): ");
    scanf("%d", &activity);
    fflush(stdin);
    printf("You have choose: %d", activity);
}
