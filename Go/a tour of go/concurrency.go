

package main

import (
	"fmt"
	"time"
)

func say(s string) {
	for i := 0; i < 2; i++ {
		time.Sleep(1000 * time.Millisecond)
		fmt.Println(s)
	}
}

// Goroutines
// A goroutine is a lightweight thread managed by the Go runtime.
// go f(x, y, z)
// starts a new goroutine running
// f(x, y, z)
// The *evaluation* of f, x, y, and z happens in the current goroutine and the *execution* of f happens in the new goroutine.
// Goroutines run in the same address space, meaning you can pass pointers, access global variables, etc., between goroutines, due to this, access to shared memory must be synchronized, for example, using sync.Mutex, else you can face undefined behaviour.
// The sync package provides useful primitives, although you won't need them much in Go as there are other primitives.
func goroutineTest() {
	go say("world")
	say("hello")
} 
// prints hello and world in new lines, sometimes in different orders, and different number of times (sometimes prints 4 lines, sometimes 3, sometimes 2).
// Due to function scope, a new `i` is created for each thread, hence the shared address space isn't the issue here.
// This behaviour is because the the main thread execution can finish before the goroutine is finished executing ("hello" is always printed 2 times, as it's in the main thread).
// This can be solved by manually waiting some time at the end of the program (not recommended), or using channels.


// Channels

// Channels are a typed conduit through which you can send and receive values with the channel operator, <-.

// ch <- v    // Send v to channel ch.
// v := <-ch  // Receive from ch, and
//            // assign value to v.
// (The data flows in the direction of the arrow.)

// Like maps and slices, channels must be created before use:

// ch := make(chan int)
// By default, sends and receives block (wait) until the other side is ready. This allows goroutines to synchronize without explicit locks or condition variables.

// The following example code sums the numbers in a slice, distributing the work between two goroutines. Once both goroutines have completed their computation, it calculates the final result.

func sum(s []int, c chan int) {
	sum := 0
	for _, v := range s {
		sum += v
	}
	c <- sum // send sum to c
}

func channelTest1() {
	
	s := []int{7, 2, 8, -9, 4, 0}

	c := make(chan int)
	go sum(s[:len(s)/2], c)
	go sum(s[len(s)/2:], c)
	x, y := <-c, <-c // receive from c

	fmt.Println(x, y, x+y)
}
// Prints -5 17 12

// Here's another example to showcase how the problem encountered before can be solved, `<- finished` waits for the channel to provide some value, hence the main thread waits for the goroutine.
func worker(finished chan bool) {
	fmt.Println("routine: Started")
	time.Sleep(time.Second)
	fmt.Println("routine: Finished")
	finished <- true
}

func channelTest2() {
	finished := make(chan bool)

	fmt.Println("Main: Starting worker")
	go worker(finished)

	fmt.Println("Main: Waiting for worker to finish")
	<- finished // You don't need to store the received value from the channel
	fmt.Println("Main: Completed")
}

// Output:
// Main: Starting worker
// Main: Waiting for worker to finish
// routine: Started
// routine: Finished
// Main: Completed

// If you have many goroutines that you want to wait for, you can use sync.WaitGroup (behaves similarly to a semaphore).

// Buffered channels
// Channels can be buffered. Provide the buffer length as the second argument to `make` to initialize a buffered channel:
// ch := make(chan int, 100)

// Sends to a buffered channel block only when the buffer is full. Receives block when the buffer is empty.

func bufferedChannelTest() {
	ch := make(chan int, 2)
	ch <- 1
	ch <- 2
	// ch <- 3       
	fmt.Println(<-ch)
	fmt.Println(<-ch)
}

// If commented line is uncommented, you get a fatal error (deadlock), as trying to send into a filled channel triggers a block, which cannot be unblocked, as the statements that receive from the channel can never be reached in order to make space in the channel.  


// Closing a channel
// A sender can close a channel to indicate that no more values will be sent. Receivers can test whether a channel has been closed by assigning a second parameter to the receive expression:
// v, ok := <-ch
// ok is false if there are no more values to receive and the channel is closed.

// The loop for i := range c receives values from the channel repeatedly until it is closed.

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y
	}
	close(c)
}

func closeChannelTest() {
	c := make(chan int, 5)
	go fibonacci(cap(c), c)
	for i := range c {
		fmt.Print(i, " ") 
	}
} // prints 0 1 1 2 3

// Channels aren't like files; you don't usually need to close them. Closing is only necessary when the receiver must be told there are no more values coming, such as to terminate a range loop.
// Note: Only the sender should close a channel, never the receiver. Sending on a closed channel will cause a panic.


// Select
// The select statement lets a goroutine wait on multiple communication operations.
// A select blocks until one of its cases can run, then it executes that case. It chooses one at random if multiple are ready.


func fibonacci(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x: // can be chosen as long as c doesn't have a value
			x, y = y, x+y
		case <-quit: // can be chosen when quit has some value
			fmt.Println("quit")
			return
		}
	}
}

func selectTest() {
	c := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 5; i++ {
			fmt.Print(<-c, " ") // at first, nothing in channel, so block
		}
		quit <- 0
	}()
	fibonacci(c, quit)
} // prints 0 1 1 2 3 quit


