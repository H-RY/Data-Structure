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
bool delete_list(PNODE p_head, int pos, int * p_val);//删除
void sort_list(PNODE p_head);//排序

int main(void){
    PNODE p_head = NULL;
    int val;//保存欲删除节点的数据
    p_head = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋值给 p_head
//    length_list(p_head);
//    sort_list(p_head);
//    insert_list(p_head,6,99);
//    delete_list(p_head,1,&val);
    traverse_list(p_head);
    return 0;
}

//尾插法建立单链表
PNODE create_list(){
    int val;
    PNODE p_head = new NODE;//头结点
    PNODE r = new NODE;//尾指针
    r = p_head;//让尾指针指向当前最后一个结点 目前单链表为空 所以尾指针指向头结点
    cout<<"(when you input '9999', the linklist created.)"<<endl;
    cout<<"Please input the point of value: ";
    cin>>val;
    while(val != 9999){
        PNODE p_new = new NODE;
        p_new->data = val;
        r->p_next = p_new;
        r = p_new;
        cout<<"Please input the point of value: ";
        cin>>val;
    }
    r->p_next = NULL;
    return p_head;
}


////另一种头插法建立单链表
//PNODE create_list(){
//    int val;
//    PNODE p_head = new NODE;//创建头结点
//    p_head->p_next = NULL;
//    if(NULL == p_head){
//        cout<<"error"<<endl;
//        exit(-1);
//    }
//    cout<<"(when you input '9999', the linklist created.)"<<endl;
//    cout<<"Please input the point of value: ";
//    cin>>val;
//    while(val != 9999){
//        PNODE p_new = new NODE;
//        p_new->data = val;
//        p_new->p_next = p_head->p_next;
//        p_head->p_next = p_new;
//        cout<<"Please input the point of value: ";
//        cin>>val;
//    }
//    return p_head;
//}


////头插法建立单链表
//PNODE create_list(){
//    int len;//用来存放有效节点的个数
//    int val;//用来临时存放用户输入节点的值
//
//    //分配了一个不存放有效数据的头结点
//    PNODE p_head = new NODE;
//    p_head->p_next = NULL;
//    if(NULL == p_head){
//        cout<<"error"<<endl;
//        exit(-1);
//    }
//
//    cout<<"len = ";
//    cin>>len;
//
//    for(int i = 0; i<len; i++){
//        cout<<"input the value of point: ";
//        cin>>val;
//
//        PNODE p_new = new NODE;
//        if(NULL == p_new){
//            cout<<"error"<<endl;
//            exit(-1);
//        }
//        p_new->data = val;
//        p_new->p_next = p_head->p_next;
//        p_head->p_next = p_new;
//    }
//    return p_head;
//}

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

//排序（运用了泛型的思想）
void sort_list(PNODE p_head){
    int i,j,t;
    PNODE p, q;

    for(i = 0, p = p_head->p_next; i< length_list(p_head)-1; i++, p = p->p_next){
        for(j = i + 1,q = p->p_next;j< length_list(p_head);j++,q = q->p_next){
            if(p->data > q->data){ //类似于数组中的：a[i] > a[j]
                t = p->data; //类似于数组中的：t = a[i]
                p->data = q->data;//类似于数组中的：a[i] = a[j]
                q->data = t;//类似于数组中的：a[j] = t
            }
        }
    }
}

//在p_head所指向链表的第pos个节点的前面插入一个新的结点，该节点的值是val，且pos的值从1开始
bool insert_list(PNODE p_head, int pos, int val){
    int i;
    PNODE p = p_head;
    for (i = 0; i<pos-1&&NULL != p;i++){
        p = p->p_next;
    }
    if (i>pos-1 || NULL == p)
        return false;

    PNODE p_new = new Node;
    if (NULL == p_new){
        cout<<"error"<<endl;
        exit(-1);
    }
    p_new->data = val;
    p_new->p_next = p->p_next;
    p->p_next = p_new;
    return true;
}
//删除p_head所指向链表的第pos个节点，该节点的值是val，且pos的值从1开始
//看懂删除和插入的关键是删除时默认头结点不可删除
//插入时默认插在当前p所指的节点的后面（可插在头结点后）
bool delete_list(PNODE p_head, int pos, int * p_val){
    int i;
    PNODE p = p_head;
    for (i = 0; i<pos-1&&NULL != p->p_next;i++){
        p = p->p_next;
    }
    if (i>pos-1 || NULL == p->p_next)
        return false;
    PNODE q = p->p_next;
    *p_val = q->data;
    p->p_next = p->p_next->p_next;
    free(q);
    return true;
}