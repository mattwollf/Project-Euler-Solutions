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
	
leftTruncatable :: Integer -> Bool
leftTruncatable n = lt (digList n) where
	lt (1:[]) = False
	lt (x:[]) = isPrime x
	lt (x:xs)
		| isPrime (fromList (x:xs)) = lt xs
		| otherwise = False

rightTruncatable :: Integer -> Bool
rightTruncatable n = rt (digList n) where
	rt (1:[]) = False
	rt (x:[]) = isPrime x
	rt xs
		| isPrime (fromList xs) = rt (init xs)
		|otherwise = False

answer = take 11 [x | x <- drop 4 primes, rightTruncatable x, leftTruncatable x]