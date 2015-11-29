import std.stdio;
import PrimeGenerator;
import std.parallelism;
import core.sync.mutex;

bool isGenerator(in int n, PrimeGenerator p)
{
	for(int i = 1; i <= n; i++)
	{
		if(n % i != 0)
			continue;
		if( ! p.isPrime(i + n/i))
		{
			return false;
		}
	}
	return true;
}

void main()
{
	auto p = new PrimeGenerator(100000001);

	writeln(isGenerator(30, p));

	long sum;

	auto mutex = new Mutex;

	int[] space;
	for(int i = 0; i < 100000000; i++)
	{
		space ~= i;
	}

	int n;
	foreach( n, taskPool.parallel(space, 8))
	{
		if(isGenerator(i,p))
		{synchronized(mutex)
			{
				sum += n;
			}
		}
	}

	for(int i = 0; i < 100000000; i++)
	{
		if(isGenerator(i,p))
			sum += i;
	}

	writeln(sum);
}
