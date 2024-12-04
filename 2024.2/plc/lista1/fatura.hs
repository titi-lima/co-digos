type Comando = String
type Valor = Int

executa :: [(Comando, Valor)] -> Int
executa = foldl aplicaComando 0
    where 
        aplicaComando acc ("Multiplica", val) = acc * val
        aplicaComando acc ("Soma", val) = acc + val
        aplicaComando acc ("Subtrai", val) = acc - val
        aplicaComando acc ("Divide", 0) = -666
        aplicaComando acc ("Divide", val) = 
            if acc == -666 
                then -666 
                else acc `div` val

main = do
    a <- getLine
    let result = executa (read a)
    print result