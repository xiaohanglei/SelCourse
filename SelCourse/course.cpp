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

void Course:: set_id(int i)//���ø��ſεĿγ̱��
{
    id = i;
}
void Course:: set_cour_name(string na)//���ø��ſε�����
{
    cour_name = na;
}
void Course:: set_xf(int x)//���ø��ſε�ѧ��
{
    xf = x;
}
void Course:: set_teacher(string nt)//���ø��ſε��ον�ʦ
{
    teacher = nt;
}

int Course:: get_id()//��ø��ſεĿγ̱��
{
    return id;
}
string Course:: get_cour_name()//��ø��ſε�����
{
    return cour_name;
}
int Course:: get_xf()//��ø��ſε�ѧ��
{
    return xf;
}
string Course:: get_teacher()//��ø��ſε��ον�ʦ
{
    return teacher;
}


void Course:: dis()//��ʾ�ÿγ̵�������Ϣ
{
    cout << endl << "��ѯ�����" << endl;
    cout << "===================================" << endl;
    cout <<setw(8) << "��    ��" << "   " <<setw(8) << "��    ��"<< "   " <<setw(4) << "ѧ��" <<  "   " << setw(6) << "��  ʦ" <<endl;
    cout << "===================================" << endl;
    cout <<setw(8) << id << "   " <<setw(8) << cour_name<< "   " <<setw(4) << xf << "   " << setw(6) << teacher << endl;
    cout << "===================================" << endl;
}
void Course:: add_st(string t)//������ѡ��ʱ����ѧ����������Ӹ�ѧ������Ϣ��������
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
void Course:: del_st(string t)//�������˿�ʱ����ѧ��������ɾ����ѧ������Ϣ
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
    cout << "û��ѡ����ſγ̣�" <<endl;
}
