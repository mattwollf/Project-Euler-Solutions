import Data.Ratio
import Data.List
properFractions :: (Integral a) => a -> [Ratio a]
properFractions n = (sort . pf . (\x -> x- 1)) n
  where
    pf 0 = []
    pf x = (x % n) : pf (x-1)

resilience :: (Integral a) => a -> Ratio a
resilience n = (r . properFractions) n
  where
    r [] = 0 % 0
    r (x:xs) = 0 % 0

main = do
  putStrLn "proper fractions of 6"
  (print . nub .  properFractions) 50
