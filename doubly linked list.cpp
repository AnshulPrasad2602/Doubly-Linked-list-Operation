

//code for doubly linked list
#include <iostream>
using namespace std;

class node	//class node that contain data value and link to the next and previous node
{
	public:
		int data;
		node *next;
		node *prev;
};

class dlist : public node	//class dlist -> child class of node
{
		public:
		node *lstptr;	//pointer that points to the 1st node
		node *temp;		//pointer that points to the last node and hold temporary value of the node
		dlist ()	//default constructor
		{
			lstptr = NULL;	//initialising lstptr and temp to NULL
			temp = NULL;
		}
		
		void create_node()	//function to create node
		{
			cout << "\n\n\tCREATE NODE OF DOUBLY LINKED LIST\n\n";
			
			node *newnode = new node();	//node pointer to create new node (dynamically memory allocated)
			int value;	//variable from which user will enter data
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;	//storing value to the data section of node
			if (lstptr == NULL)		//checking condition for empty
			{
				lstptr = temp = newnode;	//pointing lstpr and temp to 1st node
				cout << "Node created successfully";
				newnode->next = newnode->prev = NULL;
			}
			else
			{
				for (temp = lstptr; temp->next != NULL; temp = temp->next);
				temp->next = newnode;	//creating link between the nodes
				newnode->prev = temp;	//crerating link to the previous node
				temp = temp->next;
				cout << "Node created successfully";
			}
		}
		
		void print_lnkdlst()	//function to print whole doubly linked list
		{
			cout << "\n\n\tPRINT WHOLE DOUBLY LINKED LIST\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				cout << "Elements in the linked list : ";
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					cout << temp1->data << " ";		//printing each value of linked list
				}
			}
		}
		
		void length_lnkdlst()	//function to print length of linked list
		{
			cout << "\n\n\tLENGTH OF DOUBLY LINKED LIST\n\n";
			
			int count = 0; 	//variable to count the node in linked list
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "Linked list is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					count++;	//incremeting the counter
				}
				cout << "Length of the linked list is " << count;
			}
		}
		
		void insert_begnn()	//function to insert node at beginning
		{
			cout << "\n\n\tINSERT NODE AT BEGINNING\n\n";
			
			node *temp1;
			node *newnode = new node();
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = newnode->prev = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				lstptr->prev = newnode;
				newnode->next = lstptr;
				newnode->prev = NULL;
				lstptr = newnode;
				cout << "Node added successfully.";
			}
		}
		
		void insert_pos()	//function to insert at specified position
		{
			cout << "\n\n\tINSERT NODE AT SPECIFIED POSITION\n\n";
			
			node *newnode = new node();
			node *temp1;
			int pos;	//variable for position
			int count = 0;
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			cout << "Enter the position : ";
			cin >> pos;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = newnode->prev = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					count++;	//incremeting the counter to count whole liked list
				}
				if (pos > count)
				{
					cout << "Can't create the node.";
					delete newnode;
					return;
				}
				else
				{
					temp1 = lstptr;
					for (int i = 1; i < pos-1; i++)
					{
						temp1 = temp1->next;
					}
					newnode->next = temp1->next;
					temp1->next = newnode;
					newnode->prev = temp1;
					newnode->next->prev = newnode;
					cout << "Node added successfully";
				}
			}
		}
		
		void insert_end()	//function for insert at end
		{
			cout << "\n\n\tINSERT NODE AT END\n\n";
			
			int value;
			node *newnode = new node();
			node *temp1;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = newnode->prev = NULL;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != NULL; temp1 = temp1->next);	//traversing till last node
				temp1->next = newnode;	//creating link between newnode and last node
				newnode->next = NULL;
				newnode->prev = temp1;
				cout << "Node added successfully";
			}
		}
		
		void delete_node_front()	//function to delete first node
		{
			cout << "\n\n\tDELETE NODE FROM FRONT\n\n";
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				lstptr = lstptr->next;
				cout << "Deleted node had : " << lstptr->prev->data;
				delete lstptr->prev;
				lstptr->prev = NULL;
			}
		}
		
		void delete_node_end()	//function to delete node at end   
		{
			cout << "\n\n\tDELETE NODE FROM END\n\n";
			
			node *temp1, *temp2;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; (temp1->next)->next != NULL; temp1 = temp1->next);	//temp1 will traverse to the second last node
				cout << "Deleted node had : " << temp1->next->data;
				delete temp1->next;
				temp1->next = NULL;
			}
		}
		
		void delete_node_position()	//function to delete node at specified postion
		{
			cout << "\n\n\tDELETE NODE AT SPECIFIED POSITION\n\n";
			
			node *temp1;
			int node_pos;	//variable for storing node position
			int count = 0;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					count++;	//incremeting the counter to count whole liked list
				}
				cout << "Enter the node position to be deleted : ";
				cin >> node_pos;
				if (node_pos > count)
				{
					cout << "Can't delete the node.";
				}
				else
				{
					temp1 = lstptr;
					for (int i = 1; i < node_pos-1; i++)
					{
						temp1 = temp1->next;
					}
					temp1->next = temp1->next->next;
					cout << "Deleted node had : " << temp1->next->prev->data;
					delete temp1->next->prev;
					temp1->next->prev = temp1;
				}
			}
		}
		
		void delete_by_searched_value()	//function to delete node by search value
		{
			cout << "\n\n\tDELETE BY SEARCHED VALUE\n\n";
			
			node *temp1, *temp2;
			int search_value;	//to store the search value entered by the user
			int pos = 0; 		//to determine the position of searched value
			int stat = 0;	//if searched element not found then stat will remain 0
			
			cout << "Enter the data value of the node to be deleted : ";
			cin >> search_value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search_value)
					{
						stat++;
						temp2 = lstptr;
						for (int i = 1; i < pos-1; i++)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp1->next;
						delete temp1;
						cout << pos << " st/nd/rd/th node is deleted.";
						break;
					}
				}
				if (stat == 0)
				{
					cout << "No node contain " << search_value << ".";
				}
			}
		}
		
		void search_node()	//function for searching data in a node
		{
			cout << "\n\n\tSEARCH DATA OF THE NODE\n\n";
			
			int search, pos = 0;	//search variable to store search value, pos variable to determine position of node
			int count = 0;	//if remained 0 then element not found
			node *temp1;
			
			cout << "Enter the search element : ";
			cin >> search;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1 != NULL; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search)
					{
						count++;
						cout << "Search element found at node " << pos <<".";
						break;
					}
				}
				if (count == 0)
				{
					cout << "Element not found.";
				}
			}
		}
};

