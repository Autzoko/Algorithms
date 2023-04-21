#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int ans = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

typedef complex<double> comp;
const int MAXN = 1000005;
int rev[MAXN * 3];
const comp I(0, 1);
const double PI = acos(-1);
comp A[MAXN * 3], B[MAXN * 3], ans[MAXN * 3];

void fft(comp F[], int N, int sgn = 1)
{
    int bit = __lg(N);
    for(int i = 0; i < N; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if(i < rev[i])
            swap(F[i], F[rev[i]]);
    }

    for(int l = 1; l < N; l <<= 1)
    {
        comp step = exp(sgn * PI / l * I);
        for(int i = 0; i < N; i += l * 2)
        {
            comp cur(1, 0);
            for(int k = i; k < i + l; k++)
            {
                comp g = F[k], h = F[k + l] * cur;
                F[k] = g + h, F[k + l] = g - h;
                cur *= step;
            }
        }
    }
}

int main()
{
    int n = read(), m = read(), N = 1 << __lg(n + m + 1) + 1; // 补成2的整次幂
    for (int i = 0; i <= n; ++i)
        A[i] = read();
    for (int i = 0; i <= m; ++i)
        B[i] = read();
    fft(A, N), fft(B, N);
    for (int i = 0; i < N; ++i)
        ans[i] = A[i] * B[i];
    fft(ans, N, -1);
    for (int i = 0; i <= n + m; ++i)
        printf("%d ", int(ans[i].real() / N + 0.1)); // +0.1规避浮点误差
    return 0;
}