//
// Created by liekon on 2024/9/25.
//
#include "SqList.h"
#define MAXSIZE 100

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
bool SqList<T>::GetElem(int i, T &e){
    if(i < length){
        e = data[i];
        return true;
    }
    else
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
    for(;i < length;i++){
        data[i] = data[i+1];
    }
    data[i] = NULL;
    length--;
    return true;
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
    whlie(i < length){
        cout<< data[i] << endl;
    }
}