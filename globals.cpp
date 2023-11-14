#include "global.h"
#include "instructionClass.h"
#include "functions.h"

int i=0;
int registers[32]={0};
int memory[32]= {0};



map<string, inst_func_ptr> inst_map; 


void initialize_map()
{
    inst_map.emplace("add", &add); //1
    inst_map.emplace("addi", &addi); //2
    inst_map.emplace("sub", &sub); //3
    inst_map.emplace("or", &orfunc); //4
    inst_map.emplace("ori", &ori); //5
    inst_map.emplace("sll", &sll); //6
    inst_map.emplace("slli", &slli); //7
    inst_map.emplace("xor", &xorfunc); //8
    inst_map.emplace("xori", &xori); //9
    inst_map.emplace("sra", &sra); //10
    inst_map.emplace("srai", &srai); //11

}
