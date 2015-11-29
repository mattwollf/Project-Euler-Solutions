import std.algorithm, std.range;

class FactorLookupTable
{
	private long[][] factorTable;

	this(in long initialSize = 100)
	{
		factorTable.length = initialSize;

		factorTable[1] = [];
		factorTable[2] = [2];

		for(long i = 2; i < initialSize; i++)
		{
			findFactors(i);
		}
	}

	public long[] factors(in long n)
	{
		long[] ret = [1];
		findFactors(n);
		return ret ~= factorTable[n];
	}

	private void findFactors(in long n)
	{
		if(factorTable[n] != [])
			return;
		else if(n == 1)
			return;

		long[] factors;

		for(long i = n-1; i != 1; i--)
		{
			if(factors.canFind(i))
				continue;

			if(n % i == 0)
			{
				findFactors(i);
				factors ~= factorTable[i];
			}
		}
		factors.sort;

		factors ~= n;

		factors = noDupes(factors);

		factorTable[n] = factors;
	}

	private auto noDupes(T)(in T[] s) {
		import std.algorithm: canFind;
		T[] result;
		foreach (T c; s)
			if (!result.canFind(c))
				result ~= c;
		return result;
	}
}

