
digitSum :: Integer -> Integer
digitSum n = digitSum' 0 n where
	digitSum' dst n
		| n < 0		= digitSum' 0 (abs n)
		| n < 10	= n + dst
		| otherwise	= digitSum' lsd nxt 
			where
			lsd = n `mod` 10 + dst
			nxt = n `div` 10
	
digList :: Integer -> [Integer]
digList n = digList' [] n where
	digList' xs n 
		| n < 10	= n : xs
		| otherwise = digList' (lsd : xs) nxt
			where
			lsd = n `mod` 10
			nxt = n `div` 10

lst = [a ^ b | a <- [1..99], b <- [1..99]]
