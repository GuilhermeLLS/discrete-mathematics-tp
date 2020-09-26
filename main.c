#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char isReflexive(int **matrix, int matrixLength)
{
    char isReflexive = 'V';
    for (int i = 0; i < matrixLength; i++)
    {
        if (matrix[i][i] != 1)
        {
            isReflexive = 'F';
            break;
        }
    }
    return isReflexive;
}

int **getReflexivePairs(int *nodeIdentifiers, int matrixLength)
{
    int **reflexivePairs;
    reflexivePairs = (int **)malloc(sizeof(int *) * matrixLength);
    for (int i = 0; i < matrixLength; i++)
    {
        reflexivePairs[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < matrixLength; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            reflexivePairs[i][j] = nodeIdentifiers[i];
        }
    }

    return reflexivePairs;
}

int **resolveSymmetryMatrix(int **matrix, int matrixLength)
{
    // * ALOCA MATRIZ AUXILIAR
    int **aux;
    aux = (int **)malloc(sizeof(int *) * matrixLength);
    for (int i = 0; i < matrixLength; i++)
    {
        aux[i] = (int *)malloc(sizeof(int) * 6);
    }
    // AS POSICOES QUE AFETAM A CONDICAO SE SIMETRIA, SAO MARCADAS COM -1
    // AS POSICOES QUE AFETAM A CONDICAO DE ANTI SIMETRIA SAO MARCADAS COM -2
    for (int i = 0; i < matrixLength; i++)
    {
        for (int j = 0; j < matrixLength; j++)
        {
            if (i != j && matrix[i][j] != matrix[j][i])
            {
                // NAO PODE SER SIMETRICA
                aux[i][j] = -1;
            }
            else if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
            {
                // NAO PODE SER ANTI SIMETRICA
                aux[i][j] = -2;
            }
            else if (i == j && matrix[i][j] != matrix[j][i])
            {
                // NAO PODE SER SIMETRICA
                aux[i][j] = -1;
            }
        }
    }
    return aux;
}

void *resolveSymmetryCases(int **symmetricMatrix, int matrixLength, char *cases)
{
    strcpy(cases, "VVF");
    for (int i = 0; i < matrixLength; i++)
    {
        for (int j = 0; j < matrixLength; j++)
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

void printPairs(int **symmetric, int value, int *nodeIdentifiers)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (symmetric[i][j] == value)
            {
                printf("(");
                int newX = nodeIdentifiers[i];
                int newY = nodeIdentifiers[j];
                printf("%d,", newX);
                printf("%d", newY);
                printf("); ");
            }
        }
    }
    printf("\n");
}

void printSymmetryCases(int **symmetric, char *cases, int *nodeIdentifiers)
{
    char isSymmetric = cases[0];
    char isAntiSymmetric = cases[1];
    char isAsymmetric = cases[2];
    if (isSymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printPairs(symmetric, -2, nodeIdentifiers);
        printf("Assimetrica: %c \n", isAsymmetric);
    }

    if (isAntiSymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printPairs(symmetric, -1, nodeIdentifiers);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printf("Assimetrica: %c \n", isAsymmetric);
    }

    if (isAsymmetric == 'V')
    {
        printf("Simetrica: %c \n", isSymmetric);
        printPairs(symmetric, -1, nodeIdentifiers);
        printf("Anti-simetrica: %c \n", isAntiSymmetric);
        printPairs(symmetric, -2, nodeIdentifiers);
        printf("Assimetrica: %c \n", isAsymmetric);
    }
}

// TODO
// char resolveTransitivity()
// {
//     for (int i = 0; i < matrixLength; i++)
//     {
//         for (int j = 0; j < matrixLength; j++)
//         {
//             int a, b;
//             if (i != j && matrix[i][j] == 1)
//             {
//                 a = i;
//                 b = j;
//                 for (int c = 0; c < matrixLength; c++)
//                 {
//                     if (matrix[j][c] == 1 && matrix[a][c] = 1)
//                     {
//                         return 'V';
//                     }
//                 }
//             }
//         }
//     }
// }

int resolveCases(int **matrix, int matrixLength, int *nodeIdentifiers)
{
    char reflexive = isReflexive(matrix, matrixLength);
    printf("%c\n", reflexive);
    int **reflexivePairs = getReflexivePairs(nodeIdentifiers, matrixLength);
    printf("Reflexive Pairs: ");
    for (int i = 0; i < matrixLength; i++)
    {
        printf("(");
        for (int j = 0; j < 2; j++)
        {
            j == 0 ? printf("%d,", reflexivePairs[i][j]) : printf("%d", reflexivePairs[i][j]);
        }
        printf("); ");
    }

    printf("\n");

    int **symmetricMatrix = resolveSymmetryMatrix(matrix, matrixLength);
    char cases[3];
    resolveSymmetryCases(symmetricMatrix, matrixLength, cases);
    printSymmetryCases(symmetricMatrix, cases, nodeIdentifiers);

    // TODO
    // char isTransitive = resolveTransitivity();
}

int *getNodeIndetifiers(int len, char *buffer)
{
    int *nodes = (int *)malloc(sizeof(int) * len);
    int position = 0;
    int lenq = strlen(buffer);

    char *firstNodeIdentificator = strtok(buffer, " ");
    firstNodeIdentificator = strtok(NULL, " ");
    while (firstNodeIdentificator != NULL)
    {
        nodes[position] = atoi(firstNodeIdentificator);
        firstNodeIdentificator = strtok(NULL, " ");
        position++;
    }

    return nodes;
}

int main()
{
    FILE *myFile;
    int myMatrixLength = 0;
    int *nodeIdentifiers;
    int **adjcencyMatrix;
    int lines, columns = 0;
    int isFirstLine = 1;

    char fileLine[20];

    myFile = fopen("input.txt", "r");

    while (!feof(myFile))
    {
        fgets(fileLine, 20, myFile);
        if (isFirstLine == 1)
        {
            myMatrixLength = fileLine[0] - '0';
            nodeIdentifiers = getNodeIndetifiers(myMatrixLength, fileLine);
            adjcencyMatrix = (int **)malloc(sizeof(int *) * myMatrixLength);
            for (int i = 0; i < myMatrixLength; i++)
            {
                adjcencyMatrix[i] = (int *)malloc(sizeof(int) * myMatrixLength);
            }
            isFirstLine = 0;
        }
        else
        {
            char *lineNumber;
            char *columnNumber;
            lineNumber = strtok(fileLine, " ");
            columnNumber = strtok(NULL, " ");
            if (lineNumber != NULL && columnNumber != NULL)
            {
                int linePosition = atoi(lineNumber) - 3;
                int columnPosition = atoi(columnNumber) - 3;
                // printf("%d, %d\n", linePosition, columnPosition);
                adjcencyMatrix[linePosition][columnPosition] = 1;
            }
        }
    }
    fclose(myFile);
    resolveCases(adjcencyMatrix, myMatrixLength, nodeIdentifiers);
    return 1;
}
