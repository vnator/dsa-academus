{-# OPTIONS_GHC -Wall #-}

fibPair :: Integer -> (Integer, Integer)
fibPair n
  | n == 0 = (0, 1)
  | even n =
      let k = n `div` 2
          (fk, fk1) = fibPair k
          c = fk * (2 * fk1 - fk)
          d = fk * fk + fk1 * fk1
      in (c, d)
  | otherwise =
      let k = (n - 1) `div` 2
          (fk, fk1) = fibPair k
          c = fk * fk + fk1 * fk1
          d = fk1 * (2 * fk + fk1)
      in (c, d)

fibFastDoubling :: Integer -> Integer
fibFastDoubling n = fst (fibPair n)

matrixMultiply :: ((Integer, Integer), (Integer, Integer)) ->
                  ((Integer, Integer), (Integer, Integer)) ->
                  ((Integer, Integer), (Integer, Integer))
matrixMultiply ((a, b), (c, d)) ((e, f), (g, h)) =
  ((a * e + b * g, a * f + b * h),
   (c * e + d * g, c * f + d * h))

fibMatrixPower :: Integer -> Integer
fibMatrixPower n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = snd (fst result)
  where
    result = matrixPower n
    matrixPower 1 = ((1, 1), (1, 0))
    matrixPower k
      | even k =
          let m = matrixPower (k `div` 2)
              m2 = matrixMultiply m m
          in m2
      | otherwise =
          let m = matrixPower (k - 1)
              base = ((1, 1), (1, 0))
          in matrixMultiply base m

-- Main
main :: IO ()
main = do
  putStrLn "=== Fast Fibonacci Algorithms ==="
  putStrLn ""

  putStrLn "First 30 Fibonacci numbers using fast doubling:"
  let fibs = [fibFastDoubling i | i <- [0..29]]
  print fibs
  putStrLn ""

  putStrLn "Comparing algorithms for correctness:"
  putStrLn ""
  let testIndices = [0, 5, 10, 20, 30, 50]
  mapM_ (\i -> do
    let fastDouble = fibFastDoubling i
    let fastMatrix = fibMatrixPower i
    let match = fastDouble == fastMatrix
    putStrLn $ "fib(" ++ show i ++ "): doubling=" ++ show fastDouble ++
               ", matrix=" ++ show fastMatrix ++ ", match=" ++ show match
    ) testIndices
  putStrLn ""

  putStrLn "Very large Fibonacci numbers (O(log n) computation):"
  putStrLn ""
  let largeIndices = [100, 200, 500, 1000]
  mapM_ (\i -> do
    let result = fibFastDoubling i
    putStrLn $ "fib(" ++ show i ++ ") = " ++ show result
    ) largeIndices
  putStrLn ""

  putStrLn "Extremely large Fibonacci number:"
  let huge = fibFastDoubling 10000
  putStrLn $ "fib(10000) has " ++ show (length (show huge)) ++ " digits"
  putStrLn ""
