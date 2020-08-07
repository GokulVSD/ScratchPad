import urllib.request as req
import time

# A simple script that beeps or sounds an alarm when a URL or website responds to a request or is online

print("\n\nGokul's \"Is the website is online yet?\" alarm\n")

url = input("Enter a website to ping (with http / https tag): ")

counter = 1

while True:

    try:
        print("Attempting to load: ", url, "\tAttempt Counter: ", counter)
        req.urlopen(url)
        counter += 1

    except:
        print("Website is offline")
        print("Resetting attempt counter, ctrl + c to stop")
        counter = 1
        time.sleep(2)

    if counter >= 5:
        print("Website is online! ctrl + c to stop")
        print('\a', end="\r")
        time.sleep(2)


