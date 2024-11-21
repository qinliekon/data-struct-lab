#include <iostream>
#include<algorithm>
#include "linklist.h"
#include "Student.h"
#include "SqList.h"
using namespace std;
#define MAXSIZE 100

bool cmp_stu(Student x,Student y){
    return x.score > y.score;
}

void done_SqList(){
    SqList<Student> lst;
    int item = 0;
    cout << "��ѡ����:\t1.��ʾ\t2.¼��\t3.����\t4.ɾ��\t5.����\t6.ͳ��\t7.����\t8.���\t9.�˳�" << endl;
    while(cin >> item && item != 9)
    {
        switch (item)
        {
         case 1:
         {
            lst.DispList();
            break;
         }
         case 2:
         {
            Student s;
            cout << "������¼��ѧ����Ϣ��ѧ�� ���� ����)" << endl;
            cin >> s.num >> s.name >> s.score;
            lst.ListInsert(lst.length,s);
            break;
         }
         case 3:
         {
            Student s;
            string nu;
            cout << "���������ѧ��ѧ��" << endl;
            cin >> nu;
            lst.GetElem(nu,s);
            cout << s << endl;
            break;
        }
        case 4:
        {
            Student s;
            int i;
            cout << "������ɾ��ѧ��λ��" << endl;
            cin >> i;
            lst.ListDelete(i,s);
            break;
        }
        case 5:
        {
            Student s;
            int i;
            cout << "���������ѧ����Ϣ��ѧ�� ���� ����)��λ��" << endl;
            cin >> s.num >> s.name >> s.score >> i;
            lst.SetElem(i,s);
            break;
        }
        case 6:
        {
            cout << "����ѧ������Ϊ��" << lst.length << endl;
            break;
        }
        case 7:
        {
            sort(lst.data,lst.data + lst.length, cmp_stu);
            cout << "�������" << endl;
            break;
        }
        case 8:
        {
            lst.~SqList();
            break;
        }
        case 9:
            return;
        default:
            cout << "δ֪���ܣ�����������" << endl;
            break;
        }
    cout << "��ѡ����:\t1.��ʾ\t2.¼��\t3.����\t4.ɾ��\t5.����\t6.ͳ��\t7.����\t8.���\t9.�˳�" << endl;
    }
}

void done_linklist(){
    LinkList<Student> lst;
    int item = 0;
    cout << "��ѡ����:\t1.��ʾ\t2.¼��\t3.����\t4.ɾ��\t5.����\t6.ͳ��\t7.����\t8.���\t9.�˳�" << endl;
    while(cin >> item && item != 9)
    {
        switch (item)
        {
            case 1:
            {
                lst.DispList();
                break;
            }
            case 2:
            {
                Student s;
                cout << "������¼��ѧ����Ϣ��ѧ�� ���� ����)" << endl;
                cin >> s.num >> s.name >> s.score;
                lst.ListInsert(lst.length,s);
                break;
            }
            case 3:
            {
                Student s;
                string nu;
                cout << "���������ѧ��ѧ��" << endl;
                cin >> nu;
                lst.GetElem(nu,s);
                cout << s << endl;
                break;
            }
            case 4:
            {
                Student s;
                int i;
                cout << "������ɾ��ѧ��λ��" << endl;
                cin >> i;
                lst.ListDelete(i,s);
                break;
            }
            case 5:
            {
                Student s;
                int i;
                cout << "���������ѧ����Ϣ��ѧ�� ���� ����)��λ��" << endl;
                cin >> s.num >> s.name >> s.score >> i;
                lst.SetElem(i,s);
                break;
            }
            case 6:
            {
                cout << "����ѧ������Ϊ��" << lst.length << endl;
                break;
            }
            case 7:
            {
                cout << "������ɣ�"<< endl;
                break;
            }
            case 8:
            {
                lst.~LinkList();
                break;
            }
            case 9:
                return;
            default:
                cout << "δ֪���ܣ�����������" << endl;
                break;
        }
        cout << "��ѡ����:\t1.��ʾ\t2.¼��\t3.����\t4.ɾ��\t5.����\t6.ͳ��\t7.����\t8.���\t9.�˳�" << endl;
    }
}



int main(){
    int flag = 0;
    shuchu:
    cout << "������ʵ�ֵ����ݽṹ��1.˳��� 2.������" << endl;
    cin >> flag;
    if(flag == 1){
        done_SqList();
    }
    else if(flag == 2){
         done_linklist();  }
    else{
        cout << "�Ƿ����룬����������" << endl;
        goto shuchu;
    }
    return 0;
}

