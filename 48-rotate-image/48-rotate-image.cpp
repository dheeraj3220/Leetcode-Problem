class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size()-1;
        int a=0,b=0,c=size,d=size;
        int i=0;
       while(a<size){
           int tLeft=a++,tRight=b++,bRight=c--,bLeft=d--;
            while(bLeft>i){
                int temp=matrix[i][tLeft];
                matrix[i][tLeft++]=matrix[bLeft][i];
                matrix[bLeft--][i]=matrix[size][bRight];
                matrix[size][bRight--]=matrix[tRight][size];
                matrix[tRight++][size]=temp;
            }
           size--;
           i++;
        }
    }
};