spirals :: [Integer]
spirals = helper 1 2 1 where
        helper current step corner = next : helper next nextStep nextCorner where
                next = current + step
                nextStep = if corner /= 0 then step else step + 2
                nextCorner = if corner /= 3 then corner + 1 else 0

primes :: [Integer]
primes = sieve (2 : 3 : possible [1..]) where
     sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p > 0]
     possible (x:xs) = 6*x-1 : 6*x+1 : possible xs

isPrime :: Integer -> Bool
isPrime n = shortCircuit || (not $ any divisible $ takeWhile inRangeOf primes) where
    shortCircuit = elem n [2,3] || (n < 25 && ((n-1) `mod` 6 == 0 || (n+1) `mod` 6 == 0))
    divisible y = n `mod` y == 0
    inRangeOf y = y * y <= n

spiralPrimes :: [Integer]
spiralPrimes = [ x | x <- spirals, isPrime x]


squareSpirals :: Int -> [Integer]
squareSpirals n = take ( 4*   (n`div`2)) spirals

driver :: [(Int, Float)]
driver = helper 26241 where
        helper sideLength = (sideLength, (fromIntegral (length (filter isPrime $ squareSpirals sideLength)) / (fromIntegral (length $ squareSpirals sideLength)))) : (helper $ sideLength + 2)

main = do
        print $ (takeWhile (\(a,b) -> b > 0.999) driver)
