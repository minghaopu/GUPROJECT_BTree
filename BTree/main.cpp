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
    string inputFilePath = argv[1];
    string dictionaryFilePath = argv[2];
    string removalFilePath = argv[3];
    
    BTree tree(dictionaryFilePath);
    
//    for (int i = 6; i <= 20; i+= 2) {
//        tree.setChildrenNumber(i);
//        tree.fileCheck(inputFilePath);
//    }
    cout<<"---------------- B Tree ----------------"<<endl;
    if (tree.empty()) {
        cout<<"The dictionary file path is wrong"<<endl;
    } else{
        cout<<"\n---------------- file check before removal ----------------"<<endl;
        tree.fileCheck(inputFilePath);
        tree.removeAll(removalFilePath);
        cout<<"\n---------------- file check after removal ----------------"<<endl;
        tree.fileCheck(inputFilePath);
    }
    
    cout<<"\n\n---------------- link list ----------------\n"<<endl;
    
    List list(dictionaryFilePath);
    if (list.empty()) {
        cout<<"The dictionary file path is wrong"<<endl;
    } else{
        cout<<"\n---------------- file check before removal ----------------"<<endl;
        list.fileCheck(inputFilePath);
        list.removeAll(removalFilePath);
        cout<<"\n---------------- file check after removal ----------------"<<endl;
        list.fileCheck(inputFilePath);
    }
    return 0;
}
