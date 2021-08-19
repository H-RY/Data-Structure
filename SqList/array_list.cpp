//
// Created by Administrator on 2021/8/14.
//
#include <iostream>
using namespace std;

typedef struct Arr{
    int * p_base; //存储的是数组第一个元素的地址
    int len; //数组所能容纳的最大元素的个数
    int cnt; //当前数组有效元素的个数
}ARR;


void init_arr(ARR * p_arr,int length);
bool append_arr(ARR *p_arr, int val); //追加
bool insert_arr(ARR *p_arr, int pos, int val); //pos的值从1开始(放在pos前面)
bool delete_arr(ARR *p_arr, int pos, int * p_val);
bool get(ARR *p_arr, int pos); //查找
bool is_empty1(ARR *p_arr);//判空
bool is_full(ARR *p_arr);//判满
void sort_arr(ARR *p_arr); //这里写冒泡
void show_arr(ARR *p_arr); //打印
void inversion_arr(ARR *p_arr); //倒置


int main(void){

    ARR arr;
    int val;

    init_arr(&arr,6);
    show_arr(&arr);
    append_arr(&arr,1);
    append_arr(&arr,2);
    append_arr(&arr,3);
    append_arr(&arr,4);
    append_arr(&arr,5);
    get(&arr,3);
//    inversion_arr(&arr);
//    show_arr(&arr);
//    sort_arr(&arr);
//    insert_arr(&arr,6,99);
//    append_arr(&arr,6);
//    append_arr(&arr,7);
//    show_arr(&arr);

    return 0;
}

void init_arr(ARR * p_arr,int length){
    p_arr->p_base = new int;
    if (NULL == p_arr->p_base){
        cout<<"error"<<endl;
        exit(-1);//终止整个程序
    } else{
        p_arr->len = length;
        p_arr->cnt = 0;

    }
    return;
}

bool is_empty1(ARR *p_arr){
    if (0 == p_arr->cnt)
        return true;
    else
        return false;
}

void show_arr(ARR *p_arr){
    if ( is_empty1(p_arr) )
        cout << "Array is empty" << endl;
    else{
        for (int i = 0; i < p_arr->cnt; i++){
            cout << p_arr->p_base[i] <<endl;
        }
    }
}

bool is_full(ARR *p_arr){
    if (p_arr->cnt == p_arr->len)
        return true;
    else
        return false;
}

bool append_arr(ARR *p_arr, int val){
    //满时返回false
    if ( is_full(p_arr) )
        return false;
    //不满时追加
    p_arr->p_base[p_arr->cnt] = val;
    (p_arr->cnt)++;
    return true;
}

bool insert_arr(ARR *p_arr, int pos, int val){
    if (pos < 1||pos > p_arr->cnt + 1)
        return false;
    for (int i = p_arr->cnt-1; i >= (pos - 1); i--){
        p_arr->p_base[i+1] = p_arr->p_base[i];
    }
    p_arr->p_base[pos-1] = val;
    p_arr->cnt++;
    return true;
}

bool delete_arr(ARR *p_arr, int pos, int * p_val){
    if (is_empty1(p_arr))
        return false;
    if (pos<1 || pos>p_arr->cnt)
        return false;
    *p_val = p_arr->p_base[pos];
    for (int i = pos-1; i<=p_arr->cnt-pos; i++){
        p_arr->p_base[i] = p_arr->p_base[i+1];
    }
    p_arr->cnt--;
    return true;
}

void inversion_arr(ARR *p_arr){
    int i = 0;
    int j = p_arr->cnt - 1;
    int t;

    while (i<j){
        t = p_arr->p_base[i];
        p_arr->p_base[i] = p_arr->p_base[j];
        p_arr->p_base[j] = t;
        i++;
        j--;
    }
}

void sort_arr(ARR *p_arr){
    int i,j,t;
    for (i = 0; i<p_arr->cnt; i++){
        for (j= i + 1; j<p_arr->cnt; j++){
            if (p_arr->p_base[i] > p_arr->p_base[j]){
                t = p_arr->p_base[i];
                p_arr->p_base[i] = p_arr->p_base[j];
                p_arr->p_base[j] = t;
            }
        }
    }
}

bool get(ARR *p_arr, int pos){
    if (is_empty1(p_arr))
        return false;
    if (pos<1 || pos>p_arr->cnt)
        return false;
    cout<<p_arr->p_base[pos-1]<<endl;
}