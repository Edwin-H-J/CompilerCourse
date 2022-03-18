//
// Created by Mac on 17/03/2022.
//

#ifndef REGEX2DFA_DFA_H
#define REGEX2DFA_DFA_H
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <memory>
#include <queue>
#include <functional>
#include "NFA.h"

using NFAMap = std::unordered_map<int,std::unordered_map<char,std::vector<int>>>;
using charset = std::unordered_set<char>;
using Edges = std::vector<std::unordered_map<char, int>>;
class customHash
{
public:
    std::size_t operator() (std::set<int> const& a) const;
};

class DFA {
public:
    DFA(NFAMap& mp,charset& cst,int start,int end);
    DFA(NFA& n);
    friend std::ostream& operator<< (std::ostream& out,DFA& A);
    bool judge(std::string s);
private:
    Edges edges;
    std::unordered_set<int> finalStatus;
    int status = 0;
    std::set<int> epsilon_closure(std::set<int> &&src, NFAMap& mp);
    std::set<int> move(std::set<int> src, char by, NFAMap &mp);
    void create(NFAMap& mp,charset& cst,int start,int end);
    void minor(charset &cst);
    void clearDeadNode(charset &cst, Edges &edges, int start, int &status, std::unordered_set<int>& finalStatus);
};


#endif //REGEX2DFA_DFA_H
