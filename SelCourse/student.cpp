#include "student.h"
#include "course.h"
#include"iostream"
#include"iomanip"
#include "string"
using namespace std;
Student::Student()
{

}

void Student:: set_num(int n) //设置信息
{
    num = n;
}
void Student:: set_name(string na)
{
    name = na;
}
void Student:: set_tel(string te)
{
    tel = te;
}

int Student:: get_num()//获得该学生的学号
{
    return num;
}
string Student:: get_name()//获得该学生的姓名
{
    return name;
}
string Student:: get_tel()//获得该学生的电话
{
    return tel;
}
void Student::dis()//显示该学生的所有信息
{
    cout << endl << "查询结果：" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << "学    号" << "   " <<setw(6) << "姓  名"<< "   " <<setw(11) << "电       话" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << num << "   " <<setw(6) << name<< "   " <<setw(11) << tel << endl;
    cout << "===============================" << endl;
}
void Student:: add_co(Course * ac)//选课
{
    c_head.add(ac);
}
void Student:: del_co(int ac)//退课
{
    c_head.del(ac);
}
void Student:: dis_xk()//显示所有已选的课程
{
    c_head.dis();

}
