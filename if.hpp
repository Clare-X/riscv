//
// Created by 18146 on 2019/7/3.
//

#ifndef RISCV_IF_HPP
#define RISCV_IF_HPP
#include "base.hpp"
void dmp::IF()
{
	x[32]+=delta;
	inst=*(std::int32_t *)(data+x[32]);
	delta=4;
}
#endif //RISCV_IF_HPP
