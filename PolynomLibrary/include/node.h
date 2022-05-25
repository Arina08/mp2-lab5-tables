#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node 
{
	T data;
	Node *prev, *next;
};

#endif /* NODE_H */