#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define LIM() 100000000
#define extra_printing 0 

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

#if extra_printing
			if(n > 1 )
				printf("iteration a=%d, b=%d had %d "
						"consecutive primes\n",
						 a, b, curr_consec_primes ) ;
#endif

			if( curr_consec_primes >
				max_consec_primes )
			{
#if extra_printing
				printf("replacing: consecutive primes: "
						"%d, a: %d b: %d\n",
						n, a, b ) ;
#endif
				max_consec_primes = curr_consec_primes ;
				max_a = a ;
				max_b = b ;
			}
		}
	}

	printf("a=%d, b=%d, max primes is %d\n", 
			max_a, max_b, max_consec_primes) ;
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

		for( j = i * 2  ; j < limit ; j += i )
		{
			sieve[j] = 0 ;
		}
	}
	

	return 0 ;
}
int32_t prime_quadratic( int32_t n, int16_t a, int16_t b, char *sieve ) 
{
	return sieve[simple_abs_val(n * n + a * n + b)] ; 
}

int32_t simple_abs_val(int32_t n)
{
	return ( n >= 0 ) ? n : n * -1 ;
}
