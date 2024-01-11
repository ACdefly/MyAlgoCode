/*
* @Author: wlun
* @Date:   2024-01-11 12:12:06
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-11 14:13:55
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef int E;

typedef struct ListNode
{
    E val;
    struct ListNode *next;
}ListNode;

typedef struct LinkList
{
    // head存的是表头结点, 不用作计算链表的长度, 位置为 -1
    // 好处: 方便删除我们创建的链表的头结点
    ListNode *head;
    int length; // 链表的长度范围[0, length)
}LinkList;

// 初始化结点
ListNode *init_ListNode(E _val)
{
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = _val;
    p->next = nullptr;
    return p;
}

// 初始化链表
LinkList *init_LinkList()
{
    LinkList *l = (LinkList*)malloc(sizeof(LinkList));
    l->head = init_ListNode(-1);
    l->head->next = nullptr;
    l->length = 0;
    return l;
}

// 删除结点
void clear_ListNode(ListNode *p)
{
    if(p != nullptr)
    {
        free(p);
        p = nullptr;
    }
}

// 删除链表
void clear_LinkList(LinkList *l)
{
    if(l == nullptr) return;
    ListNode *p = l->head;
    ListNode *q = p;
    while(p) {
        q = p->next;
        clear_ListNode(p);
        p = q;
    }
    free(l);
    l = nullptr;
}

void output(LinkList *l)
{
    printf("LinkList length = %d\n", l->length);
    if(l->length == 0) return;
    ListNode *p = l->head;
    while(p) {
        printf("%3d ->", p->val);
        p = p->next;
    }
    printf(" nullptr\n");
}
/*
* 在index位置插入 ListNode(_val)
* 插入范围[0, l->length] 0为头结点
*/
int insert(LinkList *l, int index, E _val)
{
    if(l == nullptr) return 0;
    if(index < 0 || index > l->length) return 0;
    ListNode *p = l->head;
    ListNode *node = init_ListNode(_val);
    for(int i = 0; i < index; i++) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

/*
* 删除index的结点
* 删除范围[0, l->length)
*/
int del(LinkList *l, int index)
{
    if(l == nullptr) return 0;
    if(index < 0 || index >= l->length) return 0;
    ListNode *p = l->head;
    for(int i = 0; i < index; i++) p = p->next;
    ListNode *node = p->next;
    p->next = p->next->next;
    clear_ListNode(node);
    l->length -= 1;
    return 1;
}


int main()
{
    srand(time(nullptr));
    LinkList *l = init_LinkList();
    for(int i = 0; i < 30; i++) {
        printf("%d\n", i);
        int op = rand() % 3; // 随机数范围[0, 2)
        int index = rand() % (l->length + 1);
        int val = rand() % 100;
        switch(op) {
            // 这里理论上保证 插入点 的个数为 删除点 的个数的2倍
            case 0:
            case 1: {
                printf("insert %d at %d to LinkList = %d\n", val, index, insert(l, index, val));
            } break;
            case 2: {
                printf("del val at %d from LinkList = %d \n", index, del(l, index));
            } break;
        default: break;
        }
        output(l);
    }
    clear_LinkList(l);
    return 0;
}
