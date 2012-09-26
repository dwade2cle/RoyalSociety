/////////////////////////////////////////////////////////////////////////
/**These comments let the user know what each method does pretty well.
*Method descriptions usually would go in the header file, while comments 
*on code would go here. Good use of notation. */
////////////////////////////////////////////////////////////////////////

/*
Methods that allow useres to insertAter, insertBefore and delete nodes. 
*/
#include "Node.h"

Node::Node(void)
{
	next_ = this;
	prev_ = next_;
}

Node::Node(Node* next, Node* prev, Window* window)
{
	next_ = next;
	prev_ = prev;
	window_ = window;
}

void Node::insertAfter(Node* nodeAt, Window* newWindow)
{
	Node* nextNode = nodeAt->next_;
	Node* tmp = new Node(nextNode, nodeAt, newWindow);
	nodeAt->next_ = tmp;
	nextNode->prev_ = tmp;
}

void Node::insertBefore(Node* node, Window* newWindow)
{
	Node* previousNode = node->prev_;
	Node* tmp = new Node(node, previousNode, newWindow);
	node->prev_ = tmp;
	previousNode->next_ = tmp;
}

/////////////////////////////////////////////////////
/** This function is giving me trouble when I use it
*in the App.  I think we are deleting a connection
*because we get an Access violation error if we try to
*add another node. */
////////////////////////////////////////////////////
void Node::remove(Node* remove_here) 
{
	/////////////////////////////////
	/** Hopefully this will keep the 
	*list intact. */

	/** After testing, it seems it does
	*not. It will work the first time, 
	*and cause issues thereafter.
	*I think this might be because
	*it cannot find ->prev_ or ->next_ */
	/////////////////////////////////
	Node* cur = remove_here->prev_;
	Node* pointTo = remove_here->next_;
	cur->next_ = pointTo;
	delete remove_here;
}


void Node::reverse(Node* sentinel)
{
	Node* tmp;
	Node* cur = sentinel;
	do
	{
		tmp = cur->next_;
		cur->next_ = cur->prev_;
		cur->prev_ = tmp;
		
		// go to next node in list
		cur = cur->prev_;
	} while(cur != sentinel);
}

