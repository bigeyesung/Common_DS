#include "SinglyLinkedlist.hpp"  
	
// SinglyLinkedlist::SinglyLinkedlist()
// {
	//using default constructor

// }
	
SinglyLinkedlist::~SinglyLinkedlist()
{
	//delete every node
    while( head != NULL ) {
        // std::cout<<"cur delete value: "<<head->val<<std::endl;
        node_t* next = head->next;
        head->next=NULL;
        delete head;
        head = next;
    }
    head = NULL;
    if (tail!=NULL){
        delete tail;
        tail = NULL;
    }
    
}

node_t* SinglyLinkedlist::even_nodes(node_t** headRef)
{
    // std::cout<<**head->val<<std::endl;
    node_t* curNode = *headRef;
    node_t* evenHead = NULL;
    node_t* evenHeadRef = NULL;
    while(curNode!=NULL){
        std::cout<<curNode->val<<std::endl;
        //check if node has even value
        if (curNode->val%2==0)
        {
            node_t* evenNode = new node_t();
            evenNode->val = curNode->val;
            evenNode->next=NULL;
            //check evenHead exists
            if (evenHead==NULL){
                evenHead=evenNode;
                evenHeadRef=evenHead;

                // remove current node(redundant)
                node_t* tmpNext = curNode->next;
                delete curNode;
                curNode = tmpNext;
                continue;
            }
            
            if(curNode->next){
                curNode->val=curNode->next->val;
                node_t* tmpNext = curNode->next;
                curNode->next = curNode->next->next;

                //remove next node(redundant)
                tmpNext->next = NULL;
                delete tmpNext;
                tmpNext = NULL;

                evenHeadRef->next = evenNode;
                evenHeadRef=evenHeadRef->next;
            }
            else{
                // check in tail condition
                evenHeadRef->next = evenNode;
                evenHeadRef=evenHeadRef->next;

                //remove current node(redundant)
                delete curNode;
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

void SinglyLinkedlist::AddNode(const int& val){
    node_t* newNode = new node_t();
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

void SinglyLinkedlist::PrintList(){
    node_t* ref = head;
    while(ref!=NULL){
        std::cout<<"list value: "<<ref->val<<std::endl;
        ref=ref->next;
    }
}

node_t* SinglyLinkedlist::GetList(){
    return head;
}