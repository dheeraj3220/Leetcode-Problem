class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        int row_start=0;
        int row_end=matrix.size()-1;
        int column_start=0;
        int column_end=matrix[0].size()-1;
        int dir=0;
        
        while(row_start<=row_end && column_start<=column_end){
            if(dir==0){
                  for(int i=column_start;i<=column_end;i++){
                res.push_back(matrix[row_start][i]);
            }
            row_start++;
            }
            else if(dir==1){
                 for(int i=row_start;i<=row_end;i++){
                res.push_back(matrix[i][column_end]);
            }
            column_end--;
            }
            else if(dir==2){
                for(int i=column_end;i>=column_start;i--){
                    res.push_back(matrix[row_end][i]);
                }
                row_end--;
            }
            else if(dir==3){
               for(int i =row_end;i>=row_start;i--){
                   res.push_back(matrix[i][column_start]);
               }
               column_start++;
               }
             dir=(dir+1)%4;   
        }
        return res;
    }
};