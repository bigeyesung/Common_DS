#ifndef CLASSB_H
#define CLASSB_H
#pragma once

struct node_t
{
	unsigned val;
	node_t* next;
};

class SinglyLinkedlist  
{
	private:
		node_t* head=NULL;
		node_t* tail=NULL;
	public:
		// SinglyLinkedlist();
		~SinglyLinkedlist();
		static node_t* even_nodes(node_t** node);
		void AddNode(const int& val);
		void PrintList();
		node_t* GetList();
};
#endif