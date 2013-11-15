/** @file data_structure.h
  * @brief define the object list and data structure
  *
  * @author PokaiChang
  * @date 2013-11-15
  */
typedef struct _List {  // Structure for list storing
	char *name;
	void *pointer;
} List;

typedef struct _LinkedListData {  // Data of a node of a linked list of integers
	union {
		int number;
		List list;
	};
} LinkedListData;

typedef struct _LinkedListNode {  // Node of a linked list of integers
	LinkedListData data;
	_LinkedListNode *next;
} LinkedListNode;

class LinkedList {  // Linked list

	public:

		LinkedList();  // Initialize

		int length();  // Get the length of the link list
		LinkedListNode* head();  // Get the head of the linked list
		LinkedListNode* getNode(int);  // Get the nth node

		void insertNode(LinkedListData);  // Insert a node at the end of a list
		void insertNode(int, LinkedListData);  // Insert a node after the nth node
		void deleteNode();  // Delete the first node
		void deleteNode(int);  // Delete the nth node
		void clear();  // Delete all node

	private:

		int _length;  // Length of list
		LinkedListNode *_head;  // Pointer to the first node
};
