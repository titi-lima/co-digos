logMes :: String -> String -> Double
logMes mes fatura = foldl (+) 0 valores
    where
        registros = parseRegistros (init fatura)
        valores = [read valor :: Double | (dt, _, valor) <- registros, words dt !! 1 == mes]

parseRegistros :: String -> [(String, String, String)]
parseRegistros "" = []
parseRegistros s = 
    let (dt, rest1) = break (==';') s
        (tipo, rest2) = break (==';') (tail rest1)
        (valor, rest3) = break (==';') (tail rest2)
    in if null rest3 
       then [(dt, tipo, valor)]
       else (dt, tipo, valor) : parseRegistros (tail rest3)

main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result