//
// Created by liekon on 2024/9/25.
//

#ifndef STUNDENT_SQLIST_H
#define STUNDENT_SQLIST_H

#include <cstring>
#include <iostream>
#define MAXSIZE 100

template <typename T>
class SqList {
// 顺序表的数据成员
public:
    int length; // 顺序表的当前长度
    T *data; // 元素存储空间的首地址
public:
// 顺序表的函数成员
    SqList(){
        data = new T[MAXSIZE];
        length = 0;
    } // 构造一个空表

    ~SqList(){
        delete[] data;
    }// 析构函数

    void CreateList(T v[], int n); // 根据数组 v 的内容构造顺序表
    int ListLength() ; // 取顺序表长度
    int LocateElem(T e) ; // 元素定位，求指定元素在顺序表中的位置
    bool GetElem(std::string s, T &e) ; // 取顺序表中第 i 个元素的值
    bool SetElem(int i, const T &e); // 修改顺序表中第 i 个元素的值
    bool ListDelete(int i, T &e); // 删除顺序表中第 i 个元素
    bool ListInsert(int i, T e); // 在顺序表第 i 个位置插入元素
    void DispList();
};


template <typename T>
void SqList<T>::CreateList(T v[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = v[i];
    }
    length = n;
}

template <typename T>
int SqList<T>::ListLength(){
    return length;
}

template <typename T>
int SqList<T>::LocateElem(T e){
    int i;
    for(i = 0;i < length;i++)
        if(data[i] == e)
            break;
    if(i == length){
        return -1;
    }
    else {
        return i;
    }
}

template <typename T>
bool SqList<T>::GetElem(std::string s, T &e){
    int i = 0;
    for(i;i<length;i++){
        if(data[i].num == s){
            e = data[i];
            return true;
        }
    }
    return false;
}

template <typename T>
bool SqList<T>::SetElem(int i, const T &e){
    if(i < length){
        data[i] = e;
        return true;
    }
    else
        return false;
}

template <typename T>
bool SqList<T>::ListDelete(int i, T &e){
    if (i >= 0 && i < length) {
        e = data[i];
        for (int j = i; j < length - 1; j++) {
            data[j] = data[j + 1];
        }
        length--;
        return true;
    }
    return false;
}

template <typename T>
bool SqList<T>::ListInsert(int i, T e){
    int d = length;
    for(;d > i;d--){
        data[d] = data[d-1];
    }
    data[i] = e;
    length++;
    return true;
}

template <typename T>
void SqList<T>::DispList(){
    int i = 0;
    while(i < length){
        std::cout << data[i] << std::endl;
        i++;
    }
}


#endif //STUNDENT_SQLIST_H