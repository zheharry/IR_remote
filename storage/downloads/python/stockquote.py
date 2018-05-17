import urllib
import re

def get_quote(symbol):
    base_url = 'https://www.bloomberg.com/quote/' + symbol
    content = urllib.urlopen(base_url).read()
    #print content
    p = re.search('class="priceText_(.*?)">(.*?)<', content)
    a = re.search('class="changeAbsolute_(.*?)">(.*?)<', content)
    b = re.search('class="changePercent_(.*?)">(.*?)<', content)
    c = re.search('class="price-container (.*?)"', content)
    e = re.search('class="price">(.*?)<', content)
    d = re.search('class="change-container">.*?<div>(.*?)</div>.*?<div>(.*?)</div>', content)
    #print p, a, b, c, e, d
    if p and a and b: # stocks
        price = p.group(2)
        abs   = a.group(2)
        per = b.group(2)
        print symbol, price, abs
        return symbol+' '+price+' '+abs
    elif c and e and d: # ETFs
        price = e.group(1)
        abs = d.group(1)
        per = d.group(2)
        sign = "+" if c.group(1) == "up" else "-"
        #print symbol, price, abs, per
        print symbol, price, sign+abs.lstrip()
        return symbol+' '+price+' '+sign+abs.lstrip()
