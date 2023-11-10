#pragma once
#include <iostream>
using namespace std;

class Instructions 
{
public:
    string op;
    int rd, rs, rt, imm;

    Instructions(){
        rd = 0;
        rs = 0;
        rt = 0;
        imm = 0;
    }
};

