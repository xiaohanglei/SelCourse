#include "course.h"
#include"iostream"
#include"iomanip"
#include "string"
using namespace std;
Course::Course()
{
    s_head = new st;
    s_head->next = NULL;
}

void Course:: set_id(int i)//设置该门课的课程编号
{
    id = i;
}
void Course:: set_cour_name(string na)//设置该门课的名称
{
    cour_name = na;
}
void Course:: set_xf(int x)//设置该门课的学分
{
    xf = x;
}
void Course:: set_teacher(string nt)//设置该门课的任课教师
{
    teacher = nt;
}

int Course:: get_id()//获得该门课的课程编号
{
    return id;
}
string Course:: get_cour_name()//获得该门课的名称
{
    return cour_name;
}
int Course:: get_xf()//获得该门课的学分
{
    return xf;
}
string Course:: get_teacher()//获得该门课的任课教师
{
    return teacher;
}


void Course:: dis()//显示该课程的所有信息
{
    cout << endl << "查询结果：" << endl;
    cout << "===================================" << endl;
    cout <<setw(8) << "编    号" << "   " <<setw(8) << "名    称"<< "   " <<setw(4) << "学分" <<  "   " << setw(6) << "教  师" <<endl;
    cout << "===================================" << endl;
    cout <<setw(8) << id << "   " <<setw(8) << cour_name<< "   " <<setw(4) << xf << "   " << setw(6) << teacher << endl;
    cout << "===================================" << endl;
}
void Course:: add_st(string t)//当有人选课时，从学生链表中添加该学生的信息（姓名）
{
    st*New = new st;
    New->s_name = t;

    if (s_head->next == NULL)
    {
        s_head->next = New;
        New->next = NULL;
    }
    else
    {
        New->next = s_head->next;
        s_head->next = New;
    }
}
void Course:: del_st(string t)//当有人退课时，从学生链表中删除该学生的信息
{
    st * p = s_head->next;
    st * q = s_head;
    while (p != NULL)
    {
        if (p->s_name == t)
        {
            break;
        }
        q = p;
        p = p->next;
    }
    if(p != NULL)
    {
        q->next = p->next;
        delete p;
    }
    cout << "没有选择该门课程！" <<endl;
}
