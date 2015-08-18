digList :: Integer -> [Integer]
digList n = digList' [] n where
	digList' acc n
		| n < 10	= n : acc
		| otherwise = digList' (lsd : acc) nxt
			where
			lsd = n `mod` 10
			nxt = n `div` 10

fromList :: [Integer] -> Integer

fromList xs = fromList' 0 xs where
	fromList' acc (x:[]) = acc + x
	fromList' acc (x:xs) = fromList' (acc + x * (10 ^ length xs)) xs


sumList :: Integer -> [[Integer]]

sumList n = sl n where
        sl 1 = [[1]]
        sl 2 = [[1,1]]
        sl x = [sl x-1,[1]]
