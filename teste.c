#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int **resolveSymmetryMatrix()
{
    // * ALOCA MATRIZ AUXILIAR
    int **aux;
    aux = (int **)malloc(sizeof(int *) * FORJADA_LENGTH);
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        aux[i] = (int *)malloc(sizeof(int) * 6);
    }
    // AS POSICOES QUE AFETAM A CONDICAO SE SIMETRIA, SAO MARCADAS COM -1
    // AS POSICOES QUE AFETAM A CONDICAO DE ANTI SIMETRIA SAO MARCADAS COM -2
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        for (int j = 0; j < FORJADA_LENGTH; j++)
        {
            if (i != j && MATRIZ_FORJADA[i][j] != MATRIZ_FORJADA[j][i])
            {
                // NAO PODE SER SIMETRICA
                aux[i][j] = -1;
            }
            else if (i != j && MATRIZ_FORJADA[i][j] == 1 && MATRIZ_FORJADA[j][i] == 1)
            {
                // NAO PODE SER ANTI SIMETRICA
                aux[i][j] = -2;
            }
            else if (i == j && MATRIZ_FORJADA[i][j] != MATRIZ_FORJADA[j][i])
            {
                // NAO PODE SER SIMETRICA
                aux[i][j] = -1;
            }
        }
    }
    return aux;
}

char *resolveSymmetryCases(int **symmetricMatrix, char *cases)
{
    strcpy(cases, "VVF");
    for (int i = 0; i < FORJADA_LENGTH; i++)
    {
        for (int j = 0; j < FORJADA_LENGTH; j++)
        {
            if (symmetricMatrix[i][j] == -1)
            {
                cases[0] = 'F';
            }
            if (symmetricMatrix[i][j] == -2)
            {
                cases[1] = 'F';
            }
        }
    }
    if (cases[0] == 'F' && cases[1] == 'F')
    {
        cases[2] = 'V';
    }
}

void printPairs(int **symmetric, int value)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (symmetric[i][j] == value)
            {
                printf("(");
                int newX = NODES_FORJADOS[i];
                int newY = NODES_FORJADOS[j];
                printf("%d,", newX);
                printf("%d", newY);
                printf("); ");
            }
        }
    }
    printf("\n");
}

void printSymmetryCases(int **symmetric, char *cases)
{
    char isSymmetric = cases[0];
    char isAntiSymmetric = cases[1];
    char isAsymmetric = cases[2];
    if (isSymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printPairs(symmetric, -2);
        printf("Assimetrica: %c \n", isAsymmetric);
    }

    if (isAntiSymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printPairs(symmetric, -1);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printf("Assimetrica: %c \n", isAsymmetric);
    }

    if (isAsymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printPairs(symmetric, -1);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printPairs(symmetric, -2);
        printf("Assimetrica: %c \n", isAsymmetric);
    }
}

// TODO
// char resolveTransitivity()
// {
//     for (int i = 0; i < FORJADA_LENGTH; i++)
//     {
//         for (int j = 0; j < FORJADA_LENGTH; j++)
//         {
//             int a, b;
//             if (i != j && MATRIZ_FORJADA[i][j] == 1)
//             {
//                 a = i;
//                 b = j;
//                 for (int c = 0; c < FORJADA_LENGTH; c++)
//                 {
//                     if (MATRIZ_FORJADA[j][c] == 1 && MATRIZ_FORJADA[a][c] = 1)
//                     {
//                         return 'V';
//                     }
//                 }
//             }
//         }
//     }
// }

int main()
{
    char reflexive = isReflexive();
    printf("%c\n", reflexive);
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

    int **symmetricMatrix = resolveSymmetryMatrix();
    char cases[3];
    resolveSymmetryCases(symmetricMatrix, cases);
    printSymmetryCases(symmetricMatrix, cases);

    // TODO
    // char isTransitive = resolveTransitivity();
}