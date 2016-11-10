//
//  BTree.hpp
//  BTree
//
//  Created by roneil on 11/9/16.
//  Copyright © 2016 gu. All rights reserved.
//

#ifndef BTree_hpp
#define BTree_hpp

#include "Header.h"

#define M 4;

struct BTNode {
    int num;
    bool isLeaf;
    vector<pair<string, int> > keys;        // store the word and its frequency

    vector<BTNode*> children;
    BTNode(int nodeSize, int childSize) : num(0), isLeaf(true), keys(nodeSize, pair<string, int> ("", 0)) , children(childSize, NULL)  {}
};

class BTree {
private:
    BTNode* _root = NULL;
    int _M = M;
    int _nodeSize = _M - 1;
    int _childSize = _M;
    int _height = 0;
    int _maxCount = 0;
    string _maxCountWord = "";
public:
    BTree(string path);
    bool search(string word);
    bool searchNode(BTNode* node, const string word);
    void insert(string word);
    void remove(string word);
    void splitNode(BTNode* node, int index);
    void insertNotFull(BTNode* node, const string word);
    void fileCheck(string filePath);
    int height();
    bool empty();
    ~BTree() {};
};
#endif /* BTree_hpp */
