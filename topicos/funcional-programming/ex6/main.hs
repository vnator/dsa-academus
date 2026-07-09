{-# OPTIONS_GHC -Wall #-}


fibPairs :: [(Integer, Integer)]
fibPairs = (0, 1) : [(b, a + b) | (a, b) <- fibPairs]

fibSequence :: [Integer]
fibSequence = map fst fibPairs

fibSequenceZip :: [Integer]
fibSequenceZip = 0 : 1 : zipWith (+) fibSequenceZip (tail fibSequenceZip)

takeFibonacci :: Int -> [Integer]
takeFibonacci n = take n fibSequence

takeFibonacciZip :: Int -> [Integer]
takeFibonacciZip n = take n fibSequenceZip

-- Main 
main :: IO ()
main = do
  putStrLn "=== Fibonacci Sequence Generator ==="
  putStrLn ""

  putStrLn "First 15 Fibonacci numbers using fibSequence:"
  let fib15 = takeFibonacci 15
  print fib15
  putStrLn ""

  putStrLn "First 15 Fibonacci numbers using fibSequenceZip:"
  let fib15zip = takeFibonacciZip 15
  print fib15zip
  putStrLn ""

  putStrLn "Checking if both methods produce same results:"
  let match = takeFibonacci 20 == takeFibonacciZip 20
  putStrLn $ "Match: " ++ show match
  putStrLn ""

  putStrLn "First 30 Fibonacci numbers:"
  let fib30 = takeFibonacci 30
  print fib30
  putStrLn ""

  putStrLn "Accessing Fibonacci numbers by index (0-based):"
  let sequence = fibSequence
  putStrLn $ "fib[0] = " ++ show (sequence !! 0)
  putStrLn $ "fib[5] = " ++ show (sequence !! 5)
  putStrLn $ "fib[10] = " ++ show (sequence !! 10)
  putStrLn $ "fib[20] = " ++ show (sequence !! 20)
  putStrLn ""
