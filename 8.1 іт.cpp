#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Include(const char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '!' && s[i + 1] == '!' && s[i + 2] == '!')
            return true;
    return false;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    char* tmp = new char[len + 1];
    char* t = tmp;
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
        {
            *t++ = '*';
            *t++ = '*';
            i += 3;
        }
        else
            *t++ = str[i++];
    }
    *t = '\0';
    for (size_t k = 0; tmp[k] != '\0'; k++)
        str[k] = tmp[k];
    str[t - tmp] = '\0';
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains groups of '!!!': ";
    if (Include(str))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}