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
    print $ numberOf $ trianglesIn $ asciiSumsOf $ theWordsIn s where
        numberOf = length
        trianglesIn = filter isTriangle
        asciiSumsOf = map asciiSum
        letters = map (filter isLetter)
        asciiSum xs = sum $ map letterPosition xs
        theWordsIn xs = letters $ splitOn "," xs
        
