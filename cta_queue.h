#include<iostream>
using namespace std; 

template <class T> 
class QueueElement{
    T data;
    public:
        QueueElement *next, *prev;
        QueueElement(){
            prev = next = NULL;
        };

        void setData(T _data){
            data = _data;
        };

        T getData(void){
            return data;
        };
};


template <class T> 
class CTAQueue{
    public:
        QueueElement<T> *first, *last;
        CTAQueue(){
            first = last = NULL;
        };

        void add(QueueElement<T> *new_element){
            if(first==NULL && last==NULL){
                new_element->next = new_element->prev = NULL;
                first = last = new_element;
            }else{
                new_element->next = NULL;
                new_element->prev = last;
                last->next = new_element;
                last = new_element;
            }
        };

        QueueElement<T>* remove(void){
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
};
