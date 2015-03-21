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

fromList xs = fromList' 0 xs 
	where fromList' n (x:xs)
			| null xs = n + x
			| otherwise = fromList' (n + x * (10 ^ length xs)) xs
		
ans :: Integer -> [Integer]
ans n = digList n ++ ans (succ n)

answer = ans 1
