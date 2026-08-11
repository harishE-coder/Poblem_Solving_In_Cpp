class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        double sum =0;
        int j = 0;
        for(int i:prices){
            if(j<discounts.size()){
                sum += (double)(i*(100-discounts[j]))/100;
                j++;
            }
            else sum += i;
        }
        return sum;
    }
};