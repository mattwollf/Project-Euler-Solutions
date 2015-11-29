
quad :: Integer -> Integer -> Integer -> Integer

quad a b = \n -> n^2 + a * n + b 

primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n

isFactor :: Integer -> Integer -> Bool

factorList n = [ x | x <- [1..ceiling (n/2)], isFactor x n]

isFactor a b =  (a `mod` b) == 0 

largestFactor :: Integer -> Integer

largestFactor n = maximum [0]
