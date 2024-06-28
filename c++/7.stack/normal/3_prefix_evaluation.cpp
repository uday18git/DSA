#include <bits/stdc++.h>
using namespace std;
// imptrnt -> we have to begin from the last

// infix expression 
// <operand><operator><operand>
// example 2+3

// prefix expression (polish notation)
// <operator><operand><operand>
// example +23

// prefix can be understood by the computer easily
// infix is easy for humans to understand


// postfix expression (reverse polish notation)
// <operand><operand><operator>
// example 23+

// precedence of operators
// 1. ()
// 1. ^
// 2. * /
// 3. + -

// associativity of operators
// 1. left to right for + - * /
// 2. right to left for ^ 
// example 2^3^4 = 2^(3^4) = 2^81 = 2417851639...

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// VERY IMPORTANT TO REMEMBER THAT WE HAVE TO REVERSE THE PREFIX EXPRESSION
// WHENEVER WE ARE DEALING WITH PREFIX EXPRESSION WE ARE MAKING IT REVERSE 
// WHETHER IT IS PREFIX EVALUTION OR CONVERSION OF INFIX TO PREFIX
// SO THERE IS EVALUATION OF PREFIX POSTFIX SIMILARY THERE IS CONVERSION OF POSTPIX AND PREFIX TO INFIX , IT IS THE SAME AS BELOW ONLY
// AND FOR POSTFIX TO PREFIX , WE HAVE TO FIRST CONVERT TO POST TO IN OR PRE TO IN THEN ONLY NEXT WE CAN CONVERT

// prefix valuation
// 1. reverse the expression
// 2. push the operands in the stack
// 3. when we get an operator pop the top 2 elements and push the result back to the stack
// 4. repeat the process till the end of the expression
// 5. the top of the stack will be the result

int prefixEvaluation(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // subtracting by 0 gives int value of the number we need.
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':

                st.push(op1 + op2);
                break;
            case '-':

                st.push(op1 - op2);

                break;
            case '*':
                st.push(op1 * op2);

                break;
            case '/':
                st.push(op1 / op2);

                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    cout << prefixEvaluation("+*423") << endl; // expected ans 25
    return 0;
}
// time complexity is o(L) where l is the length of the string
