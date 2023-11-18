#pragma once

#include "instructionClass.h"
#include "global.h"
using namespace std; 



void readFile(string FileName);


void executeJAL(Instructions& inst, int& pc, int* registers);

void print(); 

void add(); 

void addi(); 

void sub(); 

void orfunc(); 

void ori(); 

void sll();

void slli();

void xorfunc();

void xori();

void sra();

void srai();

void srl() ;

void srli();

void sb();

void sh();

void andfunc();

void andi();

void lb();

void sw();

void lbu();

void slt();

void slti();

void sltu();

void lw();

void jal();

void jalr(); 

void blt();

void bge();

void bltu();

void bgeu();

void lh();

void lw(); 


