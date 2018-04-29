##
 #  @filename   :   main.cpp
 #  @brief      :   2.7inch e-paper display demo
 #  @author     :   Yehui from Waveshare
 #
 #  Copyright (C) Waveshare     August 16 2017
 #
 # Permission is hereby granted, free of charge, to any person obtaining a copy
 # of this software and associated documnetation files (the "Software"), to deal
 # in the Software without restriction, including without limitation the rights
 # to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 # copies of the Software, and to permit persons to  whom the Software is
 # furished to do so, subject to the following conditions:
 #
 # The above copyright notice and this permission notice shall be included in
 # all copies or substantial portions of the Software.
 #
 # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 # IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 # FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 # AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 # LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 # OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 # THE SOFTWARE.
 ##

import epd2in7
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw

from datetime import datetime, timedelta
import urllib2, urllib, json

location = 'taipei'
#https_proxy = 'http://proxy-chain.intel.com:912'

def weather():
    # proxy
    try:
        if https_proxy:
            proxy = urllib2.ProxyHandler({'https': https_proxy})
            opener = urllib2.build_opener(proxy)
            urllib2.install_opener(opener)
    except:
        pass

    baseurl = "https://query.yahooapis.com/v1/public/yql?"
    yql_query = 'select * from weather.forecast where woeid in (select woeid from geo.places(1) where text="' + location + '") and u="c"'
    yql_url = baseurl + urllib.urlencode({'q':yql_query}) + "&format=json"
    result = urllib2.urlopen(yql_url).read()
    data = json.loads(result)

    forecast = data['query']['results']['channel']['item']['forecast']
    today = forecast[0]
    day1  = forecast[1]
    day2  = forecast[2]
    return (today, day1, day2)

sunny  = Image.open('sunny.bmp')
night  = Image.open('night.bmp')
cloudy = Image.open('cloudy.bmp')
haze   = Image.open('haze.bmp')
rain   = Image.open('rain.bmp')
showers= Image.open('showers.bmp')

def weather_cond(text):

    if 'Cloud' in text:
        return cloudy
    if ('Showers' in text):
	return showers
    if ('Showers' in text) or ('storms' in text) or ('Rain' in text):
        return rain

def main():
    epd = epd2in7.EPD()
    epd.init()

    # static resources
    #intel = Image.open('intel.bmp').resize((100,100))
    
    font48 = ImageFont.truetype('FreeMonoBold.ttf', 48)
    font22 = ImageFont.truetype('FreeMonoBold.ttf', 22)
    font18 = ImageFont.truetype('FreeMonoBold.ttf', 18)

    # For simplicity, the arguments are explicit numerical coordinates
    image = Image.new('1', (epd2in7.EPD_HEIGHT, epd2in7.EPD_HEIGHT), 255)    # 255: clear the image with white
    draw = ImageDraw.Draw(image)

    # Current time
    now = datetime.now()
    # time
    draw.text((0, 0), now.strftime("%b,%d"), font = font48, fill = 0)
    # date
    draw.text((0, 48), now.strftime("%A, WW%W"), font = font22, fill = 0)

    # get weather from Yahoo!
    (today, day1, day2) = weather()

    # Today's weather condition
    image.paste(weather_cond(today['text']), (200, 0))
    print "Today weather: "+today['text']

    # Today's temperature
    draw.text((200, 64), today['high']+'-'+today['low'], font = font22, fill = 0)
    print "Today temperature range: "+today['high']+'-'+today['low']

    # Inter-section bar
    draw.line((0, 90, 264, 90), fill = 0)

    # Day+1
    image.paste(weather_cond(day1['text']), (0, 94))
    nextday = now + timedelta(1)
    draw.text((64+2, 94), nextday.strftime('%a%d'), font = font22, fill = 0)
    draw.text((64+2, 94+32), day1['high']+'-'+day1['low'], font = font22, fill = 0)
    draw.text((2, 94+32+22+8), day1['text'][:10], font = font22, fill = 0)
    print "Tomorrow weather: "+day1['text']
    print "Tomorrow temperature range: "+day1['high']+'-'+day1['low']

    # Day+2
    image.paste(weather_cond(day2['text']), (132+2, 94))
    nextday = now + timedelta(2)
    draw.text((64+2+132, 94), nextday.strftime('%a%d'), font = font22, fill = 0)
    draw.text((64+2+132, 94+32), day2['high']+'-'+day2['low'], font = font22, fill = 0)
    draw.text((132+2, 94+32+22+8), day2['text'][:10], font = font22, fill = 0)
    print nextday.strftime('%a%d')+" weather: "+day2['text']
    print nextday.strftime('%a%d')+" temperature range: "+day2['high']+'-'+day2['low']

    # Inter-section bar
    draw.line((132, 90, 132, 184), fill = 0)
    draw.line((0, 184, 264, 184), fill = 0)

    # others
    #image.paste(intel, (66, 166))

    #draw.arc((90, 190, 150, 250), 0, 360, fill = 0)
    #draw.chord((90, 120, 150, 180), 0, 360, fill = 0)
    #draw.rectangle((10, 200, 50, 250), fill = 0)

    image = image.rotate(90).resize((epd2in7.EPD_WIDTH, epd2in7.EPD_HEIGHT))

    epd.display_frame(epd.get_frame_buffer(image))

    # display images
    #epd.display_frame(epd.get_frame_buffer(Image.open('monocolor.bmp')))

if __name__ == '__main__':
    main()
