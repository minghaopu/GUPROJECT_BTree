//
//  main.cpp
//  BTree
//
//  Created by roneil on 11/8/16.
//  Copyright © 2016 gu. All rights reserved.
//


#include "List.hpp"
#include "BTree.hpp"
int main(int argc, const char * argv[]) {
    cout<<"List Search"<<endl;
    List l("abf");
    l.fileCheck("ac");
    cout<<"\n-----------------------------\n\n";
    cout<<"BTree Search"<<endl;
    BTree b("af");
    b.fileCheck("dsfa");
    return 0;
}
