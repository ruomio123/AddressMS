#pragma once
#include"PhonePerson.h"
/*
�ֻ�����ϵ�ˣ��̳����ֻ���ϵ��
�������ݳ�Ա��
����
QQ��
��Ա��������
һ��set����Ϊ���ݳ�Ա��ֵ
һ��modify�������޸����ݳ�Ա��ֵ
����>>��<<�������������ݳ�Ա�������������

*/
class SimPerson :public PhonePerson
{
private:
    string address;
    string qq_num;
public:
    SimPerson(string n = " ", string t = " ", string a = " ", string qq = " ") :PhonePerson(n, t), address(a), qq_num(qq) {};
    void setAddress(string a);
    void setQQNum(string q);

    string getAddress();
    string getQQ();
    //modify����
    void modifyAddress(string a);
    void modifyQQNum(string q);

    //���������
    friend istream& operator>>(istream& input, SimPerson& p);
    friend ostream& operator<<(ostream& output, const SimPerson& p);
};