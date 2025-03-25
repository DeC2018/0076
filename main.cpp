#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        // Create a frequency count array for ASCII characters
        std::vector<int> count(128);
        
        // Initialize required characters count to length of string t
        int required = t.length();
        
        // Initialize best left and minimum length to invalid values
        int bestLeft = -1;
        int minLength = s.length() + 1;

        // Count frequency of characters in string t
        for (const char c : t) {
            ++count[c];
        }

        // Initialize two pointers, l and r, to start of string s
        for (int l = 0, r = 0; r < s.length(); ++r) {
            // If current character at r is in t, decrement required count
            if (--count[s[r]] >= 0) {
                --required;
            }
            
            // If all characters in t are found in current window
            while (required == 0) {
                // Update minimum length and best left if current window is smaller
                if (r - l + 1 < minLength) {
                    bestLeft = l;
                    minLength = r - l + 1;
                }
                
                // If current character at l is in t, increment required count
                if (++count[s[l++]] > 0) {
                    ++required;
                }
            }
        }

        // Return minimum window substring if found, otherwise return empty string
        return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::string s1 = "ADOBECODEBANC";
    std::string t1 = "ABC";
    std::cout << "Input: s = \"ADOBECODEBANC\", t = \"ABC\"\nOutput: \"" << solution.minWindow(s1, t1) << "\"" << std::endl;

    // Example 2
    std::string s2 = "a";
    std::string t2 = "a";
    std::cout << "Input: s = \"a\", t = \"a\"\nOutput: \"" << solution.minWindow(s2, t2) << "\"" << std::endl;

    // Example 3
    std::string s3 = "a";
    std::string t3 = "aa";
    std::cout << "Input: s = \"a\", t = \"aa\"\nOutput: \"" << solution.minWindow(s3, t3) << "\"" << std::endl;

    return 0;
}
