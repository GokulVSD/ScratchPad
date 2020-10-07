package main

import "fmt"

// The type *T is a pointer to a T value. Its zero value is nil. Go's null value is nil.
func pointerTest() {
	i, j := 2, 25 // regular int variables

	var p *int
	p = &i			// The & operator generates a pointer to its operand.
	// OR with shorthand:
	p := &i         // point to i

	// * is the "dereferencing" or "indirecting" operator, similar to C.
	fmt.Println(*p) // read i through the pointer (prints 42)
	*p = 1         // set i through the pointer
	fmt.Println(i)  // see the new value of i (prints 21)

	p = &j         // point to j
	*p = *p / 5   // divide j through the pointer
	fmt.Println(j) // see the new value of j (prints 5)

	fmt.Println(p) // prints 0xc000100018 (an address)

	// Unlike C, Go has no pointer arithmetic.
	p = p + 1
	q := &i
	p = p + q // All these fail
}



// A struct is a collection of fields.
type Vertex struct {
	X int
	Y string
}

func structTest() {
	fmt.Println(Vertex{1, "hello"})
	// Prints {1 hello}

	// Struct fields are accessed using a dot.
	v := Vertex{1, "hello"}
	v.X = 4
	fmt.Println(v.X) // prints 4

	// Struct fields can be accessed through a struct pointer.
	p := &v

	// To access the field X of a struct when we have the struct pointer p we could write (*p).X.
	// However, that notation is cumbersome, so the language permits us instead to write just p.X,
	// without the explicit dereference.

	p.X = 1e9 // same as (*p).X = 1e9
	fmt.Println(v) // prints {1000000000 hello}

	fmt.Println(p) // prints &{1000000000 hello}

	// different vertex literals:
	v1 := Vertex{1, "hello"}
	v2 := Vertex{Y: "hello", X: 1} // order doesn't matter when explicitly naming variables
	v3 := Vertex{Y: "world"} // All other variables take 0 value
	v4 := Vertex{} // All variables take 0 value
}





// The type [n]T is an array of n values of type T.
func arrayTest() {

	var a [2]string // declares a variable a as an array of two strings.

	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1]) // prints Hello World
	fmt.Println(a) // prints [Hello World]

	primes := [6]int{2, 3, 5, 7, 11, 13} // an array literal
	fmt.Println(primes) // prints [2 3 5 7 11 13]

	// An array's length is part of its type, so arrays cannot be resized. 
	// This seems limiting, but don't worry;
	// Go provides a convenient way of working with arrays.
}



// An array has a fixed size. A slice, on the other hand, is a dynamically-sized, 
// flexible view into the elements of an array.
// In practice, slices are much more common than arrays.

