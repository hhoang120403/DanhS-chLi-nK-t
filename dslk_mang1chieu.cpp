#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

node makeNode(int x){
    node newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(node &top, int x){
    node newNode = makeNode(x);
    if(top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void pop(node &top){
    if(top != NULL){
        node tmp = top;
        top = tmp->next;
        delete tmp;
    }
}

int Top(node top){
    if(top != NULL){
        return top->data;
    }
}

int size(node top){
    int cnt = 0;
    while(top != NULL){
        cnt++;
        top = top->next;
    }
    return cnt;
}

int main(){
    node st = NULL;
    while(true){
        cout << "Cac chuc nang:\n";
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.top\n";
        cout << "4.size\n";
        cout << "0.Thoat\n";
        int lc;
        cout << "Nhap chuc nang ma ban muon: "; cin >> lc;
        if(lc==1){
            int x; 
            cout << "Nhap x: "; cin >> x;
            push(st, x);
        }
        else if(lc==2){
            pop(st);
        }
        else if(lc==3){
            if(size(st)==0) cout << "EMPTY\n";
            cout << Top(st) << endl;
        }
        else if(lc==4){
            cout << size(st) << endl;
        }
        else{
            return 0;
        }
    }
}