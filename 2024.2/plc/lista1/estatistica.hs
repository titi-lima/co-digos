getValues :: [String] -> [String]
getValues [] = []
getValues (x:y:z:xs) = z : getValues xs
getValues _ = []

minMaxCartao :: String -> (Double, Double)
minMaxCartao str = 
    let values = getValues $ split str
        numbers = map read values :: [Double]
    in (minimum numbers, maximum numbers)
    where
        split :: String -> [String]
        split [] = []
        split str = case dropWhile (==';') str of
            "" -> []
            s -> w : split rest
                where (w, rest) = break (==';') s
                
main = do
    a <- getLine
    let result = minMaxCartao a
    print result