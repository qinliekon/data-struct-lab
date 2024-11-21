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
    cout << "请选择功能:\t1.显示\t2.录入\t3.查找\t4.删除\t5.更新\t6.统计\t7.排序\t8.清空\t9.退出" << endl;
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
            cout << "请输入录入学生信息（学号 姓名 绩点)" << endl;
            cin >> s.num >> s.name >> s.score;
            lst.ListInsert(lst.length,s);
            break;
         }
         case 3:
         {
            Student s;
            string nu;
            cout << "请输入查找学生学号" << endl;
            cin >> nu;
            lst.GetElem(nu,s);
            cout << s << endl;
            break;
        }
        case 4:
        {
            Student s;
            int i;
            cout << "请输入删除学生位置" << endl;
            cin >> i;
            lst.ListDelete(i,s);
            break;
        }
        case 5:
        {
            Student s;
            int i;
            cout << "请输入更新学生信息（学号 姓名 绩点)和位置" << endl;
            cin >> s.num >> s.name >> s.score >> i;
            lst.SetElem(i,s);
            break;
        }
        case 6:
        {
            cout << "表中学生数量为：" << lst.length << endl;
            break;
        }
        case 7:
        {
            sort(lst.data,lst.data + lst.length, cmp_stu);
            cout << "排序完成" << endl;
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
            cout << "未知功能，请重新输入" << endl;
            break;
        }
    cout << "请选择功能:\t1.显示\t2.录入\t3.查找\t4.删除\t5.更新\t6.统计\t7.排序\t8.清空\t9.退出" << endl;
    }
}

void done_linklist(){
    LinkList<Student> lst;
    int item = 0;
    cout << "请选择功能:\t1.显示\t2.录入\t3.查找\t4.删除\t5.更新\t6.统计\t7.排序\t8.清空\t9.退出" << endl;
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
                cout << "请输入录入学生信息（学号 姓名 绩点)" << endl;
                cin >> s.num >> s.name >> s.score;
                lst.ListInsert(lst.length,s);
                break;
            }
            case 3:
            {
                Student s;
                string nu;
                cout << "请输入查找学生学号" << endl;
                cin >> nu;
                lst.GetElem(nu,s);
                cout << s << endl;
                break;
            }
            case 4:
            {
                Student s;
                int i;
                cout << "请输入删除学生位置" << endl;
                cin >> i;
                lst.ListDelete(i,s);
                break;
            }
            case 5:
            {
                Student s;
                int i;
                cout << "请输入更新学生信息（学号 姓名 绩点)和位置" << endl;
                cin >> s.num >> s.name >> s.score >> i;
                lst.SetElem(i,s);
                break;
            }
            case 6:
            {
                cout << "表中学生数量为：" << lst.length << endl;
                break;
            }
            case 7:
            {
                cout << "排序完成！"<< endl;
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
                cout << "未知功能，请重新输入" << endl;
                break;
        }
        cout << "请选择功能:\t1.显示\t2.录入\t3.查找\t4.删除\t5.更新\t6.统计\t7.排序\t8.清空\t9.退出" << endl;
    }
}



int main(){
    int flag = 0;
    shuchu:
    cout << "请输入实现的数据结构（1.顺序表 2.单链表）" << endl;
    cin >> flag;
    if(flag == 1){
        done_SqList();
    }
    else if(flag == 2){
         done_linklist();  }
    else{
        cout << "非法输入，请重新输入" << endl;
        goto shuchu;
    }
    return 0;
}

