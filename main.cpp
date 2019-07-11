#include <iostream>
#include <cstring>
#include <fstream>
#include "id.hpp"
#include "if.hpp"
#include "mem.hpp"
#include "ex.hpp"
#include "wb.hpp"
std::uint32_t address32(const std::string &s,std::uint32_t pos)
{
	std::uint32_t ans=0;
	for (std::uint32_t i=pos;i<s.length();++i)
	{
		ans=ans<<4;
		if (s[i]<='9') ans=ans|(s[i]-'0');
		else ans=ans|(std::uint32_t)(s[i]-'A'+10);
	}
	return ans;
}
std::uint8_t address8(const std::string &s,std::uint8_t pos)
{
	std::uint8_t ans=0;
	for (std::uint8_t i=pos;i<s.length();++i)
	{
		ans=ans<<4;
		if (s[i]<='9') ans=ans|(s[i]-'0');
		else ans=ans|(std::uint8_t)(s[i]-'A'+10);
	}
	return ans;
}

int main()
{
	std::string s;
	std::uint32_t i=0;
	while (std::cin>>s&&s!="end")
	{
		if (s[0] == '@') i = address32(s, 1);
		else
		{
			*(uint8_t *)(data+i)=address8(s,0);
			++i;
		}
	}
	std::cout<<std::hex;
	while (true)
	{

		d.IF();
		d.ID();
		d.EX();
		d.MEM();
		d.WB();
		if (d.inst==0x00c68223)
		{
			std::cout<<std::dec<<(x[10]&0xff);
			return 0;
		}

	}

}