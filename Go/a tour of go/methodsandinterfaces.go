
package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

func (v Vertex) HypMethod() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func HypFunction(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func (v *Vertex) ScaleMethod(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func ScaleFunction(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// Methods
// Go does not have classes. However, you can define methods on types.
// A method is a function with a special receiver argument. The receiver appears in its own argument list between the func keyword and the method name.
// In this example, the Abs method has a receiver of type Vertex named v. This v can be considered equivalent to using `this` in other OO languages.
func methodTest() {
	h := Vertex{3, 4}
	fmt.Println(h.HypMethod()) // prints 5

	// equivalently
	fmt.Println(HypFunction(h)) // prints 5

	// You can declare a method on non-struct types, too. In this example we see a numeric type MyFloat with an Abs method.
	// You can only declare a method with a receiver whose type is defined in the same package as the method. 
	// You *cannot* declare a method with a receiver whose type is defined in another package (which includes the built-in types such as int).
	f := MyFloat(-math.Sqrt2) // math.Sqrt2 is root 2
	fmt.Println(f.Abs())

	// You can declare methods with pointer receivers.
	// This means the receiver type has the literal syntax *T for some type T. (Also, T cannot itself be a pointer such as *int.)
	// For example, the Scale method here is defined on *Vertex. Methods with pointer receivers can modify the value to which the receiver points (as Scale does here).
	// Since methods often need to modify their receiver, pointer receivers are more common than value receivers.
	
	v := Vertex{3, 4}
	v.ScaleMethod(10) // v gets updated

	// equivalently
	ScaleFunction(&v, 10)


	// Nuances when using pointers with methods and functions:

	var v Vertex
	ScaleFunction(v, 5)  // Compile error!
	ScaleFunction(&v, 5) // OK

	var v Vertex
	v.ScaleMethod(5)  // OK
	p := &v
	p.ScaleMethod(10) // OK

	// For the statement v.ScaleMethod(5), even though v is a value and not a pointer, it is passed as a pointer since the ScaleMethod has a pointer receiver.
	// That is, as a convenience, Go interprets the statement v.Scale(5) as (&v).Scale(5)


	// Nuances when using values with methods and functions:

	var v Vertex
	fmt.Println(HypFunction(v))  // OK
	fmt.Println(HypFunction(&v)) // Compile error!

	var v Vertex
	fmt.Println(v.HypMethod()) // OK
	p := &v
	fmt.Println(p.HypMethod()) // OK
	
	// Methods with value receivers can also be called on pointers. That is, the method call p.Abs() is interpreted by Go as (*p).Abs().
	// Since the method uses a value receiver, it still cannot modify the values pointed by p. It is essentially call by value, even though you are calling it on a pointer.

	// There are two reasons to use a pointer receiver.
	// The first is so that the method can modify the value that its receiver points to.
	// The second is to avoid copying the value on each method call. This can be more efficient if the receiver is a large struct, for example.

	// As good practice, all methods on a given type should have either value or pointer receivers, but not a mixture of both.
}


// Interfaces
// An interface type is defined as a set of *method* signatures. A variable of interface type can hold any value that has implementations for those methods.
type Abser interface {
	Abs() float64
}

type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

type Vertex struct {
	X, Y float64
}

func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func describe(a Abser) {
	fmt.Printf("(%v, %T)\n", a, a)
}

func interfaceTest1() {
	var a Abser	
	f := MyFloat(-math.Sqrt2)
	v := Vertex{3, 4}

	a = f  // There is an an Abs method defined with MyFloat receiver argument, hence MyFloat type implements Abser.
	a = &v // Similarly, there is an Abs method defined with *Vertex receiver argument, hence *Vertex type implements Abser. `&` gives a pointer to the Vertex value.

	a = v // Error, there is no method implementation for Abs defined with Vertex receiver argument (even though there is one for its pointer).

	fmt.Println(a.Abs())


	// Under the hood, interface values can be thought of as a tuple of a value and a concrete type:
	// (value, type)
	// An interface value holds a `value` of a specific underlying concrete `type`.
	// Calling a method on an interface value executes the method of the same name on its underlying `type`.
	a = f
	describe(a) // prints (-1.4142135623730951, main.MyFloat)
}


// Interface values with nil underlying values
// If the concrete value inside the interface itself is nil, the method will be called with a nil receiver.
// In some languages this would trigger a null pointer exception, but in Go it is common to write methods that gracefully handle being called with a nil receiver.
// Note that an interface value that holds a nil concrete value is itself non-nil.
type I interface {
	M()
}

type T struct {
	S string
}

func (t *T) M() {
	if t == nil {
		fmt.Println("<nil>")
		return
	}
	fmt.Println(t.S)
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}

func interfaceTest2() {
	var i I

	var t *T
	i = t
	describe(i) // prints (<nil>, *main.T)
	i.M() 		// prints <nil>

	i = &T{"hello"}
	describe(i) // prints (&{hello}, *main.T)
	i.M() 		// prints hello


	// A nil interface value holds neither value nor concrete type.
	// Calling a method on a nil interface is a run-time error because there is no type inside the interface tuple to indicate which concrete method to call.
	var i I
	describe(i) // prints (<nil>, <nil>)
	i.M()		// runtime error


	// The interface type that specifies zero methods is known as the empty interface: `interface{}`
	// An empty interface may hold values of any type. (Every type implements at least zero methods.)
	// Empty interfaces are used by code that handles values of unknown type. For example, fmt.Print takes any number of arguments of type interface{}:
	// `func Print(a ...interface{}) (n int, err error)`
	var i interface{}
	fmt.Printf("(%v, %T)\n", i, i) // prints (<nil>, <nil>)

	i = 42
	fmt.Printf("(%v, %T)\n", i, i) // prints (42, int)

	i = "hello"
	fmt.Printf("(%v, %T)\n", i, i) // prints (hello, string)



	// Type assertions
	// A type assertion provides access to an interface value's underlying concrete value:
	// `t := i.(T)`
	// If i does not hold a value of type T, the statement will trigger a panic (A special type of error, which stops regular flow of execution, executes any deferred function calls, and returns to parent, where the panic can be handled using `recover`).
	// To test whether an interface value holds a specific type, a type assertion can return two values: the underlying value and a boolean value that reports whether the assertion succeeded.
	// `t, ok := i.(T)`
	// If i holds a value of type T, then t will take that value and ok will be true. If not, ok will be false and t will be the zero value of type T, and no panic occurs.

	var i interface{} = "hello"

	s := i.(string)
	fmt.Println(s) // prints hello

	s, ok := i.(string)
	fmt.Println(s, ok) // prints hello true

	f, ok := i.(float64)
	fmt.Println(f, ok) // prints 0 false

	f = i.(float64) // triggers a panic
	fmt.Println(f) // doesn't execute

	
	// Type switch
	// A type switch is a construct that permits several type assertions in series.
	// A type switch is like a regular switch statement, but the cases in a type switch specify types (not values), and those types are compared against the type of the value held by the given interface value.
	switch v := i.(type) { // type is a keyword
	case T:
		// here v is the underlying value of i, which is a value of type T
	case S:
		// here v is the underlying value of i, which is a value of type S
	default:
		// None of the cases had the actual type; here v has the same type as the underlying type of i
	}
}


// Applications of Interface: Stringers
// One of the most ubiquitous interfaces is Stringer defined by the fmt package.
// A Stringer is a type that can describe itself as a string. The fmt package (and many others) look for this interface to print values. It's similar to toString() that's present in all Java objects.
//
// type Stringer interface {
//     String() string
// }

type Person struct {
	Name string
	Age  int
}

func (p Person) String() string {
	return fmt.Sprintf("%v (%v years)\n", p.Name, p.Age)
}

func stringerTest() {
	a := Person{"Harvey Dent", 42}
	z := Person{"Batman", 81}
	fmt.Println(a, z)
	// prints: Harvey Dent (42 years)
	//		   Batman (81 years)
}



// Excercise Stringer
package main

import "fmt"

type IPAddr [4]byte

func (ip IPAddr) String() string {
	return fmt.Sprintf("%v.%v.%v.%v", ip[0], ip[1], ip[2], ip[3])
}

func main() {
	hosts := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for name, ip := range hosts {
		fmt.Printf("%v: %v\n", name, ip)
	}
}



// Applications of Interface: Errors
// Go programs express error state with error values. The error type is a built-in interface similar to fmt.Stringer:
//
// type error interface {
//     Error() string
// }
//
// As with fmt.Stringer, the fmt package looks for the error interface when printing values.

import (
	"fmt"
	"time"
)

type MyError struct {
	What string
	When time.Time
}

func (e *MyError) Error() string {
	return fmt.Sprintf("%s, at %v",
		e.What, e.When)
}

// `error` is an interface, we can return a *MyError here since we have previously declared a method for *MyError implementing `error`
func run() error { 
	return &MyError{
		"it didn't work",
		time.Now(),
	}
}

func ErrorTest() {
	if err := run(); err != nil {
		fmt.Println(err) // prints: it didn't work, at 2020-10-12 21:05:04 +0000 UTC m=+0.000000001
	}
}



// Error Excercise
package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string{
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if(x < 0){
		return 0, ErrNegativeSqrt(x)
	}
	return math.Sqrt(x), nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}





// Applications of Interface: Readers
// The io package specifies the io.Reader interface, which represents the read end of a stream of data.
// The Go standard library contains many implementations of these interfaces, including files, network connections, compressors, ciphers, and others.
// The io.Reader interface has a Read method:
// func (T) Read(b []byte) (n int, err error)
// Read populates the given byte slice with data and returns the number of bytes populated and an error value. It returns an io.EOF error when the stream ends.
// The example code creates a strings.Reader and consumes its output 4 bytes at a time

import (
	"fmt"
	"io"
	"strings"
)

func readerTest() {
	r := strings.NewReader("Hello")

	b := make([]byte, 4)
	for {
		n, err := r.Read(b)
		fmt.Printf("n = %v err = %v b = %v\n", n, err, b)
		fmt.Printf("b[:n] = %q\n", b[:n])
		if err == io.EOF {
			break
		}
	}
	// prints:
	// n = 4 err = <nil> b = [72 101 108 108]
	// b[:n] = "Hell"
	// n = 1 err = <nil> b = [111 101 108 108]
	// b[:n] = "o"
	// n = 0 err = EOF b = [111 101 108 108]
	// b[:n] = ""
}

// Here is an example of a custom Reader, which gives an infinite stream of 'A's
type MyReader struct{}

func (r MyReader) Read(b []byte) (int, error) {
	for i,_ := range b {
		b[i] = byte('A')
	}
	return len(b), nil
}



// Readers Excercise
package main

import "golang.org/x/tour/reader"

type MyReader struct{}

func (r MyReader) Read(b []byte) (int, error) {
	for i,_ := range b {
		b[i] = byte('A')
	}
	return len(b), nil
}

// ROT13Reader Excercise
func main() {
	reader.Validate(MyReader{})
}

package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}
func (rot *rot13Reader) Read(b []byte) (n int, err error) {
	n, err = rot.r.Read(b)
	for i := 0; i < n; i++ {
		if b[i] >= 'A' && b[i] < 'Z' {
			b[i] = 65 + (((b[i] - 65) + 13) % 26)
		} else if b[i] >= 'a' && b[i] <= 'z' {
			b[i] = 97 + (((b[i] - 97) + 13) % 26)
		}
	}
	return
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}