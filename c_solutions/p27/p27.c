#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define LIM() 100000000
#define extra_printing 1 

int32_t simple_abs_val(int32_t n) ;

int32_t prime_quadratic( int32_t n, int16_t a, int16_t b, char *sieve ) ;

int fill_prime_sieve( char *sieve, size_t limit ) ;

int main()
{
	int16_t a = -1000 ;
	int16_t b = -1000 ;

	int32_t n = 0 ;

	int32_t max_a = 0;
	int32_t max_b = 0;

	int32_t max_consec_primes = 0;
	int32_t curr_consec_primes = 0;
	char *sieve = NULL ;

	sieve = realloc(sieve, sizeof(char ) * LIM() ) ;

	fill_prime_sieve( sieve, LIM() ) ;

	for(a = -1000 ; a < 1001 ; ++ a )
	{
		for( b = -1000 ; b < 1001 ; ++ b )
		{
			n = 0 ;
			curr_consec_primes = 0 ;

			while( prime_quadratic( n, a, b, sieve ) ) 
			{
				++ curr_consec_primes ;
				++ n ;
			}

			if( curr_consec_primes >
				max_consec_primes )
			{
				max_consec_primes = curr_consec_primes ;
				max_a = a ;
				max_b = b ;

#if extra_printing
				printf("replacing: consecutive primes: "
						"%d, a: %d b: %d\n",
						n, a, b ) ;
#endif
			}
		}
	}

	printf("a=%d, b=%d, a * b is %d, max primes is %d\n", 
			max_a, max_b, max_a * max_b, max_consec_primes) ;

	return 0 ;
}

int fill_prime_sieve( char *sieve, size_t limit )
{
	size_t i, j;

	sieve[0] = sieve[1] = 0 ;

	for( i = 2 ; i < limit ; ++ i ) sieve[i] = 1 ;

	for( i = 2 ; i < limit ; ++ i )
	{
		if(sieve [i] == 0 ) continue ;

		for( j = i * i  ; j < limit ; j += i )
		{
			sieve[j] = 0 ;
		}
	}
	

	return 0 ;
}
int32_t prime_quadratic( int32_t n, int16_t a, int16_t b, char *sieve ) 
{
	int32_t index = simple_abs_val(n * n + a * n + b ) ;

	return sieve[index] ;
}

int32_t simple_abs_val(int32_t n)
{
	return ( n >= 0 ) ? n : n * -1 ;
}
