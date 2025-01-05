#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node{
    string name;
    string number;
    struct node *next;
    struct node *prev;
} *head = NULL;

void add(string name, string number){
    node *p = new struct node;
    p->name = name;
    p->number = number;
    p->next = NULL;
    p->prev = NULL;

    if (head == NULL){//empty directory
        head = p;
    }
    else if (name < head->name)//if it is first in the list
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    else{
        node* t =head;
        while(t->next != NULL && name > t->name){
            t=t->next;
        }
        if(p->name < t->name){//condition for last second node
            p->prev = t->prev;
            t->prev->next = p;
            p->next = t;
            t->prev = p;
        }
        else if(t->next==NULL){//condition for last node
            p->prev=t;
            t->next=p;
        }else{                //condition for nodes in between
            p->prev = t->prev;
            t->prev->next = p;
            p->next = t;
            t->prev = p;
        }
    }
}

node *search(string n){
    node *t=head;
    while(t!=NULL){
        if(t->name==n){
            return t;
        }
        t=t->next;
    }
    return NULL;
}

void remove(){
    string n;
    cout<<"Enter Name to remove: ";
    getline(cin,n);

    node *t=search(n);//t is the contact to remove
    if(t==NULL){
        cout<<"Contact not found!\n";
        return;
    }else{
        if(t==head){//deleting the first node 
            head=t->next;
            head->prev=NULL;
        }
        else{
            t->prev->next=t->next;
            if(t->next!=NULL){//to check for last node 
                t->next->prev=t->prev;
            }
        }
        cout<<"Contact Deleted\n";
    }
}

void display(){
    node *t=head;
    while(t!=NULL){
        cout<<t->name<<" : "<<t->number<<endl;
        t=t->next;
    }
}

void checknum(string &num){
    if(num.length()==10){
        node *t=head;
        while(t!=NULL){
            if(t->number==num){
                cout<<"Number already exist with other name! \nEnter another number: ";
                cin>>num;
                checknum(num);
                return;
            }
            t=t->next;
        }
    }
    else{
        cout<<"Invalid number \nEnter a 10 digit number: ";
        cin>>num;
        checknum(num);
        return;
    }
}

void checkname(string &n){
    node *t=head;
    while(t!=NULL){
        if(t->name==n){
            cout<<"Name already exists! \nEnter another name: ";
            cin>>n;
            checkname(n);
            return;
        }
        t=t->next;
    }
}
void modify(string name){
    string num;
    node *temp = search(name);
    if(temp == NULL){
        cout<<"Contact not found";
        return;
    }else{
        cout<<"Enter Modified Number: ";
        cin>>num;
        node *t=head;
        while(t!=NULL){
            if(t->number==num){
                cout<<"Number already exist with other name! \nEnter another number: ";
                cin>>num;
                checknum(num);
                temp->number=num;
                return;
            }
        t=t->next;
        }
        temp->number=num;
    }
}
void check(string &name){
    node *t = search(name);
    if(t == NULL){
        return;
    }else{
        cout<<"Name already exist! \nEnter another name: ";
        getline(cin,name);
        check(name);
    }
}
void modifyname(string name) {
    string n;
    node *temp = search(name);
    if (temp == NULL) {
        cout << "Contact not found\n";
        return;
    } else {
        cout << "Enter Modified Name: ";
        getline(cin, n);
        checkname(n);
        temp->name = n;
    }
}

void savefile(){
    fstream file("phone.txt",ios::out);
    if (!file.is_open()) {
        cout << "Error opening file for writing\n";
        return;
    }
    node *t = head;
    while (t != NULL) {
        file << t->name << " " << t->number << endl;
        t = t->next;
    }
    file.close();
}

void loadfile(){
    fstream file("phone.txt");
    if (!file.is_open()) {
        cout << "Error opening file for reading\n";
        return;
    }
    string line;
    while(getline(file,line)){
        string n, number;
        for(int i=0;i < line.length(); i++){
            char x=line[i];
            if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
                n+=x;
            }
            else if(x >='0' && x <= '9'){
                number+=x;
            }else{
                n+=x;
            }
        }
        string name;
        for (int i = 0; i < n.length(); i++) {
            if (n[i] == ' ' && n[i + 1] == '\0') {
                break;
            }
            name+=n[i];
        }
        add(name,number);
    }
    file.close();
}

int main(){
    loadfile();
    string name;
    string num;
    node *s;
    int ch;
    char x=2;

    cout<<"1-Add Contact"<<endl<<
    "2-Remove Contact"<<endl<<
    "3-Search Number"<<endl<<
    "4-Display Directory"<<endl<<
    "5-Modify Contact"<<endl<<
    "6-Save to Directory"<<endl<<
    "7-Exit"<<endl;

    do{
        cout<<"\nEnter Choice: ";
        cin>>ch;
        cin.ignore();
        switch(ch){
            case 1: 
                cout<<"Enter Name: ";
                getline(cin,name); 
                check(name);
                cout<<"Enter Number: ";
                cin>>num;
                checknum(num);
                add(name,num);
                break;
            case 2:
                remove();
                break;
            case 3:
                cout<<"Enter Name: ";
                getline(cin,name); 
                s=search(name);
                if(s==NULL){
                    cout<<"Contact not found"<<endl;
                }else{
                    cout<<"Number: "<<s->number<<endl;
                }
                break;
            case 4:
                if(head==NULL){
                    cout<<"Empty Directory"<<endl;
                }else{
                    display();
                }
                break;
            case 5:{
                int a;
                cout << "Enter 0 to modify name and 1 to modify number: ";
                cin >> a;
                cin.ignore();
                if (a == 0) {
                    cout << "Enter Name to be modified: ";
                    getline(cin, name);
                    modifyname(name);
                } else if (a == 1) {
                    cout << "Enter Name for number to be modified: ";
                    getline(cin, name);
                    modify(name);
                } else {
                    cout << "Invalid Choice\n";
                }
                break;
            }
            case 6:
                savefile();
                cout<<"File Saved "<<x<<endl;
            case 7:
                break;
            default:
                cout<<"Invalid Choice!\n";
        }

    }while(ch!=7);
    savefile();
    return 0;
}