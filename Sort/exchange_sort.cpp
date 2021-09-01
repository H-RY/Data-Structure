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
int partition(int temp[], int low, int high);//一趟划分

int main(){
    int temp[max_size] = {49,38,65,97,76,13,27,49,1};//序号从1开始
//    bubble_sort(temp, 9);
    partition(temp, 0, 8);
    quick_sort(temp, 0,8);
    traverse_array(temp);
    return 0;
}

void traverse_array(int temp[]){
    for(int i = 0; i < max_size - 1; i++){
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

int partition(int temp[], int low, int high){
    int pivot = temp[low];
    while(low < high){
        while(low < high && temp[high] >= pivot)
            high--;
        temp[low] = temp[high];
        while(low < high && temp[low] <= pivot)
            low++;
        temp[high] = temp[low];
    }
    temp[low] = pivot;
    return low;
}

void quick_sort(int temp[], int low, int high){
    if(low < high){
        //partition()是划分操作，将表 temp[low] 到  temp[high] 划分为满足上述条件的两个子表
        int pivotpos = partition(temp, low, high);
        quick_sort(temp, low, pivotpos - 1);
        quick_sort(temp, pivotpos + 1, high);
    }
}

