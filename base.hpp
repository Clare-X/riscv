//
// Created by 18146 on 2019/7/3.
//

#ifndef RISCV_BASE_HPP
#define RISCV_BASE_HPP
#include <cstdint>
#include <fstream>
enum ORDER
{
	ERR,
	LUI,
	AUIPC,
	JAL,
	JALR,
	BEQ,
	BNE,
	BLT,
	BGE,
	BLTU,
	BGEU,
	LB,
	LH,
	LW,
	LBU,
	LHU,
	SB,
	SH,
	SW,
	ADDI,
	SLTI,
	SLTIU,
	XORI,
	ORI,
	ANDI,
	SLLI,
	SRLI,
	SRAI,
	ADD,
	SUB,
	SLL,
	SLT,
	SLTU,
	XOR,
	SRL,
	SRA,
	OR,
	AND
};

class OrderErr{};
const bool disp=true;
class dmp
{public:
	std::int32_t inst, rd, rs1, rs2, imm;
	ORDER ord;

	void IF();
	void ID();
	void EX();
	void WB();

private:
	void R_ID2();

	void I_ID2();

	void S_ID2();

	void B_ID2();

	void U_ID2();

	void J_ID2();

	void LUI_EX3();
	void AUIPC_EX3();
	void JAL_EX3();
	void JALR_EX3();
	void BEQ_EX3();
	void BNE_EX3();
	void BLT_EX3();
	void BGE_EX3();
	void BLTU_EX3();
	void BGEU_EX3();
	void LB_EX3();
	void LH_EX3();
	void LW_EX3();
	void LBU_EX3();
	void LHU_EX3();
	void SB_EX3();
	void SH_EX3();
	void SW_EX3();
	void ADDI_EX3();
	void SLTI_EX3();
	void SLTIU_EX3();
	void XORI_EX3();
	void ORI_EX3();
	void ANDI_EX3();
	void SLLI_EX3();
	void SRLI_EX3();
	void SRAI_EX3();
	void ADD_EX3();
	void SUB_EX3();
	void SLL_EX3();
	void SLT_EX3();
	void SLTU_EX3();
	void XOR_EX3();
	void SRL_EX3();
	void SRA_EX3();
	void OR_EX3();
	void AND_EX3();
};

char data[0x200000] = {0};
std::int32_t x[33] = {0};
dmp d[5];
//std::ofstream file;
#endif //RISCV_BASE_HPP
