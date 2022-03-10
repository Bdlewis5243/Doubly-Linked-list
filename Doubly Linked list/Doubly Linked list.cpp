// Doubly Linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Bailey Lewis
//
//I followed the guide on https://www.geeksforgeeks.org/doubly-linked-list/ and combined it with my own code
//to use as reference. Half of the functions are made by me and the other half was adapted from geeksforgeeks
//for learning/educational purposes. 

#include <iostream>
#include <string>
using namespace std;



struct Node {
public:
    int data;
    Node* next;
    Node* prev;

}; // end of Node

class DoublyLinkedList {
    private:


    public:
        
        // This function inserts at the front
        void insertFront(Node** head_ref, int new_data)
        {
            /* 1. allocate node */
            Node* new_node = new Node();

            /* 2. put in the data */
            new_node->data = new_data;

            /* 3. Make next of new node as head
            and previous as NULL */
            new_node->next = (*head_ref);
            new_node->prev = NULL;

            /* 4. change prev of head node to new node */
            if ((*head_ref) != NULL)
                (*head_ref)->prev = new_node;

            /* 5. move the head to point to the new node */
            (*head_ref) = new_node;
        };//end of InsertFront

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function inserts after a specified node
        void insertAfter(Node* prev_node, int prev_data, int new_data)
        {
            //check if the given prev_node is NULL
            if (prev_node == NULL)
            {
                cout << "the given previous node cannot be NULL";
                return;
            }

            //allocate new node
            Node* new_node = new Node();

            //put in the data
            new_node->data = new_data;

            //setting previous node to the node you want to insert after
            while (prev_node->data != prev_data) {
                prev_node= prev_node->next;
            }

            //Make next of new node as next of prev_node
            new_node->next = prev_node->next;

            //Make the next of prev_node as new_node
            prev_node->next = new_node;

            //Make prev_node as previous of new_node
            new_node->prev = prev_node;

            //Change previous of new_node's next node
            if (new_node->next != NULL)
                new_node->next->prev = new_node;

            


        }//end of insertAfter

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function inserts at the rear
        void insertRear(Node** head_ref, int new_data)
        {
            /* 1. allocate node */
            Node* new_node = new Node();

            Node* last = *head_ref; /* used in step 5*/

            /* 2. put in the data */
            new_node->data = new_data;

            /* 3. This new node is going to be the last node, so
                make next of it as NULL*/
            new_node->next = NULL;

            /* 4. If the Linked List is empty, then make the new
                node as head */
            if (*head_ref == NULL)
            {
                new_node->prev = NULL;
                *head_ref = new_node;
                return;
            }

            /* 5. Else traverse till the last node */
            while (last->next != NULL)
                last = last->next;

            /* 6. Change the next of last node */
            last->next = new_node;

            /* 7. Make last node as previous of new node */
            new_node->prev = last;

            return;
        }//end of insertEnd

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function delets the front node
        void removeFront(Node** head_ref)
        {

            if ((*head_ref)->next != NULL) {
                //Setting head to the next node (new head)
                *head_ref = (*head_ref)->next;

                //Deleting the connection to the previous node (old head)
                (*head_ref)->prev = NULL;
            }
            else {
                cout << "cannot remove the front because there is no second node";
            }
                
        };

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function delets a specified node
        void removeNode(Node* prev_node, int delete_data)
        {
            Node* temp_node = new Node();

            //check if the given prev_node is NULL
            if (prev_node == NULL)
            {
                cout << "the given previous node cannot be NULL";
                return;
            }

            //setting previous node to the node you want to insert after
            while (prev_node->next->data != delete_data) {
                prev_node = prev_node->next;
            }

            prev_node->next = prev_node->next->next;
            
            prev_node = prev_node->next;
            
            
            prev_node->prev = prev_node->prev->prev;

            
        }//end of removeNode

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function delets the rear node
        void removeRear(Node* prev_node)
        {
            Node* temp_node = new Node();

          

            //setting previous node to the node you want to insert after
            while (prev_node->next->next != NULL) {
                prev_node = prev_node->next;
            }

            prev_node->next->data = NULL;
            
            prev_node->next = NULL;

        }//end of removeRear


        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////
     
        // This function prints all the nodes
        void printList(Node* node)
        {
            Node* last = NULL;
            cout << "\nTraversal in forward direction \n";
            while (node != NULL)
            {
                cout << node->data << "->";
                last = node;
                node = node->next;
            }

            cout << "\nTraversal in reverse direction \n";
            while (last != NULL)
            {
                cout << last->data << "<-";
                last = last->prev;
            }

        }//end of printList

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        // This function delets all nodes
        void deleteNodes(Node* node)
        {
           
            while (node->next != NULL)
            {
                node = node->next;
            }

            while (node->prev != NULL)
            {
                node->next->data = NULL;

                node->next = NULL;
            }
            
            
            

        }//end of printList

};//end of DoublyLinkedList

int main()
{
    DoublyLinkedList DLL;

    Node* head = NULL;

    DLL.insertFront(&head, 6);
    DLL.insertAfter(head, 6, 7);
    DLL.insertAfter(head, 7, 8);
    DLL.insertAfter(head, 8, 9);

   

    DLL.insertRear(&head, 2);
    DLL.insertRear(&head, 3);
    DLL.insertRear(&head, 4);

 
    //List: 6 7 8 9 2 3 4
    
    DLL.deleteNodes(head);



    DLL.printList(head);


}; // end of main

//----------Checklist----------//
//--Not perfect but runs well--//
//insert front      --working--
//insert after      --working--
//insert rear       --working--

//remove front      --working--
//remove rear       --working
//remove node       --working--

//printList         --working--
//deleteNodes       --working--