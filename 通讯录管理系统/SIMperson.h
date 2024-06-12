#pragma once
#include"PhonePerson.h"
/*
手机卡联系人，继承于手机联系人
新增数据成员：
籍贯
QQ号
成员函数包括
一组set函数为数据成员赋值
一组modify函数，修改数据成员的值
重载>>，<<运算符，完成数据成员的输入输出操作

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
    //modify函数
    void modifyAddress(string a);
    void modifyQQNum(string q);

    //重载运算符
    friend istream& operator>>(istream& input, SimPerson& p);
    friend ostream& operator<<(ostream& output, const SimPerson& p);
};