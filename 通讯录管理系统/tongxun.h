#pragma once
#include<iostream>
#include<string>

class AddressBook
{
public:
    // 增加一个联系人
    virtual void addPerson() = 0;

    // 删除一个联系人(根据电话号）
    virtual void deletePersonByTell() = 0;

    // 显示所有联系人的信息
    virtual void display() = 0;

    // 修改某一联系人的信息（根据电话号码）
    virtual void modifyPersonByTell() = 0;

    // 查询并显示某一联系人的信息(根据姓名）
    virtual void searchPersonByName() = 0;

    // 析构函数
};
