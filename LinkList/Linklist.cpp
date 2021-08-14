//
// Created by Administrator on 2021/8/14.
//

#include <iostream>
using namespace std;

typedef struct Node{
    int data; //数据域
    struct Node * p_next; //指针域
}NODE, *PNODE; //NODE等价于struct Node   PNODE等价于struct Node *

//函数声明
PNODE create_list();//创建非循环单链表
void traverse_list(PNODE p_head);//遍历
bool is_empty1(PNODE p_head);//判空
int length_list(PNODE p_head);//长度
bool insert_list(PNODE p_head, int pos, int val);//插入
bool delete_list(PNODE p_head, int pos, int * val);//删除
void sort_list(PNODE p_head);//排序

int main(void){
    PNODE p_head = NULL;
    p_head = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋值给 p_head
//    traverse_list(p_head);

    return 0;
}

PNODE create_list(){
    int len;//用来存放有效节点的个数
    int val;//用来临时存放用户输入节点的值

    //分配了一个不存放有效数据的头结点
    PNODE p_head = new NODE;
    p_head->p_next = NULL;
    if(NULL == p_head){
        cout<<"error"<<endl;
        exit(-1);
    }

    cout<<"len = ";
    cin>>len;

    for(int i = 0; i<len; i++){
        cout<<"input the value of point: ";
        cin>>val;

        PNODE p_new = new NODE;
        if(NULL == p_new){
            cout<<"error"<<endl;
            exit(-1);
        }
        p_new->data = val;
        p_new->p_next = p_head->p_next;
        p_head->p_next = p_new;
    }
    return p_head;
}

void traverse_list(PNODE p_head){
    PNODE p = p_head->p_next;
    while(NULL != p){
        cout<<p->data<<endl;
        p = p->p_next;
    }
}

bool is_empty1(PNODE p_head){
    if (NULL == p_head->p_next)
        return true;
    else
        return false;
}

int length_list(PNODE p_head){
    PNODE p = p_head->p_next;
    int length = 0;
    while (NULL != p){
        length++;
        p = p->p_next;
    }
    return length;
}

void sort_list(PNODE p_head){

}