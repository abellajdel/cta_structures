#include<iostream>
#include"cta_queue.h"
using namespace std;

int main()
{
    int i;
    QueueElement *read_el;
    cout << "Got to the main function" << endl;
    CTAQueue *wq = new CTAQueue();
    for(i=0; i<100; i++){
        QueueElement *qe = new QueueElement();        
        qe->setData(i);
        wq->add(qe);
    }

    while(wq->first!=NULL){
        read_el = wq->remove();
        cout << "The value of the element is " << read_el->getData() << endl;
        delete read_el;
    }

    return 0;
}

