// comparing
// when you are comparing s[i] you should compare it with a char as it is a char

// reverse
// reverse function reverse(str.begin(),str.end())

// insert
// insert function str1.insert(pos,str2)
// Yes, you can use the `+=` operator to append a string at the back of another string in C++. Here's an example:
// In this example, `originalString += appendString;` appends the content of `appendString` to the end of `originalString`. After this operation, `originalString` will contain "Hello, world!".
// ans+= string(freq, c) this constructor of string is used to create a string which is made by repeating the character c freq times.

// convert char to int
// to convert '1' to 1 int digit = s[i] - '0';
// s[i]-'a' converts suppose s[i]='a' gives 0


// int main() {
//     char ch = 'A';
//     std::string str(1, ch); // Construct string from 1 character
//     std::cout << "String: " << str << std::endl;
//     return 0;
// }


// substring
// substr (pos,len)
// if(t.substr(i,5)==s) can compare like this

// convert int to string
// to convert a int to a string -> to_string

// In C++, you can convert a string to an integer using the stoi (string to integer) function.

// In C++, istringstream is a class defined in the <sstream> header, and it stands for "input string stream."
// It is part of the C++ Standard Library and is used for parsing strings as if they were input streams
// istringstream is input string stream

// length
// ip.length() ip.size() both work enjoy

// convert to upper case
// toupper(char) works

// to get the max element in a string
// char m = *max_element(s.begin()+start+1,s.end());

// to compare
// s.compare(s1) gives positive if s>s1 , gives 0  if equal , gives -ve if s<s1



// class Solution {
// public:
//     char repeatedCharacter(string s) {
//         int n=s.length();
//         vector<int>visited(27,0);
//         for(int i=0;i<n;i++)
//         {
//             if(visited[s[i]-'a'])
//             {
//                 return s[i];
//             }
//             else
//             {
//                 visited[s[i]-'a']=1;
//             }
//         }
        
//         return 'a';
//     }
// };



// ascii value of A is 65 and a is 97 so the difference is 32
// class Solution {
// public:
//     int countKeyChanges(string s) {
//         int n=s.size();
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             while(i<n-1 && (s[i]==s[i+1] || s[i]==s[i+1]+32 || s[i]==s[i+1]-32 ))i++;
//             ans++;
            
//         }
//         return ans-1;
//     }
// };