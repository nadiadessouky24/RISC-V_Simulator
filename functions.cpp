// #pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdint> // or #include <cinttypes>
#include "instructionClass.h"
#include "global.h"
#include "functions.h"
using namespace std; 

vector<Instructions> instructions;


void readFile(string FileName)
{
    FILE *fp = fopen(FileName.c_str(), "r");
    char line[100];
    Instructions inst;
    char op[100];
    while (fgets(line, 100, fp) != NULL)
     {
        sscanf(line, "%s", op);
        inst.op = op;
        if (inst.op == "add" || inst.op == "sub" || inst.op == "and" || inst.op == "slt" || inst.op == "sltu") 
        {
            sscanf(line, "%s x%d, x%d, x%d", op, &inst.rd, &inst.rs, &inst.rt);
        } 
        else if (inst.op == "addi" || inst.op == "andi" || inst.op == "slti" || inst.op == "lb" || inst.op == "lbu")  //check format of lb and lbu
        {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rd, &inst.rs, &inst.imm);
        } 
        else if (inst.op == "beq") 
        {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rs, &inst.rt, &inst.imm);
        } 
        else if (inst.op == "j")
        {
            sscanf(line, "%s %d", op, &inst.imm);
        }

         else if (inst.op == "lw" || inst.op == "sw" || inst.op == "sb" || inst.op == "sh") 
        {
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } 

        else if (inst.op == "jr") 
        {
            sscanf(line, "%s x%d", op, &inst.rs);
        } 
        else if (inst.op == "jal")
        {
            sscanf(line, "%s %d", op, &inst.imm);
        } 
        else if (inst.op == "halt")
         {
            sscanf(line, "%s", inst.op);
        }
        else if (inst.op == "nop")
        {
            sscanf(line, "%s", inst.op);
        }
        else {
            cout << "Error: Unknown instruction: " << inst.op << endl;
            exit(1);
        }
        instructions.push_back(inst);
    
    }
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

void add ()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] + registers[instructions[i].rt];
    i++;
}

void addi()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] + instructions[i].imm;
    i++;
}

void sub()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] - registers[instructions[i].rt];
    i++;
}

void orfunc()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] | registers[instructions[i].rt];
    i++;
}

void ori()
{
        registers[instructions[i].rd] = registers[instructions[i].rs] | instructions[i].imm;
        i++;
}

void sll()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* registers[instructions[i].rt]);
    i++;
}

void slli()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* instructions[i].imm);
    i++;
}
void xorfunc()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ registers[instructions[i].rt];
    i++;
}
void xori()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ instructions[i].imm;
    i++;
}
void sra()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] >> registers[instructions[i].rt];
    i++;
}
void srai()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] >> instructions[i].imm;
    i++;
}

void srl()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* registers[instructions[i].rt]);
    i++;
}

void srli()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* instructions[i].rt);
    i++;

}

void sb()
 {
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFFFF00) | registers[instructions[i].rt]; 
}

void sh() 
{
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFF0000) | registers[instructions[i].rt]; 
}

void andfunc()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] & registers[instructions[i].rt];
    i++;
}

void andi()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] & instructions[i].rt;
    i++;
}

