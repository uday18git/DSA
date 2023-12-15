// #include <bits/stdc++.h>

// using namespace std;

//imptrnt -> we have to begin from the last
// int prefixEvaluation(string s)
// {
//     stack<int> st;
//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             st.push(s[i] - '0'); // subtracting by 0 gives int value of the number we need.
//         }
//         else
//         {
//             int op1 = st.top();
//             st.pop();
//             int op2 = st.top();
//             st.pop();
//             switch (s[i])
//             {
//             case '+':

//                 st.push(op1 + op2);
//                 break;
//             case '-':

//                 st.push(op1 - op2);

//                 break;
//             case '*':
//                 st.push(op1 * op2);

//                 break;
//             case '/':
//                 st.push(op1 / op2);

//                 break;
//             case '^':
//                 st.push(pow(op1, op2));
//                 break;
//             }
//         }
//     }
//     return st.top();
// }
// int main()
// {
//     cout << prefixEvaluation("-+7*45+20") << endl; // expected ans 25
//     return 0;
// }
// time complexity is o(L) where l is the length of the string
