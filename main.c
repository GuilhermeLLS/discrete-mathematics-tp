#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getNodeIndentificators(int len, char buffer[])
{
    int *nodes = malloc(sizeof(len));
    int t = strlen(buffer) - 2; // -2 é por causa do \n e \r
    for (int i = 0; i < t; i++)
    {
        if (buffer[i] != ' ')
        {
            nodes[i] = buffer[i] - 48;
        }
    }

    return nodes;
}

int main()
{
    FILE *myFile;
    char buffer[255];
    int myMatrixLength = 0;
    int *nodeIdentificators;
    myFile = fopen("input.txt", "r");
    int isFirstLine = 1;

    while (fgets(buffer, 255, myFile))
    {
        if (isFirstLine == 1)
        {
            myMatrixLength = buffer[0] - 48;
            nodeIdentificators = getNodeIndentificators(myMatrixLength, buffer);
            isFirstLine = 0;
        }
        printf("%s\n", buffer);
    }

    fclose(myFile);
}
