#include"PhonePerson.h"

PhonePerson::PhonePerson(string n , string t):name(n),tell(t)
{
	
}
 /*
 设置姓名
 */
 void PhonePerson::setName(string name)
 {
	 this->name = name;
 }

 /*
 设置电话
 */
 void PhonePerson::setTell(string tell)
 {
	 this->tell = tell;
 }
 /*
 获得电话
 */
 string PhonePerson::getTell()
 {
	 return tell;
 }

 /*
 获取名字
 */

 string PhonePerson::getName()
 {
	 return name;
 }
 /*
 修改名字
 */
 void PhonePerson::modifyName()
 {
	 cout << "请输入修改后的姓名" << endl;
	 string n;
	 cin >> n;
	 this-> name = n;
 }
 /*
 修改电话
 */
 void PhonePerson::modifyTell()
 {
	 cout << "请输入修改后的电话号码" << endl;
	 string t;
	 cin >> t;
	 this->tell = t;
 }

 /*
 重载运算符
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