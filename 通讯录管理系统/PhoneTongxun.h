#pragma once
/*
4��	�ֻ�ͨѶ���ࣨ����һ�����ݿ��࣬�̳���ͨѶ�������ࣩ�����ڼ�¼�ֻ��д洢��������ϵ�˵���Ϣ
        ���ݳ�Ա������
            �ֻ���ϵ�˵�����
            �ֻ���ϵ�˶�������
        ��Ա��������
            ���캯������ȡ�ı��ļ��е�����,�������ļ����ݴ�����ϵ�˶�������
            ���������������������е�����д�뵽�ı��ļ��С�
            ���Ӻ���������һ����ϵ��
            ɾ��������ɾ��һ����ϵ�ˣ����ݵ绰���룩
            Display:��ʾ������ϵ�˵���Ϣ
            �޸�ĳһ��ϵ�˵���Ϣ�������ݵ绰���룩
            ��ѯ����ʾĳһ��ϵ�˵���Ϣ��(�������֣�

*/
#include <fstream>
#include "tongxun.h"
#include "PhonePerson.h"
using namespace std;
class Phonebook : public AddressBook 
{
public:
    int personNum;            // �ֻ���ϵ�˵�����
    PhonePerson persons[1000];   // �ֻ���ϵ�˶�������

    // ���캯������ȡ�ļ��е����ݲ�������ϵ�˶�������
    Phonebook();

    // ��������������ϵ�˶��������е�����д�뵽�ļ���
    ~Phonebook();

    // ���Ӻ���������һ����ϵ��
    void addPerson()override;

    // ɾ��������ɾ��һ����ϵ��
     void deletePersonByTell()override;

    // Display:��ʾ������ϵ�˵���Ϣ
    void display()override;

    // �޸�ĳһ��ϵ�˵���Ϣ
    void modifyPersonByTell()override;

    // ��ѯ����ʾĳһ��ϵ�˵���Ϣ
    void searchPersonByName()override;

    int getNum();//��ȡ��ϵ����
};
