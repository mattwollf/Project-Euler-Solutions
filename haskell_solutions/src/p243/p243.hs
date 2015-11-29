import Data.Ratio

properFractions :: (Fractional a, Eq a) => a -> [a]
properFractions n = (pf . (\x -> x- 1)) n
  where
    pf 0 = []
    pf x = (x / n) : pf (x-1)

main = do
  putStrLn "proper fraction of 0.5"
  (print . properFractions) 6
