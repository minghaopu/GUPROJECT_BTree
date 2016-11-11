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
#define DEGREE 2;

struct BTNode {
    int num;                                // actually number of nodes
    bool isLeaf;                            // whether the node is a leaf
    vector<pair<string, int> > keys;        // store the word and its frequency
    vector<BTNode*> children;
    BTNode(int nodeSize, int childSize) : num(0), isLeaf(true), keys(nodeSize, pair<string, int> ("", 0)) , children(childSize, NULL)  {}
};

class BTree {
private:
    int _degree = DEGREE;
    BTNode* _root = NULL;
    int _M = M;
    int _nodeSize = _M - 1; // maximum node size
    int _childSize = _M;    // maximum children size
    int _maxCount = 0;
    string _maxCountWord = "";
    string _path = "";      //dictionary file path
public:
    BTree(string inputFilePath);
    void init();
    bool search(string word);
    bool searchNode(BTNode* node, const string word);
    void insert(string word);
    void remove(string word);
    void splitNode(BTNode* node, int index);
    void insertNotFull(BTNode* node, const string word);
    void fileCheck(string filePath);
    void setChildrenNumber(int childrenNumber);     // childrenNumber must be even nubmer
    void clear();
    void recursiveClear(BTNode* node);
    void deleteNode(BTNode* node);
    pair<string, int> getPredecessor(BTNode* node);
    pair<string, int> getSuccessor(BTNode* node);
    void mergeChildren(BTNode* parent, int index);
    bool empty();
    void recursiveRemove(BTNode* node, const string word);
    void removeAll(string path);
    void printTree();
    void findParentNode(BTNode* node);
    void fillNode(BTNode* node, int index);
    ~BTree() {
        clear();
    };
};
#endif /* BTree_hpp */
