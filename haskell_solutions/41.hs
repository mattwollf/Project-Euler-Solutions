digList :: Integer -> [Integer]
digList n = digList' [] n where
        digList' xs n
                | n < 10        = n : xs
                | otherwise = digList' (lsd : xs) nxt
                where
                    lsd = n `mod` 10
                    nxt = n `div` 10

fromList :: [Integer] -> Integer
--fromList (x:[]) = x
--fromList (x:xs) = x * (10 ^ length xs) + fromList xs

fromList xs = fromList' 0 xs where
	fromList' n (x:[]) = n + x
        fromList' n (x:xs) = fromList' (n + x * (10 ^ length xs)) xs
		
primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n