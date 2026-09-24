class Solution {
public:
    int digitcnt(int n){
        int temp = 0;
        while(n!=0){
            temp += n%10;
            n = n/10;
        }
        return temp;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digitcnt(nums[i])==i) return i;
        }
        return -1;
    }
};