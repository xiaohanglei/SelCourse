#include "course_list.h"
#include "string"
#include"iomanip"
Course_list::Course_list()
{
    head = new coursedata;
    head->next = NULL;
}

bool Course_list:: iscf(int c)//课程是否重复
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
bool Course_list:: add(Course *c)//增加
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
bool Course_list:: del(int c)//删除
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

int Course_list::alt(int c)//修改
{
    int x ;
    coursedata * t;
    t = this->sel(c);
    if (t != NULL)
    {
        cout << "   请选择要修改的项" << endl;
        cout << "==============================" << endl;
        cout << "===========1.修改名称==========" << endl;
        cout << "===========2.修改学分==========" << endl;
        cout << "===========3.修改教师==========" << endl;
        cout << "   请选择：" ;  cin >> x ;
        if ( x == 1)
        {
            string na;
            cout << "请输入要新的名称：" ; cin>> na;
            t->cou.cour_name = na;
            cout << "修改成功！ " << endl;
        }
        else if (x == 2)
        {
            int ta;
            cout << "请输入要新的学分：" ; cin>> ta;
            t->cou.xf = ta;
            cout << "修改成功！ " << endl;
        }
        else if( x == 3)
        {
            string na;
            cout << "请输入要新的教师：" ; cin>> na;
            t->cou.teacher = na;
            cout << "修改成功！ " << endl;
        }
        else
        {
            cout << " 输入错误！" << endl;
        }
    }
    return 1;
}

coursedata *Course_list::sel(int c)//查找
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
        cout << "没有该编号的课程信息！" << endl;
    }
    q = p;
    return q;
}


void Course_list:: dis()//输出所有课程 信息
{
    cout << endl << "课程情况" << endl;
    cout << "===================================" << endl;
    cout <<setw(8) << "编    号" << "   " <<setw(8) << "名    称"<< "   " <<setw(4) << "学分" <<  "   " << setw(6) << "教  师" <<endl;
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
        cout << "=========暂无信息，请添加！========" << endl;
    }
}

//Course_list:: ~Course_list()//析构函数
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
