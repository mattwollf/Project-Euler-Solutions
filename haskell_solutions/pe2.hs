
fib n = fib' 1 n 1 1 where
	fib' i n a b
		| n < 2		= 1
		| i == n	= a + b
		| otherwise	= fib' (succ i) n (a + b) a

isEven :: Integer -> Bool
isEven n = n `mod` 2 == 0

fibEven :: Integer -> Integer
fibEven n
	| isEven n	= fib n
	| otherwise = 0

main = print (sum [fibEven n | n <- [0..4000000], fibEven n < 4000000])
