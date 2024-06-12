#include"SimTongxun.h"
SimBook::SimBook()
{  
    ifstream infile("sim.txt", ios::in);//读取文件
    int i = 0;
    if (infile.is_open()) //文件不空
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
        cout << "----------请输入新增联系人的姓名" << endl;
        cin >> n;
        cout << "----------请输入新增联系人的电话" << endl;
        cin >> t;
        cout << "----------请输入新增联系人的籍贯" << endl;
        cin >> a;
        cout << "----------请输入新增联系人的qq" << endl;
        cin >> qq;
        for (int i = 0;i < SimPersonNum;i++)
        {
            if (simpersons[i].getTell() == t)
            {
                cout << "当前联系人已经存在！！" << endl;
                return;
            }
        }
        simpersons[SimPersonNum].setName(n);
        simpersons[SimPersonNum].setTell(t);
        simpersons[SimPersonNum].setAddress(a);
        simpersons[SimPersonNum].setQQNum(qq);
        SimPersonNum++;
        cout << "添加成功!!" << endl;
    }
    else
    {
        cout << "容量超出限制" << endl;
    }
}
void SimBook::deletePersonByTell()
{
    string t;
    cout << "------请输入要删除的电话号码" << endl;
    int m = 0;//记录下标
    cin >> t;

    int i;
    for (i = 0;i < SimPersonNum;i++) 
    {
        if (simpersons[i].getTell() == t) {
            break;
        }
        
    }
    // 找到了对应的联系人，从数组中删除
    if (i < SimPersonNum)
    {
        for (;i < SimPersonNum - 1;i++)
        {
            simpersons[i] = simpersons[i + 1];
        }
        SimPersonNum--;
        cout << "删除成功!!" << endl;
        return;
    }
    
  if(i>=SimPersonNum)
    {
        cout << "-------该手机卡联系人不存在" << endl;
       }
}

void SimBook::display()
{
    for (int i=0;i<SimPersonNum;i++)
    {
        cout <<"姓名：" <<simpersons[i].getName()<<" "<<"电话："<<simpersons[i].getTell()<<" "<<"籍贯："<<simpersons[i].getAddress()<<" "<<"QQ号："<<simpersons[i].getQQ() << endl;
    }
}

void SimBook::modifyPersonByTell()
{
    string oldPhone;
    string newPhone;
    string newName;
    string newAddress;
    string newQQ;
    cout << "请输入要修改的人的电话号码" << endl;
    cin >> oldPhone;
    int a;//选择
    int i;
    for ( i = 0;i < SimPersonNum;i++)
    {
        if (simpersons[i].getTell() == oldPhone)
        {
            cout << "姓名：" << simpersons[i].getName() << " " << "电话：" << simpersons[i].getTell() << " " << "籍贯：" << simpersons[i].getAddress() << " " << "QQ号：" << simpersons[i].getQQ() << endl;
            cout << "-----------------请选择你的操作----------------" << endl;
            cout << "1.修改姓名 2.修改电话号码 ：3.修改籍贯 4.修改qq号" << endl;
            cin >> a;
            switch (a)
            {
            case 1:
                cout << "------输入新的姓名：" << endl;
                cin >> newName;
                simpersons[i].setName(newName);
                cout << "修改成功！！" << endl;
                break;
            case 2:
                cout << "------输入新的电话：" << endl;
                cin >> newPhone;
                simpersons[i].setName(newPhone);
                cout << "修改成功！！" << endl;
                break;
            case 3:
                cout << "------输入新的籍贯：" << endl;
                cin >> newAddress;
                simpersons[i].setName(newAddress);
                cout << "修改成功！！" << endl;
                break;
            case 4:
                cout << "------输入新的QQ号：" << endl;
                cin >> newQQ;
                simpersons[i].setName(newQQ);
                cout << "修改成功！！" << endl;
                break;
            default:
                break;
            }
        }
        if (i >= SimPersonNum)
        {
            cout << "！！！！抱歉，查无此人，请注意是否输入错误:" << endl;
            return;
        }
    }
   
}
void SimBook::searchPersonByName()
{
    string Name;
    cout << "请输入要查找的联系人的姓名：" << endl;
    cin >> Name;
    for (int i = 0; i < SimPersonNum; i++)
    {
        if (Name == simpersons[i].getName())
        {
            cout << "该联系人的信息如下:" << endl;
            cout << "姓名：" << simpersons[i].getName() << " " << "电话：" << simpersons[i].getTell() << " " << "籍贯：" << simpersons[i].getAddress() << " " << "QQ号：" << simpersons[i].getQQ() << endl;
            break;
        }
        if (i>=SimPersonNum)
        {
            cout << "！！！抱歉，查无此人" << endl;
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

int SimBook::getNum()
{
    return SimPersonNum;
}