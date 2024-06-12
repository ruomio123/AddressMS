#include"PhoneTongxun.h"
#include<sstream>
Phonebook::Phonebook()
{
    ifstream inFile("phone.txt");
    int i = 0;
    if (inFile.is_open())
    {
        locale loc("zh_CN.utf8"); // UTF-8�µ�locale��������Ϣ
        inFile.imbue(loc); // ָ����ʹ�õ�locale��Ϣ

        string pname, ptell;
        while (inFile >> pname >> ptell) {
            persons[i].setName(pname);
            persons[i].setTell(ptell);
            ++i;
        }
    }
    personNum = i;
    inFile.close();
}



Phonebook::~Phonebook()
{
    ofstream outFile("phone.txt", ios::out);
    if (outFile.is_open()) {
        for (int i = 0; i < personNum; i++)
        {
            outFile << persons[i].getName()<< " " << persons[i].getTell() << endl;
        }
    }
    outFile.close();
}

int Phonebook::getNum()
{
    return personNum;
}


// ���Ӻ���������һ����ϵ��
void Phonebook::addPerson()
{
    if (personNum < 1000)
    {
        string Name;
        string Tell;
        cout << "-------������������ϵ�˵�����" << endl;
        cin >> Name;
        cout << "--------������������ϵ�˵ĵ绰��" << endl;
        cin >> Tell;
        for (int i = 0;i < personNum;i++)
        {
            if (persons[i].getTell() == Tell)
            {
                cout << "��ǰ��ϵ���Ѿ����ڣ���" << endl;
                return;
            }
        }
        persons[personNum].setName(Name);
        persons[personNum].setTell(Tell);
        personNum++;
        cout << "��ӳɹ�!!" << endl;
    }
    else
    {
        cout << "������������" << endl;
    }

}

// ɾ��������ɾ��һ����ϵ��(�����ֻ���)
void Phonebook::deletePersonByTell()
{
    string t;
    cout << "----������Ҫɾ������ϵ�˵绰����" << endl;
    cin >> t;
    int m =0;//��¼�±�
   
    for (; m <personNum; m++)
    {
        if (persons[m].getTell() == t)
            break;
    }
    if (m <personNum)
    {
        for (; m < personNum - 1; m++)
        {
            persons[m] = persons[m + 1];
        }
        personNum--;
        cout << "��ϵ��ɾ���ɹ�����" << endl;
        return;
    }
   if(m>=personNum)
    {
        cout << "����ϵ�˲����ڣ�����" << endl;
    }
}
    // Display:��ʾ������ϵ�˵���Ϣ
  void Phonebook::display()
  {
      for (int i = 0;i < personNum;i++)
      {
          cout << "������" << persons[i].getName() << " " << "�绰���룺" << persons[i].getTell() << endl;
      }
    }

    // �޸�ĳһ��ϵ�˵���Ϣ�������ֻ��ţ�
    void Phonebook::modifyPersonByTell()
    {
        string oldName;
        string newPhone;
        string newName;
        cout << "-----------������Ҫ�޸ĵ��˵��ֻ��ţ�" << endl;
        cin >> oldName;
        int i;
        for ( i = 0;i < personNum;i++)
        {
            if (persons[i].getTell() == oldName)
            {
                cout << "1.�޸����� 2.�޸ĵ绰" << endl;
                int c;
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "-----------�������µ�����:" << endl;
                    cin >> newName;
                    persons[i].setName(newName);
                    cout << "�޸ĳɹ�����" << endl;
                    break;
                case 2:
                    cout << "-----------�������µĵ绰:" << endl;
                    cin >> newPhone;
                    persons[i].setTell(newPhone);
                    cout << "�޸ĳɹ�����" << endl;

                    break;
                default:
                    break;
                }
            }
            if (i >= personNum)
            {
                cout << "--------------���ֻ���ϵ�˲�����" << endl;
            }
        }
      
    }

    // ��ѯ����ʾĳһ��ϵ�˵���Ϣ������������
    void Phonebook::searchPersonByName()
    {
        string Name;
        cout << "---------------������Ҫ���ҵ���ϵ�˵�������" << endl;
        cin >> Name;
        for (int i = 0; i < personNum; i++)
        {
            if (Name == persons[i].getName())
            {
                cout << "---------------����ϵ�˵���Ϣ����:" << endl;
                cout << "������" << persons[i].getName() << " " << "�绰���룺" << persons[i].getTell() << endl;
                break;
            }
            if (i >= personNum)
            {
                cout << "������1��Ǹ���޴���" << endl;
                cout << "1.�˳� 2.������ѯ" << endl;
                int t;
                cin >> t;
                switch (t)
                {
                case 1:
                    break;
                case 2:
                    searchPersonByName();
                    break;
                default:
                    break;
                }
            }
        }
    }