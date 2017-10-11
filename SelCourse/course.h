#ifndef COURSE_H
#define COURSE_H

#include"iostream"
#include "string"
using namespace std;
struct st
{
    string s_name;
    st * next;
};
class Course
{
private:
    int id;//课程编号
    string cour_name;//课程名称
    int xf;//学分
    string teacher ; //任课教师
    st * s_head;//选该门课的学生链表头指针
public:
//    Studata_list st1;
    Course();
    void set_id(int i);//设置该门课的课程编号
    void set_cour_name(string na);//设置该门课的名称
    void set_xf(int x);//设置该门课的学分
    void set_teacher(string nt);//设置该门课的任课教师

    int get_id();//获得该门课的课程编号
    string get_cour_name();//获得该门课的名称
    int get_xf();//获得该门课的学分
    string get_teacher();//获得该门课的任课教师

    void dis();//显示该课程的所有信息
    void add_st(string t);//当有人选课时，从学生链表中添加该学生的信息（姓名）
    void del_st(string t);//当有人退课时，从学生链表中删除该学生的信息

    friend class Course_list;
};

#endif // COURSE_H
