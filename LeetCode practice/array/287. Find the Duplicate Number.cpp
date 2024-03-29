// https://leetcode.com/problems/find-the-duplicate-number/

// my Method 1: O(n) time and O(n) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i=0;
        vector<bool> isVisited(n, 0);
        while(true){
            isVisited[i] = true;
            if(isVisited[nums[i]]) break;
            else i=nums[i];
        }
        return nums[i];
    }
};

// method 2: O(n) time and O(1) space
nums[i] *= -1;
index = abs(nums[i])
See editorial solution






// method 3: modify existing array while operating but reset back to original. O(1) extra space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int index = nums[i]%n;
            nums[index] += n;
        }
        int repNum = -1;
        for(int i=0; i<n; i++) {
            if(nums[i]/n >1) {
                repNum = i;
            }
            nums[i] = nums[i]%n;
        }
        return repNum;
    }
};