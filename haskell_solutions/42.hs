triangles :: [Integer]

triangles = [ (n * n + n) `div` 2 | n <- [1..]]
