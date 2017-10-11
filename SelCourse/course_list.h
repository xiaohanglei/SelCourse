#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include"course.h"
#include "string"

struct coursedata
{
    Course cou;
    coursedata * next;
};
class Course_list
{
public:
    coursedata * head;
public:
    Course_list();
    bool add(Course *c);//增加
    bool iscf(int c);//课程是否重复
    bool del(int c);//删除
    int alt(int c);//修改
    coursedata * sel(int c);//查找
    void dis();//输出所有课程 信息
 //   ~Course_list();//析构函数

};

#endif // COURSE_LIST_H
