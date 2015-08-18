fac :: Integer -> Integer
fac 0 = 1
fac n = n * fac (n - 1)

digitList :: Integer -> [Integer]

digitList n
	| n < 10 = [n]
	| otherwise = n `mod` 10 : digitList (n `div` 10)
	
facDigitSum :: Integer -> Integer
facDigitSum n = foldl (\x y -> x + fac y) 0 (digitList n)