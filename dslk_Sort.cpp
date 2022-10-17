#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
	string name;
	double gpa;
	SinhVien(){
		;
	}
	SinhVien(string ten, double diem){
		name = ten;
		gpa = diem;
	}
};

struct Node{
    SinhVien data;
    Node *next;
};

typedef struct Node* node;

node makeNode(SinhVien sv){
    node newNode = new Node();
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

void pushBack(node &head, SinhVien sv){
    node newNode = makeNode(sv);
    if(head == NULL){
        head = newNode;
        return;
    }
    node tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void duyet(node head){
    while(head != NULL){
        cout << head->data.name << " " << fixed << setprecision(2) << head->data.gpa << endl;
        head = head-> next;
    }
}

void sapxep(node &head){
    for(node i = head; i != NULL; i = i->next){
        node minNode = i;
        for(node j = i->next; j != NULL; j = j->next){
            if(minNode->data.gpa > j->data.gpa){
                minNode = j;
            }
            else if(minNode->data.gpa == j->data.gpa){
            	if(minNode->data.name > j->data.name){
            		minNode = j;
				}
			}
        }
        SinhVien tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}

int main(){
    node head = NULL;
    SinhVien s("Teo", 3.5);
    SinhVien t("Ti", 3.8);
    SinhVien u("Hoang", 3.9);
    SinhVien v("Hai",3.3);
    SinhVien c("Ly", 3.5);
    pushBack(head,s);
    pushBack(head,t);
    pushBack(head,u);
    pushBack(head,v);
    pushBack(head,c);
    duyet(head);
    cout << endl;
    sapxep(head);
    duyet(head);
}