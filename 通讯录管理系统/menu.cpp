#include"menu.h"
void menu::display()
{
    cout << "*********************************************************************************" << endl;
    cout << "*                         " << " ### ͨѶ¼����ϵͳ ###                            *" << endl;
    cout << "*                         " << "0.���ͨѶ¼                                       *" << endl;
    cout << "*                         " << "1.��ѯ��ϵ����Ϣ                                   *" << endl;
    cout << "*                         " << "2.�޸���ϵ����Ϣ                                   *" <<endl;
    cout << "*                         " << "3.ɾ����ϵ��                                       *" << endl;
    cout << "*                         " << "4.������ϵ����Ϣ                                   *" << endl;
    cout << "*                         " << "5.���ֻ�����ϵ�˸��Ƶ��ֻ���                       *" << endl;
    cout << "*                         " << "6.���ֻ���ϵ�˸��Ƶ��ֻ�����                       *" << endl;
    cout << "*                         " << "7.���ֻ���ϵ���ƶ����ֻ�����                       *" << endl;
    cout << "*                         " << "8.���ֻ�����ϵ���ƶ����ֻ���                       *" << endl;

    cout << "*********************************************************************************" << endl;
    

    cout << "                 *******��ѡ����Ҫ�����Ĳ��裨0-8��  *******" << endl;
    int n;
    cin >> n;
    if (n > 8||n<0)
    {
        cout << "�������,���������룺" << endl;
        return;
    }

    else
    {
        switch (n)
        {
        case 0:
            p.display();
            break;
        case 1:
            p.searchbyName();
            break;
        case 2:
            p.modify();
            break;
        case 3:
            p.Delete();
            break;
        case 4:
            p.add();
            break;
        case 5:
            p.copytoTell();
            break;
        case 6:
            p.copytoCard();
            break;
        case 7:
            p.movetoCard();
            break;
        case 8:
            p.movetoTel();
            break;
        }
    }
    cout << "�Ƿ��˳�����ϵͳ��1.�� 2.����������" << endl;
    int t;
    cin >> t;
    switch (t)
    {
    case 1:
        break;
    case 2:
        system("cls");
        display();
        break;
    default: break;
    }
   
}


