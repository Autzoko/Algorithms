#include <bits/stdc++.h>

//递归快速幂
int qpow(int a, int n)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        int tmp = qpow(a, n / 2);
        return tmp * tmp;
    }
}

#define MOD 1000000007
typedef long long ll;
ll qpow_(ll a, ll n)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return qpow_(a, n - 1) * a % MOD;
    else
    {
        ll temp = qpow_(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

//非递归快速幂
int _qpow_(int a, int n)
{
    int ans = 1;
    while(n)
    {
        if(n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

//扩展
template <typename T>
T _qpow(T a, ll n)
{
    T ans = 1;
    while(n)
    {
        if(n & 1)
            ans = ans * a;
        n >>= 1;
        a = a * a;
    }
    return ans;
}

//应用：斐波那契
/*
求 Fn mod 10^9 + 7
*/
struct matrix
{
    ll a1, a2, b1, b2;
    matrix(ll a1, ll a2, ll b1, ll b2) : a1(a1), a2(a2), b1(b1), b2(b2) {}
    matrix operator*(const matrix &y)
    {
        matrix ans( (a1 * y.a1 + a2 * y.b1) % MOD,
                    (a1 * y.a2 + a2 * y.b2) % MOD,
                    (b1 * y.a1 + b2 * y.b1) % MOD,
                    (b1 * y.a2 + b2 * y.b2) % MOD);
        return ans;
    }
};

matrix mqpow(matrix a, ll n)
{
    matrix ans(1, 0, 0, 1); //单位矩阵
    while(n)
    {
        if(n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

int main()
{
    ll x;
    matrix M(0, 1, 1, 1);
    scanf("%lld", &x);
    matrix ans = mqpow(M, x - 1);
    printf("%lld\n", (ans.a1 + ans.a2) % MOD);
    return 0;
}