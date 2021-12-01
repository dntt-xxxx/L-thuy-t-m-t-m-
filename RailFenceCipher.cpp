// Rail Fence cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#define KEY 3u
#define LEN_TEXT 13u
string RailFence(string text, int key)
{
    // create the matrix to cipher plain text
     // key = rows , length(text) = columns
    char railArr[KEY][LEN_TEXT];

    int k = 0;
    for (int i = 0; i < key; i++) 
    {
        for (int j = 0; j < text.length(); j++) {
            railArr[i][j] = '.';
        }
    }
        
            

    // to find the direction down or up
    bool directDown = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++)
    {
        if (row == 0 || row == key - 1) 
        {
            directDown = !directDown;
        }
        railArr[row][col++] = text[i];
        directDown ? row++ : row--;
    }

    string cipher;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (railArr[i][j] != '.')
                cipher.push_back(railArr[i][j]);

    return cipher;
}

int main()
{
    cout << RailFence("HELLOWORLD", 3) << endl;

    return 0;
}