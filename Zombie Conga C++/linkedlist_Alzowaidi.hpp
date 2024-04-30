/*
Author: Medo
Date: 04/19/2023
Description: Double linked list class and node class
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef NODE
#define NODE

template <class T>
class Node
{
private:
        T data;
        Node<T> *next;
        Node<T> *previous;

public:
        // declare constructors
        Node()
        {
                this->data = T();
                this->next = NULL;
                this->previous = NULL;
        }

        Node(T data)
        {
                this->data = data;
                this->next = NULL;
                this->previous = NULL;
        }

        Node(T data, Node *next)
        {
                this->data = data;
                this->next = next;
                this->previous = NULL;
        }

        ~Node()
        {
        }
        // forward declaration for the Node methods
        T getData();
        void setData(T);
        Node<T> *getNext();
        void setNext(Node *);
        Node<T> *getPrevious();
        void setPrevious(Node *);
};
// reterieve data
template <class T>
T Node<T>::getData()
{
        return this->data;
}
// set data
template <class T>
void Node<T>::setData(T d)
{
        this->data = d;
}
// retrieve the next node
template <class T>
Node<T> *Node<T>::getNext()
{
        return this->next;
}
// set the next node
template <class T>
void Node<T>::setNext(Node<T> *node)
{
        this->next = node;
}
// retrieve the previous node
template <class T>
Node<T> *Node<T>::getPrevious()
{
        return this->previous;
}
// set the previous node
template <class T>
void Node<T>::setPrevious(Node<T> *node)
{
        this->previous = node;
}

#endif // NODE
// LinkedList class ---------------------------------
#ifndef LINKEDLIST
#define LINKEDLIST

template <class T>
class LinkedList
{

public:
        Node<T> *head;
        Node<T> *tail;
        int length;
        // declare class constructor
        LinkedList<T>()
        {
                head = NULL;
                tail = NULL;
                length = 0;
        }
        // declare class deconstructor
        ~LinkedList<T>()
        {
                Empty();
        }
        // forward declaration for the class methods
        void AddToFront(T);
        void AddToEnd(T);
        void AddAtIndex(T, int);
        void AddBefore(Node<T> *, T);
        void AddAfter(Node<T> *, T);
        T RemoveFromFront();
        T RemoveFromEnd();
        void RemoveTheFirst(T);
        void RemoveAllOf(T);
        T RemoveBefore(Node<T> *);
        T RemoveAfter(Node<T> *);
        bool ElementExists(T);
        Node<T> *Find(T);
        int IndexOf(T);
        T RetrieveFront();
        T RetrieveEnd();
        T Retrieve(int);
        void PrintList();
        void Empty();
        int Length();
};
// Make the node as head node
template <class T>
void LinkedList<T>::AddToFront(T data)
{
        Node<T> *node = new Node<T>(data);

        if (head == NULL)
        {
                head = node;
                tail = head;
                tail->setNext(NULL);
                head->setPrevious(NULL);
                length++;
        }
        else
        {
                node->setNext(head);
                head->setPrevious(node);
                head = node;
                head->setPrevious(NULL);
                length++;
        }
}
// make node as the tail node
template <class T>
void LinkedList<T>::AddToEnd(T data)
{

        if (head == NULL)
        {
                Node<T> *node = new Node<T>(data);
                head = node;
                tail = head;
                tail->setNext(NULL);
                head->setPrevious(NULL);
                length++;
        }
        else
        {
                Node<T> *node = new Node<T>(data);
                node->setPrevious(tail);
                tail->setNext(node);
                tail = node;
                length++;
        }
}
// add node to certain index
template <class T>
void LinkedList<T>::AddAtIndex(T data, int index)
{
        if (index > length || index < 0)
        {
                throw range_error("Error: invalid index has been entered");
        }
        else if (index == 0)
        {
                AddToFront(data);
        }
        else if (index == length)
        {
                AddToEnd(data);
        }
        else
        {
                Node<T> *current = head;
                int count = 0;
                // loop though the linked list until you reach the node before the index
                while (count < index - 1)
                {
                        current = current->getNext();
                        count++;
                }
                Node<T> *node = new Node<T>(data, current->getNext());
                node->setPrevious(current);
                current->setNext(node);
                node->getNext()->setPrevious(node);
                length++;
        }
}
// add before certain node
template <class T>
void LinkedList<T>::AddBefore(Node<T> *node, T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        if (node == NULL)
        {
                cout << "ERROR: Node with null value has been entered" << endl;
        }
        else if (node == head)
        {
                AddToFront(data);
        }
        else
        {
                Node<T> *newCurrentNode = new Node<T>(data, node);
                newCurrentNode->setPrevious(node->getPrevious());
                newCurrentNode->getPrevious()->setNext(newCurrentNode);
                node->setPrevious(newCurrentNode);

                length++;
        }
}
// add after certain node
template <class T>
void LinkedList<T>::AddAfter(Node<T> *node, T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        if (node == NULL)
        {
                cout << "ERROR: Node with null value has been entered" << endl;
        }
        else if (node == tail)
        {
                AddToEnd(data);
        }
        else
        {
                Node<T> *newCurrentNode = new Node<T>(data);
                newCurrentNode->setNext(node->getNext());
                newCurrentNode->getNext()->setPrevious(newCurrentNode);
                node->setNext(newCurrentNode);
                newCurrentNode->setPrevious(node);
                length++;
        }
}
// remove the head and decrease list size
template <class T>
T LinkedList<T>::RemoveFromFront()
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                Node<T> *nextNode = head;
                T result = head->getData();
                head = head->getNext();
                head->setPrevious(NULL);
                delete nextNode;
                length--;

                return result;
        }
}
// remove the tail and decrease list size
template <class T>
T LinkedList<T>::RemoveFromEnd()
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                Node<T> *prevNode = tail;
                T result = tail->getData();
                tail = prevNode->getPrevious();
                tail->setNext(NULL);
                delete prevNode;
                length--;

                return result;
        }
}
// check if the node exist and remove the node from the linkedlist
template <class T>
void LinkedList<T>::RemoveTheFirst(T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                if (head->getData() == data)
                {
                        RemoveFromFront();
                }
                else
                {
                        if (Find(data) == NULL)
                        {
                                throw out_of_range("Node is not in the list..");
                        }
                        Node<T> *node = Find(data);
                        if (tail == node)
                        {
                                RemoveFromEnd();
                        }
                        else
                        {
                                Node<T> *nextNode = node->getNext();
                                Node<T> *prevNode = node->getPrevious();
                                nextNode->setPrevious(prevNode);
                                prevNode->setNext(nextNode);
                                delete node;
                                length--;
                        }
                }
        }
}
// remove all the instances of a node
template <class T>
void LinkedList<T>::RemoveAllOf(T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                // keep calling the remove first method until all the data has been removed from the list
                while (Find(data) != NULL)
                {
                        RemoveTheFirst(data);
                }
        }
}
// remove before certain node
template <class T>
T LinkedList<T>::RemoveBefore(Node<T> *node)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        if (!ElementExists(node->getData()))
        {
                return T();
        }
        else
        {
                if (head == node)
                {
                        return T();
                }
                else if (head->getNext() == node)
                {
                        T result = head->getData();
                        RemoveFromFront();
                        return result;
                }
                else if (tail == node)
                {
                        Node<T> *prevNode = tail->getPrevious();
                        tail->setPrevious(prevNode->getPrevious());
                        prevNode->getPrevious()->setNext(tail);
                        T result = prevNode->getData();
                        delete prevNode;
                        length--;
                        return result;
                }
                else
                {
                        Node<T> *beforeNode = node->getPrevious();
                        Node<T> *nextNode = beforeNode->getNext();
                        Node<T> *prevNode = beforeNode->getPrevious();
                        nextNode->setPrevious(prevNode);
                        prevNode->setNext(nextNode);
                        T result = beforeNode->getData();
                        delete beforeNode;
                        length--;
                        return result;
                }
        }
        return T();
}
// remove after certain node
template <class T>
T LinkedList<T>::RemoveAfter(Node<T> *node)
{

        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        if (!ElementExists(node->getData()))
        {
                return T();
        }
        else
        {
                if (tail == node)
                {
                        return T();
                }
                else if (tail->getPrevious() == node)
                {
                        T result = tail->getData();
                        RemoveFromEnd();
                        return result;
                }
                else if (head == node)
                {
                        Node<T> *nextNode = head->getNext();
                        head->setNext(nextNode->getNext());
                        T result = nextNode->getData();
                        delete nextNode;
                        length--;
                        return result;
                }
                else
                {

                        Node<T> *nextNode = node->getNext();
                        nextNode->getNext()->setPrevious(node);
                        node->setNext(nextNode->getNext());
                        T result = nextNode->getData();
                        delete nextNode;
                        length--;
                        return result;
                }
        }
        return T();
}
// check if the elemnt exists in the list
template <class T>
bool LinkedList<T>::ElementExists(T data)
{

        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                if (Find(data) != NULL)
                {
                        return true;
                }
        }
        return false;
}
// return the wanted node if it doesn't exist return NULL
template <class T>
Node<T> *LinkedList<T>::Find(T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                Node<T> *current = head;
                while (current != NULL)
                {
                        if (current->getData() == data)
                        {
                                return current;
                        }
                        current = current->getNext();
                }
        }
        return NULL;
}
// fint index of first instance
template <class T>
int LinkedList<T>::IndexOf(T data)
{
        if (head == NULL)
        {
                throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                int index = 0;
                Node<T> *current = head;
                while (current != NULL)
                {
                        if (current->getData() == data)
                        {
                                return index;
                        }
                        current = current->getNext();
                        index++;
                }
        }

        return -1;
}
// retrieve the head
template <class T>
T LinkedList<T>::RetrieveFront()
{
        if (head == NULL)
        {
                throw out_of_range("Error: 12the list does not contain any element");
        }
        else
        {
                return head->getData();
        }
}
// retrieve the tail
template <class T>
T LinkedList<T>::RetrieveEnd()
{
        if (head == NULL)
        {
                throw out_of_range("Error: 13the list does not contain any element");
        }
        else
        {
                return tail->getData();
        }
}
// retrieve instance of certain data
template <class T>
T LinkedList<T>::Retrieve(int index)
{
        if (index >= length || index < 0)
        {
                throw out_of_range("Error: Index is less than zero or greater than the length of list");
        }
        if (head == NULL)
        {
                throw out_of_range("Error: 14the list does not contain any element");
        }
        else
        {
                int count = 0;
                Node<T> *current = head;
                while (current != NULL)
                {
                        if (count == index)
                        {
                                return current->getData();
                        }
                        current = current->getNext();
                        count++;
                }
        }
        return T();
}
// print all the nodes of the list
template <class T>
void LinkedList<T>::PrintList()
{
        try
        {
                if (head == NULL)
                {
                        throw out_of_range("Error: the list does not contain any element");
                }
                else
                {
                        Node<T> *current = head;
                        while (current != NULL)
                        {
                                if (current->getNext() != NULL)
                                {
                                        cout << current->getData() << "=";
                                }
                                else
                                {
                                        cout << current->getData();
                                }
                                current = current->getNext();
                        }
                        cout << "\n";
                }
        }
        catch (const std::out_of_range &e)
        {
                std::cerr << e.what() << '\n';
        }
}
// empety the list from all nodes
template <class T>
void LinkedList<T>::Empty()
{
        if (head == NULL)
        {
                // throw out_of_range("Error: the list does not contain any element");
        }
        else
        {
                Node<T> *current = head;
                while (current != NULL)
                {
                        Node<T> *removedNode = current;
                        current = current->getNext();
                        delete removedNode;
                        length--;
                }
                head = NULL;
                tail = NULL;
        }
}
// get the length of the list
template <class T>
int LinkedList<T>::Length()
{
        return length;
}

#endif // LINKEDLIST