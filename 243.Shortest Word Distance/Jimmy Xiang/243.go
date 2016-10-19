package main

import (
    "fmt"
)

func sortestDistance(word []string, word1 string, word2 string) int {
  for i, value := range  word {
         fmt.Println(i,value)
         fmt.Println(word1,word2)
    }

    return 3
}


func main() {

 a := []string{"a","b","c","d","f"}

 result := sortestDistance(a,"a","d")

 fmt.Println(result)

}
