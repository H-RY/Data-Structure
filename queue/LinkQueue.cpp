//
// Created by heyu on 2021/8/16.
//
//链式队列

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * p_next;
}NODE, * PNODE;

typedef struct LQueue{
    PNODE front; //队头指针
    PNODE rear; //队尾指针
}LQUEUE, * PLQUEUE;

//函数列表
void init_queue(PLQUEUE p_q);//初始化
bool is_empty1(PLQUEUE p_q);//判空
void enter_queue(PLQUEUE p_q, int val);//入队
bool out_queue(PLQUEUE p_q, int * p_val);//出队
bool traverse_queue(PLQUEUE p_q);//打印队列

int main(){
    PLQUEUE p_q = new LQUEUE;
    int val;

    init_queue(p_q);
    enter_queue(p_q,1);
    enter_queue(p_q,2);
    enter_queue(p_q,3);
    enter_queue(p_q,4);
    enter_queue(p_q,5);
    out_queue(p_q,&val);
    traverse_queue(p_q);
    return 0;
}

void init_queue(PLQUEUE p_q){
    p_q->front = new NODE; //类似于头结点
    p_q->rear = new NODE;//类似于尾结点
    p_q->rear = p_q->front;//切记要让头尾结点指向头结点
    p_q->front->p_next = NULL;
}

bool is_empty1(PLQUEUE p_q){
    if (p_q->front == p_q->rear)
        return true;
    else
        return false;
}

//入队
void enter_queue(PLQUEUE p_q, int val){
    PNODE p_new = new NODE;

    p_new->data = val;
    p_new->p_next = NULL;
    p_q->rear->p_next = p_new;
    p_q->rear = p_new;
}

//出队
bool out_queue(PLQUEUE p_q, int * p_val){
    if (is_empty1(p_q))
        return false;
    else{
        PNODE p_new = new NODE;
        p_new = p_q->front->p_next;
        * p_val = p_new->data;
        p_q->front->p_next = p_new->p_next;
        if(p_q->rear == p_new) //若队列中只有一个结点，删除后变空
            p_q->front = p_q->rear;
        free(p_new);
    }
    return true;
}

bool traverse_queue(PLQUEUE p_q){
    if (is_empty1(p_q))
        return false;
    else{
        PNODE p = new NODE;
        p = p_q->front->p_next;
        while(p != p_q->rear->p_next){
            cout<<p->data<<endl;
            p = p->p_next;
        }
    }
    return true;
}