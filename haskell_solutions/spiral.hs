
--spiral :: Integer -> Integer
corner :: Integer -> Integer -> Integer

corner f n = n ^2 - (f * (n - 1))

topright :: Integer -> Integer
topleft :: Integer -> Integer
bottomright :: Integer -> Integer
bottomleft :: Integer -> Integer

topright = corner 0
topleft = corner 1
bottomleft = corner 2
bottomright = corner 3

corners :: Integer -> Integer

corners n = topright n + topleft n + bottomleft n + bottomright n

answer = 1 + sum [corners n | n <- [3,5..1001]]

--slice = sum [ corner a | a <- [0..3]]
