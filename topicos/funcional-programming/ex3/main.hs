{-# OPTIONS_GHC -Wall #-}

isLocalMaximum :: (Ord a) => a -> a -> a -> Bool
isLocalMaximum prev curr next = curr > prev && curr > next

localMaxima :: (Ord a) => [a] -> [a]
localMaxima xs
  | length xs < 3 = []
  | otherwise = [curr | (prev, curr, next) <- triplets xs,
                        isLocalMaximum prev curr next]
  where
    triplets lst = zip3 lst (tail lst) (tail (tail lst))

-- Main function
main :: IO ()
main = do
  putStrLn "=== Local Maxima Function ==="
  putStrLn ""

  putStrLn "Test 1: localMaxima [2, 9, 5, 6, 1]"
  let result1 = localMaxima [2, 9, 5, 6, 1]
  print result1
  putStrLn $ "Expected: [9, 6]"
  putStrLn ""

  putStrLn "Test 2: localMaxima [2, 3, 4, 1, 5]"
  let result2 = localMaxima [2, 3, 4, 1, 5]
  print result2
  putStrLn $ "Expected: [4]"
  putStrLn ""

  putStrLn "Test 3: localMaxima [1, 2, 3, 4, 5]"
  let result3 = localMaxima [1, 2, 3, 4, 5]
  print result3
  putStrLn $ "Expected: []"
  putStrLn ""

  putStrLn "Test 4: localMaxima [5, 4, 3, 2, 1]"
  let result4 = localMaxima [5, 4, 3, 2, 1]
  print result4
  putStrLn $ "Expected: []"
  putStrLn ""

  putStrLn "Test 5: localMaxima [1, 5, 3, 5, 1]"
  let result5 = localMaxima [1, 5, 3, 5, 1]
  print result5
  putStrLn $ "Expected: [5, 5]"
  putStrLn ""
