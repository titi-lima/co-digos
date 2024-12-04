isReplica :: String -> Int -> Char -> Bool
isReplica [] 0 _ = True
isReplica [] _ _ = False
isReplica (x:xs) n c 
    | n <= 0 = False
    | otherwise = (x == c) && isReplica xs (n-1) c

main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b :: Int) c
    print result