
numLetters :: Char -> String -> Integer
numLetters c str = fromIntegral $ length $ filter (\x -> x == c) str

numI = numLetters 'I'
numV = numLetters 'V'
numX = numLetters 'X'
numL = numLetters 'L'
numC = numLetters 'C'
numD = numLetters 'D'
numM = numLetters 'M'

romanNumeralSort :: String -> String
romanNumeralSort str = str

fromRomanNumeral :: String -> Integer
fromRomanNumeral xs = sum $ map rnton xs

rnton :: Char -> Integer
rnton 'I' = 1
rnton 'V' = 5
rnton 'X' = 10
rnton 'L' = 50
rnton 'C' = 100
rnton 'D' = 500
rnton 'M' = 1000

ntorn :: Integer -> Char
ntorn 1    = 'I'
ntorn 5    = 'V'
ntorn 10   = 'X'
ntorn 50   = 'L'
ntorn 100  = 'C'
ntorn 500  = 'D'
ntorn 1000 = 'M'

toRomanNumeral :: Integer -> String
toRomanNumeral n = trn [] n 1000 where
	trn xs n b
		| b == 1 = xs ++ substr n b 'I'
		| otherwise = trn (xs ++ (substr n b (ntorn b))) (nextn n b) $ nb b where
			substr n b c = take (fromIntegral (n `div` b)) $ repeat c
			nextn n b = n `mod` b
			nb 1000 = 500
			nb 500 = 100
			nb 100 = 50
			nb 50 = 10
			nb 10 = 5
			nb 5 = 1

