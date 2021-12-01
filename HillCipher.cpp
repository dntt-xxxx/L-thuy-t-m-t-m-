// Hill Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#define MATRIX_COL 2U
#define MATRIX_ROW 4U
void converPlaTxt2Matrix(string _str, int  _matrixPla[][MATRIX_COL]);
void converMatrix2Str(char _str[MATRIX_COL * MATRIX_ROW + 1], int  _matrix[][MATRIX_COL]);
void HillCipher(string _str, int _matrixKey[][MATRIX_COL], char cipher[MATRIX_COL * MATRIX_ROW + 1]);

int main()
{
    int matrixKey[MATRIX_COL][MATRIX_COL] =
    {
        {3,9},
        {2,7}
    };

    string plaintext = "bachkhoa";
    cout << "Plaintext: " << plaintext << endl;
    char ciphertext[MATRIX_COL*MATRIX_ROW+1] = "";
    int matrixPlaintex[MATRIX_ROW][MATRIX_COL];

    converPlaTxt2Matrix(plaintext, matrixPlaintex);
    cout << "Matrix Plaintext: " << endl;
    for (int i = 0; i < MATRIX_ROW; i++)
    {
        for (int j = 0; j < MATRIX_COL; j++)
        {
            cout << matrixPlaintex[i][j] << "\t";
        }
        cout << endl;
    }
    HillCipher(plaintext, matrixKey, ciphertext);
    cout << "ciphertext: " << ciphertext;
}


void converPlaTxt2Matrix(string _str, int  _matrixPla[][MATRIX_COL]) {

    int k = 0;
    for (int i = 0; i < MATRIX_ROW; i++)
    {
        for (int j = 0; j < MATRIX_COL; j++) {
            _matrixPla[i][j] = (int)(_str[k] - 'a');
            k++;
        }
    }
}
void converMatrix2Str(char _str[MATRIX_COL * MATRIX_ROW + 1], int  _matrix[][MATRIX_COL]) {
    int k = 0;
    for (int i = 0; i < MATRIX_ROW; i++)
    {
        for (int j = 0; j < MATRIX_COL; j++) {
            int temp = _matrix[i][j];
            _str[k] = (char)(temp + 65);
            k++;
        }
    }
    _str[k] = NULL;
}
void HillCipher(string _str, int _matrixKey[][MATRIX_COL], char cipher[MATRIX_COL * MATRIX_ROW + 1]) {

    int matrixCiphertext[MATRIX_ROW][MATRIX_COL];
    int matrixPlaintex[MATRIX_ROW][MATRIX_COL];

    converPlaTxt2Matrix(_str, matrixPlaintex);

    //multiply 2 matrix
    for (int i = 0; i < MATRIX_ROW; i++)
    {
        for (int j = 0; j < MATRIX_COL; j++)
        {

            int temp = 0;
            for (int k = 0; k < MATRIX_COL; k++)
            {
                temp += (matrixPlaintex[i][k] * _matrixKey[k][j]);

            }
            matrixCiphertext[i][j] = temp % 26;
        }
    }
    cout << endl << "matrix Ciphertext:" << endl;
    for (int i = 0; i < MATRIX_ROW; i++)
    {
        for (int j = 0; j < MATRIX_COL; j++)
        {
            cout << matrixCiphertext[i][j] << "\t";
        }
        cout << endl;
    }
    converMatrix2Str(cipher, matrixCiphertext);
}

