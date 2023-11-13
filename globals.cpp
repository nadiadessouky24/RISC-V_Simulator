#include "global.h"
#include "instructionClass.h"
#include "functions.h"

int i=0;
int registers[32]={0};
int memory[32]= {0};



map<string, inst_func_ptr> inst_map; 


void initialize_map(){
    inst_map.emplace("add", &add);
    inst_map.emplace("addi", &addi);
}
