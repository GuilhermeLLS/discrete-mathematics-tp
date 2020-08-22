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