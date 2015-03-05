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

fromList xs = fromList' 0 xs where
	fromList' n (x:[]) = n + x
        fromList' n (x:xs) = fromList' (n + x) xs

swag = [x ^ x | x <- [1..999]]

answer = drop ((fromIntegral $ length $ digList $ sum swag) - 10) $ digList $ sum swag
