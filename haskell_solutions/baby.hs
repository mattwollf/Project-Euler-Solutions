square x = x * x

quad n a b = (square n) + (a * n) + b

primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n
    
fibr :: Integer -> Integer

fibr 0 = 1
fibr 1 = 1
fibr n = fibr (n - 1) + fibr (n - 2)

fibrList :: Integer -> [Integer]
fibrList n = [ fibr x | x <- [1..n]]


fibi :: Integer -> Integer

fibi n = fibi' 2 n 1 1 where
	fibi' i n a b
		| n < 2		= 1
		| i == n	= a + b
		| otherwise = fibi' (succ i) n (a + b) a

fibListReverse n = fibListReverse' 2 [1,1] where
	fibListReverse' i l
		| i == n 	= [sum (take 2 l)] ++ l
		| otherwise = fibListReverse' (succ i) ([sum (take 2 l)] ++ l)

fibList :: Integer -> [Integer]

fibList n = reverse (fibListReverse n)

fac :: Integer -> Integer

fac 0 = 1
fac n = n * fac (n - 1)

facList :: Integer -> [Integer]
facList 0 = [1]
facList n = [n]


