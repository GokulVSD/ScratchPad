package main

// Programs start running in package main

import (
	"fmt"
	"math"
	"math/cmplx"
	"math/rand" // sub-package is rand, part of math package (sub-directory)
	"time"
)

// Only things accessible outside a package are exported names, starting with uppercase.

func add(x, y int) int { // can also be add(x int, y int)
	return x + y
}

func swap(x, y string) (string, string) {
	return y, x
}

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return // naked return, returns the named return values (x and y)
}

func needInt(x int) int {
	return x*10 + 1
}

var c, python, java bool // package level variables

// there can only be one main function in a package
func main() {
	rand.Seed(5)
	fmt.Println("Welcome to the playground!")
	fmt.Println("The time is", time.Now())
	fmt.Println("My favorite number is", rand.Intn(10))
	fmt.Printf("Now you have %g problems.\n", math.Sqrt(7))

	a, b := swap("hello", "world")

	var i int                       // function level variables
	fmt.Println(i, c, python, java) // prints 0 false false false

	var x, y int = 1, 2   // int can be omitted since being initialised
	x, y := 1, 2          // same as above
	var p, q = 1, "hello" // initialising different variable types is inferred from value

	c, python, java := true, false, "no!" // short variable declaration
	k := 3
	// Outside a function, every statement begins with a keyword (var, func, and so on) and so the := construct is not available.

	/** Go's basic types:

	bool

	string

	int  int8  int16  int32  int64
	uint uint8 uint16 uint32 uint64 uintptr

	byte // alias for uint8

	rune // alias for int32, represents a Unicode code point

	float32 float64

	complex64 complex128
	*/

	// Variable declaration can be factored similar to import statements
	var (
		ToBe   bool       = false
		MaxInt uint64     = 1<<64 - 1
		z      complex128 = cmplx.Sqrt(-5 + 12i)
	)

	fmt.Printf("Type: %T Value: %v\n", z, z)

	// The expression T(v) converts the value v to the type T.
	i := 42 // inferring type from assignment of a constant, 'i' can be int, float64, or complex128 based on precision of the constant
	f := float64(i)
	u := uint(f)
	// Go does not support implicit type casting

	const Pi = 3.14 // Constants can be character, string, boolean, or numeric values, cannot be declared using the := syntax.

	const ( // can use factored declaration. Constants can hold high precision values
		Big   = 1 << 100
		Small = Big >> 99
	)

	fmt.Println(needInt(Small)) // const Small can fit inside an int, succeeds
	fmt.Println(needInt(Big))   // this will fail as const Big overflows int
}
