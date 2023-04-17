//
// Created by Артём  Круглый  on 10.04.2023.
//

#ifndef OSN_LAB_BIG_1_LIST_H
#define OSN_LAB_BIG_1_LIST_H

#include <stdexcept>

template <class T>
class Node{
public:
    T data;
    Node<T>* next;

    Node<T>(T value){
        data = value;
        next = nullptr;
    }
};
template <class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    Node<T>* getNode(int index){
        if(index < 0 or index >= size){
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for(int i = 0;i < index;i++){
            current = current->next;
        }
        return current;
    }
public:
    LinkedList<T>(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(T value){
        Node<T>* newNode = new Node<T>(value);
        if(size == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T pop_front(){
        if(head == nullptr){
            throw std::out_of_range("List is empty");
        }
        Node<T>* temp = head;
        T value = head->data;
        head = head->next;
        delete temp;
        size--;
        return value;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == nullptr;
    }
    void clear(){
        while (!isEmpty()){
            pop_front();
        }
    }

    ~LinkedList<T>() {
        clear();
    }

    void removeAt(int index){
        if(index < 0 or index >= size){
            throw std::out_of_range("Index out of range");
        }
        if(size == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else if(index == 0){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }else if(index == size-1){
            Node<T>* temp = getNode(index - 1);
            delete tail;
            tail = temp;
            tail->next = nullptr;
        } else{
            Node<T>* prev = getNode(index - 1);
            Node<T>* temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }
        size--;
    }

    T at(int index){
        return getNode(index)->data;
    }
};

#endif //OSN_LAB_BIG_1_LIST_H
