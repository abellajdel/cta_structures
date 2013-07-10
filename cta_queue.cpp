#include<iostream>
#include"cta_queue.h"
using namespace std;

template <class T>
QueueElement<T>::QueueElement(){
    data = 0;
    prev = next = NULL;
}

template <class T>
void QueueElement<T>::setData(T _data){
    data = _data;
}

template <class T>
T QueueElement<T>::getData(void){
    return data;
}


template <class T>
CTAQueue<T>::CTAQueue(){
    first = last = NULL;
}


template <class T>
void CTAQueue<T>::add(QueueElement<T> *new_element){
    if(first==NULL && last==NULL){
        new_element->next = new_element->prev = NULL;
        first = last = new_element;
    }else{
        new_element->next = NULL;
        new_element->prev = last;
        last->next = new_element;
        last = new_element;
    }
}


template <class T>
QueueElement<T>* CTAQueue<T>::remove(void){
    QueueElement<T> *return_element;

    if(first==NULL) return NULL;

    return_element = first;
    if(first->next!=NULL){
        first = first->next;
        first->prev = NULL;
    }else{
        first = NULL;
        last = NULL;
    }

    return return_element;
}
