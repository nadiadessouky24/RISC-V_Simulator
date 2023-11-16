#pragma once

#include "instructionClass.h"
#include "global.h"
using namespace std; 



void readFile(string FileName);


void executeJAL(Instructions& inst, int& pc, int* registers);

void print();

void add ();

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

void and();

void andi();

void lb();

void sw();

void lbu();

void slt();

void slti();

void sltu();
 void jal();
 void blt(); 
 void bge();
 void lh();
 void lhu();
void lw(); 



 void jal();
 void blt(); 
 void bge();
 void lh();
 void lhu();
void lw(); 


//void jalr();



// void BLTU() ;

// void BGEU() ;


// void SLT() ;

// void SLTU() ;

// void SLTI() ;

// void SLTIU();

