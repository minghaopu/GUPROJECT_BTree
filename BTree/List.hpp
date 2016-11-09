//
//  List.hpp
//  BTree
//
//  Created by roneil on 11/8/16.
//  Copyright © 2016 gu. All rights reserved.
//

#ifndef List_hpp
#define List_hpp


#include "Header.h"
struct ListNode {
    string val;
    ListNode * next;
    int count;
    ListNode(string x) : val(x), count(0), next(NULL) {}
};

class List {
private:
    ListNode* _head;
    ListNode* _last;
    int _total = 0;
    int _maxCount = 0;
    string _maxCountWord = "";
public:
    List(string path);
    bool search(string word);
    void add(string word);
    void remove(string word);
    void fileCheck(string filePath);
    int size();
    bool empty();
    ~List() {
        ListNode* p = _head;
        ListNode* next;
        while (p) {
            next = p->next;
            delete p;
            p = next;
        }
        _head = NULL;
        _last = NULL;
    };
};

#endif /* List_hpp */
