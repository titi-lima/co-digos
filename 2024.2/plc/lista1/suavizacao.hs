calcMedia ::Float -> Float -> Float -> Float
calcMedia x y z = (x + y + z) / 3

suavizaArrAux :: [Float] -> [Float]
suavizaArrAux [] = []
suavizaArrAux [x] = []
suavizaArrAux [x, y] = [y]
suavizaArrAux [x, y, z] = [calcMedia x y z, z]
suavizaArrAux (x:y:z:xs) = calcMedia x y z : suavizaArrAux (y : z : xs)

suaviza :: [Float] -> [Float]
suaviza [] = []
suaviza [x] = [x]
suaviza [x, y] = [x, y]
suaviza [x, y, z] = [x, calcMedia x y z, z]
suaviza (x:y:z:xs) = x : suavizaArrAux(x:y:z:xs) 



main = do
        lista <- getLine
        print $ suaviza (read lista :: [Float])