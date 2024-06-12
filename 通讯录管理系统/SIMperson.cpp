#include"SIMperson.h"
void SimPerson::setAddress(string a)
{
	address = a;
}
void SimPerson::setQQNum(string q)
{
	qq_num = q;
}
string SimPerson::getAddress()
{
	return address;
}

string SimPerson::getQQ()
{
	return qq_num;
}
//modifyº¯Êı
void SimPerson::modifyAddress(string a)
{
	address = a;
}
void SimPerson::modifyQQNum(string q)
{
	qq_num = q;
}

//ÖØÔØÔËËã·û
istream& operator>>(istream& input, SimPerson& p)
{
	input >> p.address >> p.qq_num;
	return input;
}
ostream& operator<<(ostream& output, const SimPerson& p)
{
	output << p.address << " "<< p.qq_num;
	return output;
}