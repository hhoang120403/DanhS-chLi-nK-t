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

void push(node &queue, int x){
    node newNode = makeNode(x);
    if(queue == NULL){
        queue = newNode;
        return;
    }
    node tmp = queue;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void pop(node &queue){
    if(queue == NULL){
        return;
    }
    node tmp = queue;
    queue = queue->next;
    delete tmp;
}

int size(node queue){
    int cnt = 0;
    while(queue != NULL){
        cnt++;
        queue = queue->next;
    }
    return cnt;
}

bool empty(node queue){
    return queue == NULL;
}

int front(node queue){
    return queue->data;
}

void duyet(node queue){
	while(queue != NULL){
		cout << queue->data << " ";
		queue = queue->next;
	}
	cout << "\n"; 
}

int main(){
    node queue = NULL;
    while(true){
        cout << "Cac chuc nang:\n";
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.size\n";
        cout << "4.empty\n";
        cout << "5.front\n";
        cout << "6.duyet\n";
        cout << "0.Thoat\n";
        int lc;
        cout << "Nhap chuc nang ma ban muon: "; cin >> lc;
        if(lc==1){
            int x; 
            cout << "Nhap x: "; cin >> x;
            push(queue, x);
        }
        else if(lc==2){
            pop(queue);
        }
        else if(lc==3){
            cout << size(queue) << endl;
        }
        else if(lc==4){
            if(empty(queue)) cout << "EMPTY\n";
            else cout << "NOT EMPTY\n";
        }
        else if(lc==5){
            cout << front(queue) << "\n";
        }
        else if(lc==6){
        	duyet(queue);
		}
        else{
            return 0;
        }
    }
}