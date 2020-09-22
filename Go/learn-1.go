// Finished upto https://golang.org/doc/tutorial/create-module

package main

import (
	"fmt"

	"rsc.io/quote"
)

func main() {
	fmt.Println(quote.Hello() + " It is I, GokulVSD.")
	fmt.Println("I hope you know that " + quote.Opt())
	fmt.Print("A little something to help you get to know me, ")
	fmt.Println(quote.Glass())
	fmt.Println(quote.Go())
}
