//
// Created by Eternal on 2021/8/26.
//
#include "iostream"
using namespace std;
#define max_size 10

//函数列表
void traverse_array(int temp[]);//打印
void bubble_sort(int temp[], int n);//冒泡排序
void quick_sort(int temp[], int low, int high);//快速排序

int main(){
    int temp[max_size] = {49,38,65,97,76,13,27,49,1};//序号从1开始
    bubble_sort(temp, 9);
    traverse_array(temp);
    return 0;
}

void traverse_array(int temp[]){
    for(int i = 1; i < max_size; i++){
        cout<<temp[i]<<endl;
    }
}

void bubble_sort(int temp[], int n){
    int i, j;
    bool flag;
    for(i = 0; i < n; i++){
        flag = false;
        for(j = n - 1; j > i; j--){
            if(temp[j - 1] > temp[j]){
                swap(temp[j - 1], temp[j]);
                flag = true;
            }
        }
        if(flag == false){
            return;
        }
    }
}