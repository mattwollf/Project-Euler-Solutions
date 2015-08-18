primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n
    

oddComposites = [ x | x <- [25,27..], not (isPrime x)]

isSPTS :: Integer -> Bool
isSPTS n = isSPTS' 0 1 where
	isSPTS' pcount scount
		| primes !! pcount > n 	= False
		| s == n 				= True
		| s > n 	= isSPTS' (succ pcount) 1
		| otherwise = isSPTS' pcount (succ scount)
		where s = (primes !! pcount) + (2 * (scount ^ 2))
