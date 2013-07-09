#include<iostream>
#include"cta_queue.h"
using namespace std;


QueueElement::QueueElement(){
    data = 0;
    prev = next = NULL;
}


void QueueElement::setData(int _data){
    data = _data;
}


int QueueElement::getData(void){
    return data;
}



CTAQueue::CTAQueue(){
    first = last = NULL;
}


void CTAQueue::add(QueueElement *new_element){
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


QueueElement* CTAQueue::remove(void){
    QueueElement *return_element;

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
