#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string line;
    vector<string> myVector;
    int *numbersGroup = NULL;
    int lineIndex = 0;
    ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (lineIndex == 0) {
                int lineLen = line.length();
                int len = lineLen > 1 ? (lineLen - 1) - (lineLen / 2) + 1 : 1;
                numbersGroup = new int[len];
                for (int i = 0; i < len; i++) {

                }
            }
            int x = int(line[0]);
            int y = int(line[2]);
            cout << line[2] << " ";
            myVector.push_back(line);
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}

// symetric, asymetric anti-symetric

// symetric [[1,2],[1,1],[1,3][3,1],[2,2],[1,1],[2,1]] => A = [1,2,3]
// anti-symetric [[1,3][3,1],[2,2],[1,1],[2,1]] => A = [1,2,3]
// asymetric [[1,3],[1,4],[2,1]] => A = [1,2,3,4]

//! bool hasSimetricSimbling(int target[], int matrix[][])
// {
//     int m1 = matrix;
//     if (target[0] == target[1])
//     {
//         return true;
//     }

//     bool found = false;
//     for (int i = 0; i < m1.length; i++)
//     {
//         int pair = m1[i];
//         if (pair != = target && pair[0] == = target[1] && pair[1] == = target[0])
//         { // pair != target checks if it is happening a comparison to itself
//             found = true;
//             break;
//         }
//     }
//     return found;
// }

// bool isSymetric(int matrix)
// {
//     int counter = 0;
//     for (int i = 0; i < matrix.length; i++)
//     {
//         int pair = matrix[i];
//         if (hasSimetricSimbling(pair, matrix))
//         {
//             counter = counter + 1;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return counter == matrix.length;
// int myMatrix[10][2] = {{1, 2}, {1, 3}, {1, 4}, {1, 1}, {2, 2}, {2, 1}, {3, 1}, {4, 1}, {3, 3}, {4, 4}};
//! }