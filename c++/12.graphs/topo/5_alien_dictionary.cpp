string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>> graph(k);
    for(int i=0;i<dictionary.size()-1;i++)
    {
        int j=0;
        int k=0;
        while(j<dictionary[i].size() && k<dictionary[i+1].size())
        {
            if(dictionary[i][j]==dictionary[i+1][k])
            {
                j++;
                k++;
            }
            else 
            {
                graph[dictionary[i][j]-'a'].push_back(dictionary[i+1][k] - 'a');
                break;
            }
        }

    }
    vector<int> indegree(k);
    queue<int> q;
    for(int i=0;i<k;i++)
    {
        for(auto it : graph[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i:graph[node])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);

            }
        }
    }
    string order;
    for(int i=0;i<ans.size();i++)
    {
        char c = 'a' + ans[i];
        order += c;
    }
    return order;
}
// crazy question
// once u made off graph its game over
//  you have to make graph like check one string and next string 
// compare each letter and if they are not equal then first char points to second char
// after that it is just topological sort , i donno how i did it in first attempt
