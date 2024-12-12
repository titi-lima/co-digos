somarMultiplos :: [Int] -> Int -> [Int]
somarMultiplos xs m 
    | m <= 0 = replicate (length xs) 0  -- se m for 0 ou negativo, retorna lista com zeros
    | otherwise = map (somaMultiplos m) xs
    where
        somaMultiplos :: Int -> Int -> Int
        somaMultiplos m x
            | x < m = 0  -- se m for maior que o elemento, retorna 0
            | otherwise = sum [n | n <- [m,m*2..x], n <= x]

main = do
    lista <- getLine
    let readList = read lista :: [Int]
    num <- getLine
    let readNum = read num :: Int
    let result = somarMultiplos readList readNum
    print result