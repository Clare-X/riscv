#include <iostream>
#include <cstring>
#include <fstream>
#include "id.hpp"
#include "if.hpp"
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
		//else {data[i>>2]=data[i>>2]|(address(s,0)<<((i%4)*8));++i;}
	}
	std::cout<<std::hex;
	//file.open("mysort.log");
	int cnt = 0;
	while (cnt<1142240)
	{
		//file<<std::hex<<"pc: "<<x[32]<<"\n";
		d[0].rs2=d[0].rs1=d[0].imm=0;

		d[0].IF();

		//file<<"code: ";
		//for (int ii=31;ii>=0;--ii) file<<((d[0].inst>>ii)&1);
		//file<<"\n";file<<std::dec<<"++++++++   "<<cnt++<<"\n";

		d[0].ID();
		/*
		file<<std::hex;
		file<<"   imm:"<<d[0].imm;
		file<<"   rs1::"<<d[0].rs1;
		file<<"   rs2::"<<d[0].rs2;
		file<<"   rd::"<<((d[0].inst>>7)&0x1f)<<"\n";
		*/
		d[0].EX();
		//d[0].MEM();
		d[0].WB();
		if (d[0].inst==0x00c68223)
		{
			std::cout<<std::dec<<(x[10]&0xff);
			return 0;
		}
		//file<<std::dec;
		//for (int ii=0;ii<32;ii++) file<<x[ii]<<"  ";
		//file<<"\n";
	}
	//file.close();

}