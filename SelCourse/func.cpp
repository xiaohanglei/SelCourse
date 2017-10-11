#include"iostream"
#include "student.h"
#include"studata_list.h"
#include "course.h"
#include"course_list.h"
#include "string"
#include<fstream>
#include <Windows.h>
using namespace std;
#define STUDENT "stinfo.txt"
#define COURSE "coinfo.txt"
//******************************函数声明******************************

int z_j_(Studata_list a,Course_list b);//主界面
int a_j(Studata_list a,Course_list b);//管理界面
int s_j(Studata_list a,Course_list b);//学生界面
int s_add(Studata_list a);//添加学生信息
int c_add(Course_list b);//添加课程
int s_del(Studata_list a);//删除指定学号的学生
int c_del(Course_list b);//删除指定编号的课程
int s_alt(Studata_list a); //修改指定学号的学生信息
int c_alt(Course_list b); //修改指定编号的课程信息
int s_sel(Studata_list a);//查询指定学号的学生信息
int c_sel(Course_list b);//查询指定编号的课程信息
int xk(studentdata * t, Course_list b);//选课
int ck(studentdata * t, Course_list b);//退课
int save(Studata_list l_a, Course_list l_b);//保存数据到文件中
string GetProgramDir();//返回该程序所在路径
//******************************函数声明******************************


//******************************函数定义******************************
int z_j(Studata_list a, Course_list b)//主界面
{
    int x ,n;
    loop:
    cout << "\t" <<"*****************主菜单*****************" << endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             1.管理员             ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             2.学  生             ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             0.退出系统           ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"*****************主菜单*****************" << endl <<endl;
    cout << "请选择你的身份：[ ]" ;
    cout << "\b\b" ;
    cin >> n;
    if (n == 1)
    {
        system("cls");
        x = a_j(a,b);//进入管理员界面
    }
    else if ( n == 2)
    {
        system("cls");
        x = s_j(a,b);//进入学生界面
    }
    else if (n == 0)
    {
        save(a,b);
        cout << "感谢您的使用,按任意键退出系统！" <<endl;
        exit(-1);
    }
    else
    {
        cout << "输入错误，请重新输入" << endl;
        system("pause");
        system("cls");
        goto loop;
    }
    return 1;
}
int a_j(Studata_list a, Course_list b)//管理界面
{
    int n;
    int flag;
loop:
    cout << "\t" <<"=================管理端==================" << endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===1.增加学生              2.增加课程===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===3.删除学生              4.删除课程===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===5.修改学生              6.修改课程===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===7.查询学生              8.查询课程===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===9.学生情况              10.课程情况==="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===           0.返回主菜单           ===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"=================管理端==================" << endl <<endl;

    cout << "请选择功能序号：[  ]" ;
    cout << "\b\b\b" ;
    cin >> n ;
    switch (n)
    {
    case 0:
        system("cls");
        n = z_j(a,b);
        break;
    case 1:
        flag = s_add(a);
        break;
    case 2:
        flag = c_add(b);
        break;
    case 3:
        flag = s_del(a);
        break;
    case 4:
        flag = c_del(b);
        break;
    case 5:
        flag = s_alt(a);
        break;
    case 6:
        flag = c_alt(b);
        break;
    case 7:
        flag = s_sel(a);
        break;
    case 8:
        flag = c_sel(b);
        break;
    case 9:
        a.dis();
        break;
    case 10:
        b.dis();;
        break;
    default:
        cout << "序号有错，请重新输入：" << endl;
        system("pause");
        system("cls");
        goto loop;
        break;
    }
    system("pause");
    system("cls");
    goto loop;
    return 1;
}
int s_j(Studata_list a, Course_list b)//学生界面
{
    int flag;
    int n;
    int nu;
    studentdata * p;
    cout << "请输入你的学号：" ; cin >> nu;
loop:
    p = a.sel(nu);
    if (p != NULL)
    {

        cout << "\t" <<"*****************学生端*****************" << endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            1.学生选课            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            2.学生退课            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            3.选课情况            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***           0.返回主菜单           ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"*****************学生端*****************" << endl <<endl;
        cout << "请选择功能序号：[ ]" ;
        cout << "\b\b" ;
        cin >> n ;
        switch (n)
        {
        case 0:
            system("cls");
            n = z_j(a,b);
            break;
        case 1:
            flag = xk(p,b);
            break;
        case 2:
            flag = ck(p,b);
            break;
        case 3:
            p->stu.dis_xk();
            break;
        default:
            cout << "序号有错，请重新输入：" << endl;
            system("pause");
            system("cls");
            goto loop;
            break;
        }
        system("pause");
        system("cls");
        goto loop;
    }
    system("pause");
    system("cls");
    n = z_j(a,b);
    return 1;
}
int s_add(Studata_list a)//添加学生信息
{
    Student * New = new Student;
    int n;
    string na;
    string t;
    cout << "请输入学号：" ; cin >> n;
    cout << "请输入姓名：" ; cin >> na;
    cout << "请输入电话：" ; cin >> t;
    New->set_num(n);
    New->set_name(na);
    New->set_tel(t);
    if (a.add(New))
    {
       cout << "添加成功！" << endl;
    }
    else
    {
        cout << "添加失败，编号重复！" << endl;
    }
    return 1;
}
int c_add(Course_list b)//添加课程
{
    Course * New = new Course;
    int i ;
    string na;
    int x;
    string t;
    cout << "请输入编号：" ; cin >> i;
    cout << "请输入名称：" ; cin >> na;
    cout << "请输入学分：" ; cin >> x;
    cout << "请输入教师：" ; cin >> t;
    New->set_id(i);
    New->set_cour_name(na);
    New->set_xf(x);
    New->set_teacher(t);
    if (b.add(New))
    {
       cout << "添加成功！" << endl;
    }
    else
    {
        cout << "添加失败，编号重复！" << endl;
    }
    return 1;
}
int s_del(Studata_list a)//删除指定学号的学生
{
    int sn;
    cout << "请输入要删除的学生的学号：" ; cin >> sn;
    a.del(sn);
    cout << "删除成功！"<< endl;
    return 1;
}
int c_del(Course_list b)//删除指定编号的课程
{
    int ci;
    cout << "请输入要删除的课程编号：" ;cin >> ci;
    b.del(ci);
    return 1;
}
int s_alt(Studata_list a) //修改指定学号的学生信息
{
    int n;
    cout << "请输入要修改的学生学号：" ; cin >> n;
    a.alt(n);
    return 1;
}
int c_alt(Course_list b) //修改指定编号的课程信息
{
    int n;
    cout << "请输入要修改的课程编号：" ; cin >> n;
    b.alt(n);
    return 1;
}
int s_sel(Studata_list a)//查询指定学号的学生信息
{
    int na;
    cout << "请输入要查询的学号：" ; cin >> na ;
    a.sel(na);
    return 1;
}
int c_sel(Course_list b)//查询指定编号的课程信息
{
    int na ;
    cout << "请输入要查询的编号：" ;cin >> na;
    b.sel(na);
    return 1;

}
int xk(studentdata * t, Course_list b)//选课
{
    int cn;
    string cnx;
    coursedata * q;
    Course * c;
    b.dis();
    cout << "请输入你要选择的课程编号：" ; cin >> cn;
    if (b.iscf(cn))
    {
        cout << "要选择的课程信息如下：" << endl;
        q = b.sel(cn);
        c = &(q->cou);
        t->stu.add_co(c);//将所选的课程c，添加到该生的课程链表中


        cout << "选课成功！" << endl;
    }
    else
    {
        cout << "编号输入错误！" << endl;
    }
    return 1;
}
int ck(studentdata * t, Course_list b)//退课
{
    int cn;
    string cnx;
    coursedata * q;
    Course * c;
    t->stu.dis_xk();
    cout << "请输入要退掉课程的编号：" ;cin >> cn;
    if (b.iscf(cn))
    {
        cout << "要退掉的课程信息如下：" << endl;
        q = b.sel(cn);
        c = &(q->cou);
        t->stu.del_co(c->get_id()); //将所要退掉的课程从该生的课程链表中删除
        cout << "退课成功！" << endl;
    }
    else
    {
        cout << "编号输入错误！" << endl;
    }
    return 1;
}

