data Animal = Cisnal | Iguanoide | Narvale | Null
  deriving (Eq, Show)

dna2 :: [String] -> [String] -> [Int]
dna2 ws0 ws1 =
  [ length (filter (== Cisnal) animals)
  , length (filter (== Iguanoide) animals)
  , length (filter (== Narvale) animals)
  ]
  where
    animals = map (\(x,y) -> classify (similarity x y)) (zip ws0 ws1)
    classify v
      | v >= 0.1 && v <= 0.3 = Cisnal
      | v >= 0.4 && v <= 0.7 = Iguanoide
      | v >= 0.8            = Narvale
      | otherwise           = Null
    similarity a b =
      let m = fromIntegral (max (length a) (length b))
          s = fromIntegral (length [() | (c1,c2) <- zip a b, c1 == c2])
      in if m == 0 then 0 else s / m

main :: IO ()
main = do
  firstExtract <- words <$> getLine
  secondExtract <- words <$> getLine
  print $ dna2 firstExtract secondExtract
