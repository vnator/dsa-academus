{-# OPTIONS_GHC -Wall #-}

fibMemo :: [Integer]
fibMemo = 0 : 1 : zipWith (+) fibMemo (tail fibMemo)

fib :: Int -> Integer
fib n = fibMemo !! n

fibDP :: Int -> [Integer]
fibDP n = take n fibMemo

fibIterative :: Int -> [Integer]
fibIterative n
  | n <= 0 = []
  | n == 1 = [0]
  | otherwise = reverse (fibIter n 0 1 [0])
  where
    fibIter count a b acc
      | count <= 1 = acc
      | otherwise = fibIter (count - 1) b (a + b) (b : acc)

-- Main
main :: IO ()
main = do
  putStrLn "=== Fibonacci with Dynamic Programming ==="
  putStrLn ""

  putStrLn "Memoized approach - First 20 Fibonacci numbers:"
  let fib20 = fibDP 20
  print fib20
  putStrLn ""

  putStrLn "Iterative DP approach - First 20 Fibonacci numbers:"
  let fib20Iter = fibIterative 20
  print fib20Iter
  putStrLn ""

  putStrLn "Checking if methods produce same results:"
  let match = fibDP 30 == fibIterative 30
  putStrLn $ "Match: " ++ show match
  putStrLn ""

  putStrLn "Accessing Fibonacci by index using memoization:"
  putStrLn $ "fib(0) = " ++ show (fib 0)
  putStrLn $ "fib(10) = " ++ show (fib 10)
  putStrLn $ "fib(20) = " ++ show (fib 20)
  putStrLn $ "fib(30) = " ++ show (fib 30)
  putStrLn ""

  putStrLn "First 50 Fibonacci numbers (DP):"
  let fib50 = fibDP 50
  print fib50
  putStrLn ""
