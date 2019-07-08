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
		case LB:case LH:case LW:case LBU:case LHU:
		case SB:case SH:case SW:break;
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
	if (*(std::uint32_t *)(&rs1)>=*(std::uint32_t *)(&rs2)) x[32]+=imm-4;
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
