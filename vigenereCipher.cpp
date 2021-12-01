
#include <iostream>
using namespace std;


string genKey(string _str, string _key)
{
    int temp = _str.size();

    for (int i = 0; ; i++)
    {
        if (temp == i)
            i = 0;

        if (_key.size() == _str.size())
            break;
        _key.push_back(_key[i]);
    }
    return _key;
}

string cipherText(string _str, string _key)
{
    string ciphertext="";

    for (int i = 0; i< (_str.size()); i++)
    {
        int temp = (_str[i]-'a' + _key[i]-'A') % 26;

        char cc = char(temp+int('A'));

        ciphertext.push_back(cc);
    }
    return ciphertext;
}


string oriText(string _ciphertext, string _key)
{
    string origText="";

    for (int i = 0; i < _ciphertext.size(); i++)
    {
        int temp = (_ciphertext[i]-(int)'A' + 26 - (_key[i]-(int)'A')) % 26;

        char pc = char((int)'a' + temp);
        origText.push_back(pc);
    }
    return origText;
}

// Driver program to test the above function
int main()
{
    string str = "sheislistening";
    string keyword = "PASCAL";

    string s_key = genKey(str, keyword);
    string s_cipherText = cipherText(str, key);

    cout << "Ciphertext : "
        << s_cipherText << "\n";

    cout << "Original Text : "
        << oriText(s_cipherText, s_key);
    return 0;
}