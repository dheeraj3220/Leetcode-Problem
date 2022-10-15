class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0,count10=0;
        for(auto paid:bills){
            if(paid==5) count5++;
            else if(paid==10){
                if(count5>0){
                    count5--;
                    count10++;
                }
                else{
                    return false;
                }
            }
            else{
                if((count5>0 && count10>0) || count5>=3) {
                    if(count10==0) count5-=3;
                    else{
                        count5--;
                        count10--;
                    }
                }
                else{
                    return false;
                }
                    
            }
        }
        return true;
    }
};