#include <iostream>
using namespace std;

int a[100][100];
long long d[100][100];

int main(void)
{
    int n;
    cin >> n;
    
    d[0][0] = 1;
    
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin >> a[i][j];
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(i==0 && j==0) continue;
            
            for(int k = 0 ;k<j;k++) {
                if(j-k == a[i][k])
                    d[i][j] += d[i][k];
            }
            
            for(int k = 0;k<i;k++) {
                if(i-k == a[k][j])
                    d[i][j] += d[k][j];
            }
        }
    }
    
    cout << d[n-1][n-1] << '\n';
    return 0;
}