// The type []T is a slice with elements of type T.
func sliceTest() {
	primes := [6]int{2, 3, 5, 7, 11, 13}

	// A slice is formed by specifying two indices, a low and high bound, separated by a colon:
	// a[low : high]
	// includes low, excludes high
	var s []int = primes[1:4]
	fmt.Println(s) // prints [3 5 7]

	// When slicing, you may omit the high or low bounds to use their defaults instead.
	// The default is zero for the low bound and the length of the slice for the high bound.

	// a[0:10]
	// a[:10]
	// a[0:]
	// a[:]
	// are all the same for creating a slice of an array a of length 10

	// A slice does not store any data, it just describes a section of an underlying array.
	// Changing the elements of a slice modifies the corresponding elements of its underlying array.
	// Other slices that share the same underlying array will see those changes.

	names := [3]string{
		"john",
		"paul",
		"ringo"
	} // regular array

	a := names[0:2]
	b := names[1:3]  // a and b are slices

	fmt.Println(names) // prints [john paul ringo]
	fmt.Println(a) // prints [john paul]
	fmt.Println(b) // prints [paul ringo]

	b[0] = "george"

	fmt.Println(names) // prints [john george ringo]
	fmt.Println(a) // prints [john george]
	fmt.Println(b) // prints [george ringo]


	// A slice literal is like an array literal without the length. This is an array literal:
	// [3]bool{true, true, false} 
	// This creates the same array as above, then builds a slice that references it:
	// []bool{true, true, false}

	q := []int{2, 3, 5, 7, 11, 13}
	fmt.Println(q) // prints [2 3 5 7 11 13]

	s := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}

	fmt.Println(s)
	// prints [{2 true} {3 false} {5 true} {7 true} {11 false} {13 true}]


	// Slice length and capacity
	/*
	A slice has both a length and a capacity.
	The length of a slice is the number of elements it contains.
	The capacity of a slice is the number of elements in the underlying array, counting from the first element in the slice.
	The length and capacity of a slice s can be obtained using the expressions len(s) and cap(s).
	You can extend a slice's length by re-slicing it, provided it has sufficient capacity. If you try
	extending the slice beyond it's capacity, Go will throw a runtime error.
	*/
	s := []int{1, 2, 3, 4, 5} // a slice

	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s) // prints len=5 cap=5 [1 2 3 4 5]

	// Slice the slice to give it zero length.
	s = s[:0]
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s) // prints len=0 cap=5 []

	// Extend its length.
	s = s[:4]		// if you try extending as s = s[:6], you get a runtime error
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s) // prints len=4 cap=5 [1 2 3 4]

	// Drop its first two values.
	s = s[2:]
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s) // prints len=2 cap=3 [3 4]


	// The zero value of a slice is nil. A nil slice has a length and capacity of 0 and has no underlying array.
	var s []int
	if s == nil {	// evaluates to true
		fmt.Println("nil!")
	}


	// Slices can be created with the built-in make function; this is how you create dynamically-sized arrays.
	// The make function allocates a zeroed array and returns a slice that refers to that array:
	// a := make([]int, 5)  // len(a)=5
	// To specify a capacity, pass a third argument to make:
	// b := make([]int, 0, 5) // len(b)=0, cap(b)=5

	// Slices can contain any type, including other slices.

	board := [][]string{
		[]string{"_", "_"},
		[]string{"_", "_"},
	}

	board[0][0] = "X"
	board[0][1] = "O"
	board[1][0] = "X"
	board[1][1] = "O"

	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}
	// prints:
	// X O
	// X O



	// Appending to a slice:
	// func append(s []T, value/s ...T) []T
	// The first parameter s of append is a slice of type T, and the rest are T values to append to the slice.

	// The resulting value of append is a slice containing all the elements of the original slice plus the provided values.

	// If the backing array of s is too small to fit all the given values a bigger array will be allocated. 
	// The returned slice will point to the newly allocated array.

	var s []int
	s = append(s, 0) // len=1 cap=1, prints [0]
	s = append(s, 1, 2, 3, 4) // len=4 cap=6 [0 1 2 3 4]


	// The range form of the for loop iterates over a slice or map.
	// When ranging over a slice, two values are returned for each iteration. 
	// The first is the index, and the second is a copy of the element at that index.


	var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	} // prints 2**0 = 1 ...

	// You can skip the index or value by assigning to _.
	// for i, _ := range pow
	// for _, value := range pow
	// If you only want the index, you can omit the second variable.
	// for i := range pow

}

// Slice excercise
package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	var x [][]uint8
	for i := 0; i < dy; i++ {
		var y []uint8
		for j := 0; j < dx; j++ {
			y = append(y, uint8(i^j))
		}
		x = append(x, y)
	} 
	return x
}

func main() {
	pic.Show(Pic)
}



// A map maps keys to values. The zero value of a map is nil. A nil map has no keys, nor can keys be added.
// The make function returns a map of the given type, initialized and ready for use.

type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func mapTest(){
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	fmt.Println(m["Bell Labs"]) // prints {40.68433 -74.39967}

	// Map literals are like struct literals, but the keys are required.
	var m = map[string]Vertex{
		"Bell Labs": Vertex{
			40.68433, -74.39967,
		},
		"Google": Vertex{
			37.42202, -122.08408,
		},
	} // you can omit `Vertex` inside since it is a type name, like "Google": {37.42202, -122.08408,}

	fmt.Println(m) // prints map[Bell Labs:{40.68433 -74.39967} Google:{37.42202 -122.08408}]

	// delete(m, key) to delete a key from a map m

	// Test that a key is present with a two-value assignment:
	// elem, ok := m[key]
	// If key is in m, ok is true. If not, ok is false.
	// If key is not in the map, then elem is the zero value for the map's element type.

}


// Maps excercise
package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)
	for _, w := range strings.Fields(s) {
		m[w]++
	}
	return m
}

func main() {
	wc.Test(WordCount)
}



// Functions are values too. They can be passed around just like other values.
// Function values may be used as function arguments and return values.
func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func funcValTest(){
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println(compute(hypot)) // prints 5
	fmt.Println(compute(math.Pow)) // prints 81 (which is 3**4)
}

// Function closures:
/*
Go functions may be closures.
A closure is a function value that references variables from outside its body.
The function may access and assign to the referenced variables;
in this sense the function is "bound" to the variables.

For example, the adder function returns a closure. Each closure is bound to its own sum variable.
*/
func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func funcClosureTest() {
	pos, neg := adder(), adder()
	for i := 1; i < 5; i++ {
		fmt.Println(pos(i), neg(-i)
	} // prints 1 -1
	  // 		3 -3 ... till 10 -10
}



// Function Closure exercise
package main

import "fmt"

func fibonacci() func() int {
	x, y, z := 1, 0, 0
	return func() int {
		z = x + y
		x = y
		y = z
		return x
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}





