#pragma once
#include<iostream>
#include"SimTongxun.h"
#include"PhoneTongxun.h"
using namespace std;
/*
6．	用户类（这是一个操作类，完成通讯簿的操作）：用户拥有一个两个通讯簿（一个是手机中存储的联系人，一个是手机卡中存储的联系人），并且可以对通讯录进行管理
		数据成员包括：
			两个通讯簿的对象
		成员函数包括（成员函数体现用户的行为）：
			添加联系人：利用基类指针，调用相应的通讯簿对象（手机通讯簿或手机卡通信簿）的增加函数完成联系人的添加。实现动态联编，体现出多态特点。（下同）
			删除联系人：调用相应的通讯簿对象的删除操作删除一个联系人
			Display：显示相应的通讯簿中联系人的信息
			修改某一联系人的信息：调用通讯簿对象的函数完成操作
			查询并显示某一联系人的信息：调用通讯簿对象的函数完成操作
			将手机卡中的存储的联系人的信息移动到手机中
			将手机中存储的联系人的信息移动到手机卡中
			将手机卡中的存储的联系人的信息复制到手机中
			将手机中存储的联系人的信息复制到手机卡中

*/
class User
{
private:
	AddressBook* a;//基类指针
	SimBook s;
	Phonebook  p;
public:
	void add();
	void Delete();
	void display();
	void modify();
	void searchbyName();
	void movetoTel();//移动到手机中
	void movetoCard();//移动到手机卡中
	void copytoCard();//复制到手机卡
	void copytoTell();//复制到手机
};
