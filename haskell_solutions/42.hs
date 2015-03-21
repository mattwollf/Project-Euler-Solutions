import Data.List
import Data.Char (ord)
import Data.List.Split

triangles :: [Integer]

triangles = [ (n * n + n) `div` 2 | n <- [1..]]

isTriangle :: Integer -> Bool
isTriangle n = n `elem` takeWhile (<= n) triangles

letterPosition :: Char -> Integer
letterPosition c = toInteger $ ord c - 64

isLetter :: Char -> Bool
isLetter c = and [n > 0,n < 27] where
	n = ord c - 64
	
main = do
	s <- readFile "p042_words.txt"
	print $ length $ filter isTriangle $ map sum $ map (map letterPosition) $ map (filter isLetter) $ splitOn "," s
