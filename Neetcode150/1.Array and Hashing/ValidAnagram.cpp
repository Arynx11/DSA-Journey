// with two unordermap
//time complexity O(S+T) total size of string
// O(1) at 26 char
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())  return false;
        
        unordered_map <char,int> sfreq;
        unordered_map <char,int> tfreq;
        for (char b:s) sfreq[b]++;
        for (char c:t) tfreq[c]++;

        return sfreq == tfreq;

    }
};

//with one maps
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length())  return false;
            
            unordered_map <char,int> sfreq;
            for (char b:s) sfreq[b]++;
            
            for (auto& it : t ) {
                if (sfreq.find(it) != sfreq.end()) {
                    sfreq[it]--;  
                } 
                else {
                    return false;
                }
                
            }
            
            for (auto& [ch, freq] : sfreq) {
                if (freq != 0) return false;
            }
            return true;
        }
    };

    You're **very close**, just a small correction in how you're using `.find()` — good instinct!

    ### 🧠 STL Reminder:
    - `sfreq.find(it)` returns an **iterator**, not a boolean.
    - In C++, this will **always be truthy**, even if the key is not found — which leads to bugs.  
    - To check existence properly:
    
    ```cpp
    if (sfreq.find(it) != sfreq.end()) {
        // Key exists — now decrement
        sfreq[it]--;
    }
    else {
        // Key not found — return false (not an anagram)
    }
    ```