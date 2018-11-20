# A simple python script to scrape a website's html
from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
from json import loads

def simple_get(url):
    """
    Attempts to get the content at `url` by making an HTTP GET request.
    If the content-type of response is some kind of HTML/XML, return the
    text content, otherwise return None.
    """
    try:
        with closing(get(url, stream=True)) as resp:
            if is_good_response(resp):
                return resp.content
            else:
                return None

    except RequestException as e:
        log_error('Error during requests to {0} : {1}'.format(url, str(e)))
        return None


def is_good_response(resp):
    """
    Returns True if the response seems to be HTML, False otherwise.
    """
    content_type = resp.headers['Content-Type'].lower()
    return (resp.status_code == 200
            and content_type is not None)


def log_error(e):
    """
    It is always a good idea to log errors.
    This function just prints them, but you can
    make it do anything.
    """
    print(e)

tag = input("enter your blizzard battle tag: ")
#platformm codes are xbl, psn, pc
platform = input("enter the platform you play on: ")
#region codes are us, eu, kr, cn, global
region = input("enter your region (eu, us etc...) ")

tag = tag.replace("#", "-")

url = "https://ow-api.com/v1/stats/" + platform + "/" + region + "/" + tag + "/profile"

print(url)

raw_html = simple_get(url)

print(raw_html)
str = raw_html.decode('utf8')

json = loads(str)

print("rank:", json["rating"])

soup = BeautifulSoup(raw_html, 'html.parser')
#this is how we scrape and print the code of a website.

#let's put it in a file
#print(soup.prettify().encode('utf8'))

f = open("Overscrape.html", "w")
f.close()
#writing in binary mode because the encode outputs binary encoded utf8 and not a string
f = open("Overscrape.html", "wb")

f.write(soup.prettify().encode('utf8'))

input("enter to close")