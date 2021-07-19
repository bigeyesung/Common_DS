#include <string>
#include <iostream>
#include "ClassA.cpp"
#include "SinglyLinkedlist.cpp"
using namespace std;

int main(){

    //Q1
    ClassA* myclass1 = new ClassA;
    cout<<"cur obj count: "<<ClassA::nobjs()<<endl;
    ClassA* myclass2 = new ClassA;
    ClassA* myclass3 = new ClassA;
    cout<<"cur obj count: "<<ClassA::nobjs()<<endl;
    delete myclass1;
    myclass1 = NULL;
    int count1 = ClassA::nobjs();
    cout<<"cur obj count: "<<ClassA::nobjs()<<endl;

    //Q2
    SinglyLinkedlist* list = new SinglyLinkedlist;
    list->AddNode(1);
    list->AddNode(2);
    list->AddNode(8);
    list->AddNode(4);
    list->AddNode(4);
    list->AddNode(9);
    list->AddNode(8);
    list->AddNode(8);

    node_t** headRef = NULL;
    // list->PrintList();
    node_t* retHead = list->GetList();
    headRef = &retHead;
    node_t* evenHead = SinglyLinkedlist::even_nodes(headRef);
    while(evenHead!=NULL){
        std::cout<<"even list value: "<<evenHead->val<<std::endl;
        evenHead=evenHead->next;
    }
    delete list;
    list=NULL;
    return 0;
}