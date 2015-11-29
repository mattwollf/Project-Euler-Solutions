import Data.List

primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
	sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
	possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

noDivsBy factors n = foldr (\f r-> f*f>n || ((rem n f /= 0) && r)) True factors

 -- primeNums = filter (noDivsBy [2..]) [2..]
primeNums = 2 : 3 : filter (noDivsBy $ tail primeNums) [5,7..]

isPrime n = n > 1 && noDivsBy primeNums n


lows n = filter ((== 0) . mod n) [1..truncate . sqrt $fromIntegral n]
factors:: Integer -> [Integer]

factors n = ( lows n )++ (reverse $ map (div n) $ lows n )

isGenerating::Integer -> Bool
isGenerating n = and $ map f xs
	where
	f = (\x -> isPrime (x + (n `div` x)))
	xs = lows n

main = do
	print $ sum $filter isGenerating [1.. 1000000]
