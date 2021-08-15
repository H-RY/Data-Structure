//
// Created by Administrator on 2021/8/14.
//
//循环队列
#include <iostream>
using namespace std;

typedef struct Queue{
    int * p_base;
    int front;
    int rear;
}QUEUE;

//函数列表
void init_queue(QUEUE * p_q);//初始化
bool en_queue(QUEUE * p_q, int val, int len);//入队
bool out_queue(QUEUE * p_q,int *p_val,int len);//出队
void traverse_queue(QUEUE * p_q, int len);//遍历该循环队列
bool empty_queue(QUEUE * p_q);//判空
bool full_queue(QUEUE * p_q, int len);//判满

int main(void){
    int len = 6;//定义队列长度
    int val;//记录出队元素值
    QUEUE q;

    init_queue(&q);
    en_queue(&q,1,len);
    en_queue(&q,2,len);
    en_queue(&q,3,len);
    en_queue(&q,4,len);
    out_queue(&q, &val, len);
    traverse_queue(&q,len);

    return 0;
}

void init_queue(QUEUE * p_q){
    p_q->p_base = new int;
    p_q->front = 0;//队头
    p_q->rear = 0;//队尾
}

bool full_queue(QUEUE * p_q, int len){
    if((p_q->rear + 1) % len == p_q->front)
        return true;
    else
        return false;
}

bool en_queue(QUEUE * p_q, int val, int len){
    if(full_queue(p_q,len)){
        return false;
    } else{
        p_q->p_base[p_q->rear] = val;
        p_q->rear = (p_q->rear+1) % len;
        return true;
    }
}

void traverse_queue(QUEUE * p_q, int len){
    int i = p_q->front;
    while (i != p_q->rear){
        cout<<p_q->p_base[i]<<endl;
        i = (i + 1) % len;
    }
    return;
}

bool empty_queue(QUEUE * p_q){
    if(p_q->rear == p_q->front)
        return true;
    else
        return false;
}

bool out_queue(QUEUE * p_q,int *p_val,int len){
    if(empty_queue(p_q))
        return false;
    else{
        *p_val = p_q->p_base[p_q->front];
        p_q->front = (p_q->front + 1) % len;
    }
}