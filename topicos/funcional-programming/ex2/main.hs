{-# OPTIONS_GHC -Wall #-}
nthElement :: Int -> [a] -> [a]
nthElement i xs = [x | (idx, x) <- zip [1..] xs, idx `mod` i == 0]

skips :: [a] -> [[a]]
skips xs
  | null xs = []
  | otherwise = [nthElement i xs | i <- [1 .. length xs]]

-- Main
main :: IO ()
main = do
  putStrLn "=== Skips Function ==="
  putStrLn ""

  putStrLn "Test 1: skips \"ABCD\""
  let result1 = skips "ABCD"
  print result1
  putStrLn $ "Expected: [\"ABCD\", \"BD\", \"C\", \"D\"]"
  putStrLn ""

  putStrLn "Test 2: skips \"hello!\""
  let result2 = skips "hello!"
  print result2
  putStrLn $ "Expected: [\"hello!\", \"el!\", \"l!\", \"l\", \"o\", \"!\"]"
  putStrLn ""

  putStrLn "Test 3: skips []"
  let result3 = skips ([] :: [Char])
  print result3
  putStrLn $ "Expected: []"
  putStrLn ""

  putStrLn "Test 4: skips [1,2,3,4,5]"
  let result4 = skips [1, 2, 3, 4, 5]
  print result4
  putStrLn ""
