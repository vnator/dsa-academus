{-# OPTIONS_GHC -Wall #-}

countTrue :: [Bool] -> Int
countTrue = length . filter id

xor :: [Bool] -> Bool
xor bools = odd (countTrue bools)

xorFold :: [Bool] -> Bool
xorFold = foldl (/=) False

-- Main
main :: IO ()
main = do
  putStrLn "=== XOR Function ==="
  putStrLn ""

  putStrLn "Test 1: xor []"
  let result1 = xor []
  print result1
  putStrLn $ "Expected: False (zero Trues is even)"
  putStrLn ""

  putStrLn "Test 2: xor [True]"
  let result2 = xor [True]
  print result2
  putStrLn $ "Expected: True (one True is odd)"
  putStrLn ""

  putStrLn "Test 3: xor [True, True]"
  let result3 = xor [True, True]
  print result3
  putStrLn $ "Expected: False (two Trues is even)"
  putStrLn ""

  putStrLn "Test 4: xor [True, False]"
  let result4 = xor [True, False]
  print result4
  putStrLn $ "Expected: True (one True is odd)"
  putStrLn ""

  putStrLn "Test 5: xor [True, True, True]"
  let result5 = xor [True, True, True]
  print result5
  putStrLn $ "Expected: True (three Trues is odd)"
  putStrLn ""

  putStrLn "Test 6: xor [False, False, False]"
  let result6 = xor [False, False, False]
  print result6
  putStrLn $ "Expected: False (zero Trues is even)"
  putStrLn ""

  putStrLn "Test 7: xor [True, False, True, False]"
  let result7 = xor [True, False, True, False]
  print result7
  putStrLn $ "Expected: False (two Trues is even)"
  putStrLn ""

  putStrLn "Comparing both implementations:"
  putStrLn ""
  let testList = [True, False, True]
  putStr "xor [True, False, True] = "
  print (xor testList)
  putStr "xorFold [True, False, True] = "
  print (xorFold testList)
  putStrLn ""
