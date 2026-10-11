class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            if((i+1)%n==0||n%(i+1)==0){
                cout<<nums[i]<<endl;
                cnt += nums[i]*nums[i];
            }
        }
        return cnt;
    }
};