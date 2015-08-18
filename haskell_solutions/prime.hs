quad :: Integer -> Integer -> Integer -> Integer
quad n a b = (n * n) + (a * n) + b

primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n


consecutivePrimes :: Integer -> Integer -> [Integer]

consecutivePrimes a b = cp 0 a b [] where
	cp n a b xs 
		| isPrime ans = cp (succ n) a b (xs ++ [ans])
		| otherwise = xs where
		ans = abs (quad n a b)

answer = [[a,b,fromIntegral (length (consecutivePrimes a b))] | a <- [(-999)..999], b <- [(-999)..999], 65 < length (consecutivePrimes a b)]
