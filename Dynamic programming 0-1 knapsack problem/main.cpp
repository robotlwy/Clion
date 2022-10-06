#include <iostream>
#include <cstring>

using namespace std;
const int N = 100;

int main() {
    int n, c;
    cin >> n >> c;
    int sumW = c;
    int w[N], v[N], m[N][N];
    memset(m,0,sizeof(m));//如果直接m[n][c]初始化会让最后一行没有初始化
    //输入物品 i的重量和价值
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (j >= w[i])
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);
            else
                m[i][j] = m[i - 1][j];
        }
    }
    int x[n + 1];
    for (int i = n; i > 1; i--) {
        if (m[i][c] == m[i - 1][c])
            x[i] = 0;
        else {
            x[i] = 1;
            c -= w[i];
        }
    }
    x[1] = (m[1][c]>0) ? 1 : 0;
    cout << "最大价值为：" << m[n][sumW] << endl;
    cout << "背包中有物品：";
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}
