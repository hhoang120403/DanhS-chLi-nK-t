#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

//Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

//Kiem tra rong
bool empty(node a){
    return a == NULL;
}

int Size(node a){
    int cnt=0;
    while(a!=NULL){
        ++cnt;
        a = a->next; // gan dia chi cua node tiep theo cho node hien tai
        // Cho node hien tai nhay sang node tiep theo
    }
    return cnt;
}

// Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        tmp->next = a;
        a = tmp;
    }
}

// Them 1 phan tu vao cuoi danh sach lien ket
void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        node tmp = makeNode(x);
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

// Them 1 phan tu vao 1 vi tri bat ky
void insert(node &a, int x, int pos){
    int n = Size(a);
    if(pos <= 0 || pos > n + 1){
        cout << "Vi tri chen khong hop le !\n";
    }
    if(pos==1){
        insertFirst(a,x);
        return;
    }
    else if(pos==n+1){
        insertLast(a,x);
        return;
    }
    else{
        node p = a;
        for(int i=1;i<pos-1;i++){
            p = p->next;
        }
        node tmp = makeNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

// Xoa phan tu o dau
void deleteFirst(node &a){
    if(a == NULL) return;
    a = a->next;
}

// Xoa phan tu o cuoi
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = NULL;
    }
    else{
        truoc->next = NULL;
    }
}

// Xoa 1 phan tu o vi tri bat ky
void deletePos(node &a, int pos){
    if(pos<=0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for(int i=1;i<pos;i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = a->next;
    }
    else{
        truoc->next = sau->next;
    }
}

void in(node a){
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n";
}

void sapxep(node &a){
	for(node p = a;p->next = NULL; p = p->next){
		node min = p;
		for(node q = p->next; q!=NULL; q = q->next){
			if(q->data < min->data){
				min = q;
			}
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}

int main(){
    node head = NULL;
    while(1){
        cout << "-------------MENU-------------\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao vi tri bat ky vao danh sach\n";
        cout << "4. Xoa phan tu o dau danh sach\n";
        cout << "5. Xoa phan tu o cuoi danh sach\n";
        cout << "6. Xoa phan tu o vi tri bat ky trong danh sach\n";
        cout << "7. Duyet danh sach lien ket\n";
        cout << "8. Sap xep danh sach lien ket\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        int x;
        int idx;
        switch (lc){
        case 1:
            cout << "Nhap gia tri can chen: "; cin >> x;
            insertFirst(head, x);
            break;
        case 2:
            cout << "Nhap gia tri can chen: "; cin >> x;
            insertLast(head, x);
            break;
        case 3:
            cout << "Nhap vi tri can chen: "; cin >> idx;
            cout << "Nhap gia tri can chen: "; cin >> x;
            insert(head, x, idx);
            break;
        case 4:
            deleteFirst(head);
            break;
        case 5:
            deleteLast(head);
            break;
        case 6:
            cout << "Nhap vi tri can xoa: "; cin >> idx;
            deletePos(head, idx);
            break;
        case 7:
            cout << "Danh sach lien ket:";
            in(head);
            break;
        case 8:
        	sapxep(head);
        	break;
        case 0:
            return 0;
            break;
        }
    }
}