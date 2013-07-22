#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cctype>

using namespace std;

const int MaxCount = 10;
const int MaxKey = 16;
const int MaxName = 16;
const int okey = 1;
const int fail = 2;
const int end = 3;

FILE *myFile;

typedef int (*func_t)(int c, int cou);

bool accept_file (func_t func)
{
    int c = fgetc(myFile);
    int symbolCount = 0;

    while (EOF != c)
    {
        int CallBack = func (c, symbolCount);
        if (fail == CallBack)
        {
            ungetc(c, myFile);
            return 0;
        }
        c = fgetc(myFile);
        ++symbolCount;
    }
    return 1;
}

int accept_comment(int c, int cou)
{
    if (0 == cou)
    {
        if ('#' == c) return okey;
        else return fail;
    }
    return okey;
}

int accept_count(int c, int cou)
{
    if (cou < MaxCount) return okey;
    else
        if(isalnum(c) && isdigit(c)) return okey;
        else return fail;
}

int accept_key(int c, int cou)
{
    if(cou < MaxKey) return okey;
    else
        if(isalnum(c)) return okey;
        else return fail;
}

int accept_name(int c, int cou)
{
    if(cou < MaxName) return okey;
    else
        if (isalpha(c)) return okey;
        else return fail;
}

int main()
{
    myFile = fopen("test.txt", "r");
    //accept_file
    return 0;
}
