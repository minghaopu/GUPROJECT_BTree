//
//  BTree.cpp
//  BTree
//
//  Created by roneil on 11/9/16.
//  Copyright © 2016 gu. All rights reserved.
//

#include "BTree.hpp"

BTree::BTree(string path) {
    string testPath = "/Users/roneil/Project/GUPROJECT_BTree/p/Files/dictionaryFile.txt";
    ifstream inputData(testPath);
    string content((istreambuf_iterator<char>(inputData)),(istreambuf_iterator<char>()));
    replace_if(content.begin() , content.end(),
               [] (const char& c) { return c == '\r' ;},'\n');
    stringstream ss;
    
    string word;
    if (content != "") {
        
        ss.str(content);
        while (getline(ss, word)) {
            if (word != "") {
                insert(toUpper(word));
            }
        }
    }
}
void BTree::insert(string word) {
    if (_root == NULL) {
        _root = new BTNode(_nodeSize, _childSize);
        insertNotFull(_root, word);
    } else {
        if (_root->num == _nodeSize) {
            BTNode* r = _root;
            BTNode* p = new BTNode(_nodeSize, _childSize);
            _root = p;
            p->isLeaf = false;
            p->children[0] = r;
            splitNode(p, 0);
            insertNotFull(p, word);
        } else {
            insertNotFull(_root, word);
        }
    }
}
void BTree::remove(string word) {
    
}
void printVector(vector<pair<string,int>> v) {
    cout<<"-----------------------------"<<endl;
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i].first<<endl;
    }
}
void BTree::insertNotFull(BTNode *node, const string word) {
    int index = node->num - 1;
    
    if (node->isLeaf) {
        while (index >= 1 && word < node->keys[index].first) {
            node->keys[index] = node->keys[index - 1];
            index--;
        }
        node->keys[index + 1].first = word;
        node->keys[index + 1].second = 0;
        node->num++;
//        printVector(node->keys);
    } else {
        while (index >= 0 && word < node->keys[index].first) index--;
        index++;
        BTNode *child = node->children[index];
        if (child->num == _nodeSize) {
            splitNode(node, index);
            if (word > node->keys[index].first) index++;
        }
        insertNotFull(node->children[index], word);
    }
}
void BTree::splitNode(BTNode *node, int index) {
    BTNode* p = new BTNode(_nodeSize,_childSize);
    BTNode* child = node->children[index];
    p->isLeaf = child->isLeaf;
    p->num = _degree - 1;
    for (int i = 0; i < _degree - 1; i++) {
        
        p->keys[i] = child->keys[i + _degree];
        child->keys[i + _degree].first = "";
        child->keys[i + _degree].second = 0;
    }
    if (!child->isLeaf) {
        for (int i = 0; i < _degree; i++) {
            p->children[i] = child->children[i + _degree];
            child->children[i + _degree] = NULL;
        }
    }
    child->num = _degree - 1;
    for (int i = node->num; i > index; i--) {
        node->children[i + 1] = node->children[i];
    }
    node->children[index + 1] = p;
    for (int i = node->num - 1; i >= index; i--) {
        node->keys[i+1] = node->keys[i];
    }
    node->keys[index] = child->keys[_degree - 1];
    child->keys[_degree - 1].first = "";
    child->keys[_degree - 1].second = 0;
    node->num++;
}

bool BTree::search(string word) {
    if (_root == NULL) return false;
    bool res = searchNode(_root, word);
    return res;
}
bool BTree::searchNode(BTNode* node, const string word) {
    int i = 0;
    while (i < node->num && word > node->keys[i].first) {
        i++;
    }
    if (i < node->num && word == node->keys[i].first) {
        node->keys[i].second++;
        if (node->keys[i].second > _maxCount) {
            _maxCount = node->keys[i].second;
            _maxCountWord = node->keys[i].first;
        }
        return true;
    } else if (node->isLeaf) return false;
    else {
        return searchNode(node->children[i], word);
    }
}
void BTree::fileCheck(string filePath) {
    clock_t timeBegin, timeEnd;
    double totalTime = 0.0;
    timeBegin = clock();
    
    string testPath = "/Users/roneil/Project/GUPROJECT_BTree/p/Files/inputFile1.txt";
    ifstream inputData(testPath);
    string content((istreambuf_iterator<char>(inputData)),(istreambuf_iterator<char>()));
    
    replace_if(content.begin() , content.end(),
               [] (const char& c) { return ispunct(c) ;},' ');
    replace_if(content.begin() , content.end(),
               [] (const char& c) { return c == '\r' || c == '\n' ;},' ');
    
    stringstream ss;
    string word;
    ss.str(content);
    
    _maxCount = 0;
    _maxCountWord = "";
    
    int misSpell = 0;
    while (getline(ss, word, ' ')) {
        if (word == "") continue;
        string t = toUpper(word);
        if (search(t) == false) {
            misSpell++;
        }
    }
    
    timeEnd = clock();
    totalTime = (double)(timeEnd - timeBegin)/CLOCKS_PER_SEC;
    
    cout << "Total number of misspelled word: " << misSpell << endl
    << "The highest frequency of occurrence: " << _maxCountWord << endl
    << "The highest frequency word: " << _maxCount<<endl;
    cout << "Total (approx) runtime is " << totalTime << endl;
}
