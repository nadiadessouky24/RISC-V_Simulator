#include "global.h"
#include "instructionClass.h"
#include "functions.h"


int i=0;
int registers[32]={0};
int memory[32]= {0};
int offset;

map<string, inst_func_ptr> inst_map; 
map<string,int> labels;

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
    inst_map.emplace("srl", &srl); //12
    inst_map.emplace("srli", &srli); //13
    inst_map.emplace("sb", &sb); //14
    inst_map.emplace("sh", &sh); //15
    inst_map.emplace("and", &andfunc); //16
    inst_map.emplace("andi", &andi); //17
    inst_map.emplace("lb", &lb); //18
    inst_map.emplace("sw", &sw); //19
    inst_map.emplace("slt", &slt); //20
    inst_map.emplace("slti", &slti); //21
    inst_map.emplace("sltu", &sltu); //22
    inst_map.emplace("lbu", &lbu); //23
    inst_map.emplace("lw", &lw);//24

    inst_map.emplace("jal", &jal);//25
    inst_map.emplace("blt", &blt);//26
    inst_map.emplace("bge", &bge);//27
    inst_map.emplace("lh", &lh);//28
    inst_map.emplace("lhu", &lhu);//29

    inst_map.emplace("lui", &lui);//30
    inst_map.emplace("auipc", &auipc);//31
    inst_map.emplace("jalr",&jalr);//32
    inst_map.emplace("beq",&beq);//33
    inst_map.emplace("bne",&bne);//34
    //inst_map.emplace("bltu",&bltu);//35
    //inst_map.emplace("bgeu",&bgeu);//36
    inst_map.emplace("sltiu",&sltiu);//37
    
}

// void initialize_labelmap()
// {
//     labels.emplace(inst.label, inst.j);
// }
