
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            
            while(n!=0){
                if(n%3==2){
                    return false  ;
                }
                n= n/3 ;
            }
    
            return true ; // check if n can be divided by three bcz if not definitetly , it is very sure that number is not power of three .
        }
    };

    //github link : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04