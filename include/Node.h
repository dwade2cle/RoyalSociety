#include "Window.h"


class Node
{
	public:

		Node* next_;
		Node* prev_;

		Window* window_;

		Node(void);
		/*
		@param next next spot in the list
		@param prev previous spot in the list
		@param window a rectangle
		*/
		Node(Node* next, Node* prev, Window* window);
		/*
		@param nodeAt the node you want to insert after
		@param newWindow the new rectangle to be placed after the nodeAt
		*/
		void insertAfter(Node* node, Window* newWindow);
		/*
		@param node the node you want to insert in front of
		@param newWindow the new rectangle to be placed before the node
		*/
		void insertBefore(Node* node, Window* newWindow);
		/*
		@param remove_here removes the given node from the list
		*/
		void remove(Node* remove_here);
		/*
		This method reverses the order of the nodes in the list.
		@param sentinel the decode node in the list
		*/
		void reverse(Node* sentinel);
};

