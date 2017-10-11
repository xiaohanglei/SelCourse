#include <iostream>
#include "student.h"
#include"studata_list.h"
#include "course.h"
#include"course_list.h"
#include"func.cpp"
#include <fstream>
#include <Windows.h>

#define STUDENT "stinfo.txt"
#define COURSE "coinfo.txt"
using namespace std;
int sc_load(Studata_list l_a, Course_list l_b);
int main()
{
    Studata_list a;
    Course_list b;
//**************************加载后台文件中的学生和课程**************************
    sc_load(a,b);

    system("cls");
    cout << "正在加载数据....." << endl;
    Sleep(3000);
    system("cls");
    cout << "加载完成！" <<endl;
    system("pause");
    system("cls");
//**************************调用主菜单进入功能系统**************************

    z_j(a,b);

//**************************更新后台文件中的学生和课程**************************
    save(a,b);


    return 0;
}
int sc_load(Studata_list l_a,Course_list l_b)
{

    string ss = GetProgramDir();  // Return the directory without the file name
    ss += "\\";


    //========================加载学生========================
    string stfile = ss + STUDENT;
    fstream fs(stfile.c_str(),ios::ate|ios::in|ios::out);
    fs.seekp(0,ios::beg);//文件指针移向文件开头
    Student * New ;
    int n;
    string na;
    string t;
    while(!(fs.eof()))
    {
        fs>>n>>na>>t;

        New = new Student;

        New->set_num(n);
        New->set_name(na);
        New->set_tel(t);
        l_a.add(New);
    }
    fs.close();

//========================加载课程========================
    string cofile = ss += COURSE;
    fstream fs2(cofile.c_str(),ios::ate|ios::in|ios::out);
    fs2.seekp(0,ios::beg);//文件指针移向文件开头
    Course * New_1;
    int i ;
    string _na;
    int x;
    string _t;

    while(!(fs2.eof()))
    {
        fs2>> i >> _na >> x >> _t;

        New_1 = new Course;

        New_1->set_id(i);
        New_1->set_cour_name(_na);
        New_1->set_xf(x);
        New_1->set_teacher(_t);
        l_b.add(New_1);
    }
    fs2.close();
    return 1;
}
