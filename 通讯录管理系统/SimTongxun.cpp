#include"SimTongxun.h"
SimBook::SimBook()
{  
    ifstream infile("sim.txt", ios::in);//��ȡ�ļ�
    int i = 0;
    if (infile.is_open()) //�ļ�����
    {
        string pname, ptelephone, paddress, pQQ;
        while (infile >> pname) 
        {
            infile >> ptelephone;
            infile >> paddress;
            infile >> pQQ;
            simpersons[i].setName(pname);
            simpersons[i].setTell(ptelephone);
            simpersons[i].setAddress(paddress);
            simpersons[i].setQQNum(pQQ);
            i++;
        }
    }
    SimPersonNum = i;
    infile.close();
}

SimBook::~SimBook()
{
    ofstream outFile("sim.txt", ios::out);

    if (outFile.is_open()) {
        for (int i = 0; i < SimPersonNum; i++)
        {
            outFile << simpersons[i].getName() << " " << simpersons[i].getTell() << " " << simpersons[i].getAddress()<<" "<< simpersons[i].getQQ()<<endl;
        }
    }
    outFile.close();
}

void SimBook::addPerson()
{
    if (SimPersonNum < 1000)
    {
        string n;
        string t;
        string a;
        string qq;
        cout << "----------������������ϵ�˵�����" << endl;
        cin >> n;
        cout << "----------������������ϵ�˵ĵ绰" << endl;
        cin >> t;
        cout << "----------������������ϵ�˵ļ���" << endl;
        cin >> a;
        cout << "----------������������ϵ�˵�qq" << endl;
        cin >> qq;
        for (int i = 0;i < SimPersonNum;i++)
        {
            if (simpersons[i].getTell() == t)
            {
                cout << "��ǰ��ϵ���Ѿ����ڣ���" << endl;
                return;
            }
        }
        simpersons[SimPersonNum].setName(n);
        simpersons[SimPersonNum].setTell(t);
        simpersons[SimPersonNum].setAddress(a);
        simpersons[SimPersonNum].setQQNum(qq);
        SimPersonNum++;
        cout << "��ӳɹ�!!" << endl;
    }
    else
    {
        cout << "������������" << endl;
    }
}
void SimBook::deletePersonByTell()
{
    string t;
    cout << "------������Ҫɾ���ĵ绰����" << endl;
    int m = 0;//��¼�±�
    cin >> t;

    int i;
    for (i = 0;i < SimPersonNum;i++) 
    {
        if (simpersons[i].getTell() == t) {
            break;
        }
        
    }
    // �ҵ��˶�Ӧ����ϵ�ˣ���������ɾ��
    if (i < SimPersonNum)
    {
        for (;i < SimPersonNum - 1;i++)
        {
            simpersons[i] = simpersons[i + 1];
        }
        SimPersonNum--;
        cout << "ɾ���ɹ�!!" << endl;
        return;
    }
    
  if(i>=SimPersonNum)
    {
        cout << "-------���ֻ�����ϵ�˲�����" << endl;
       }
}

void SimBook::display()
{
    for (int i=0;i<SimPersonNum;i++)
    {
        cout <<"������" <<simpersons[i].getName()<<" "<<"�绰��"<<simpersons[i].getTell()<<" "<<"���᣺"<<simpersons[i].getAddress()<<" "<<"QQ�ţ�"<<simpersons[i].getQQ() << endl;
    }
}

void SimBook::modifyPersonByTell()
{
    string oldPhone;
    string newPhone;
    string newName;
    string newAddress;
    string newQQ;
    cout << "������Ҫ�޸ĵ��˵ĵ绰����" << endl;
    cin >> oldPhone;
    int a;//ѡ��
    int i;
    for ( i = 0;i < SimPersonNum;i++)
    {
        if (simpersons[i].getTell() == oldPhone)
        {
            cout << "������" << simpersons[i].getName() << " " << "�绰��" << simpersons[i].getTell() << " " << "���᣺" << simpersons[i].getAddress() << " " << "QQ�ţ�" << simpersons[i].getQQ() << endl;
            cout << "-----------------��ѡ����Ĳ���----------------" << endl;
            cout << "1.�޸����� 2.�޸ĵ绰���� ��3.�޸ļ��� 4.�޸�qq��" << endl;
            cin >> a;
            switch (a)
            {
            case 1:
                cout << "------�����µ�������" << endl;
                cin >> newName;
                simpersons[i].setName(newName);
                cout << "�޸ĳɹ�����" << endl;
                break;
            case 2:
                cout << "------�����µĵ绰��" << endl;
                cin >> newPhone;
                simpersons[i].setName(newPhone);
                cout << "�޸ĳɹ�����" << endl;
                break;
            case 3:
                cout << "------�����µļ��᣺" << endl;
                cin >> newAddress;
                simpersons[i].setName(newAddress);
                cout << "�޸ĳɹ�����" << endl;
                break;
            case 4:
                cout << "------�����µ�QQ�ţ�" << endl;
                cin >> newQQ;
                simpersons[i].setName(newQQ);
                cout << "�޸ĳɹ�����" << endl;
                break;
            default:
                break;
            }
        }
        if (i >= SimPersonNum)
        {
            cout << "����������Ǹ�����޴��ˣ���ע���Ƿ��������:" << endl;
            return;
        }
    }
   
}
void SimBook::searchPersonByName()
{
    string Name;
    cout << "������Ҫ���ҵ���ϵ�˵�������" << endl;
    cin >> Name;
    for (int i = 0; i < SimPersonNum; i++)
    {
        if (Name == simpersons[i].getName())
        {
            cout << "����ϵ�˵���Ϣ����:" << endl;
            cout << "������" << simpersons[i].getName() << " " << "�绰��" << simpersons[i].getTell() << " " << "���᣺" << simpersons[i].getAddress() << " " << "QQ�ţ�" << simpersons[i].getQQ() << endl;
            break;
        }
        if (i>=SimPersonNum)
        {
            cout << "��������Ǹ�����޴���" << endl;
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

int SimBook::getNum()
{
    return SimPersonNum;
}