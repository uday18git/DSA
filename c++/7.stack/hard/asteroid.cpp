// so i thought like there are 3 cases for stacks top and incoming asteroid[i], both are positive , both are negative, and one neg one pos
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<n;i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
                continue;
            }
            else if((st.top()>0 && asteroids[i]>0) || (st.top()< 0 &&asteroids[i]<0 ))
            {    
                st.push(asteroids[i]);
            }
            else
            {
                if(st.top()>0) // only condition when colission will happen
                {   
                    while(!st.empty() && st.top()>0 && (st.top()+asteroids[i]<0))
                    {
                        st.pop();
                    }
                    if(!st.empty() && st.top()+asteroids[i]==0)
                    {
                        st.pop();
                        continue;
                    }
                    if(st.empty() || st.top()<0)
                    {
                        st.push(asteroids[i]);
                    }
                }
                else
                {
                    st.push(asteroids[i]);
                }
                
                // else if(st.top()+asteroids[i]<0)
                // {
                //     st.pop();
                // }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



// flop attempt, try to think in specific cases and try to cover all cases instead of bullshitting as done below
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int> st;
//         int n=asteroids.size();
//         st.push(asteroids[0]);
//         for(int i=1;i<n;i++)
//         {
//             if(asteroids[i]+st.top() == 0)
//             {
//                 st.pop();
//             }
//             if(!st.empty() && asteroids[i]+st.top()>0)
//             {
//                 if(asteroids[i]>0)
//                 {
//                     st.push(asteroids[i]);
//                 }
//                 else
//                 {
//                     continue;
//                 }
//             }
//             if(asteroids[i]>0)
//             {
//                 while(!st.empty() && (st.top() + asteroids[i]<0))
//                 {
//                     st.pop();
//                 }
//             }
//             else
//             {
//                 st.push(asteroids[i]);
//             }
            
//         }
//         vector<int> ans;
//         while(!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };