#include <stdlib.h>
#include <stdio.h>
struct node_t{
    unsigned val;
    struct node_t* next;
};
//global vars
node_t* head = NULL;
node_t* tail = NULL;

void AddNode(int val){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->val=val;
    newNode->next=NULL;
    //if list is empty
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail=tail->next;
    }

}

void PrintList(node_t* head){
    node_t* ref = head;
    while(ref!=NULL){
        printf("list value: %d\n",ref->val);
        ref=ref->next;
    }
}

node_t* even_nodes(node_t** headRef){
    node_t* curNode = *headRef;
    node_t* evenHead = NULL;
    node_t* evenHeadRef = NULL;
    while(curNode!=NULL){
        // printf("curNode val: %d \n" ,curNode->val);
        //check if node has even value
        if (curNode->val%2==0)
        {
            node_t* evenNode = (node_t*)malloc(sizeof(node_t));
            evenNode->val = curNode->val;
            evenNode->next=NULL;
            //check evenHead exists
            if (evenHead==NULL){
                evenHead=evenNode;
                evenHeadRef=evenHead;

                // remove current node(redundant)
                node_t* tmpNext = curNode->next;
                free(curNode);
                curNode = tmpNext;
                continue;
            }
            
            if(curNode->next){
                curNode->val=curNode->next->val;
                node_t* tmpNext = curNode->next;
                curNode->next = curNode->next->next;

                //remove next node(redundant)
                tmpNext->next = NULL;
                free(tmpNext);
                tmpNext = NULL;

                evenHeadRef->next = evenNode;
                evenHeadRef=evenHeadRef->next;
            }
            else{
                // check in tail condition
                evenHeadRef->next = evenNode;
                evenHeadRef=evenHeadRef->next;

                //remove current node(redundant)
                free(curNode);
                curNode = NULL;
            }

        }
        else{
            curNode=curNode->next;
        }
    }
    // node_t* tmpNode = *headRef;
    // while(tmpNode!=NULL){
    //     std::cout<<"origi list val: "<<tmpNode->val<<std::endl;
    //     tmpNode=tmpNode->next;
    // }
    return evenHead;

}

void Release(){

	//delete every node
    while( head != NULL ) {
        // printf("evenList node val: %u\n",head->val);
        node_t* next = head->next;
        head->next=NULL;
        free(head);
        head = next;
    }
    head = NULL;
    if (tail!=NULL){
        free(tail);
        tail = NULL;
    }
}

int main()
{
    AddNode(10);
    AddNode(1);
    AddNode(3);
    AddNode(5);
    AddNode(2);
    // PrintList(head);
    node_t** headRef = NULL;
    headRef = &head;
    struct node_t* ret = even_nodes(headRef);
    while(ret!=NULL){
        printf("evenList node val: %u\n",ret->val);
        ret=ret->next;
    }
    Release();
    return 0;
}