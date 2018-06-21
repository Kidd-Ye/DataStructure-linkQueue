//
//  main.cpp
//  LinkQueue
//
//  Created by kidd on 2018/6/21.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
using namespace std;

struct QNode{
    QNode *next;
    int data;
};

struct LinkQueue{
    QNode *front;
    QNode *rear;
};

void InitQueue(LinkQueue &Q){
    QNode *q;
    q = new QNode;
    q->next = NULL;
    
    Q.front = Q.rear = q;
}

bool IsEmpty(LinkQueue &Q){
    if (Q.rear == Q.front) {
        return true;
    }else return  false;
}

void EnQueue(LinkQueue &Q, int element){
    QNode *n;
    n = new QNode;
    n -> data = element;
    n -> next = NULL;
    cout << "插入:" << element <<endl;
    Q.rear -> next = n;
    Q.rear = n;
}

void Dequeue(LinkQueue &Q){
    if (IsEmpty(Q)) {
        cout<< "QUEUE is empty" <<endl;
    }else{
        QNode *d;
        d = Q.front ->next;
        cout<< "删除：" << d -> data <<endl;
        Q.front ->next = d -> next;
        if (Q.rear == d) {//如果要删除的元素即为尾结点，则将头指针赋予尾指针，一同指向头结点，表示队列为空
            Q.rear = Q.front;
        }
        delete d;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, LinkQueue!\n";
    LinkQueue *Q;
    Q = new LinkQueue;
    InitQueue(*Q);
 
    cout<< "开始向链式队列插入数据，以0作为结束符" <<endl;
    cout<< "请输入：" <<endl;
    int  a;
    cin >> a;
    while(a != 0){
        EnQueue(*Q, a);
        cout<< "请继续输入：" <<endl;
        cin >> a;
    }
    
    //将所有元素打印并出队
    while (!IsEmpty(*Q)) {
        Dequeue(*Q);
    }
    cout << "-------destory" <<endl;
    
    delete Q->front;
    delete Q;
    
    return 0;
}




