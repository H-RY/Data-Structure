//
// Created by Administrator on 2021/8/14.
//
//链栈
#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node * p_next;
}NODE, * PNODE;

typedef struct Stack{
    PNODE p_top;
    PNODE p_bottom;
}STACK, * PSTACK;

void init_stack(PSTACK p_s);//初始化栈
void push_stack(PSTACK p_s, int val);//将元素压入栈
bool pop_stack(PSTACK p_s, int *p_val);//出栈
void traverse_stack(PSTACK p_s);//遍历栈（从栈顶到栈底）
void clear(PSTACK p_s);//清空栈


int main(void){
    int val;
    STACK s; //STACK 等价于 struct Stack
    init_stack(&s);
    push_stack(&s, 1);
    push_stack(&s, 2);
    push_stack(&s, 3);
    push_stack(&s, 4);
    push_stack(&s, 5);
//    pop_stack(&s,&val);
//    traverse_stack(&s);
    clear(&s);
    traverse_stack(&s);

    return 0;
}

void init_stack(PSTACK p_s){
    p_s->p_top = new Node;
    if(NULL == p_s->p_top){
        cout<<"error"<<endl;
        exit(-1);
    } else{
        p_s->p_bottom = p_s->p_top;
        p_s->p_top->p_next = NULL;
    }
}

void push_stack(PSTACK p_s, int val){
    PNODE p_new = new Node;
    if(NULL == p_new){
        cout<<"error"<<endl;
        exit(-1);
    }
    p_new->data = val;
    p_new->p_next = p_s->p_top;
    p_s->p_top = p_new;
    return;
}

void traverse_stack(PSTACK p_s){
    PNODE p = p_s->p_top;

    while (p != p_s->p_bottom){
        cout<<p->data<<endl;
        p = p->p_next;
    }
    return;
}

bool empty(PSTACK p_s){
    if (p_s->p_top ==p_s->p_bottom)
        return true;
    else
        return false;
}

//把p_s所指向的栈出栈一次，并把出栈的元素存入P_val形参所指向的变量中，如果出栈失败返回false，否则返回true
bool pop_stack(PSTACK p_s, int *p_val){
    if (empty(p_s))
        return false;
    else{
        PNODE p = p_s->p_top;
        *p_val = p->data;
        p_s->p_top = p->p_next;
        free(p);
        p = NULL;
        return true;
    }
}

//清空栈
void clear(PSTACK p_s){
    if (empty(p_s))
        return;
    else{
        PNODE p = p_s->p_top;
        PNODE q = p->p_next;

        while (p != p_s->p_bottom){
            q = p->p_next;
            free(p);
            p = q;
        }
        p_s->p_top = p_s->p_bottom;
    }
}