#pragma once
#include<iostream>
#include<string>

class AddressBook
{
public:
    // ����һ����ϵ��
    virtual void addPerson() = 0;

    // ɾ��һ����ϵ��(���ݵ绰�ţ�
    virtual void deletePersonByTell() = 0;

    // ��ʾ������ϵ�˵���Ϣ
    virtual void display() = 0;

    // �޸�ĳһ��ϵ�˵���Ϣ�����ݵ绰���룩
    virtual void modifyPersonByTell() = 0;

    // ��ѯ����ʾĳһ��ϵ�˵���Ϣ(����������
    virtual void searchPersonByName() = 0;

    // ��������
};
