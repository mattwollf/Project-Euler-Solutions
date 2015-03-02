digList :: Integer -> [Integer]
digList n = digList' [] n where
	digList' xs n 
		| n < 10	= n : xs
		| otherwise = digList' (lsd : xs) nxt
			where
			lsd = n `mod` 10
			nxt = n `div` 10

digitSum :: Integer -> Integer
digitSum n = foldl (+) 0 (digList n)

lst = [1..10000000]

digitSquare :: Integer -> Integer
digitSquare n = sum (map (^ 2) (digList n))

isDone :: [Integer] -> Bool
isDone xs = foldl (\acc x -> acc && (x == 89)) True xs

op :: [Integer] -> [Integer]
op xs = map (\x -> if x == 89 then 89 else digitSquare x) (filter (/= 1) xs)
ans :: [Integer] -> Integer -> Integer

ans xs acc
	| xs == []		= acc
	| elem 89 xs	= ans (filter (\x -> (x /= 1) || (x /= 89)) xs) (acc + (fromIntegral (length (filter (== 89) xs))))
	| otherwise 	= ans (filter (\x -> (x /= 1)) xs) acc
