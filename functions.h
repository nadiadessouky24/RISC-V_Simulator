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

// void jal();

// void AND() ;

// void ANDI();

// void SRL() ;

// void SRLI();
// void BLTU() ;

// void BGEU() ;

// void SB() ;

// void SH() ;

// void SLT() ;

// void SLTU() ;

// void SLTI() ;

// void SLTIU();