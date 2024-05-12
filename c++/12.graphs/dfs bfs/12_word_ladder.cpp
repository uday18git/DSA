#include <bits/stdc++.h> 
using namespace std;
// i am flabbergasted by this code
#include <unordered_set>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    word[i] = ch;
                    // if it exists in the set
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

// N * word length * 26*logN


// WORD LADDER 2
// they need the full sequence 
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            //erase all the words that has been used in prev levels to transforms
            if(vec.size()>level)
            {
                level++;
                for(auto it:usedOnLevel)   
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();
            if(word==endWord)
            {
                if(ans.size()==0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(st.count(word)>0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};
// 32 TEST CASES PASSED 
