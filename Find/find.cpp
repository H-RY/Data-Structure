//
// Created by Administrator on 2021/8/19.
//

#include "iostream"
using namespace std;

#define max_size 50

typedef struct {
    int data[max_size];
    int len;
}TABLE;

//函数列表
TABLE * create_list();//创建线性表
int order_search_val(TABLE * t, int key);//顺序查找

int main(){
    TABLE * t = NULL;
    int temp = 1;

    t = create_list();
//    cout<<t->len;
//    while(t->data[temp] != NULL){
//        cout<<t->data[temp]<<endl;
//        temp++;
//    }
    cout<<order_search_val(t, 3);
    return 0;
}

TABLE * create_list(){
    TABLE * t = new TABLE;
    int i = 1, val;

    cout<<"Please input the point of value: ";
    cin>>val;
    while(val != 9999){
        t->data[i] = val;
        i++;
        cout<<"Please input the point of value: ";
        cin>>val;
    }
    t->len = i - 1;
    t->data[i] = NULL;
    return t;
}

int order_search_val(TABLE * t, int key){
    t->data[0] = key;
    int i;
    for(i = t->len; t->data[i] != key; i--);
    return i;
}