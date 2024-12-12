pokemon :: String -> String
pokemon (a:b:c:d:_) = do
    let ab = (read [a] :: Int) * (read [b] :: Int)
    let cd = (read [c] :: Int) * (read [d] :: Int)
    let diff = ab - cd
    let squared = diff ^ 2
    if squared < (read [a] :: Int) * (read [b] :: Int) * (read [c] :: Int) * (read [d] :: Int)
        then "Charmander vitorioso"
    else "Charmander derrotado"

main = do
    cp <- getLine
    print $ pokemon cp