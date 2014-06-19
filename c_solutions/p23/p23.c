#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define extra_printing 0

uint16_t is_divisior(uint16_t n, uint16_t d) ;

uint16_t divisor_sum( uint16_t n ) ;

uint16_t is_perfect(uint16_t n) ;

uint16_t divisor_or_zero(uint16_t n, uint16_t d) ;

uint16_t is_abundant( uint16_t n ) ;

uint16_t match_array_member( uint16_t a[], uint16_t n ) ;

int main(int argc, char *argv[] )
{
	uint16_t *abundant = NULL ;

	size_t abundant_size = 0 ;

	uint16_t i, j, k ;

	uint16_t found_flag ;

	uint32_t sum_2_abundants ;
	uint32_t sum = 1 ;

	/* sum is initialized to 1 because 1 cannot be expressed as a sum of two 	   abundants.*/
	/* fill the array telling if characters are abundant */

	for( i = 12; i < 29000; ++ i )
	{
		if( is_abundant( i ) )
		{
			++ abundant_size ;

			abundant = realloc( (void *) abundant,
					sizeof(uint16_t) * abundant_size ) ;

			abundant[abundant_size - 1] = i ;

#if extra_printing
			printf("adding abundant number %d\n", i );
#endif
		}

	}

#if extra_printing
	printf("beginning search for sums of abundant numbers\n");
#endif

	/* first loop for finding the numbers that cannot be written as hte sum of two nonabundant numbers */

	for(i = 2; i < 28124 ; ++i )
	{
		found_flag = 0 ;

		/* second loop for finding first  abundant number to make sum */
		/* j starts as 1 because 1 is first abundant number */
		for( j = 0;  abundant[j] < i /*&& j < abundant_size*/ ; ++ j )
		{

			if(found_flag == 1) break ;

			/* third loop for finding second abundant number to */
			/* make sum ( i ) */
			for( k = 0; k < abundant_size /*&& abundant[k] < i*/ ; ++k )
			{
				sum_2_abundants = abundant[k] + abundant[j] ;

				if( sum_2_abundants == i )
				{
#if extra_printing
					printf("%d = %d + %d \n"    ,
							i           ,
							abundant[j] ,
							abundant[k] );
#endif
					found_flag = 1 ;

					/*set found flag to break out*/

				}

				else if( sum_2_abundants > i ) break ;
			}
		}

		/* add i to sum if a sum of 2 abundants is not found */

		if(found_flag == 0 ) sum += i ;
	}

	printf("the sum of all numbers which cannot be expressed as a sum of 2 abundant numbers is %d\n", sum );

	return 0;
}

uint16_t is_abundant( uint16_t n )
{
	return ( divisor_sum(n) > n) ? 1 : 0 ;
}

uint16_t is_divisor(uint16_t n, uint16_t d)
{
	return ( ( n % d ) == 0 ) ? 1 : 0 ;
}

uint16_t divisor_or_zero(uint16_t n, uint16_t d)
{
	return ( ( n % d ) == 0 ) ? d : 0 ;
}

uint16_t is_perfect(uint16_t n)
{
	return ( divisor_sum(n) == n) ? 1 : 0 ;
}

uint16_t divisor_sum( uint16_t n )
{
	uint16_t s = 0 ;

	uint16_t i;

	for( i = 1; i <= n/2 ; ++ i )
	{

		if( is_divisor( n, i ) == 1)
		{
			s += i;
		}
	}

	return s ;
}
