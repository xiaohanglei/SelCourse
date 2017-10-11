#include "course_list.h"
#include "string"
#include"iomanip"
Course_list::Course_list()
{
    head = new coursedata;
    head->next = NULL;
}

bool Course_list:: iscf(int c)//�γ��Ƿ��ظ�
{
    coursedata * p = head->next;
    while (p != NULL)
    {
        if (p->cou.id == c)
        {
            return true;
        }
        p= p->next;
    }
    return false;
}
bool Course_list:: add(Course *c)//����
{
    if (iscf(c->id))
    {
        return false ;
    }
    else
    {
        coursedata * cur = new coursedata;
        cur->cou = *c;
        if (head->next == NULL)
        {
            head->next = cur;
            cur->next = NULL;
        }
        else
        {
            cur->next = head->next;
            head->next = cur;
        }
        return true ;
    }
}
bool Course_list:: del(int c)//ɾ��
{
    coursedata *p = head->next;
    coursedata *q = head;
    while( p != NULL)
    {
        if (p->cou.id == c)
        {
            q->next = p->next;
            delete p;

            return true;
        }
        q = p;
        p = p->next;
    }

    return false;
}

int Course_list::alt(int c)//�޸�
{
    int x ;
    coursedata * t;
    t = this->sel(c);
    if (t != NULL)
    {
        cout << "   ��ѡ��Ҫ�޸ĵ���" << endl;
        cout << "==============================" << endl;
        cout << "===========1.�޸�����==========" << endl;
        cout << "===========2.�޸�ѧ��==========" << endl;
        cout << "===========3.�޸Ľ�ʦ==========" << endl;
        cout << "   ��ѡ��" ;  cin >> x ;
        if ( x == 1)
        {
            string na;
            cout << "������Ҫ�µ����ƣ�" ; cin>> na;
            t->cou.cour_name = na;
            cout << "�޸ĳɹ��� " << endl;
        }
        else if (x == 2)
        {
            int ta;
            cout << "������Ҫ�µ�ѧ�֣�" ; cin>> ta;
            t->cou.xf = ta;
            cout << "�޸ĳɹ��� " << endl;
        }
        else if( x == 3)
        {
            string na;
            cout << "������Ҫ�µĽ�ʦ��" ; cin>> na;
            t->cou.teacher = na;
            cout << "�޸ĳɹ��� " << endl;
        }
        else
        {
            cout << " �������" << endl;
        }
    }
    return 1;
}

coursedata *Course_list::sel(int c)//����
{
    coursedata * q ;
    coursedata * p = head->next;
    while (p != NULL)
    {
        if (p->cou.id == c)
        {
            break;
        }
        p = p->next;
    }

    if (p != NULL)
    {
        p->cou.dis();
    }
    else
    {
        cout << "û�иñ�ŵĿγ���Ϣ��" << endl;
    }
    q = p;
    return q;
}


void Course_list:: dis()//������пγ� ��Ϣ
{
    cout << endl << "�γ����" << endl;
    cout << "===================================" << endl;
    cout <<setw(8) << "��    ��" << "   " <<setw(8) << "��    ��"<< "   " <<setw(4) << "ѧ��" <<  "   " << setw(6) << "��  ʦ" <<endl;
    if (head->next != NULL)
    {
        coursedata* p = head->next;
        while (p != NULL)
        {
            cout << "===================================" << endl;
            cout <<setw(8) << p->cou.id << "   " <<setw(8) << p->cou.cour_name<< "   " <<setw(4) << p->cou.xf << "   " << setw(6) << p->cou.teacher << endl;
            p = p->next;
        }
        cout << "===================================" << endl;
    }
    else
    {
        cout << "=========������Ϣ������ӣ�========" << endl;
    }
}

//Course_list:: ~Course_list()//��������
//{
//    coursedata * p = head->next;
//    coursedata * q = head;
//    while (p != NULL)
//    {
//        q = p;
//        p = p->next;
//        delete q ;
//    }
//    delete head;
//}
