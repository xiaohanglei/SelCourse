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
//******************************��������******************************

int z_j_(Studata_list a,Course_list b);//������
int a_j(Studata_list a,Course_list b);//�������
int s_j(Studata_list a,Course_list b);//ѧ������
int s_add(Studata_list a);//���ѧ����Ϣ
int c_add(Course_list b);//��ӿγ�
int s_del(Studata_list a);//ɾ��ָ��ѧ�ŵ�ѧ��
int c_del(Course_list b);//ɾ��ָ����ŵĿγ�
int s_alt(Studata_list a); //�޸�ָ��ѧ�ŵ�ѧ����Ϣ
int c_alt(Course_list b); //�޸�ָ����ŵĿγ���Ϣ
int s_sel(Studata_list a);//��ѯָ��ѧ�ŵ�ѧ����Ϣ
int c_sel(Course_list b);//��ѯָ����ŵĿγ���Ϣ
int xk(studentdata * t, Course_list b);//ѡ��
int ck(studentdata * t, Course_list b);//�˿�
int save(Studata_list l_a, Course_list l_b);//�������ݵ��ļ���
string GetProgramDir();//���ظó�������·��
//******************************��������******************************


//******************************��������******************************
int z_j(Studata_list a, Course_list b)//������
{
    int x ,n;
    loop:
    cout << "\t" <<"*****************���˵�*****************" << endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             1.����Ա             ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             2.ѧ  ��             ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"***             0.�˳�ϵͳ           ***"<< endl;
    cout << "\t" <<"***                                  ***"<< endl;
    cout << "\t" <<"*****************���˵�*****************" << endl <<endl;
    cout << "��ѡ�������ݣ�[ ]" ;
    cout << "\b\b" ;
    cin >> n;
    if (n == 1)
    {
        system("cls");
        x = a_j(a,b);//�������Ա����
    }
    else if ( n == 2)
    {
        system("cls");
        x = s_j(a,b);//����ѧ������
    }
    else if (n == 0)
    {
        save(a,b);
        cout << "��л����ʹ��,��������˳�ϵͳ��" <<endl;
        exit(-1);
    }
    else
    {
        cout << "�����������������" << endl;
        system("pause");
        system("cls");
        goto loop;
    }
    return 1;
}
int a_j(Studata_list a, Course_list b)//�������
{
    int n;
    int flag;
loop:
    cout << "\t" <<"=================�����==================" << endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===1.����ѧ��              2.���ӿγ�===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===3.ɾ��ѧ��              4.ɾ���γ�===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===5.�޸�ѧ��              6.�޸Ŀγ�===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===7.��ѯѧ��              8.��ѯ�γ�===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===9.ѧ�����              10.�γ����==="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"===           0.�������˵�           ===="<< endl;
    cout << "\t" <<"===                                  ===="<< endl;
    cout << "\t" <<"=================�����==================" << endl <<endl;

    cout << "��ѡ������ţ�[  ]" ;
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
        cout << "����д����������룺" << endl;
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
int s_j(Studata_list a, Course_list b)//ѧ������
{
    int flag;
    int n;
    int nu;
    studentdata * p;
    cout << "���������ѧ�ţ�" ; cin >> nu;
loop:
    p = a.sel(nu);
    if (p != NULL)
    {

        cout << "\t" <<"*****************ѧ����*****************" << endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            1.ѧ��ѡ��            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            2.ѧ���˿�            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***            3.ѡ�����            ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"***           0.�������˵�           ***"<< endl;
        cout << "\t" <<"***                                  ***"<< endl;
        cout << "\t" <<"*****************ѧ����*****************" << endl <<endl;
        cout << "��ѡ������ţ�[ ]" ;
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
            cout << "����д����������룺" << endl;
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
int s_add(Studata_list a)//���ѧ����Ϣ
{
    Student * New = new Student;
    int n;
    string na;
    string t;
    cout << "������ѧ�ţ�" ; cin >> n;
    cout << "������������" ; cin >> na;
    cout << "������绰��" ; cin >> t;
    New->set_num(n);
    New->set_name(na);
    New->set_tel(t);
    if (a.add(New))
    {
       cout << "��ӳɹ���" << endl;
    }
    else
    {
        cout << "���ʧ�ܣ�����ظ���" << endl;
    }
    return 1;
}
int c_add(Course_list b)//��ӿγ�
{
    Course * New = new Course;
    int i ;
    string na;
    int x;
    string t;
    cout << "�������ţ�" ; cin >> i;
    cout << "���������ƣ�" ; cin >> na;
    cout << "������ѧ�֣�" ; cin >> x;
    cout << "�������ʦ��" ; cin >> t;
    New->set_id(i);
    New->set_cour_name(na);
    New->set_xf(x);
    New->set_teacher(t);
    if (b.add(New))
    {
       cout << "��ӳɹ���" << endl;
    }
    else
    {
        cout << "���ʧ�ܣ�����ظ���" << endl;
    }
    return 1;
}
int s_del(Studata_list a)//ɾ��ָ��ѧ�ŵ�ѧ��
{
    int sn;
    cout << "������Ҫɾ����ѧ����ѧ�ţ�" ; cin >> sn;
    a.del(sn);
    cout << "ɾ���ɹ���"<< endl;
    return 1;
}
int c_del(Course_list b)//ɾ��ָ����ŵĿγ�
{
    int ci;
    cout << "������Ҫɾ���Ŀγ̱�ţ�" ;cin >> ci;
    b.del(ci);
    return 1;
}
int s_alt(Studata_list a) //�޸�ָ��ѧ�ŵ�ѧ����Ϣ
{
    int n;
    cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" ; cin >> n;
    a.alt(n);
    return 1;
}
int c_alt(Course_list b) //�޸�ָ����ŵĿγ���Ϣ
{
    int n;
    cout << "������Ҫ�޸ĵĿγ̱�ţ�" ; cin >> n;
    b.alt(n);
    return 1;
}
int s_sel(Studata_list a)//��ѯָ��ѧ�ŵ�ѧ����Ϣ
{
    int na;
    cout << "������Ҫ��ѯ��ѧ�ţ�" ; cin >> na ;
    a.sel(na);
    return 1;
}
int c_sel(Course_list b)//��ѯָ����ŵĿγ���Ϣ
{
    int na ;
    cout << "������Ҫ��ѯ�ı�ţ�" ;cin >> na;
    b.sel(na);
    return 1;

}
int xk(studentdata * t, Course_list b)//ѡ��
{
    int cn;
    string cnx;
    coursedata * q;
    Course * c;
    b.dis();
    cout << "��������Ҫѡ��Ŀγ̱�ţ�" ; cin >> cn;
    if (b.iscf(cn))
    {
        cout << "Ҫѡ��Ŀγ���Ϣ���£�" << endl;
        q = b.sel(cn);
        c = &(q->cou);
        t->stu.add_co(c);//����ѡ�Ŀγ�c����ӵ������Ŀγ�������


        cout << "ѡ�γɹ���" << endl;
    }
    else
    {
        cout << "����������" << endl;
    }
    return 1;
}
int ck(studentdata * t, Course_list b)//�˿�
{
    int cn;
    string cnx;
    coursedata * q;
    Course * c;
    t->stu.dis_xk();
    cout << "������Ҫ�˵��γ̵ı�ţ�" ;cin >> cn;
    if (b.iscf(cn))
    {
        cout << "Ҫ�˵��Ŀγ���Ϣ���£�" << endl;
        q = b.sel(cn);
        c = &(q->cou);
        t->stu.del_co(c->get_id()); //����Ҫ�˵��Ŀγ̴Ӹ����Ŀγ�������ɾ��
        cout << "�˿γɹ���" << endl;
    }
    else
    {
        cout << "����������" << endl;
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
string GetProgramDir()//���ظó�������Ŀ¼
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

