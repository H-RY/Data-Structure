//
// Created by heyu on 2021/8/19.
//

#include <iostream>
using namespace std;

#define MaxSize 50

typedef struct Node{
    int data[MaxSize];
    int top;
} NODE, * PNODE;

//函数列表
void init_stack(PNODE s);//初始化
bool is_empty_stack(PNODE s);//判栈空
bool is_full(PNODE s);//判栈满
bool push(PNODE s, int val);//压栈
bool pop(PNODE s, int * val);//出栈
bool traverse_stack(PNODE s);//遍历栈
bool get_pop(PNODE s, int * val);//读取栈顶元素


int main(){
    PNODE s = new Node;
    int val;

    init_stack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    pop(s, &val);
    get_pop(s, &val);
    cout<<val;
//    traverse_stack(s);
//    cout<<val<<endl;
    return 0;
}

void init_stack(PNODE s){
    s->top = -1;
}

bool is_empty_stack(PNODE s){
    if(s->top == -1)
        return true;
    else
        return false;
}

bool is_full(PNODE s){
    if(s->top == MaxSize-1)
        return true;
    else
        return false;
}

bool push(PNODE s, int val){
    if(is_full(s))
        return false;
    else{
        s->data[++s->top] = val;//指针先加 1 再入栈
        return true;
    }
}

bool traverse_stack(PNODE s){
    if(is_empty_stack(s))
        return false;
    else{
        while(s->top != -1){
            cout<<s->data[s->top--]<<endl;
        }
        return true;
    }
}

bool pop(PNODE s, int * val){
    if(is_empty_stack(s))
        return false;
    else{
        * val = s->data[s->top--];
        return true;
    }
}

bool get_pop(PNODE s, int * val){
    if(is_empty_stack(s))
        return false;
    else{
        * val = s->data[s->top];
        return true;
    }
}