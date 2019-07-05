//
// Created by 18146 on 2019/7/3.
//

#ifndef RISCV_EX_HPP
#define RISCV_EX_HPP
#include "base.hpp"
void dmp::EX()
{
	if (inst==0x00c68223) return;
	switch (ord)
	{
		case LUI:LUI_EX3();break;
		case AUIPC:AUIPC_EX3();break;
		case JAL:JAL_EX3();break;
		case JALR:JALR_EX3();break;
		case BEQ:BEQ_EX3();break;
		case BNE:BNE_EX3();break;
		case BLT:BLT_EX3();break;
		case BGE:BGE_EX3();break;
		case BLTU:BLTU_EX3();break;
		case BGEU:BGEU_EX3();break;
		case LB:LB_EX3();break;
		case LH:LH_EX3();break;
		case LW:LW_EX3();break;
		case LBU:LBU_EX3();break;
		case LHU:LHU_EX3();break;
		case SB:SB_EX3();break;
		case SH:SH_EX3();break;
		case SW:SW_EX3();break;
		case ADDI:ADDI_EX3();break;
		case SLTI:SLTI_EX3();break;
		case SLTIU:SLTIU_EX3();break;
		case XORI:XORI_EX3();break;
		case ORI:ORI_EX3();break;
		case ANDI:ANDI_EX3();break;
		case SLLI:SLLI_EX3();break;
		case SRLI:SRLI_EX3();break;
		case SRAI:SRAI_EX3();break;
		case ADD:ADD_EX3();break;
		case SUB:SUB_EX3();break;
		case SLL:SLL_EX3();break;
		case SLT:SLT_EX3();break;
		case SLTU:SLTU_EX3();break;
		case XOR:XOR_EX3();break;
		case SRL:SRL_EX3();break;
		case SRA:SRA_EX3();break;
		case OR:OR_EX3();break;
		case AND:AND_EX3();break;
		default:throw OrderErr();
	}
}
void dmp::LUI_EX3()
{
	rd=imm;
}
void dmp::AUIPC_EX3()
{
	rd=imm+x[32]-4;
}
void dmp::JAL_EX3()
{
	rd=x[32];
	x[32]+=imm-4;
}
void dmp::JALR_EX3()
{
	//std::cout<<"JALR num "<<((inst>>15)&0x1f)<<" rs1 "<<rs1<<" imm "<<imm<<"\n";

	rd=x[32];
	x[32]=rs1+imm;
}
void dmp::BEQ_EX3()
{
	if (rs1==rs2) x[32]+=imm-4;
}
void dmp::BNE_EX3()
{
	if (rs1!=rs2) x[32]+=imm-4;
}
void dmp::BLT_EX3()
{
	if (rs1<rs2) x[32]+=imm-4;
}
void dmp::BGE_EX3()
{
	if (rs1>=rs2) x[32]+=imm-4;
}
void dmp::BLTU_EX3()
{
	if (*(std::uint32_t *)(&rs1)<*(std::uint32_t *)(&rs2)) x[32]+=imm-4;
}
void dmp::BGEU_EX3()
{
	//std::cout<<"BGEU<= rs1 "<<rs1<<" rs2 "<<rs2<<" imm "<<imm<<"\n";
	if (*(std::uint32_t *)(&rs1)>=*(std::uint32_t *)(&rs2)) x[32]+=imm-4;
}
void dmp::LB_EX3()
{
	rd=*(std::int8_t *)(data+rs1+imm);
}
void dmp::LH_EX3()
{
	rd=*(std::int16_t *)(data+rs1+imm);
}
void dmp::LW_EX3()
{
	rd=*(std::int32_t *)(data+rs1+imm);
}
void dmp::LBU_EX3()
{
	rd=*(std::uint8_t *)(data+rs1+imm);
}
void dmp::LHU_EX3()
{
	rd=*(std::uint16_t *)(data+rs1+imm);
}
void dmp::SB_EX3()
{
	*(std::int8_t *)(data+rs1+imm)=*(std::int8_t *)(&rs2);
}
void dmp::SH_EX3()
{

	*(std::int16_t *)(data+rs1+imm)=*(std::int16_t *)(&rs2);
}
void dmp::SW_EX3()
{
	//td::cout<<"SW pla "<<rs1+imm<<" rs2 "<<rs2<<"\n";
	*(std::int32_t *)(data+rs1+imm)=rs2;
}
void dmp::ADDI_EX3()
{
	rd=rs1+imm;
}
void dmp::SLTI_EX3()
{
	if (rs1<imm) rd=1;else rd=0;
}
void dmp::SLTIU_EX3()
{
	if (*(std::uint32_t *)(&rs1)<*(std::uint32_t *)(&imm)) rd=1;
	else rd=0;
}
void dmp::XORI_EX3()
{
	rd=rs1^imm;
}
void dmp::ORI_EX3()
{
	rd=rs1|imm;
}
void dmp::ANDI_EX3()
{
	rd=rs1&imm;
}
void dmp::SLLI_EX3()
{
	rd=rs1<<((inst>>20)&0x1f);
	//rd=rs1<<(imm&0x1f)&(0xffffffff-((1<<(imm&0x1f))-1));
}
void dmp::SRLI_EX3()
{
	*(&rd)=(*(std::uint32_t *)(&rs1)>>((inst>>20)&0x1f));
}
void dmp::SRAI_EX3()
{
	rd=rs1>>((inst>>20)&0x1f);
}
void dmp::ADD_EX3()
{
	rd=rs1+rs2;
}
void dmp::SUB_EX3()
{
	rd=rs1-rs2;
}
void dmp::SLL_EX3()
{
	rd=rs1<<(rs2&0x1f);
}
void dmp::SLT_EX3()
{
	if (rs1<rs2) rd=1;else rd=0;
}
void dmp::SLTU_EX3()
{
	if (*(std::uint32_t *)(&rs1)<*(std::uint32_t *)(&rs2)) rd=1;
	else rd=0;
}
void dmp::XOR_EX3()
{
	rd=rs1^rs2;
}
void dmp::SRL_EX3()
{
	*(&rd)=(*(std::uint32_t *)(&rs1)>>(rs2&0x1f));
}
void dmp::SRA_EX3()
{
	rd=rs1<<(rs2&0x1f);
}
void dmp::OR_EX3()
{
	rd=rs1|rs2;
}
void dmp::AND_EX3()
{
	rd=rs1&rs2;
}

#endif //RISCV_EX_HPP
