#pragma once
#include"tongxun.h"
#include"SIMperson.h"
#include<vector>
#include<fstream>
/*
5��	�ֻ���ͨ�Ų��ࣨ����һ�����ݿ��࣬�̳���ͨѶ�������ࣩ�����ڼ�¼�ֻ����д洢��������ϵ�˵���Ϣ
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
class SimBook : public AddressBook 
{
public:
 
     // ���캯������ȡ�ļ��е����ݲ�������ϵ�˶�������

    SimBook();

    // ��������������ϵ�˶��������е�����д�뵽�ļ���
    ~SimBook();


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

    int getNum();//������ϵ����


    int SimPersonNum; // �ֻ�����ϵ�˵�����
    SimPerson simpersons[1000]; // �ֻ�����ϵ�˶�������

};