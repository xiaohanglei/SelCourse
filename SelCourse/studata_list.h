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
    int add(Student *c);//���ѧ����Ϣ�ڵ�
    bool iscf(Student *c);// �Ƿ��ظ�
    int del(int c);//ɾ��ѧ����Ϣ�ڵ�
    int alt(int c);//�޸�ѧ����Ϣ
    studentdata * sel(int c);//����ѧ����Ϣ
    void dis();//�������ѧ����Ϣ�ڵ�
  //  ~Studata_list();//��������
 //   friend int save(Studata_list l_a, Course_list l_b);

};

#endif // STUDATA_LIST_H
