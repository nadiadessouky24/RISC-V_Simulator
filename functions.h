#pragma once

#include "instructionClass.h"
#include "global.h"
using namespace std; 



void readFile(string FileName);


void executeJAL(Instructions& inst, int& pc, int* registers);

void print(); 

//LUI and AUIPC
void lui();//1
void auipc();//2

//jumps
void jal();//3
void jalr();//4

//branches
void beq();//5
void bne();//6
void blt();//7
void bge();//8
void bltu();//9
void bgeu();//10


// Load and store
void lb();//11
void lh();//12
void lw();//13
void lbu();//14
void lhu();//15
void sb();//16
void sh();//17
void sw();//18


//arithmetics
void addi();//19
void slti();//20
void sltiu();//21
void xori();//22
void ori();//23
void andi();//24
void slli();//25
void srli();//26
void srai();//27
void add();//28
void sub();//29
void sll();//30
void slt();//31
void sltu();//32
void xorfunc();//33
void srl();//34
void sra();//35
void orfunc();//36
void andfunc();//37