int save(Studata_list l_a, Course_list l_b)
{
    string ss = GetProgramDir();  // Return the directory without the file name
    ss += "\\";

    studentdata * p = l_a.head->next;
    string stfile = ss + STUDENT;
    fstream fs(stfile.c_str(),ios::trunc|ios::in|ios::out);
    while (p != NULL)
    {
        fs<<p->stu.get_num()<< " " << p->stu.get_name()<< " " <<p->stu.get_tel()<<endl;
        p = p->next;
    }
    fs.close();

    coursedata * q = l_b.head->next;
    string cofile = ss + COURSE;
    fstream fs2(cofile.c_str(),ios::trunc|ios::in|ios::out);
    while(q != NULL)
    {
        fs2<<q->cou.get_id()<< " "
          <<q->cou.get_cour_name() << " "
         <<q->cou.get_xf() << " "
        <<q->cou.get_teacher()<<endl;
        q = q->next;
    }
    fs2.close();
    return 0;
}
string GetProgramDir()//返回该程序所在目录
{
    wchar_t exeFullPath[MAX_PATH]; // Full path
    string strPath = "";

    GetModuleFileName(NULL,exeFullPath,MAX_PATH);
    char CharString[MAX_PATH];
    size_t convertedChars = 0;
    wcstombs_s(&convertedChars, CharString, MAX_PATH, exeFullPath , _TRUNCATE);

    strPath=(string)CharString;    // Get full path of the file

    int pos = strPath.find_last_of('\\', strPath.length());
    return strPath.substr(0, pos);  // Return the directory without the file name
}

