#ifndef STUDENT_H
#define STUDENT_H

#include"iostream"
#include "course_list.h"
using namespace std;
class Student
{
private:
    int num;//ѧ��
    string name;//����
    string tel;//�绰

public:
    Course_list c_head;//ѡ�����пγ̵�����ָ��
    Student();
    void set_num(int n); //���ø�ѧ����ѧ��
    void set_name(string na);//���ø�ѧ��������
    void set_tel(string te);//���ø�ѧ���ĵ绰

    int get_num();//��ø�ѧ����ѧ��
    string get_name();//��ø�ѧ��������
    string get_tel();//��ø�ѧ���ĵ绰

    void dis();//��ʾ��ѧ����������Ϣ

    void add_co(Course * ac);//ѡ��
    void del_co(int ac);//�˿�
    void dis_xk();//��ʾ������ѡ�Ŀγ�

    friend class Studata_list;

};

#endif // STUDENT_H
