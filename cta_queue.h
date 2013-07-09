#include<iostream>
using namespace std; 


class QueueElement{
    int data;
    public:
        QueueElement *next, *prev;
        QueueElement();
        void setData(int _data);
        int getData(void);
};

class CTAQueue{
    public:
        QueueElement *first, *last;
        CTAQueue();
        void add(QueueElement *new_element);
        QueueElement* remove(void);
};
