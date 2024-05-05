#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define PINK "\033[38;2;255;105;180m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"
#define KEY "x"

typedef char string[11];

void printInColor(string *order);

string colors[6] = {"red", "blue", "yellow", "green", "pink", "purple"};

int main(void)
{
    int i, j, k, cor = 0;
    string set[4];
    srand(time(0));

    printf("Description of the game");
    printf("\nMastermind is a two-player game. In this computer implementation, the computer sets the code consisting of four colors (out of six colors in total) arranged in a particular order. The colors can be repeated. ");
    printf("The player's main goal is to guess the code consisting of four colors arranged in a particular order.");
    printf("In each turn, the player sets the colors in a certain order, then the computer responds to the player's guess:\n");
    printf("\tblack indicates the player guessed the color and put it in the right position (without indicating which color)\n");
    printf("\twhite indicates the player chose the right color, but it's not in the correct position\n");
    printf("\tnothing indicates the color doesn't appear in the code\n");
    printf("The player has eight (8) tries to guess the correct colors in the correct order, otherwise the computer wins.\n");
    printf("Good luck!\n");

    printf("\nPossible colors: ");
    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            printf(RED);
            break;
        case 1:
            printf(BLUE);
            break;
        case 2:
            printf(YELLOW);
            break;
        case 3:
            printf(GREEN);
            break;
        case 4:
            printf(PINK);
            break;
        case 5:
            printf(PURPLE);
            break;

        default:
            break;
        }
        printf("%s  ", colors[i]);
    }
    printf(RESET "\n\n");

    /* generate set of colors */
    for (i = 0; i < 4; i++)
        strcpy(set[i], colors[rand() % 6]);

    for (k = 0; k < 8 && cor < 4; k++)
    {

        string col, tmp[4], order[4];
        for (i = 0; i < 4; i++)
            strcpy(tmp[i], set[i]);
        int output[4] = {0};

        /* color input */
        printf("tries left: %d\n", 8-k);
        printf("input:\n");
        for (i = 0; i < 4; i++)
        {
            while (1)
            {
                printf("%d", i + 1);
                switch (i)
                {
                case 0:
                    printf("st");
                    break;
                case 1:
                    printf("nd");
                    break;
                case 2:
                    printf("rd");
                    break;
                case 3:
                    printf("th");
                    break;
                default:
                    break;
                }
                printf(" color: ");
                scanf("%s", col);
                for (j = 0; j < 6; j++)
                    if (strcasecmp(col, colors[j]) == 0)
                        break;
                if (j == 6)
                    printf("incorrect input\n");
                else
                    break;
            }

            strcpy(order[i], col);

            /* is the color in the correct place ? */
            if (strcasecmp(col, tmp[i]) == 0)
            {
                output[i] = 2;
                strcpy(tmp[i], "");
            }
            /* if not, is it at least the correct color ? */
            else
            {
                for (j = 0; j < 4; j++)
                {
                    if (i == j)
                        continue;
                    if (strcasecmp(col, tmp[j]) == 0)
                    {
                        output[i] = 1;
                        strcpy(tmp[j], "");
                    }
                }
            }
        }

        printf("combination of colors:");
        printInColor(order);

        /* the result for this input */
        cor = 0;
        int start = rand() % 4;
        i = start;
        do
        {
            if (output[i] == 1)
                printf("white ");
            else if (output[i] == 2)
            {
                printf("black ");
                cor++;
            }
            i = (i + 1) % 4;
        } while (i != start);

        printf("\n\n");
    }

    if (cor == 4)
        printf("\ngood job! you guessed the correct combination! :)\n\n");
    else
        printf("\nyou didn't break the code :(\nbetter luck next time!");
    printf("\nThe correct combination was:");
    printInColor(set);

    return 0;
}

void printInColor(string *order)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (!strcmp(order[i], "red"))
            printf(RED);
        else if (!strcmp(order[i], "blue"))
            printf(BLUE);
        else if (!strcmp(order[i], "yellow"))
            printf(YELLOW);
        else if (!strcmp(order[i], "green"))
            printf(GREEN);
        else if (!strcmp(order[i], "pink"))
            printf(PINK);
        else if (!strcmp(order[i], "purple"))
            printf(PURPLE);
        printf(" " KEY);
    }
    printf(RESET "\n");
    return;
}