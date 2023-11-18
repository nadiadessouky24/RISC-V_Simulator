#pragma once
#include <iostream>
using namespace std;

class Instructions 
{
public:
    string op,label;
    int rd, rs, rt, imm,j;
    int ra;

    Instructions()
    {
        rd = 0;
        rs = 0;
        rt = 0;
        imm = 0;
        j = 0;
    }
};

