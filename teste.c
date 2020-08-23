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
    {0, 1, 0, 1, 0, 1},
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

char isSymmetric()
{
    char isSymmetric = 'V';
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        if (isSymmetric != 'V')
        {
            break;
        }
        for (int j = 0; j < FORJADA_LENGTH; j++)
        {
            if (MATRIZ_FORJADA[i][j] == 1 && MATRIZ_FORJADA[i][j] != MATRIZ_FORJADA[j][i])
            {
                printf("i = %d, j = %d", i, j);
                isSymmetric = 'F';
                break;
            }
        }
    }
    return isSymmetric;
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
            printf("%d", reflexivePairs[i][j]);
        }
        printf("), ");
    }

    printf("\n");
    char symmetric = isSymmetric();
    printf("\n%c\n", symmetric);
}