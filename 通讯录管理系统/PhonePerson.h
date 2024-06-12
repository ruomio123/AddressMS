#pragma once
#include<iostream>
#include<string>
using namespace std;
/*
��д�ֻ���ϵ����
���ݳ�Ա��
����
�绰����
��Ա������
���β���Ĭ��ֵ�Ĺ��캯��
һ��set����Ϊ���ݳ�Ա��ֵ
һ��modify�������޸����ݳ�Ա��ֵ
����>>,<<���������ɶ����������������


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
