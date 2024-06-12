#include"User.h"
void User::add()
{
	cout << "1.在手机上添加 2.在电话卡上添加" << endl;
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
        cout << "1.退出 2.继续添加" << endl;
      
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
    cout << "1.在手机上删除  2.在手机卡上删除" << endl;
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
        cout << "1.退出 2.继续删除" << endl;
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
    cout << "1.在手机上显示 2.在电话卡上显示" << endl;
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
        cout << "1.退出 2.继续显示" << endl;
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
    cout << "1.在手机上修改 2.在电话卡上修改" << endl;
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
        cout << "1.退出 2.继续修改" << endl;
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
    cout << "1.在手机上查询 2.在电话卡上查询" << endl;
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
        cout << "1.退出 2.继续查询" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            break;
        }
        else if (n == 2)searchbyName();
    }
}

void User::copytoTell()//复制到手机中
{
    string a, b, c, d;
    ifstream infile("sim.txt", ios::in);
    ofstream outfile("phone.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "打开失败！" << endl;
    }
    else
    {
        while (infile >> a >> b >>c >> d)//读取手机卡的文件信息
        {
            int flag = 0;//标记变量
            if (p.personNum> 1000)
            {
                cout << "内存已满！" << endl;
                break;
            }
            for (int i = 0;i < p.personNum;i++)//去重
            {
                if (p.persons[i].getName() == a && p.persons[i].getTell() == b)
                {
                    flag = 1;
                    break;
               }
            }
            if (!flag)//当前联系人不重复

            {
                outfile << a << " " << b << endl;
                p.persons[p.personNum].setName(a);
                p.persons[p.personNum].setTell(b);
                cout << a<<" 复制成功！" << endl;
                p.personNum++;

            }
            if (flag)
            {
                cout << a << " 已经存在" << endl;
            }
        }
    }
    infile.close();
    outfile.close();
}
void User::copytoCard()//复制到手机卡中
{
    string a, b, c=" ", d=" ";
    ifstream infile("phone.txt", ios::in);
    ofstream outfile("sim.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "打开失败！" << endl;
    }
    else
    {
        while (infile >> a >> b )//读取手机的文件信息
        {
            int flag = 0;//标记变量
            if (s.SimPersonNum > 1000)
            {
                cout << "内存已满！" << endl;
                break;
            }
            for (int i = 0;i < s.SimPersonNum;i++)//去重
            {
                if (s.simpersons[i].getName() == a && s.simpersons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//当前联系人不重复
            {
                outfile << a << " " << b << " " << c << " " << d;
               s.simpersons[s.SimPersonNum].setName(a);
               s.simpersons[s.SimPersonNum].setTell(b);
               s.simpersons[s.SimPersonNum].setAddress(c);
               s.simpersons[s.SimPersonNum].setQQNum(d);
                cout << a << " 复制成功！" << endl;
                s.SimPersonNum++;

            }
            if (flag)
            {
                cout << a << " 已经存在" << endl;
            }
        }
    }
    infile.close();
    outfile.close();
}

void User::movetoTel()//手机卡移动到手机中
{
    string a, b, c, d;
    ifstream infile("sim.txt", ios::in);
    ofstream outfile("phone.txt", ios::out);
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "打开失败！" << endl;
    }
    else
    {
        while (infile >> a >> b >> c >> d)//读取手机卡的文件信息
        {
            int flag = 0;//标记变量
            if (p.personNum > 1000)
            {
                cout << "内存已满！" << endl;
                break;
            }
            for (int i = 0;i < p.personNum;i++)//去重
            {
                if (p.persons[i].getName() == a && p.persons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//当前联系人不重复
            {
                outfile << a << " " << b << endl;
                p.persons[p.personNum].setName(a);
                p.persons[p.personNum].setTell(b);
                cout << a << "移动成功" << endl;
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
        cout << "打开失败！" << endl;
    }
    else
    {
        while (infile >> a >> b)//读取手机的文件信息
        {
            int flag = 0;//标记变量
            if (s.SimPersonNum > 1000)
            {
                cout << "内存已满！" << endl;
                break;
            }
            for (int i = 0;i < s.SimPersonNum;i++)//去重
            {
                if (s.simpersons[i].getName() == a && s.simpersons[i].getTell() == b)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)//当前联系人不重复
            {
                outfile << a << " " << b << " " << c << " " << d;
                s.simpersons[s.SimPersonNum].setName(a);
                s.simpersons[s.SimPersonNum].setTell(b);
                s.simpersons[s.SimPersonNum].setAddress(c);
                s.simpersons[s.SimPersonNum].setQQNum(c);
                cout << a << " 移动成功！" << endl;
                s.SimPersonNum++;
                p.personNum = 0;
            }

        }
    }
    
    infile.close();
    outfile.close();
    

}