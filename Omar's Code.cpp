// #include <iostream>
// #include <vector>
// #include <cstdint>

// using namespace std;

// int registers[32];

// int memory[32];

// int pointer_address;

// void AND(int rd, int rs1, int rs2) {
//     registers[rd] = registers[rs1] & registers[rs2];
// }

// void ANDI(int rd, int rs1, int imm) {
//     registers[rd] = registers[rs1] & imm;
// }

// void SRL(int rd, int rs1, int rs2) {
//     int shift_value =registers[rs2]; 
//     if (shift_value >=32){
//         shift_value  &=0x1F; 
//     }

//     registers[rd] = registers[rs1] >> shift_value; 
// }

// void SRLI(int rd, int rs1, int shamt) {
//     registers[rd] = registers[rs1] >> shamt;
// }

// void BLTU(int rs1, int rs2,int imm) {
//     if ( static_cast<uint32_t>(registers[rs1]) < static_cast<uint32_t>(registers[rs2])){
//         pointer_address += imm;
//     }
// }

// void BGEU(int rs1, int rs2,int imm) {
//     if ( static_cast<uint32_t>(registers[rs1]) >= static_cast<uint32_t>(registers[rs2])){
//         pointer_address += imm;
//     }
// }

// void SB(int address, int rs2) {
//     memory[address] =(memory[address]& 0xFFFFFF00) | registers[rs2]; 
// }

// void SH(uint32_t address, int rs2) {
//     memory[address] =(memory[address]& 0xFFFF0000) | registers[rs2]; 
// }

// void SLT(int rd, int rs1, int rs2) {
//     if(registers[rs1] < registers[rs2]){
//         registers[rd] = 1;
//     }else{
//         registers[rd] = 0;
//     }
// }

// void SLTU(int rd, int rs1, int rs2) {
    
//     if(static_cast<uint32_t>(registers[rs1]) < static_cast<uint32_t>(registers[rs2])){
//         registers[rd] = 1;
//     }else{
//         registers[rd] = 0;
//     }

// }

// void SLTI(int rd, int rs1, int imm) {
//         if(registers[rs1] < imm){
//         registers[rd] = 1;
//     }else{
//         registers[rd] = 0;
//     }
// }

// void SLTIU(int rd, int rs1, int imm) {
//     if(static_cast<uint32_t>(registers[rs1]) < static_cast<uint32_t>(imm)){
//         registers[rd] = 1;
//     }else{
//         registers[rd] = 0;
//     }
// }