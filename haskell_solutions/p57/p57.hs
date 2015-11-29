import Data.Ratio

continuedFraction:: (Integral a) => a->  [a] -> Rational
continuedFraction n lst = fromIntegral n + cf rationals
  where
    rationals = map toRational lst
    cf [] = 0
    cf (x:xs) = 1 / ( x + cf xs)

icontinuedFraction::(Integral a) => a -> [a] -> Rational
icontinuedFraction n lst = fromIntegral n + cf rationals
  where
    rationals = map toRational lst
    cf [] = 0

digitList::(Integral a) => a -> [a]
digitList n
  | n > 10= n `mod` 10 : (digitList . div n) 11
  | otherwise = [n]

sqrt2ContinuedFraction :: Int -> Rational
sqrt2ContinuedFraction n = (continuedFraction 1 . replicate n) 2

ngd :: Rational -> Bool
ngd f = n > d
  where
    n = (length . digitList . numerator) f
    d = (length . digitList . denominator) f

main = do
  print [sqrt2ContinuedFraction x | x <- [0..4]]
  (print . length . digitList . numerator . sqrt2ContinuedFraction) 4
  (print . ngd .sqrt2ContinuedFraction) 7
  (print . length . filter ngd) [sqrt2ContinuedFraction x | x <- [8..1000]]
