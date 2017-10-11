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
    int id;//�γ̱��
    string cour_name;//�γ�����
    int xf;//ѧ��
    string teacher ; //�ον�ʦ
    st * s_head;//ѡ���ſε�ѧ������ͷָ��
public:
//    Studata_list st1;
    Course();
    void set_id(int i);//���ø��ſεĿγ̱��
    void set_cour_name(string na);//���ø��ſε�����
    void set_xf(int x);//���ø��ſε�ѧ��
    void set_teacher(string nt);//���ø��ſε��ον�ʦ

    int get_id();//��ø��ſεĿγ̱��
    string get_cour_name();//��ø��ſε�����
    int get_xf();//��ø��ſε�ѧ��
    string get_teacher();//��ø��ſε��ον�ʦ

    void dis();//��ʾ�ÿγ̵�������Ϣ
    void add_st(string t);//������ѡ��ʱ����ѧ����������Ӹ�ѧ������Ϣ��������
    void del_st(string t);//�������˿�ʱ����ѧ��������ɾ����ѧ������Ϣ

    friend class Course_list;
};

#endif // COURSE_H
