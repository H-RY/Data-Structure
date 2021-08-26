//
// Created by Eternal on 2021/8/26.
//
#include "iostream"
using namespace std;
#define max_size 10

//函数列表
void traverse_array(int temp[]);//打印
void select_sort(int temp[], int n);//简单选择排序
void build_max_heap(int temp[], int len);//建立大根堆
void head_adjust(int temp[], int k, int len);//将元素 k 为根的子树进行调整
void heap_sort(int temp[], int len);//堆排序

int main(){
    int temp[max_size] = {0,49,38,65,97,76,13,27,49,1};
//    select_sort(temp, 10);
    heap_sort(temp, 9);
    traverse_array(temp);
    return 0;
}

void traverse_array(int temp[]){
    for(int i = 1; i < max_size; i++){
        cout<<temp[i]<<endl;
    }
}

void select_sort(int temp[], int n){
    int i, j, min;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(temp[j] < temp[min]){
                min = j;
            }
        }
        if(min != i){
            swap(temp[i], temp[min]);
        }
    }
}

void build_max_heap(int temp[], int len){
    for(int i = len / 2; i > 0; i--)
        head_adjust(temp,i,len);
}

void head_adjust(int temp[], int k, int len){
    int i;
    temp[0] = temp[k];
    for(i = 2 * k; i <= len; i *= 2){
        if(i < len && temp[i] < temp[i + 1])
            i++;
        if(temp[0] >= temp[i])
            break;
        else{
            temp[k] = temp[i];
            k = i;
        }
    }
    temp[k] = temp[0];
}

void heap_sort(int temp[], int len){
    build_max_heap(temp,len);
    for(int i = len; i > 1; i--){
        swap(temp[i], temp[1]);
        head_adjust(temp,1,i - 1);
    }
}