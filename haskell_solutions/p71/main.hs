import Data.Ratio as Ratio
import Data.List

properFractions::Integral a => a -> [Ratio a]
properFractions d = nub $ helper [1..(d-1)]
	where
	helper [] = []
	helper (x:xs) = x % d : helper xs

fractionsList :: Integral a => a -> [Ratio a]
fractionsList n = sort . nub $ helper [1..n]
	where
	helper [] = []
	helper (x:xs) = (properFractions x) ++ helper xs
