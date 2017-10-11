#include "studata_list.h"
#include"iomanip"
#include "student.h"
#include "string"

Studata_list::Studata_list()//构造函数
{
    head = new studentdata;
    head->next = NULL;
}
bool Studata_list:: iscf(Student *c)// 是否重复
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
int Studata_list:: add(Student *c)//添加学生信息节点
{
    if(iscf(c))
    {
        cout << "学号重复" << endl;
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
int Studata_list::del(int c)//删除学生信息节点
{
    studentdata * p = head->next;
    studentdata * q = head;
    while (p != NULL)
    {
        if (p->stu.num == c)
        {
            q->next = p->next;
            delete p;
            cout << "删除成功！" << endl;
            return 1;
        }
        q = p;
        p = p->next;
    }
    cout << "没有该学生!" << endl;
    return 1;

}
int Studata_list:: alt(int c)//修改学生信息
{
    int x ;
    studentdata * t;
    t = this->sel(c);
    if (t != NULL)
    {
        cout << "   请选择要修改的项" << endl;
        cout << "==============================" << endl;
        cout << "===========1.修改姓名==========" << endl;
        cout << "===========2.修改电话==========" << endl;
        cout << "   请选择：" ;  cin >> x ;
        if ( x == 1)
        {
            string na;
            cout << "请输入要新的姓名：" ; cin>> na;
            t->stu.name = na;
            cout << "修改成功！ " << endl;
        }
        else if (x == 2)
        {
            string ta;
            cout << "请输入要新的电话：" ; cin>> ta;
            t->stu.tel = ta;
            cout << "修改成功！ " << endl;
        }
        else
        {
            cout << " 输入错误！" << endl;
        }
    }
    return 1;
}

studentdata * Studata_list:: sel(int c)//查找学生信息
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
        cout << "没有该学号的学生信息！" << endl;
    }
    q = p;
    return q;
}


void Studata_list:: dis()//输出所有学生信息节点
{
    cout << endl << "学生情况：" << endl;
    cout << "===============================" << endl;
    cout <<setw(8) << "学    号" << "   " <<setw(6) << "姓  名"<< "   " <<setw(11) << "电       话" << endl;
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
        cout << "=======暂无信息，请添加！======" << endl;
    }
}
