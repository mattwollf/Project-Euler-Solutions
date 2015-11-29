import std.stdio, std.math, std.algorithm, std.range;
import FactorLookupTable;
import std.datetime;


T[] factors(T)(in T n) pure nothrow {
	if (n == 1)
		return [n];

	T[] res = [1, n];
	T limit = cast(T)real(n).sqrt + 1;
	for (T i = 2; i < limit; i++)
	{
		if (n % i == 0)
		{
			res ~= i;
			immutable q = n / i;
			if (q > i)
				res ~= q;
		}
	}

	return
		res.sort().release;
}


void main()
{
	import std.conv;
	long limit = 10000;
	StopWatch sw;
	sw.start();
	auto ft = new FactorLookupTable(limit);
	sw.stop();
	writeln(sw.peek());

	sw.reset();
	sw.start();

	for(long i = 1; i < limit; i++)
	{
		auto ret = factors!long(i);
	}
	sw.stop();
	writeln(sw.peek());

}
