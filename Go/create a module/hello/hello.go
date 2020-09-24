// https://golang.org/doc/tutorial/call-module-code

// https://golang.org/doc/tutorial/handle-errors

// For compiling and installing: https://golang.org/doc/tutorial/compile-install

package main

import (
	"fmt"
	"log"

	"example.com/greetings"
)

func main() {
	// Set properties of the predefined Logger, including
	// the log entry prefix and a flag to disable printing
	// the time, source file, and line number.
	log.SetPrefix("greetings module: ")
	log.SetFlags(0)

	// Request a greeting message.
	message, err := greetings.Hello("Gokul") // Pass "" to test error handling
	// If an error was returned, print it to the console and
	// exit the program.
	if err != nil {
		log.Fatal(err)
	}

	// If no error was returned, print the returned message
	// to the console.
	fmt.Println(message)

	// https://golang.org/doc/tutorial/greetings-multiple-people

	// A slice of names.
	names := []string{"Gokul1", "Gokul2", "Gokul3"}

	// Request greeting messages for the names.
	messages, err := greetings.Hellos(names)
	if err != nil {
		log.Fatal(err)
	}
	// If no error was returned, print the returned map of
	// messages to the console.
	fmt.Println(messages)
}
