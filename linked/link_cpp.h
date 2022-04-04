//
// Created by fly on 2022/4/1.
//


#ifndef DATA_STRUCTURES_LINK_CPP_H
#define DATA_STRUCTURES_LINK_CPP_H
#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next= nullptr;
};

template<typename T>
class link {
private:
    int count = 0;
    Node<T>* head = new Node<T>();
    Node<T>* last = head;

public:

    //构建链表
    link() {head = new Node<T>();}
    link(std::initializer_list<T> list);
    link(const link<T>&);

    //// 拷贝赋值
    link& operator = (const link& p);

    //// 插入数据
    void push_back(T element);
    void insert(int pos, T element);

    //// 删除数据
    void pop_back();
    void erase(int pos);

    //// 链表长度
    int size() const { return count;}

    //// 两个链表链接
    link<T>& operator+= (const link<T>& p);

    void print() {
        Node<T>* p = head;
        while(p != nullptr) {
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    void destroy() {
        Node<T>* p = head;
        head = nullptr;
        last = nullptr;
        while (p != nullptr) {
            Node<T>* q = p;
            p = p->next;
            delete q;
        }
        count = 0;
    }
    //// 释放内存
    ~link() {
        destroy();
    }
};

template <typename T>
inline
link<T>::link(const link<T>& p) {
    Node<T>* q = p.head;
    while(q != nullptr) {
        push_back(q->data);
        q = q->next;
    }
}

template <typename T>
inline
link<T>& link<T>::operator= (const link<T>& p) {
    destroy();
    head = new Node<T>();
    last = head;
    Node<T>* q = p.head;
    while(q != nullptr) {
        push_back(q->data);
        q = q->next;
    }
    return *this;
}


template <typename T>
inline
link<T>::link(initializer_list<T> list) {
    auto t = list.begin();
    head->data = *t;
    ++count;
    for(auto it = list.begin() + 1; it != list.end(); ++it) {
        push_back(*it);
    }
    last->next = nullptr;
}

template <typename T>
inline
link<T>& link<T>::operator+= (const link<T>& p) {

    Node<T>* q = p.head;
    while(q != nullptr) {
        push_back(q->data);
        q = q->next;
    }
    return *this;
}

template <typename T>
inline
void link<T>::push_back(T element) {

    //头部放入数据
    if(count == 0) {
        head->data = element;
        ++count;
        return;
    }

    //赋值
    Node<T> *p = new Node<T>;
    p->data = element;
    //最后一个指针指向p
    last->next = p;
    last = p;
    ++count;
}

template <typename T>
inline
void link<T>::insert(int pos, T element) {
    if(pos > count) {cout<<"out of range \n"; return;}
    Node<T>* p = head;
    for(int i = 0; i < pos; ++i)
        p = p->next;
    Node<T>* q = new Node<T>();
    q->data = element;
    //插入操作
    q->next = p->next;
    p->next = q;
}

template <typename T>
inline
void link<T>::erase(int pos) {
    if(pos > count) {cout<<"out of range \n"; return;}
    Node<T>* p = head;
    for(int i = 0; i < pos - 1; ++i) {
        p = p->next;
    }
    Node<T>* q = p->next;
    //删除的节点为第一个
    if(q == head) {
        head = head->next;
        delete q;
        return;
    }
    p->next = q->next;
    delete q;
}
template <typename T>
inline
void link<T>::pop_back() {
    erase(count - 1);
}

#endif //DATA_STRUCTURES_LINK_CPP_H
