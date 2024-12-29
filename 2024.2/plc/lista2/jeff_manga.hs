contagemNotas :: [String] -> [String] -> Int
contagemNotas notas cortes = length $ filter (\corte -> letraParaNota corte <= mediaNumericaJeff) cortes
    where mediaNumericaJeff = mediaNotas $ map letraParaNota notas

-- Converte nota em letra para número
letraParaNota :: String -> Float
letraParaNota "A+" = 9.7
letraParaNota "A"  = 9.3
letraParaNota "A-" = 9.0
letraParaNota "B+" = 8.7
letraParaNota "B"  = 8.3
letraParaNota "B-" = 8.0
letraParaNota "C+" = 7.7
letraParaNota "C"  = 7.3
letraParaNota "C-" = 7.0
letraParaNota "D+" = 6.7
letraParaNota "D"  = 6.3
letraParaNota "D-" = 6.0
letraParaNota "F"  = 5.9
letraParaNota _    = 0.0

-- Calcula a média das notas numéricas
mediaNotas :: [Float] -> Float
mediaNotas notas = sum notas / fromIntegral (length notas)

main = do
    a <- getLine
    b <- getLine
    print (contagemNotas (read a) (read b))