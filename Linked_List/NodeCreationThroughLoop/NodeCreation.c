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

struct Node * InsetionLinkList(struct Node * head, int val){
    struct Node * MadeNode;
    MadeNode = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        MadeNode->data = val;
        MadeNode->next = NULL;
        head = MadeNode;
        //free(MadeNode);
        return head;
    }
    else{
        struct Node* p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = MadeNode;
        MadeNode->data = val;
        MadeNode->next = NULL;
        return head;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node * head = NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        head = InsetionLinkList(head,x);
    }
    printf("link list traversal\n");
    linklistTraversal(head);
}
