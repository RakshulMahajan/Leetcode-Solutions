class Solution {
public:
    bool isMagicSquare(vector<vector<int>> &a){
        vector<int> b(10,0);
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]>9) return false;
                b[a[i][j]]++;
            }
        }
        for(int i=1;i<b.size();i++){
            if(b[i]!=1) return false;
        }
        int s=a[0][0]+a[0][1]+a[0][2];
        for(int i=1;i<a.size();i++){
            int sum=0;
            for(int j=0;j<a[i].size();j++){
                sum+=a[i][j];
            }
            if(sum!=s) return false;
        }
        for(int j=0;j<a[0].size();j++){
            int sum=0;
            for(int i=0;i<a.size();i++){
                sum+=a[i][j];
            }
            if(sum!=s) return false;
        }
        int d1=a[0][0]+a[1][1]+a[2][2];
        int d2=a[0][2]+a[1][1]+a[2][0];
        return (d1==s && d2==s);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                vector<vector<int>> curr;
                for(int k=i;k<i+3;k++){
                    vector<int> v;
                    for(int p=j;p<j+3;p++){
                        v.push_back(grid[k][p]);
                    }
                    curr.push_back(v);
                }
                if(isMagicSquare(curr)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};