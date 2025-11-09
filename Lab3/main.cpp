#include<iostream>
#include"templates/priority_queue.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue* px = new priority_queue();

    px->push(10);
    px->push(67);
    px->push(100);

    priority_queue* py = px;

    cout << px->pop() << endl;
    cout << px->pop() << endl;
    cout << px->pop() << endl;

    cout << py->pop() << endl;
    cout << py->pop() << endl;
    cout << py->pop() << endl;

    priority_queue* pz = new priority_queue();

    pz->push(1);

    cout << pz->pop() << endl;
    cout << pz->pop() << endl;

    return 0;
}
