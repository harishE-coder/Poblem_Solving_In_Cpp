class Solution {
public:
int cnt(int a){
    int sum = 1;
    while(a!=0){
        sum *= a%10;
        a = a/10;
    }
    return sum;
}
    int smallestNumber(int n, int t) {
        while(true){
            int temp = cnt(n);
            if(temp%t==0){
                return n;
            } else{
                n++;
            }
        }
        return -1;
    }
};