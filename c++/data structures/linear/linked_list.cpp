#include<iostream>
using namespace std;
struct node {
int elem;
node *next;
};
node *head;
//..............................

void insert (int x){
    node *temp= new node ;
    temp->elem=x;
    temp->next=head ;
    head=temp;
}
//..............................

    void append (int data){
        node *temp=new node ;
        temp->elem=data;
        if (head ==NULL){
            head =temp;
            temp->next=NULL;
            return ;
        }else {
            node *ptr=head;
            while (ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->next=NULL;
        }
    }
//..............................

void print (){
    node *temp=head ;
    cout <<"list is  :";
    while (temp!=NULL ){
        cout <<temp->elem<<" ";
        temp=temp->next;
    }
cout <<"\n";
}

//..............................

void printrec(node *p){
    if (p==NULL) return;
    cout <<p->elem<<endl;//to revers just below write it 
    printrec(p->next);

}

//..............................

void insernth(int data,int pos){
    node *temp1 =new node ;
    temp1->elem=data;
    temp1->next=NULL;
if (pos==1){
    temp1->next=head ;
    head =temp1;
    return;
}
    node *temp2=head ;
    for (int i=0;i<pos-2;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;

}

//..............................

void delet (int pos){
    node *temp=head ;
    if (pos==1){
        head =temp->next;
        delete temp;
    }else {
        for (int i=0;i<pos-2;i++){
            temp=temp->next;
        }
        node *temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
    }
}

//..............................

void reversed (){
    node *current ,*prev,*next;
    prev=NULL;
    current=head;
    while (current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
head=prev;
}

//..............................

void recursionrev(node *p){
if (p->next==NULL){
    head =p;
    return;
}
    recursionrev(p->next);
   p->next->next=p;
  //or  node *q=p->next;
    //q->next=p;
    p->next=NULL;
}

//..............................
bool detector (node *head) {
    while(head!=0){
     node *tmp;
    for(tmp = head->next; tmp!=0; tmp=tmp->next)
        if(tmp->elem==head->elem) return false; 
            head = head->next;
}
return true;
}
//..............................

void duplicat(){
        node *temp=head;
        while (temp!=NULL){
             node *dup=new node;
                dup->elem=temp->elem;
                dup->next=temp->next;
                temp->next=dup;
                temp=temp->next;
                temp=temp->next;
        }
}
//.........................................

void sortings (node * head) {
    int swapped;
    node* ptr1;
    node* lptr = NULL;
    if (head == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->elem > ptr1->next->elem) {
                // swap nodes
                int temp = ptr1->elem;
                ptr1->elem = ptr1->next->elem;
                ptr1->next->elem = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void sortingtwo (node *head){
    node *ptr1 ;
    ptr1=head;
    while (ptr1->next!=NULL){
        node* ptr2 = ptr1->next;
        while (ptr2!=nullptr)
        {
            if (ptr1->elem > ptr2->elem){
                swap(ptr1->elem,ptr2->elem);
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        
    }
}
//.........................................
void deltelist(node* &head){
while (head!=NULL){
    node*temp=head;
    head=head->next;
    delete temp;
    temp=nullptr;
}
}

int main (){
    head=NULL;
    insernth(1,1);
    insernth(3,2);
    insernth(2,3);
    insernth(4,4);
    printrec(head);
    sortingtwo(head);
    printrec(head);


    return 0;
}


