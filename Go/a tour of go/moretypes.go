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

	https://tour.golang.org/moretypes/13
}




