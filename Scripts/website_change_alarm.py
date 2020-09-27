import urllib.request as req
import ssl
import time

# A simple script that beeps or sounds an alarm when a URL or website's HTML contents change (if online)

print("\n\nGokul's \"Has the website changed?\" alarm\n")

url = input("Enter a website to check (with http / https tag): ")

freq = int(input("Enter pinging frequency in seconds: "))

context = ssl._create_unverified_context()

changed = False

res = None

while True:

    if changed:
        print("Website HTML contents have changed! ctrl + c to stop")
        print('\a', end="\r")
        time.sleep(2)
        continue

    try:
        print("Attempting to load: ", url)
        if res == None:
            temp = req.urlopen(url, context=context)
            res = temp.read()
            print("Website seems to be online")
        else:
            new = req.urlopen(url, context=context).read()
            if new == res:
                print("No change")
            else:
                changed = True


    except:
        print("Website is offline")

    time.sleep(freq)

    