// The default case in a select is run if no other case is ready.
// select {
// case i := <-c:
//     // use i
// default:
//     // trying to receive from c would have blocked, so default is run
// }
func selectDefaultTest() {
	tick := time.Tick(100 * time.Millisecond)
	boom := time.After(300 * time.Millisecond)
	for {
		select {
		case <-tick:
			fmt.Print("   tick")
		case <-boom:
			fmt.Print("   BOOM!")
			return
		default:
			fmt.Print("   .")
			time.Sleep(50 * time.Millisecond)
		}
	}
}
// prints    .   .   tick   .   .   tick   .   .   BOOM!







// Exercise: Equivalent Binary Trees

package main

import (
	"golang.org/x/tour/tree"
	"fmt"
)

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int){
	if t.Left != nil {
		Walk(t.Left, ch)
	}
	ch <- t.Value
	if t.Right != nil {
		Walk(t.Right, ch)
	}
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int, 10)
	ch2 := make(chan int, 10)
	go Walk(t1, ch1)
	go Walk(t2, ch2)
	for i:= 0; i < 10; i++ {
		v1, v2 := <- ch1, <- ch2
		if v1 == v2 {
			continue;
		} else {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(Same(tree.New(1), tree.New(1)))
	fmt.Println(Same(tree.New(1), tree.New(2)))
}


// sync.Mutex
// Channels are great for communication among goroutines.
// But if we just want to make sure only one goroutine can access a variable at a time to avoid conflicts, we need synchronisation via locks.
// This concept is called mutual exclusion, and the conventional name for the data structure that provides it is mutex.
// Go's standard library provides mutual exclusion with sync.Mutex and its two methods: `Lock` and `Unlock`

// We can define a block of code to be executed in mutual exclusion by surrounding it with a call to Lock and Unlock as shown in the Increment method.
// We can also use defer to ensure the mutex will be unlocked as shown in the Value method.

import (
	"fmt"
	"sync"
	"time"
)

type SafeCounter struct {
	i int
	mux sync.Mutex
}

func (c *SafeCounter) Increment() {
	c.mux.Lock() // Lock so only one goroutine at a time can access c.i
	c.i++
	c.mux.Unlock()
}

func (c *SafeCounter) Value() int {
	c.mux.Lock()
	defer c.mux.Unlock() // good practice, to ensure lock will be released when returning
	return c.i
}

func mutexTest() {
	c := SafeCounter{i: 0}
	for i := 0; i < 1000; i++ {
		go c.Increment()
	}

	time.Sleep(time.Second)
	fmt.Println(c.Value()) // prints 1000 after a second
}




// Exercise Web Crawler

package main

import (
	"fmt"
	"sync"
)

type Fetcher interface {
	// Fetch returns the body of URL and
	// a slice of URLs found on that page.
	Fetch(url string) (body string, urls []string, err error)
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher) {
	// TODO: Fetch URLs in parallel.
	// TODO: Don't fetch the same URL twice.

	defer wg.Done()
	
	if depth <= 0 {
		return
	}
	
	cache.mux.Lock()
	cache.visited[url] = true
	cache.mux.Unlock()
	
	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("found: %s %q\n", url, body)
	for _, u := range urls {
	
		cache.mux.Lock()
		if !cache.visited[u] {
			wg.Add(1)
			go Crawl(u, depth-1, fetcher)
		}
		cache.mux.Unlock()
	}
}

type safeCache struct {
	visited map[string]bool
	mux sync.Mutex
}

var cache safeCache
var wg sync.WaitGroup

func main() {
	cache = safeCache{visited: make(map[string]bool)}
	wg.Add(1)
	go Crawl("https://golang.org/", 4, fetcher)
	wg.Wait()
	fmt.Println("Done crawling")
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher is a populated fakeFetcher.
var fetcher = fakeFetcher{
	"https://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"https://golang.org/pkg/",
			"https://golang.org/cmd/",
		},
	},
	"https://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"https://golang.org/",
			"https://golang.org/cmd/",
			"https://golang.org/pkg/fmt/",
			"https://golang.org/pkg/os/",
		},
	},
	"https://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
	"https://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
}



// Set up Go environment, start experimenting with importing modules, creating modules, basic testing, etc. (Just need to do the Getting Started section, the rest was covered in this blog)
// https://golang.org/doc/

// Go more in-depth into Concurrency in Go
// https://golang.org/ref/mem
// https://talks.golang.org/2012/concurrency.slide#1
// https://talks.golang.org/2013/advconc.slide#1
// https://golang.org/doc/codewalk/sharemem/

// Learn to write web applications in Go
// https://talks.golang.org/2012/simple.slide#1
// https://golang.org/doc/articles/wiki/

// More info on the features available in the standard library, as well as language specification of Go
// https://golang.org/pkg/
// https://golang.org/ref/spec

// For an interesting read on how functions can be used intuitively in Go
// https://golang.org/doc/codewalk/functions/

// To get more insight into the design decisions Go's creators made
// https://golang.org/doc/faq