void choice (dlist lst)
{
	int ch;
	
	cout << "\n\n\nChoose one of the following:\n1. Create a node\n2. Insert node at begining\n3. Insert node at end\n4. Insert node at specified position\n5. Print doubly linked list\n6. Length of doubly linked list\n7. Delete node from front\n8. Delete node from end\n9. Delete node from node position\n10. Delete node by searched value\n11. Search of node\n12.Exit\nEnter your choice : ";
	cin >> ch;
	
	switch(ch)
	{
		case 1 :
			lst.create_node();
			choice(lst);
			break;
			
		case 2 :
			lst.insert_begnn();
			choice(lst);
			break;
			
		case 3 :
			lst.insert_end();
			choice(lst);
			break;
			
		case 4 :
			lst.insert_pos();
			choice(lst);
			break;
			
		case 5 :
			lst.print_lnkdlst();
			choice(lst);
			break;
			
		case 6 :
			lst.length_lnkdlst();
			choice(lst);
			break;
			
		case 7 :
			lst.delete_node_front();
			choice(lst);
			break;
			
		case 8 :
			lst.delete_node_end();
			choice(lst);
			break;
		
		case 9 :
			lst.delete_node_position();
			choice(lst);
			break;
			
		case 10 :
			lst.delete_by_searched_value();
			choice(lst);
			break;
			
		case 11 :
			lst.search_node();
			choice(lst);
			break;
			
		case 12 :
			exit(0);
			
		default :
			cout << "\nChoice not valid.";
			choice (lst);	
	}
}

main ()
{
	dlist lst;
	choice(lst);
}
