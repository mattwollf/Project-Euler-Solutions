#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

size_t msd(size_t n) ;

size_t  msd_power(size_t n ) ;

size_t my_pow( size_t n, size_t e ) ;

int fill_prime_sieve( char *sieve, size_t limit ) ;

int is_truncatable_prime( size_t n, char *sieve ) ;

int is_truncatable_right(size_t n, char *sieve ) ;

int is_truncatable_left(size_t n, char *sieve ) ;

int main() 
{
	char *sieve = NULL ;

	size_t limit = 10000000 ;

	size_t i = 8;

	size_t sum = 0 ;

	sieve = realloc(sieve, sizeof(char) * limit ) ;

	fill_prime_sieve( sieve, limit ) ;

	while(i < limit )
	{
		if( is_truncatable_prime( i, sieve ) )
		{
			sum += i ;

			printf("%lu is truncatable\n", i);
		}

		 ++i ;
	}

	printf("the sum is %lu\n", sum ) ;
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

int is_truncatable_prime( size_t n, char *sieve )
{
	int left_rc = is_truncatable_left(n, sieve) ;
	int right_rc = is_truncatable_right(n, sieve) ; 

	if(sieve[n] == 0) return 0 ;

	return left_rc && right_rc ;
}

int is_truncatable_right(size_t n, char *sieve ) 
{
	size_t temp_n = n ;

	while( temp_n > 9 )
	{
		if( sieve[temp_n] == 0 ) return 0 ;

		temp_n /= 10 ;
	}

	return sieve[temp_n] ;
}

int is_truncatable_left(size_t n, char *sieve )
{
	size_t temp_n = n;

	while( temp_n > 9 )
	{
		if( sieve[temp_n] == 0 ) return 0 ;

		temp_n -= ( msd(temp_n) * my_pow(10, msd_power(temp_n) ) ) ;

	}

	return sieve[temp_n] ;	
}

size_t my_pow(size_t n, size_t e ) 
{
	size_t rc = n ;

	if(e == 0) return 1 ;

	while( --e > 0 ) rc *= n ;

	return rc ;
}

size_t msd_power(size_t n )
{
	size_t power = 0 ;

	while( n > 9 )
	{
		n /= 10  ;

		++ power ;
	}

	return power ;
}

size_t msd(size_t n)
{
	while( n > 9 )
	{
		n /= 10 ;
	}

	return n ;
}
