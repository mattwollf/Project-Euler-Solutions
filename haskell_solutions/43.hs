digList :: Integer -> [Integer]
digList n = digList' [] n where
	digList' xs n 
		| n < 10	= n : xs
		| otherwise = digList' (lsd : xs) nxt
		where
			lsd = n `mod` 10
			nxt = n `div` 10

fromList :: [Integer] -> Integer
--fromList (x:[]) = x
--fromList (x:xs) = x * (10 ^ length xs) + fromList xs

fromList xs = fromList' 0 xs where
	fromList' n (x:[]) = n + x
	fromList' n (x:xs) = fromList' (n + x * (10 ^ length xs)) xs


--pans :: [Integer]
pans = [ [a,b,c,d,f,g,h,i,j,k] | a <- [1..9], b <- [0..9], c <- [0..9], d <- [0..9], e <- [0..9], f <- [0..9], g <- [0..9], h <- [0..9], i <- [0..9], j <- [0..9], k <- [0..9]]


ssd :: Integer -> Bool

ssd n = ssd' (tail (digList n)) 2 where
	ssd' xs  2 = if fromList (take 3 xs) `mod`  2 == 0 then ssd' (tail xs)  3 else False
	ssd' xs  3 = if fromList (take 3 xs) `mod`  3 == 0 then ssd' (tail xs)  5 else False
	ssd' xs  5 = if fromList (take 3 xs) `mod`  5 == 0 then ssd' (tail xs)  7 else False
	ssd' xs  7 = if fromList (take 3 xs) `mod`  7 == 0 then ssd' (tail xs) 11 else False
	ssd' xs 11 = if fromList (take 3 xs) `mod` 11 == 0 then ssd' (tail xs) 13 else False
	ssd' xs 13 = if fromList (take 3 xs) `mod` 13 == 0 then ssd' (tail xs) 17 else False
	ssd' xs 17 = fromList xs `mod` 17 == 0 

pandigital :: Integer -> Bool
pandigital n = pan 0 (digList n) where
	pan n xs
		| n == 9 			= elem 9 xs
		| not (elem n xs) 	= False
		| otherwise 		= pan (succ n) xs
