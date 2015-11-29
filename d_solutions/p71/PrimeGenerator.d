module PrimeGenerator;
import std.math;
import std.conv;
import std.stdio;

class PrimeGenerator
{
	public this(in ulong initial_sieve_size = 100)
	{
		sieve.length = initial_sieve_size;

		if(initial_sieve_size < 100)
		{
			sieve.length = 100;
		}

		reset();
		eratosthenes();

		primes ~= 2;
		primes ~= 3;

		update_primes();

	}

	public auto primeRange() {

		update_primes();

		auto a = primes;
		struct pr{

			ulong index;
			@property auto front(){ return a[index];}
			@property auto empty(){ return index == a.length;}
			auto popFront(){index++;}
		};

		return pr();
	}

	private bool[] sieve;
	private ulong[] primes;

	private void update_primes()
	{
		//the last element is the last stored prime in the prime range.
		//so we can start from the last element +1 to look for new primes
		auto start = primes[$-1] + 1;

		for(auto i = start; i < sieve.length; i++)
		{
			if(sieve[i])
			{
				primes ~= i;
			}
		}
	}

	public bool isPrime(long n)
	{
		if(n > sieve.length)
			lookNext(n - sieve.length + 1);

		return sieve[n];
	}

	public void lookNext(in ulong n)
	{
		bool[] nextArray;
		nextArray.length = n;
		nextArray[] = true;

		sieve ~= nextArray;

		eratosthenes();
	}

	public void reset()
	{
		sieve[] = true;
		sieve[0..2] = false;

		primes = [2,3];
	}

	private void eratosthenes(in ulong start = 0)
	{
		immutable auto upper = floor(sqrt(to!real(sieve.length)));

		for(ulong i = 2; i < upper; i++)
		{
			if( sieve[i] )
			{
				ulong j = i * i;

				//while(j < start) j += i;

				for(; j < sieve.length; j += i)
				{
					sieve[j] = false;
				}
			}
		}
	}
};

