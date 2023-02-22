class Solution {
public:

   //This func is to find out min wt 
   bool solve(vector<int>& weights, int days,int capacity){
       int req_days=1;//min no of days
       int curr_wt=0; // min wt
       for(int i=0;i<weights.size();i++){ 
           if(curr_wt+weights[i]>capacity){
               req_days++;
               curr_wt=0;
           }
           curr_wt=curr_wt+weights[i];
       }
       if(req_days>days) return false;
       return true;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,right=0;
 for(int i=0;i<weights.size();i++){
       left=max(left,weights[i]); // left index as max wt coz min itna toh hoga hi
         right=right+weights[i]; // right index agr saare wt ek hi dun mei jae
        }
        int ans =right;
          while(left<=right){
              int mid=(left+right)/2;
              if(solve(weights,days,mid)){
                  ans=mid;
                  right=mid-1;
              }
              else{
                  left=mid+1;
              }
          }
          return ans;
    }
};
