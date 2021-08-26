//
// Created by Eternal on 2021/8/26.
//

#include "iostream"
using namespace std;
#define max_size 10

//函数列表
//
void traverse_array(int temp[]);//打印
void direct_insert_sort(int temp[], int n);//直接插入排序(有哨兵)
void half_insert_sort(int temp[], int n);//折半插入排序
void shell_sort(int temp[],int n);//希尔排序

int main(){
    int temp[max_size] = {NULL,49,38,65,97,76,13,27,49,1};
//    direct_insert_sort(temp, 9);
    half_insert_sort(temp, 9);
    traverse_array(temp);
    return 0;
}

void traverse_array(int temp[]){
    for(int i = 1; i < max_size; i++){
        cout<<temp[i]<<endl;
    }
}

void direct_insert_sort(int temp[], int n){
    int i, j;
    for(i = 2; i <= n; i++){
        if(temp[i] < temp[i - 1]){
            temp[0] = temp[i];
            for(j = i - 1; temp[0] < temp[j]; --j){
                temp[j + 1] = temp[j];
            }
            temp[j + 1] = temp[0];
        }
    }
}

void half_insert_sort(int temp[], int n){
    int i, j, low, high, mid;
    for(i = 2; i <= n; i++){
        temp[0] = temp[i];
        low = 1, high = i - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(temp[mid] > temp[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(j = i - 1; j >= high + 1; --j){
            temp[j + 1] = temp[j];
        }
        temp[high + 1] = temp[0];
    }
}

void shell_sort(int temp[],int n){

}