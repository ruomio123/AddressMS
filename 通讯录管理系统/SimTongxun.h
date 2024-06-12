#pragma once
#include"tongxun.h"
#include"SIMperson.h"
#include<vector>
#include<fstream>
/*
5．	手机卡通信簿类（这是一个数据库类，继承于通讯簿抽象类）：用于记录手机卡中存储的所有联系人的信息
		  数据成员包括：
            手机联系人的数量
            手机联系人对象数组
        成员函数包括
            构造函数：读取文本文件中的数据,并根据文件内容创建联系人对象数组
            析构函数：将对象数组中的内容写入到文本文件中。
            增加函数：增加一个联系人
            删除操作：删除一个联系人（根据电话号码）
            Display:显示所有联系人的信息
            修改某一联系人的信息：（根据电话号码）
            查询并显示某一联系人的信息：(根据名字）


*/
class SimBook : public AddressBook 
{
public:
 
     // 构造函数：读取文件中的数据并创建联系人对象数组

    SimBook();

    // 析构函数：将联系人对象数组中的内容写入到文件中
    ~SimBook();


    // 增加函数：增加一个联系人
    void addPerson()override;

    // 删除操作：删除一个联系人
    void deletePersonByTell()override;

    // Display:显示所有联系人的信息
    void display()override;

    // 修改某一联系人的信息
    void modifyPersonByTell()override;

    // 查询并显示某一联系人的信息
    void searchPersonByName()override;

    int getNum();//返回联系人数


    int SimPersonNum; // 手机卡联系人的数量
    SimPerson simpersons[1000]; // 手机卡联系人对象数组

};