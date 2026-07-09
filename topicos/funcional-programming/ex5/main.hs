{-# OPTIONS_GHC -Wall #-}

fibNaive :: Integer -> Integer
fibNaive n
  | n < 0 = error "Fibonacci index cannot be negative"
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibNaive (n - 1) + fibNaive (n - 2)

fibFast :: Integer -> Integer
fibFast n
  | n < 0 = error "Fibonacci index cannot be negative"
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibIter n 0 1
  where
    fibIter k a b
      | k == 0 = a
      | k == 1 = b
      | otherwise = fibIter (k - 1) b (a + b)

-- Main
main :: IO ()
main = do
  putStrLn "=== Fibonacci Number Calculator ==="
  putStrLn ""

  putStrLn "First 10 Fibonacci numbers using fibFast:"
  let fibs = [fibFast i | i <- [0..9]]
  print fibs
  putStrLn ""

  putStrLn "Testing fibNaive vs fibFast:"
  putStrLn ""
  let testIndices = [0, 1, 5, 10, 15, 20]
  mapM_ (\i -> do
    let naive = fibNaive i
    let fast = fibFast i
    putStrLn $ "fib(" ++ show i ++ ") = " ++ show fast ++
               " (naive: " ++ show naive ++ ")"
    ) testIndices
  putStrLn ""

  putStrLn "Large Fibonacci numbers using fibFast:"
  putStrLn ""
  let largeIndices = [30, 50, 100]
  mapM_ (\i -> do
    let result = fibFast i
    putStrLn $ "fib(" ++ show i ++ ") = " ++ show result
    ) largeIndices
