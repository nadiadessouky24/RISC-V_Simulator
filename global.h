#pragma once 
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include "instructionClass.h"
using namespace std;


extern int i;
extern int registers[32];
extern void print();
extern map<int,int> memory;

extern vector<Instructions> instructions;



typedef void(*inst_func_ptr)(void);
extern map<string, inst_func_ptr> inst_map; 
void initialize_map();
extern map<string,int> labels;

