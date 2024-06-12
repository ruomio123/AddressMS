#include"User.h"
void User::add()
{
	cout << "1.���ֻ������ 2.�ڵ绰�������" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        a = &p;
        a->addPerson();
        break;
    case 2:
        a = &s;
        a->addPerson();
        break;
    default:
        break;
    }
    while (true)
    {
        int c;
        cout << "1.�˳� 2.�������" << endl;
      
        cin >> c;
        if (c == 1)
        {
            break;
        }
        else if (c == 2)
        {
            add();
            break;
        }
    }
}

void User::Delete()
{
    cout << "1.���ֻ���ɾ��  2.���ֻ�����ɾ��" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        a = &p;
        a->deletePersonByTell();
        break;
    case 2:
        a = &s;
        a->deletePersonByTell();
        break;
    }
   
   
    

    while (true)
    {
        cout << "1.�˳� 2.����ɾ��" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            break;
        }
        else if (n == 2) Delete();
    }
}

void User::display()
{
    cout << "1.���ֻ�����ʾ 2.�ڵ绰������ʾ" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        a = &p;
        a->display();
        break;
    case 2:
        a = &s;
        a->display();
        break;
    default:
        break;
    }
    while (true)
    {
        cout << "1.�˳� 2.������ʾ" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            break;
        }
        else if (n == 2)
        {
            system("cls");
            display();
        }
    }
}

void User::modify()
{
    cout << "1.���ֻ����޸� 2.�ڵ绰�����޸�" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        a = &p;
        a->modifyPersonByTell();
        break;
    case 2:
        a = &s;
        a->modifyPersonByTell();
        break;
    default:
        break;
    }

    while (true)
    {
        cout << "1.�˳� 2.�����޸�" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            break;
        }
        else if (n == 2)modify();
    }
}

void User::searchbyName()
{
    cout << "1.���ֻ��ϲ�ѯ 2.�ڵ绰���ϲ�ѯ" << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        a = &p;
        a->searchPersonByName();
        break;
    case 2:
        a = &s;
        a->searchPersonByName();
        break;
    default:
        break;
    }

    while (true)
    {
        cout << "1.�˳� 2.������ѯ" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            break;
        }
        else if (n == 2)searchbyName();
    }
}

void User::copytoTell()//���Ƶ��ֻ���
{
    string a, b, c, d;
    ifstream infile("sim.txt", ios::in);
    ofstream outfile("phone.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "��ʧ�ܣ�" << endl;
    }
    else
    {
        while (infile >> a >> b >>c >> d)//��ȡ�ֻ������ļ���Ϣ
        {
            int flag = 0;//��Ǳ���
            if (p.personNum> 1000)
            {
                cout << "�ڴ�������" << endl;
                break;
            }
            for (int i = 0;i < p.personNum;i++)//ȥ��
            {
                if (p.persons[i].getName() == a && p.persons[i].getTell() == b)
                {
                    flag = 1;
                    break;
               }
            }
            if (!flag)//��ǰ��ϵ�˲��ظ�

            {
                outfile << a << " " << b << endl;
                p.persons[p.personNum].setName(a);
                p.persons[p.personNum].setTell(b);
                cout << a<<" ���Ƴɹ���" << endl;
                p.personNum++;

            }
            if (flag)
            {
                cout << a << " �Ѿ�����" << endl;
            }
        }
    }
    infile.close();
    outfile.close();
}
void User::copytoCard()//���Ƶ��ֻ�����
{
    string a, b, c=" ", d=" ";
    ifstream infile("phone.txt", ios::in);
    ofstream outfile("sim.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "��ʧ�ܣ�" << endl;
    }
    else
    {
        while (infile >> a >> b )//��ȡ�ֻ����ļ���Ϣ
        {
            int flag = 0;//��Ǳ���
            if (s.SimPersonNum > 1000)
            {
                cout << "�ڴ�������" << endl;
                break;
            }
            for (int i = 0;i < s.SimPersonNum;i++)//ȥ��
            {
                if (s.simpersons[i].getName() == a && s.simpersons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//��ǰ��ϵ�˲��ظ�
            {
                outfile << a << " " << b << " " << c << " " << d;
               s.simpersons[s.SimPersonNum].setName(a);
               s.simpersons[s.SimPersonNum].setTell(b);
               s.simpersons[s.SimPersonNum].setAddress(c);
               s.simpersons[s.SimPersonNum].setQQNum(d);
                cout << a << " ���Ƴɹ���" << endl;
                s.SimPersonNum++;

            }
            if (flag)
            {
                cout << a << " �Ѿ�����" << endl;
            }
        }
    }
    infile.close();
    outfile.close();
}

void User::movetoTel()//�ֻ����ƶ����ֻ���
{
    string a, b, c, d;
    ifstream infile("sim.txt", ios::in);
    ofstream outfile("phone.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "��ʧ�ܣ�" << endl;
    }
    else
    {
        while (infile >> a >> b >> c >> d)//��ȡ�ֻ������ļ���Ϣ
        {
            int flag = 0;//��Ǳ���
            if (p.personNum > 1000)
            {
                cout << "�ڴ�������" << endl;
                break;
            }
            for (int i = 0;i < p.personNum;i++)//ȥ��
            {
                if (p.persons[i].getName() == a && p.persons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//��ǰ��ϵ�˲��ظ�
            {
                outfile << a << " " << b << endl;
                p.persons[p.personNum].setName(a);
                p.persons[p.personNum].setTell(b);
                cout << a << "�ƶ��ɹ�" << endl;
                p.personNum++;
                s.SimPersonNum = 0;
            }

        }
    }
  
    infile.close();
    outfile.close();
}




void User::movetoCard()
{
    string a, b, c = " ", d = " ";
    ifstream infile("phone.txt", ios::in);
    ofstream outfile("sim.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "��ʧ�ܣ�" << endl;
    }
    else
    {
        while (infile >> a >> b)//��ȡ�ֻ����ļ���Ϣ
        {
            int flag = 0;//��Ǳ���
            if (s.SimPersonNum > 1000)
            {
                cout << "�ڴ�������" << endl;
                break;
            }
            for (int i = 0;i < s.SimPersonNum;i++)//ȥ��
            {
                if (s.simpersons[i].getName() == a && s.simpersons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//��ǰ��ϵ�˲��ظ�
            {
                outfile << a << " " << b << " " << c << " " << d;
                s.simpersons[s.SimPersonNum].setName(a);
                s.simpersons[s.SimPersonNum].setTell(b);
                s.simpersons[s.SimPersonNum].setAddress(c);
                s.simpersons[s.SimPersonNum].setQQNum(c);
                cout << a << " �ƶ��ɹ���" << endl;
                s.SimPersonNum++;
                p.personNum = 0;
            }

        }
    }
    
    infile.close();
    outfile.close();
    

}