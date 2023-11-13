#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "instructionClass.h"
#include "global.h"
using namespace std; 


vector<Instructions> instructions;

void readFile(string FileName){
    FILE *fp = fopen(FileName.c_str(), "r");
    char line[100];
    Instructions inst;
    char op[100];
    while (fgets(line, 100, fp) != NULL) {
        sscanf(line, "%s", op);
        inst.op = op;
        if (inst.op == "add" || inst.op == "sub" || inst.op == "mul" || inst.op == "slt") {
            sscanf(line, "%s x%d, x%d, x%d", op, &inst.rd, &inst.rs, &inst.rt);
        } else if (inst.op == "addi" || inst.op == "lw" || inst.op == "sw") {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rd, &inst.rs, &inst.imm);
        } else if (inst.op == "beq") {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rs, &inst.rt, &inst.imm);
        } else if (inst.op == "j") {
            sscanf(line, "%s %d", op, &inst.imm);
        } else if (inst.op == "lw") {
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } else if (inst.op == "sw") {
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } else if (inst.op == "jr") {
            sscanf(line, "%s x%d", op, &inst.rs);
        } else if (inst.op == "jal") {
            sscanf(line, "%s %d", op, &inst.imm);
        } else if (inst.op == "halt") {
            sscanf(line, "%s", inst.op);
        } else if (inst.op == "nop") {
            sscanf(line, "%s", inst.op);
        }
        else {
            cout << "Error: Unknown instruction: " << inst.op << endl;
            exit(1);
        }
        instructions.push_back(inst);
    
    }

}

void executeJAL(Instructions& inst, int& pc, int* registers) 
{   
        registers[inst.rd] = pc; //saves return address (counter i) in rd
        pc += inst.imm; //updates the program counter to target address
}

void print()
{
    cout<<"Program Counter: "<<i*4<<endl;
    cout<<"Register File: \n";
    for (int i=0;i<32;i++)
    {
        if (i<10)
            cout<<" x"<<i<<"  :"<<registers[i]<<endl;
        else
            cout<<" x"<<i<<" :"<<registers[i]<<endl;
    }
    cout<<"----------------------------------------\n";

}