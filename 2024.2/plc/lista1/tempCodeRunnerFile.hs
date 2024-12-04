pokemon :: String -> String
pokemon (a:b:c:d:_) = do
    let ab = read [a, b] :: Int
    let cd = read [c, d] :: Int
    let sum = ab + cd
    let squared = sum ^ 2
    if squared == (read [a, b, c, d] :: Int)
        then "Charmander vitorioso"
    else "Charmander derrotado"



main = do
    cp <- getLine
    print $ pokemon cp