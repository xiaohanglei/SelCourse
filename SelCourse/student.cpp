#include "student.h"
#include "course.h"
#include"iostream"
#include"iomanip"
#include "string"
using namespace std;
Student::Student()
{

}

void Student:: set_num(int n) //������Ϣ
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

int Student:: get_num()//��ø�ѧ����ѧ��
{
    return num;
}
string Student:: get_name()//��ø�ѧ��������
{
    return name;
}
string Student:: get_tel()//��ø�ѧ���ĵ绰
{
    return tel;
}
void Student::dis()//��ʾ��ѧ����������Ϣ
{
    cout << endl << "��ѯ�����" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << "ѧ    ��" << "   " <<setw(6) << "��  ��"<< "   " <<setw(11) << "��       ��" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << num << "   " <<setw(6) << name<< "   " <<setw(11) << tel << endl;
    cout << "===============================" << endl;
}
void Student:: add_co(Course * ac)//ѡ��
{
    c_head.add(ac);
}
void Student:: del_co(int ac)//�˿�
{
    c_head.del(ac);
}
void Student:: dis_xk()//��ʾ������ѡ�Ŀγ�
{
    c_head.dis();

}
