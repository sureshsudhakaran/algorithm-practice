#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4010;
const int MAXM = 810;
 
int n, m,a[MAXN][MAXN],b[MAXN][MAXN],w[MAXN][MAXN];
int f[MAXM][MAXN];
int s[MAXM][MAXN];
 
int main()
{
    //freopen("F:\\rush.txt", "r", stdin);
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)// Matrix prefix and
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)// Add the repeated subtraction part. Divide by 2 is the cost
            w[i][j] = (a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1]) / 2;
    memset(f, 127 / 3, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[1][i] = w[1][i], s[1][n] = 0;
    for (int i = 2; i <= m; i++)
    {
        s[i][n + 1] = n;
        for (int j = n; j >= i; j--)
        {
            for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++)
                if (f[i][j] > f[i - 1][k] + w[k + 1][j])
                    f[i][j] = f[i - 1][k] + w[k + 1][j], s[i][j] = k;// Change the amount of decision.
        }
    }
    printf("%d\n", f[m][n]);
    return 0;
}
