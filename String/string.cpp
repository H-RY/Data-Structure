//
// Created by Administrator on 2021/8/21.
//

#include "iostream"
using namespace std;

#define max_size 13

typedef struct {
    char ch[max_size];
    int length;
}SS;

//函数列表
void init_str(SS * s);//创建一个串
bool traverse_str(SS * s);//遍历该串
bool is_empty1(SS * s);//判空
int str_length(SS * s);//求串长
SS * sub_str(SS * sub, SS * s, int pos, int len);//求子串
bool str_compare(SS * sub, SS * s);//比较
int index(SS * s, SS * sub);//求子串在主串中的位置

int main(){
    SS * s = new SS;
    SS * sub = new SS;
    init_str(s);
    sub_str(sub,s, 3,5);
    traverse_str(sub);
    cout<<index(s,sub);
//    traverse_str(s);
//    cout<<endl;
//    cout<<sub->length;
    return 0;
}

void init_str(SS * s){
    string a = "ababcabcacbab";
    char ch = a[0];
    int i = 0;
    s->length = 0;
    for(;i < max_size; i++){
        s->ch[i] = ch;
        ch = a[i + 1];
        s->length++;
    }
}

bool is_empty1(SS * s){
    if(s->length == 0)
        return true;
    else
        return false;
}

bool traverse_str(SS * s){
    if(is_empty1(s))
        return false;
    else{
        for(int i = 0;i < s->length; i++){
            cout<< s->ch[i];
        }
        return 0;
    }
}

int str_length(SS * s){
    return s->length;
}

SS * sub_str(SS * sub, SS * s, int pos, int len){
    sub->length = 0;
    for(int i = 0; i < len; i++){
        sub->ch[i] = s->ch[pos-1];
        pos++;
        sub->length++;
    }
    return sub;
}

bool str_compare(SS * sub, SS * s){
    int i = 0;
    int j = 0;
    while(i != s->length){
        if (s->ch[j] != sub->ch[i])
            return -1;
        else{
            i++;
            j++;
        }
    }
    return 0;
}

int index(SS * s, SS * t){
    SS * sub = new SS;
    int i = 1, n = s->length, m = t->length;
    while(i <= n - m + 1){
        sub_str(sub,s,i,m);
        if(str_compare(sub,t) != 0) ++i;
        else return i;
    }
    return 0;
}