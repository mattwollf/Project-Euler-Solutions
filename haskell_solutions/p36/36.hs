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
		

palindrome :: [Integer] -> Bool
palindrome [] = True
palindrome (x:[]) = True
palindrome (x:xs)
	| x == last xs = palindrome (init xs)
	| otherwise = False
	
toBinary :: Integer -> [Integer]
toBinary n = toBin [] n where
	toBin xs n
		| n < 2 = n : xs
		|otherwise = toBin ((n `mod` 2) : xs) (n `div` 2)
		
fromBinary :: [Integer] -> Integer
fromBinary xs = fromB xs 0 where
	fromB (x:[]) acc = acc + x
	fromB (x:xs) acc = fromB xs (acc + x * (2 ^(length xs)))
	
answer = [ x | x <- [1..999999], palindrome (digList x), palindrome (toBinary x)]