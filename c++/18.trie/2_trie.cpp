#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    // bool flag=false;
    int cntPrefix =0;
    int cntEndWith=0;

    bool containsKey(char c)
    {
        return (links[c-'a']!=NULL);
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char c,Node* node)
    {
        links[c-'a'] = node;
    }
    
    void increasePrefix()
    {
        cntPrefix++;
    }
    void increaseEndsWith()
    {
        cntEndWith++;
    }
    void decreasePrefix()
    {
        cntPrefix--;
    }
    void decreaseEndWith()
    {
        cntEndWith--;
    }
};

class Trie{
    private:Node* root;
    public:

    Trie(){
        
        root=new Node();
    }

    void insert(string &word){
        
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndsWith(); //  last node will have increase ends with so that we know that word ended there
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->cntPrefix;
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if (node->containsKey(word[i])) 
            {
                node->decreasePrefix();
                node = node->get(word[i]);
            } 
            else 
            {
                return;
            }
        }
        node->decreaseEndWith();
    }
};
