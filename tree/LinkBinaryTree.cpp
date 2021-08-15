#include <iostream>
using namespace std;

typedef struct BTNode{
    char data;//数据域
    struct BTNode * p_lchild;//左指针域  p是指针  l是左  child是孩子
    struct BTNode * p_rchild;//右指针域
}BTNODE, * PBTNODE;

//函数声明
PBTNODE create_bi_tree();//创建一个静态二叉树
void pre_traverse_tree(PBTNODE p_t);//先序遍历
void in_traverse_tree(PBTNODE p_t);//中序遍历
void post_traverse_tree(PBTNODE p_t);//后序遍历

int main(){
    PBTNODE p_t = create_bi_tree();
//    pre_traverse_tree(p_t);
//    in_traverse_tree(p_t);
    post_traverse_tree(p_t);

    return 0;
}

//创建一个静态二叉树 先序遍历为ABCDE 中序遍历为BADEC  后序遍历为BEDCA
PBTNODE create_bi_tree(){
    PBTNODE pA = new BTNODE;
    PBTNODE pB = new BTNODE;
    PBTNODE pC = new BTNODE;
    PBTNODE pD = new BTNODE;
    PBTNODE pE = new BTNODE;

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    pA->p_lchild = pB;
    pA->p_rchild = pC;
    pB->p_lchild = pB->p_rchild = NULL;
    pC->p_lchild = pD;
    pC->p_rchild = NULL;
    pD->p_lchild = NULL;
    pD->p_rchild = pE;
    pE->p_lchild = pE->p_rchild = NULL;

    return pA;
}

//先序遍历 先序访问根 再先序访问左子树 再先序访问右子树
void pre_traverse_tree(PBTNODE p_t){
    //孩子节点可能存在空节点 所以要加if
    if (NULL != p_t){
        cout<<p_t->data<<endl;
        //p_t->p_lchild可以代表整个左子树
        if(NULL != p_t->p_lchild){
            pre_traverse_tree(p_t->p_lchild);
        }
        if(NULL != p_t->p_rchild){
            pre_traverse_tree(p_t->p_rchild);
        }
    }
}

void in_traverse_tree(PBTNODE p_t){
    if (NULL != p_t){
        if(NULL != p_t->p_lchild){
            in_traverse_tree(p_t->p_lchild);
        }
        cout<<p_t->data<<endl;
        if(NULL != p_t->p_rchild){
            in_traverse_tree(p_t->p_rchild);
        }
    }
}

void post_traverse_tree(PBTNODE p_t){
    if (NULL != p_t){
        if(NULL != p_t->p_lchild){
            post_traverse_tree(p_t->p_lchild);
        }
        if(NULL != p_t->p_rchild){
            post_traverse_tree(p_t->p_rchild);
        }
        cout<<p_t->data<<endl;
    }
}