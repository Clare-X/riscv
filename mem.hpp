//
// Created by 18146 on 2019/7/8.
//

#ifndef CODE_MEM_HPP
#define CODE_MEM_HPP

#include "base.hpp"
void dmp::MEM()
{
	if (inst==0x00c68223) return;
	switch (ord)
	{
		case ERR:throw OrderErr();
		case LB:LB_MEM4();break;
		case LH:LH_MEM4();break;
		case LW:LW_MEM4();break;
		case LBU:LBU_MEM4();break;
		case LHU:LHU_MEM4();break;
		case SB:SB_MEM4();break;
		case SH:SH_MEM4();break;
		case SW:SW_MEM4();break;

	}
}


void dmp::LB_MEM4()
{
	rd=*(std::int8_t *)(data+rs1+imm);
	//std::cout<<"load"<<rs1+imm<<"=="<<rd<<"\n";
}
void dmp::LH_MEM4()
{
	rd=*(std::int16_t *)(data+rs1+imm);
	//std::cout<<"load"<<rs1+imm<<"=="<<rd<<"\n";
}
void dmp::LW_MEM4()
{
	rd=*(std::int32_t *)(data+rs1+imm);
	//std::cout<<"load"<<rs1+imm<<"=="<<rd<<"\n";
}
void dmp::LBU_MEM4()
{
	rd=*(std::uint8_t *)(data+rs1+imm);
	//std::cout<<"load"<<rs1+imm<<"=="<<rd<<"\n";
}
void dmp::LHU_MEM4()
{
	rd=*(std::uint16_t *)(data+rs1+imm);
	//std::cout<<"load"<<rs1+imm<<"=="<<rd<<"\n";
}
void dmp::SB_MEM4()
{
	*(std::int8_t *)(data+rs1+imm)=*(std::int8_t *)(&rs2);
	//std::cout<<"save"<<rs1+imm<<"=="<<rs2<<"\n";
}
void dmp::SH_MEM4()
{
	*(std::int16_t *)(data+rs1+imm)=*(std::int16_t *)(&rs2);
	//std::cout<<"save"<<rs1+imm<<"=="<<rs2<<"\n";
}
void dmp::SW_MEM4()
{
	//td::cout<<"SW pla "<<rs1+imm<<" rs2 "<<rs2<<"\n";
	*(std::int32_t *)(data+rs1+imm)=rs2;
	//std::cout<<"save"<<rs1+imm<<"=="<<rs2<<"\n";
}
#endif //CODE_MEM_HPP
