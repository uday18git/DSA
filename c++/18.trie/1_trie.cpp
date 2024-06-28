#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* links[26];
    bool flag=false;
    bool contains(char c)
    {
        return links[c-'a']!=NULL;
    }
    void put(char c,Node* node)
    {
        links[c-'a'] = node;
    }
    Node* get(char c)
    {
        return links[c-'a'];
    } 
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root; //  dummy node
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i],new Node());
            }
            // moves to reference trie , or basically moves forward
            node =  node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root; // dummy
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->contains(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */