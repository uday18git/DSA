#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1);
        istringstream iss2(version2);
        int v1;
        int v2;
        char dotChar;
        while(bool(iss1>>v1) + bool(iss2>>v2))
        {
            if(v1<v2)
                return -1;
            if(v1>v2)
                return 1;
            iss1>>dotChar;
            iss2>>dotChar;
            v1=0;
            v2=0;
        }
        return 0;
    }
};

// istringstream iss1(version1); and istringstream iss2(version2);:
//  Two istringstream objects are created to treat the input strings version1 and version2 as streams,
//  allowing for easy extraction of version numbers.
// Initialization: iss1 and iss2 are istringstream objects created from the input strings "1.01" and "1.001", respectively. v1 and v2 are variables to store the version components, and dotChar is a character to store the dot between version components.

// Comparison Loop: The loop compares version components until there are no more versions in either string. The loop considers both iss1 and iss2, and the comparison is done for each version component.

// In the first iteration:

// iss1 >> v1 reads "1" from "1.01".
// iss2 >> v2 reads "1" from "1.001".
// Since v1 and v2 are equal, it moves to the next iteration.
// In the second iteration:

// iss1 >> dotChar reads "." from "1.01".
// iss2 >> dotChar reads "." from "1.001".
// v1 and v2 are reset to 0.
// In the third iteration:

// iss1 >> v1 reads "01" from "1.01".
// iss2 >> v2 reads "001" from "1.001".
// Since v1 is less than v2 ("01" is numerically less than "001"), the function returns -1.
// Result: The result of comparing "1.01" and "1.001" is -1, indicating that "1.01" is considered less than "1.001" in version comparison.