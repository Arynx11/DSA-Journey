// Brute Force time complexity O(n^2)
// space comp O(1)

class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] == nums[j]) {
                        return true; 
                    }
                }
            }
            return false;
        }
};

// Sorting -> time comp O(n), space comp O(1)

// by iterator loop 
// for (auto it=nums.begin()+1; it!=nums.end(); ++it) {
//     (*it == *(it - 1)) 
//         return true; // Found a duplicate
// }
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            sort (nums.begin(), nums.end());
            
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i - 1]) {
                    return true; 
                }
            }
            return false;
        }
};

//Unordered Set Method 
// Brute Force time complexity O(n)
// space comp O(n)

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> Seen;
            for (auto num : nums) {
                if (Seen.count(num)) return true;
                else Seen.insert(num);
           }
        return false;
        }
    };

    