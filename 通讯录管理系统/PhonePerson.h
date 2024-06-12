#pragma once
#include<iostream>
#include<string>
using namespace std;
/*
编写手机联系人类
数据成员：
姓名
电话号码
成员函数：
带参并带默认值的构造函数
一组set函数为数据成员赋值
一组modify函数，修改数据成员的值
重载>>,<<运算符，完成对象的输入和输出操作


*/
class PhonePerson
{
private:
	string name;
	string tell;
public:
	PhonePerson(string n = " ", string t = " ");
	void setName(string n);
	void setTell(string t);
	void modifyName();
	void modifyTell();
	string getTell();
	string getName();
	friend ostream& operator<<(ostream& output, const PhonePerson& p);
	friend istream& operator>>(istream& input, PhonePerson& p);

};
