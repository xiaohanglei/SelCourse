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
    bool add(Course *c);//����
    bool iscf(int c);//�γ��Ƿ��ظ�
    bool del(int c);//ɾ��
    int alt(int c);//�޸�
    coursedata * sel(int c);//����
    void dis();//������пγ� ��Ϣ
 //   ~Course_list();//��������

};

#endif // COURSE_LIST_H
