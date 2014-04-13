class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		//这里的dividend如果不加long long或者加double， 就会当是INT_MIN的时候溢出
		long long a = abs((long long)dividend);
		long long b = abs((long long)divisor);

		int result = 0;
		while (a >= b)
		{
			int count = 0;
			while (a >= b<<(count+1)) count++;
			a -= b<<count;
			result += 1<<count;
		}
		return (dividend>>31 ^ divisor>>31)? -result:result;
	}
};