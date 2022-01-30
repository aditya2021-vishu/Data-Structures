#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void linklistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertATFirst(struct Node * head,int data){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}

struct Node * insertATIndex(struct Node * head,int data,int index){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
    return head;
}

struct Node * insertAfterNode(struct Node * head,struct Node * prevNode,int data){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = prevNode->next;
    ptr->data = data;
    prevNode->next = ptr;
    return head;
}

struct Node * insertATEnd(struct Node * head,int data){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node * delNodeFromBeginn(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * delAtIndex(struct Node * head , int index){
    struct Node* p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    struct Node * ptr;
    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct Node * delAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * delWithVal(struct Node * head , int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    // Allocate memory for node in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // link first and second node
    head->data = 7;
    head->next = second;

    //link secomd and third node
    second->data = 11;
    second->next = third;

    // terminate the list at third node
    third->data = 66;
    third->next = NULL;

    linklistTraversal(head);
    printf("we are traversing using newly created link list in which element is inserted at the beggining\n");
    head = insertATFirst(head,56);
    linklistTraversal(head);

    printf("we are traversing using newly created link list in which element is inserted between nodes\n");
    head = insertATIndex(head,69,1);
    linklistTraversal(head);

    printf("we are inserting data and printing newly craeted linklist by inserting data at the end\n");
    head = insertATEnd(head,99);
    linklistTraversal(head);
    
    printf("we are inserting node after an node whose address is given to us\n");
    struct Node* prevNode = second;
    head = insertAfterNode(head,prevNode,133);
    linklistTraversal(head);


    
    printf("after this we will code to delete an node from linklist\n");
    
    printf("deleting first node in linklist\n");
    head = delNodeFromBeginn(head);
    linklistTraversal(head);

    printf("deleting node from between nodes\n");
    head = delAtIndex(head,2);
    linklistTraversal(head);

    printf("deletion from the end\n");
    head = delAtEnd(head);
    linklistTraversal(head);

    printf("deletion with given data\n");
    head = delWithVal(head,133);
    linklistTraversal(head);

    return 0;
}
