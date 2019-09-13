import java.math.BigInteger;

class Solution {
	public BigInteger fac (int n) {
		BigInteger res = BigInteger.ONE;
		for (int i = 2; i <= n; i++) res = res.multiply(BigInteger.valueOf(i));
		return res;
	}

	public int uniquePaths(int m, int n) {
		int a = (m > n) ? n - 1 : m - 1;
		int t = m + n - 2;
		BigInteger ans = fac(t).divide(fac(t - a)).divide(fac(a));
		return ans.intValue();
	}
}
