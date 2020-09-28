package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	sum := 0
	// Go only has for as a looping construct
	for i := 0; i < 10; i++ { // init; cond; post
		sum += i
	}

	for sum < 100 { // init and post are optional (becomes a while loop)
		sum++
	}

	for { // removing cond creates an infinite loop
		sum++
	}

}

func sqrt(x float64) string {
	if x < 0 { // if statement
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim { // short; cond. short is similar to init in for loops.
		return v
	} else {
		fmt.Println(v) // shorts and inits are only within scope of the block (including the else blocks) of the flow construct
	}
	// can't use v here
	return lim
}

func days() {
	fmt.Println("When's Saturday?")

	switch today := time.Now().Weekday(); time.Saturday { // Go has switch, also supports short statements
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow.")
	case today + 2:
		fmt.Println("In two days.")
	default:
		fmt.Println("Too far away.")
	}
	// case conditions need not be constants, can be an expression / use functions. There is an implicit break between cases

	// switch can be conditionless, it will select the first case that evaluates to true
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
}

func deferExample() {
	defer fmt.Println("world") // the function is not called until the surrounding function returns.
	// however, the arguments to the function are executed and not deferred.
	fmt.Println("hello")
} // this functions first prints "hello", and then "world"

func deferStack() {
	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}
} // defers are put into a stack, and called last-in first-out when the surrounding function returns.
