#include"PhonePerson.h"

PhonePerson::PhonePerson(string n , string t):name(n),tell(t)
{
	
}
 /*
 ��������
 */
 void PhonePerson::setName(string name)
 {
	 this->name = name;
 }

 /*
 ���õ绰
 */
 void PhonePerson::setTell(string tell)
 {
	 this->tell = tell;
 }
 /*
 ��õ绰
 */
 string PhonePerson::getTell()
 {
	 return tell;
 }

 /*
 ��ȡ����
 */

 string PhonePerson::getName()
 {
	 return name;
 }
 /*
 �޸�����
 */
 void PhonePerson::modifyName()
 {
	 cout << "�������޸ĺ������" << endl;
	 string n;
	 cin >> n;
	 this-> name = n;
 }
 /*
 �޸ĵ绰
 */
 void PhonePerson::modifyTell()
 {
	 cout << "�������޸ĺ�ĵ绰����" << endl;
	 string t;
	 cin >> t;
	 this->tell = t;
 }

 /*
 ���������
 */
 ostream& operator<<(ostream& output, const PhonePerson& p) {
	 output << p.name << " " << p.tell<<" ";
	 return output;
 }

istream& operator>>(istream& input, PhonePerson& p)
{
	 input >> p.name >> p.tell;
     return input;
 }