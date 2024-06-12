#include"PhoneTongxun.h"
#include<sstream>
Phonebook::Phonebook()
{
    ifstream inFile("phone.txt");
    int i = 0;
    if (inFile.is_open())
    {
        locale loc("zh_CN.utf8"); // UTF-8下的locale（区域）信息
        inFile.imbue(loc); // 指定流使用的locale信息

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


// 增加函数：增加一个联系人
void Phonebook::addPerson()
{
    if (personNum < 1000)
    {
        string Name;
        string Tell;
        cout << "-------请输入新增联系人的姓名" << endl;
        cin >> Name;
        cout << "--------请输入新增联系人的电话：" << endl;
        cin >> Tell;
        for (int i = 0;i < personNum;i++)
        {
            if (persons[i].getTell() == Tell)
            {
                cout << "当前联系人已经存在！！" << endl;
                return;
            }
        }
        persons[personNum].setName(Name);
        persons[personNum].setTell(Tell);
        personNum++;
        cout << "添加成功!!" << endl;
    }
    else
    {
        cout << "容量超出限制" << endl;
    }

}

// 删除操作：删除一个联系人(根据手机号)
void Phonebook::deletePersonByTell()
{
    string t;
    cout << "----请输入要删除的联系人电话号码" << endl;
    cin >> t;
    int m =0;//记录下标
   
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
        cout << "联系人删除成功！！" << endl;
        return;
    }
   if(m>=personNum)
    {
        cout << "该联系人不存在！！！" << endl;
    }
}
    // Display:显示所有联系人的信息
  void Phonebook::display()
  {
      for (int i = 0;i < personNum;i++)
      {
          cout << "姓名：" << persons[i].getName() << " " << "电话号码：" << persons[i].getTell() << endl;
      }
    }

    // 修改某一联系人的信息（根据手机号）
    void Phonebook::modifyPersonByTell()
    {
        string oldName;
        string newPhone;
        string newName;
        cout << "-----------请输入要修改的人的手机号：" << endl;
        cin >> oldName;
        int i;
        for ( i = 0;i < personNum;i++)
        {
            if (persons[i].getTell() == oldName)
            {
                cout << "1.修改姓名 2.修改电话" << endl;
                int c;
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "-----------请输入新的姓名:" << endl;
                    cin >> newName;
                    persons[i].setName(newName);
                    cout << "修改成功！！" << endl;
                    break;
                case 2:
                    cout << "-----------请输入新的电话:" << endl;
                    cin >> newPhone;
                    persons[i].setTell(newPhone);
                    cout << "修改成功！！" << endl;

                    break;
                default:
                    break;
                }
            }
            if (i >= personNum)
            {
                cout << "--------------该手机联系人不存在" << endl;
            }
        }
      
    }

    // 查询并显示某一联系人的信息（根据姓名）
    void Phonebook::searchPersonByName()
    {
        string Name;
        cout << "---------------请输入要查找的联系人的姓名：" << endl;
        cin >> Name;
        for (int i = 0; i < personNum; i++)
        {
            if (Name == persons[i].getName())
            {
                cout << "---------------该联系人的信息如下:" << endl;
                cout << "姓名：" << persons[i].getName() << " " << "电话号码：" << persons[i].getTell() << endl;
                break;
            }
            if (i >= personNum)
            {
                cout << "！！！1抱歉查无此人" << endl;
                cout << "1.退出 2.继续查询" << endl;
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