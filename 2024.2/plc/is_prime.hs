module Main where

import System.Environment
import Data.List

isPrime :: Int -> Bool
isPrime n = n > 1 && all (\x -> n `mod` x /= 0) [2..(floor $ sqrt $ fromIntegral n)]

main :: IO ()
main = do
  args <- getArgs
  let n = read $ head args
  putStrLn $ show $ isPrime n