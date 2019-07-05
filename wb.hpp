//
// Created by 18146 on 2019/7/3.
//

#ifndef RISCV_WB_HPP
#define RISCV_WB_HPP
#include "base.hpp"

void dmp::WB()
{
	if (inst==0x00c68223) return;
	if (ord==JAL|ord==LUI|ord==AUIPC
	|ord==JALR|ord==LB|ord==LH|ord==LW|ord==LBU|ord==LHU
	|ord==ADDI|ord==SLTI|ord==SLTIU|ord==XORI|ord==ORI|ord==ANDI
	|ord==SLLI|ord==SRLI|ord==SRAI|ord==ADD|ord==SUB
	|ord==SLT|ord==SLTU||ord==SLL|ord==SRL|ord==SRA
	|ord==XOR|ord==OR|ord==AND)
	{
		x[(inst>>7)&0x1f]=rd;
		//if (((inst>>7)&0x1f)==15) std::cout<<"a5 "<<rd<<"\n";
		//if (((inst>>7)&0x1f)==13) std::cout<<"a3 "<<rd<<"\n";
		//if (((inst>>7)&0x1f)==12) std::cout<<"a2 "<<rd<<" a3 "<<x[13]<<"\n";
	}
	x[0]=0;
}
#endif //RISCV_WB_HPP
