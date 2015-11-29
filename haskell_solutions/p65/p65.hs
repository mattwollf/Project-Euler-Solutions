import Data.Ratio

continuedFraction:: (Integral a) => [a] -> Rational
continuedFraction lst = 2 + cf rationals
  where
    rationals = map toRational lst
    cf [] = 0
    cf (x:xs) = 1 / ( x + cf xs)

eContinuedFractionSeed :: [Integer]
eContinuedFractionSeed = ecf 2
  where
    ecf n = [1,n,1] ++ ecf (n+2)

digitList::(Integral a) => a -> [a]
digitList n
  | n > 10= n `mod` 10 : (digitList . div n) 10
  | otherwise = [n]

main :: IO ()
main = do
  print [ (continuedFraction . replicate x) 2 | x <- [0..20]]
  putStrLn "the first twenty numbers in the e continued fraction are"
  (print . take 20) eContinuedFractionSeed
  putStrLn "the second continued fraction iteration for e is"
  (print . continuedFraction . take 2) eContinuedFractionSeed
  putStrLn "the first continued fraction iteration for e is"
  (print . continuedFraction) []
  putStrLn "the 100th iteration of e continued fraction"
  (print . numerator . continuedFraction . take 99) eContinuedFractionSeed
  putStrLn "the sum of digits in the numerator of the100th e continued fraction"
  (print . sum . digitList . numerator . continuedFraction . take 99) eContinuedFractionSeed
