//
// Created by fly on 2022/4/1.
//


#include "link_cpp.h"
#include <iostream>

using namespace std;

int main() {
////    link<int> head(1);
//
    link<int> head2 = {1,2,3,4};
    link<int> head3 = {5,6,7,8};
    head2.print();
    head2 += head3;
    cout<<endl;
    head2.print();
    cout<<endl;
    head2.insert(4, 10);
    head2.erase(5);
    head2.pop_back();
    cout<<head2.size()<<endl;
    link<int> head4(head2);
    head4.print();
    cout<<endl;
    link<int> head5;
    head5.push_back(1);
    head5.print();
    cout<<"hello world\n" ;

}