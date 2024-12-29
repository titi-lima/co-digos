import Data.List (sortBy)
import Data.Function (on)
import qualified Data.Map as M

palavrasFrequentes :: [String] -> [String]
palavrasFrequentes ws =
  let freqMap = M.fromListWith (+) [(w, 1) | w <- ws]
      freqList = M.toList freqMap
      sorted = sortBy (\(w1, c1) (w2, c2) ->
                        compare c2 c1 <> compare (length w1) (length w2)
                      ) freqList
  in map fst (take 3 sorted)

main :: IO ()
main = do
  lista <- getLine
  print $ palavrasFrequentes (read lista :: [String])
