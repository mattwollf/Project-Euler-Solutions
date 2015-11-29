primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || not ( any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n

digList :: Integer -> [Integer]
digList n = digList' [] n where
        digList' xs a
                | a < 10        = a : xs
                | otherwise = digList' (lsd : xs) nxt
                where
                    lsd = a `mod` 10
                    nxt = a `div` 10

fromList :: [Integer] -> Integer
fromList xs = fromList' 0 xs where
    fromList' n [x] = n + x
    fromList' n (x:xs) = fromList' (n + x * (10 ^ length xs)) xs

main = print 5
