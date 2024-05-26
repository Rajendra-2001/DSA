class Solution
{
public:
  int M = 1e9 + 7;
  // Recursion
  int solve(int n, int absent, int late)
  {
    if (absent >= 1 || late >= 3)
    {
      return 0;
    }
    if (n == 0)
      return 1;
    int A = solve(n - 1, absent + 1, late) % M;
    int L = solve(n - 1, absent, late + 1) % M;
    int P = solve(n - 1, absent, late) % M;
    return ((A + L) % M + P) % M;
  }
  int checkRecord(int n)
  {
    return solve(n, 0, 0);
  }

  // MEMO
  const long long mod = 1e9 + 7;
  long long dp[100001][2][3];
  long long f(int i, int absent, int late)
  {
    //    if (absent>=2 || late>=3) return 0;
    if (i == 0)
      return 1;
    if (dp[i][absent][late] != -1)
      return dp[i][absent][late];

    long long ans = f(i - 1, absent, 0);                // P
    ans += (late < 2 ? f(i - 1, absent, late + 1) : 0); // L
    ans += (absent == 0 ? f(i - 1, absent + 1, 0) : 0); // A

    return dp[i][absent][late] = ans % mod;
  }
  int checkRecord(int n)
  {
    fill(&dp[0][0][0], &dp[0][0][0] + (n + 1) * 6, -1);
    return f(n, 0, 0);
  }
};