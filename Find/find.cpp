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
TABLE * create_list();//手动创建线性表(1开头)
TABLE * auto_create_list();//自动创建线性表(0开头)
int order_search_val1(TABLE * t, int key);//顺序查找(有哨兵，从1开始)
int order_search_val2(TABLE * t, int key);//顺序查找(无哨兵，从0开始)
int binary_search(TABLE * t, int key);//二分查找
void hash_list(int * key);//哈希函数(还没写)

int main(){
    TABLE * t = NULL;
    int temp = 1;

//    t = create_list();
    t = auto_create_list();
//    cout<<t->len;
//    while(t->data[temp] != NULL){
//        cout<<t->data[temp]<<endl;
//        temp++;
//    }
    cout<<binary_search(t, 13);
//    cout<<order_search_val2(t, 13)<<endl;
//    cout<<order_search_val1(t, 13)<<endl;

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

TABLE * auto_create_list(){
    TABLE * t = new TABLE;
    int val[max_size] = {7,10,13,16,19,29,32,33,37,41,43,NULL};
    int i = 0;
    while(val[i] != NULL){
        t->data[i] = val[i];
        i++;
    }
    t->len = i + 1;
    return t;
}

int order_search_val1(TABLE * t, int key){
    t->data[0] = key;
    int i;
    for(i = t->len; t->data[i] != key; i--);
    return i;
}

int order_search_val2(TABLE * t, int key){
    for(int i = 0; i < t->len; i++){
        if(t->data[i] == key)
            return i + 1;
    }
    return -1;
}

int binary_search(TABLE * t, int key){
    int left = 0, right = t->len - 2;//因为数组最后一个元素赋值了NULL
    int mid;
    while(left <= right){
        mid = left + (right - left) >> 1;
        if(t->data[mid] == key)
            return mid;
        else if(t->data[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
