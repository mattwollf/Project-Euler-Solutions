digList :: Integer -> [Integer]
digList n = digList' [] n where
	digList' acc n 
		| n < 10	= n : acc
		| otherwise = digList' (lsd : acc) nxt
			where
			lsd = n `mod` 10
			nxt = n `div` 10

fromList :: [Integer] -> Integer
--fromList (x:[]) = x
--fromList (x:xs) = x * (10 ^ length xs) + fromList xs

fromList xs = fromList' 0 xs where
	fromList' acc (x:[]) = acc + x
	fromList' acc (x:xs) = fromList' (acc + x * (10 ^ length xs)) xs
	

isPandigital :: Integer -> Bool
isPandigital n = isPan 1 (digList n) where
	isPan n (x:xs)
		| n == 10 = (length (x:xs)) == 9
		| elem n (x:xs) = isPan (succ n) (x:xs)
		| otherwise = False
		
construct :: Integer -> Integer
construct n = (t [] 1) where
	t acc i
		| length acc >= 9 = fromList acc
		| otherwise = t (acc ++ digList(n * i)) (succ i)
