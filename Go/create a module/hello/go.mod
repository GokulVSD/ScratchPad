module hello

go 1.15

replace example.com/greetings => ../greetings // Omit if module is published on the web

require example.com/greetings v0.0.0-00010101000000-000000000000
