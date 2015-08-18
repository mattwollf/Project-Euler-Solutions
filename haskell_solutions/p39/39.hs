right :: Integer -> Integer -> Integer -> Bool

right a b c = ((a^2) + (b^2)) == (c^2)

gen :: Integer -> [[Integer]]
gen n = [[a,b,n - (a + b)] | a <- [1..n], b <- [1..n], right a b (n - (a + b))]

answer = [gen x | x <- [1..1000]]

--real answer
ans = filter (\x -> length x > 14) answer

--g n = g' 1 1 [[]] where
--	g' a b acc
--		| a^2 + b^2 == c^2 = g' a (succ b) (
--		| a == (n-1) = g' 
--		| b == (n-1) = g' (succ a) 1 acc
