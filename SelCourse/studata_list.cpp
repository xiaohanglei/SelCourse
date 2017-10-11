#include "studata_list.h"
#include"iomanip"
#include "student.h"
#include "string"

Studata_list::Studata_list()//���캯��
{
    head = new studentdata;
    head->next = NULL;
}
bool Studata_list:: iscf(Student *c)// �Ƿ��ظ�
{
    studentdata * p = head->next;
    while (p != NULL)
    {
        if (p->stu.num == c->num)
        {
            return true ;
        }
        p = p->next;
    }
    return false;

}
int Studata_list:: add(Student *c)//���ѧ����Ϣ�ڵ�
{
    if(iscf(c))
    {
        cout << "ѧ���ظ�" << endl;
        return 0;
    }
    else
    {
        studentdata * cur = new studentdata;
        cur->stu = *c;
        if(head->next == NULL)
        {
            head->next = cur;
            cur->next = NULL;
        }
        else
        {
            cur->next = head->next;
            head->next = cur;
        }
    }
    return 1;
}
int Studata_list::del(int c)//ɾ��ѧ����Ϣ�ڵ�
{
    studentdata * p = head->next;
    studentdata * q = head;
    while (p != NULL)
    {
        if (p->stu.num == c)
        {
            q->next = p->next;
            delete p;
            cout << "ɾ���ɹ���" << endl;
            return 1;
        }
        q = p;
        p = p->next;
    }
    cout << "û�и�ѧ��!" << endl;
    return 1;

}
int Studata_list:: alt(int c)//�޸�ѧ����Ϣ
{
    int x ;
    studentdata * t;
    t = this->sel(c);
    if (t != NULL)
    {
        cout << "   ��ѡ��Ҫ�޸ĵ���" << endl;
        cout << "==============================" << endl;
        cout << "===========1.�޸�����==========" << endl;
        cout << "===========2.�޸ĵ绰==========" << endl;
        cout << "   ��ѡ��" ;  cin >> x ;
        if ( x == 1)
        {
            string na;
            cout << "������Ҫ�µ�������" ; cin>> na;
            t->stu.name = na;
            cout << "�޸ĳɹ��� " << endl;
        }
        else if (x == 2)
        {
            string ta;
            cout << "������Ҫ�µĵ绰��" ; cin>> ta;
            t->stu.tel = ta;
            cout << "�޸ĳɹ��� " << endl;
        }
        else
        {
            cout << " �������" << endl;
        }
    }
    return 1;
}

studentdata * Studata_list:: sel(int c)//����ѧ����Ϣ
{
    studentdata * q;
    studentdata * p = head->next;
    while(p != NULL)
    {
        if (p->stu.num == c)
        {

            break;
        }

        p = p->next;
    }
    if (p != NULL)
    {
        p->stu.dis();
    }
    else
    {
        cout << "û�и�ѧ�ŵ�ѧ����Ϣ��" << endl;
    }
    q = p;
    return q;
}


void Studata_list:: dis()//�������ѧ����Ϣ�ڵ�
{
    cout << endl << "ѧ�������" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << "ѧ    ��" << "   " <<setw(6) << "��  ��"<< "   " <<setw(11) << "��       ��" << endl;
    if (head->next != NULL)
    {
        studentdata * p = head->next;
        while(p != NULL)
        {
            cout << "===============================" << endl;
            cout <<setw(8) << p->stu.num << "   " <<setw(6) << p->stu.name<< "   " <<setw(11) << p->stu.tel << endl;
            p = p->next;
        }
        cout << "===============================" << endl;
    }
    else
    {
        cout << "=======������Ϣ������ӣ�======" << endl;
    }
}
