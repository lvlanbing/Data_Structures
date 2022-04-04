//
// Created by fly on 2022/4/1.
//
#include <stdio.h>
#include <stdlib.h>
//// 定义数据结构
typedef struct Node {
    int data;
    Node* next;
};

//// 是否是空链表
bool empty(Node* head) {
    if(head == NULL)
        return true;
    return false;
}

//// 创建链表（尾部插入试）
void create_rear(Node* head, int a[], int n) {
    Node* last = head;
    last->data = a[0];
    for(int i = 1; i < n; ++i) {
        Node* p = (Node*) malloc(sizeof (Node));
        p->data = a[i];
        last->next = p;
        last = p;
    }
    last->next = NULL;
}

//// 创建链表 （头部插入试）
void create_head(Node* head, int a[], int n) {
    head->next = NULL;

    for(int i = 0; i < n -1; ++i) {
        Node* p = (Node* ) malloc(sizeof (Node));
        p->data = a[i];
        p->next = head->next;
        head->next = p;
    }
    head->data = a[n - 1];
}
//// 获取元素
Node* get_element(Node* head, int pos) {
    for(int i = 0; i < pos; ++i) {
        if(empty(head)) {
            perror(" out of range");
            return NULL;
        }
        head = head->next;
    }
    return head;
}

//// 插入链表
void insert(Node* head, int pos, int element) {
    Node* q = get_element(head, pos);
    Node* p = (Node*) malloc(sizeof (Node));
    p->data = element;
    p->next = q->next;
    q->next = p;
}

//// 删除链表
void delete_node(Node* head, int pos) {

    Node* p = get_element(head, pos);
    Node* q = p->next;
    p->data = q->data;
    p->next = q->next;

    free(q);
}

//// 销毁链表
void destroy(Node* head) {
    Node* p = head;
    while (!empty(p)) {
        Node* q = p;
        p = p->next;
        free(q);
    }
    printf("destroy link\n");
}

//// 打印链表
void print(Node* head) {
    Node* p = head;
    while(!empty(p)) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node* head = (Node*) malloc(sizeof (Node));
    Node* head2 = (Node*) malloc(sizeof (Node));
    int a[] = {1,2,3,4,5,6};
    create_rear(head2, a, 6);
    print(head2);
    create_head(head, a, 6);
    print(head);
    delete_node(head, 4);
    print(head);
    printf("%d\n", get_element(head, 2)->data);
    insert(head, 3, 2);
    print(head);
    destroy(head);
}
