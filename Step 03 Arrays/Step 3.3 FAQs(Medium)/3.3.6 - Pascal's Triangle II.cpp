class Solution {
public:
    // this uses binominal pascal triangle 
    vector<int> getRow(int rowIndex){
         vector<int> sol(rowIndex+1, 1);
         long long change = 1;

         for(int i = 1; i<rowIndex; i++){
            change = change*(rowIndex-i+1)/i;
            sol[i] = change;
        }

        return sol;
   } 
};