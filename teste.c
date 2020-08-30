#include <stdio.h>
#include <stdlib.h>

int FORJADA_LENGTH = 6;
int NODES_FORJADOS[6] = {3, 4, 5, 6, 7, 8};
int MATRIZ_FORJADA[6][6] = {
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
};

char isReflexive()
{
    char isReflexive = 'V';
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        if (MATRIZ_FORJADA[i][i] != 1)
        {
            isReflexive = 'F';
            break;
        }
    }
    return isReflexive;
}

int **getReflexivePairs()
{
    int **reflexivePairs;
    reflexivePairs = (int **)malloc(sizeof(int *) * FORJADA_LENGTH);
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        reflexivePairs[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            reflexivePairs[i][j] = NODES_FORJADOS[i];
        }
    }

    return reflexivePairs;
}

int **isSymmetric()
{
    int **t;
    t = (int **)malloc(sizeof(int *) * FORJADA_LENGTH);
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        t[i] = (int *)malloc(sizeof(int) * 6);
    }

    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        // if (isSymmetric != 'V')
        // {
        //     break;
        // }
        for (int j = 0; j < FORJADA_LENGTH; j++)
        {
            if (i != j && MATRIZ_FORJADA[i][j] != MATRIZ_FORJADA[j][i])
            {
                t[i][j] = 1;
                printf("inOne %d, %d \n", i, j);
                continue;
            }
            else if (i == j)
            {
                if (MATRIZ_FORJADA[i][j] != 1)
                {
                t[i][j] = 1;
                    printf("inTwo %d, %d \n", i, j);
                    continue;
                }
            }
            printf("inThree %d, %d \n", i, j);
            t[i][j] = -1;
            // t[i][1] = -1;
        }
    }
    return t;
}

int main()
{
    char reflexive = isReflexive();
    int **reflexivePairs = getReflexivePairs();
    printf("Reflexive Pairs: ");
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        printf("(");
        for (int j = 0; j < 2; j++)
        {
            j == 0 ? printf("%d,", reflexivePairs[i][j]) : printf("%d", reflexivePairs[i][j]);
        }
        printf("); ");
    }

    printf("\n");
    char isSymetric = 'V';
    int **symetricValues = isSymmetric();
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        if (isSymetric != 'V')
        {
            break;
        }
        for (int j = 0; j < 2; j++)
        {
            if (symetricValues[i][j] != -1)
            {
                isSymetric = 'F';
                break;
            }
        }
    }
    printf("Anti Symetrical Pairs: ");
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (symetricValues[i][j] != -1)
            {
                printf("(");
                // printf("%d, i:%d j:%d", symetricValues[i][j], i, j);
                int newX = NODES_FORJADOS[i];
                int newY = NODES_FORJADOS[j];
                printf("%d,", newX);
                printf("%d", newY);
                printf("); ");
                printf("\n");
            }
        }
    }
    // printf("\n%c\n", symmetric);
}