void lb()
{
    registers[instructions[i].rt] = (memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}

void sw() 
{
    memory[registers[instructions[i].rs]] = (memory[instructions[i].imm] & 0xFFFFFFF0) | (registers[instructions[i].rt] & 0xF);
}


// void lw()
// {
//     // Assuming memory, registers, and instructions are global arrays/structures
//     // and i is a global variable indicating the current instruction index

//     // Calculate the effective address for the load word operation
//     int effectiveAddress = registers[instructions[i].rs] + instructions[i].imm;

//     // Load the word from memory to the destination register
//     registers[instructions[i].rt] = memory[effectiveAddress];
// }



//double check
void slt() 
{
    if(registers[instructions[i].rs] < registers[instructions[i].rt])
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void sltu()
 {
    
    if(static_cast<uint32_t>(registers[instructions[i].rs]) < static_cast<uint32_t>(registers[instructions[i].rt]))
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }

}

void slti() 
{
    if(registers[instructions[i].rs] < instructions[i].imm)
    {
    registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void sltiu() 
{
    if(static_cast<uint32_t>(registers[instructions[i].rs]) < static_cast<uint32_t>(instructions[i].imm))
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void lbu() 
{
    registers[instructions[i].rt] = static_cast<uint32_t>(memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}


// void executeJAL(const Instructions& inst, int& pc, int* registers) 
// {   
//         registers[inst.rd] = pc; //saves return address (counter i) in rd
//         pc += inst.imm; //updates the program counter to target address
// }
// void jal()
// {
//     executeJAL(instructions[i], i, registers); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     i++;
// }
// void executeBLT(const Instructions &inst, int &pc) //Branch if less than 
// {
     
//         if (registers[inst.rs] < registers[inst.rd]) {
//             // Branch is taken, update the program counter
//            // pc += inst.imm;
//            i+=inst.imm; 
//         } else {
//             // Branch not taken, continue to the next instruction
//             pc += 4; // Assuming each instruction is 4 bytes
            
//         }
// }
// void blt()
// {
//     executeBLT(instructions[i], i); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     i++;

// }

// void executeBGE(const Instructions &inst)// Branch if greater than 
// {
//     if (registers[inst.rs] >= registers[inst.rd])
//      {
//             // Branch is taken, update the program counter
//             i += inst.imm;
//         } 
//         else 
//         {
//             // Branch not taken, continue to the next instruction
//             //pc += 4; // Assuming each instruction is 4 bytes
//             i+=4; 
//         }
// }

// void bge()
// {
//     executeBGE(instructions[i]); 
//     i++; 

// }

// void executeLH(const Instructions &inst) //Load halfword 
// {
//     int baseAddress = registers[inst.rs];
//     int offset = inst.imm;
//     int effectiveAddress = baseAddress + offset;

//             // Check if the effective address is aligned to a 32-bit boundary
//     if (effectiveAddress % 4 == 0) 
//         {
//             int loadedValue = memory[effectiveAddress / 4];
//             registers[inst.rd] = static_cast<int16_t>(loadedValue & 0xFFFF);
//         } 
//         else 
//         {
//             exit(1);
//         }
// }

// void lh()
// {
//     executeLH(instructions[i]);
//     i++; 
// }

// void executeLHU(const Instructions &inst) // Load halfword unsigned 
// {
//         int baseAddress = registers[inst.rs];
//         int offset = inst.imm;
//         int effectiveAddress = baseAddress + offset;

//         // Check if the effective address is aligned to a 32-bit boundary
//         if (effectiveAddress % 4 == 0) {
//             int loadedValue = memory[effectiveAddress / 4];
//             registers[inst.rd] = loadedValue & 0xFFFF;
//         } 
//         else 
//         {
//             exit(1); 
//         }
// }
// void lhu()
// {
//     executeLHU(instructions[i]);
//     i++; 
// }
// void executeLW(const Instructions &inst)
// {
//     int baseAddress = registers[inst.rs];
//     if (baseAddress % 4 == 0) 
//         {
//             // Load the 32-bit value from memory into the destination register
//             registers[inst.rd] = memory[baseAddress / 4];
//         } 
//         else 
//         {
//             exit(1);
//         }
// }

// void lw()
// {
//     executeLW(instructions[i]);
//     i++; 
// }

// void BGEU() {
//     if ( static_cast<uint32_t>(registers[instructions[i].rs1]) >= static_cast<uint32_t>(registers[instructions[i].rs2])){
//         pointer_address += imm;
//     }
// }


// void BLTU() 
// {
//     if (static_cast<uint32_t>(registers[instructions[i].rs1]) < static_cast<uint32_t>(registers[instructions[i].rs2]))
//     {
//         pointer_address += imm;
//     }
// }


// void executeJAL(Instructions& inst, int& pc, int* registers) 
// {   
//         registers[inst.rd] = pc; //saves return address (counter i) in rd
//         pc += inst.imm; //updates the program counter to target address
// }

// void jal()
// {
//     executeJAL(instructions[i], i, registers);
//     i++;
// }
// void SRL() {
//     int shift_value =registers[instructions[i].rs2]; 
//     if (shift_value >=32){
//         shift_value  &=0x1F; 
//     }

//     registers[instructions[i].rd] = registers[instructions[i].rs1] >> shift_value; 
// }

// void SRLI() {
//     registers[instructions[i].rd] = registers[instructions[i].rs1] >> shamt;
// }

// void BLTU() {
//     if (static_cast<uint32_t>(registers[instructions[i].rs1]) < static_cast<uint32_t>(registers[instructions[i].rs2]))
//     {
//         pointer_address += imm;
//     }
// }

// void BGEU() {
//     if ( static_cast<uint32_t>(registers[instructions[i].rs1]) >= static_cast<uint32_t>(registers[instructions[i].rs2])){
//         pointer_address += imm;
//     }
// }

// void SB() {
//     memory[address] =(memory[address]& 0xFFFFFF00) | registers[instructions[i].rs2]; 
// }

// void SH() {
//     memory[address] =(memory[address]& 0xFFFF0000) | registers[instructions[i].rs2]; 
// }

