#include<iostream>
#include<time.h>
#include"cta_queue.h"
using namespace std;

int main()
{
    int i;
    QueueElement<int> *read_el;
    cout << "Got to the main function" << endl;
    CTAQueue<int> *wq = new CTAQueue<int>();
    for(i=0; i<100; i++){
        QueueElement<int> *qe = new QueueElement<int>;        
        qe->setData(i);
        clock_t tic = clock();
        wq->add(qe);
        clock_t toc = clock();
        cout << "It took " << (double)(toc - tic) << " to add the element number " << i << endl;
    };

    while(wq->first!=NULL){
        clock_t remove_tic = clock();
        read_el = wq->remove();
        clock_t remove_toc = clock();
        cout << "The value of the element is " << read_el->getData() << " it took " << (double)(remove_toc - remove_tic) << " to remove" <<endl;
        delete read_el;
    }

    return 0;
}
