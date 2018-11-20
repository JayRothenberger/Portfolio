# A simple python script to check for misspelled words.
import urllib.request
import urllib2
url = 'http://cs1110.cs.virginia.edu/files/words.txt'

stream = urllib.request.urlopen(url)
words = []
for line in stream:
    words.append(line.decode("utf-8").strip())
words.append("")
print("Type text; enter a blank line to end.")
line = "input"

while line != "":
    line = input()
    if line == "":
        break
    line = line.strip('.?!,()"').split(" ")
    for i in line:
        i = i.strip('.?!,()"')
        i = i.strip("'!")
        if i.lower() not in words:
            print("MISSPELLED: "+i)
