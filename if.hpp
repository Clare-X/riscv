//
// Created by 18146 on 2019/7/3.
//

#ifndef RISCV_IF_HPP
#define RISCV_IF_HPP
#include "base.hpp"
void dmp::IF()
{
	x[32]+=4;
	inst=*(std::int32_t *)(data+x[32]);
}
#endif //RISCV_IF_HPP
