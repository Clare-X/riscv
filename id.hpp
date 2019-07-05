//
// Created by 18146 on 2019/7/2.
//

#ifndef RISCV_ID_HPP
#define RISCV_ID_HPP
#include "base.hpp"
void dmp::ID()
{
	if (inst==0x00c68223) return;
	switch (inst&0x7f)
	{
		case 0x33:R_ID2();break;
		case 0x67:I_ID2();break;
		case 0x03:I_ID2();break;
		case 0x23:S_ID2();break;
		case 0x63:B_ID2();break;
		case 0x6f:J_ID2();break;
		case 0x17:U_ID2();break;
		case 0x37:U_ID2();break;
		case 0x13:
			if (((inst&0x707f)==0x1013)||((inst&0x707f)==0x5013)) R_ID2();
			else I_ID2();break;
		default:throw OrderErr();
	}
}

void dmp::R_ID2()
{
	rs1=x[(inst>>15)&0x1f];
	rs2=x[(inst>>20)&0x1f];
	switch(inst&0xfe00707f)
	{
		case 0x1013:ord=SLLI;break;
		case 0x5013:ord=SRLI;break;
		case 0x40005013:ord=SRAI;break;
		case 0x33:ord=ADD;break;
		case 0x40000033:ord=SUB;break;
		case 0x1033:ord=SLL;break;
		case 0x2033:ord=SLT;break;
		case 0x3033:ord=SLTU;break;
		case 0x4033:ord=XOR;break;
		case 0x5033:ord=SRL;break;
		case 0x40005033:ord=SRA;break;
		case 0x6033:ord=OR;break;
		case 0x7033:ord=AND;break;
		default:throw OrderErr();
	}
}
void dmp::I_ID2()
{
	rs1=x[(inst>>15)&0x1f];
	imm=inst>>20;
	switch (inst&0x707f)
	{
		case 0x67:ord=JALR;break;
		case 0x03:ord=LB;break;
		case 0x1003:ord=LH;break;
		case 0x2003:ord=LW;break;
		case 0x4003:ord=LBU;break;
		case 0x5003:ord=LHU;break;

		case 0x13:ord=ADDI;break;
		case 0x2013:ord=SLTI;break;
		case 0x3013:ord=SLTIU;break;
		case 0x4013:ord=XORI;break;
		case 0x6013:ord=ORI;break;
		case 0x7013:ord=ANDI;break;
		default:throw OrderErr();
	}
};
void dmp::S_ID2()
{
	rs1=x[(inst>>15)&0x1f];
	rs2=x[(inst>>20)&0x1f];
	imm=(inst&0xfe000000)|((inst<<13)&0x1f00000);
	imm=imm>>20;
	switch (inst&0x707f)
	{
		case 0x23:ord=SB;break;
		case 0x1023:ord=SH;break;
		case 0x2023:ord=SW;break;
		default:throw OrderErr();
	}

};
void dmp::B_ID2()
{
	rs1=x[(inst>>15)&0x1f];
	rs2=x[(inst>>20)&0x1f];
	imm=(inst&0x80000000)|((inst<<23)&0x40000000)|((inst>>1)&0x3f000000)|((inst<<12)&0xf00000);
	imm=imm>>19;
	switch (inst&0x707f)
	{
		case 0x63:ord=BEQ;break;
		case 0x1063:ord=BNE;break;
		case 0x4063:ord=BLT;break;
		case 0x5063:ord=BGE;break;
		case 0x6063:ord=BLTU;break;
		case 0x7063:ord=BGEU;break;
		default:throw OrderErr();
	}
};
void dmp::J_ID2()
{
	imm=(((inst&0xff000)|((inst>>9)&0x800)|((inst>>20)&0x7fe))<<11)|(inst&0x80000000);
	imm=imm>>11;
	switch (inst&0x7f)
	{
		case 0x6f:ord=JAL;break;
		default:throw OrderErr();
	}

};
void dmp::U_ID2()
{
	imm=inst&0xfffff000;
	switch (inst&0x7f)
	{
		case 0x37:ord=LUI;break;
		case 0x17:ord=AUIPC;break;
		default:throw OrderErr();
	}
};


#endif
