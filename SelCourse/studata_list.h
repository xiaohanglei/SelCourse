#ifndef STUDATA_LIST_H
#define STUDATA_LIST_H

#include"student.h"
struct studentdata
{
    Student stu;
    studentdata * next;
};

class Studata_list
{
public:
    studentdata * head;
public:
    Studata_list();
    int add(Student *c);//添加学生信息节点
    bool iscf(Student *c);// 是否重复
    int del(int c);//删除学生信息节点
    int alt(int c);//修改学生信息
    studentdata * sel(int c);//查找学生信息
    void dis();//输出所有学生信息节点
  //  ~Studata_list();//析构函数
 //   friend int save(Studata_list l_a, Course_list l_b);

};

#endif // STUDATA_LIST_H
