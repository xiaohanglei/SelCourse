#ifndef STUDENT_H
#define STUDENT_H

#include"iostream"
#include "course_list.h"
using namespace std;
class Student
{
private:
    int num;//学号
    string name;//姓名
    string tel;//电话

public:
    Course_list c_head;//选的所有课程的链表指针
    Student();
    void set_num(int n); //设置该学生的学号
    void set_name(string na);//设置该学生的姓名
    void set_tel(string te);//设置该学生的电话

    int get_num();//获得该学生的学号
    string get_name();//获得该学生的姓名
    string get_tel();//获得该学生的电话

    void dis();//显示该学生的所有信息

    void add_co(Course * ac);//选课
    void del_co(int ac);//退课
    void dis_xk();//显示所有已选的课程

    friend class Studata_list;

};

#endif // STUDENT_H
