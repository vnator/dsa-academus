{-# OPTIONS_GHC -Wall #-}

extractDigits :: Integer -> [Int]
extractDigits n
  | n < 0 = extractDigits (-n)
  | n < 10 = [fromIntegral n]
  | otherwise = extractDigits (n `div` 10) ++ [fromIntegral (n `mod` 10)]

sumSingleNumber :: Int -> Int
sumSingleNumber num
  | num < 10 = num
  | otherwise = (num `div` 10) + (num `mod` 10)

doubleEverySecondFromRight :: [Int] -> [Int]
doubleEverySecondFromRight digits =
  let reversedDigits = reverse digits
      doubledDigits = [if even (idx :: Integer) then d else d * 2 |
                       (idx, d) <- zip [0..] reversedDigits]
  in reverse doubledDigits

sumAllDigits :: [Int] -> Int
sumAllDigits = sum . map sumSingleNumber

isValidCard :: Integer -> Bool
isValidCard cardNumber =
  let digits = extractDigits cardNumber
      doubled = doubleEverySecondFromRight digits
      totalSum = sumAllDigits doubled
  in totalSum `mod` 10 == 0

-- Main function to test the card validator
main :: IO ()
main = do
  putStrLn "=== Card Validator (Luhn Algorithm) ==="
  putStrLn ""

  let testCards = [
        (4532015112830366, "Valid Visa"),
        (5425233010103442, "Valid Mastercard"),
        (6011111111111117, "Valid Discover"),
        (378282246310005, "Valid American Express"),
        (4532015112830367, "Invalid (last digit changed)"),
        (1234567890123456, "Invalid random number"),
        (49927398716, "Valid short number")
        ]

  putStrLn "Testing various card numbers:\n"
  mapM_ (uncurry testCard) testCards

-- utils to print
testCard :: Integer -> String -> IO ()
testCard cardNum description = do
  let result = if isValidCard cardNum then "[VALID]" else "[INVALID]"
  putStrLn $ "Card: " ++ show cardNum
  putStrLn $ "Description: " ++ description
  putStrLn $ "Result: " ++ result
  putStrLn ""
