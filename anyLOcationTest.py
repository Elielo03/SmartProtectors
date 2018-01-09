#require pyhton3
#to install geocoder run #pip install geocoder

import geocoder

'''
use 'me' in 'ip_here' for your device ip, or put another ip you want
'''
#geo = geocoder.ip('ip_here')
geo = geocoder.ip('me')

latitude = geo.latlng[0]
longitude = geo.latlng[1]

print("latitude", latitude)
print("longitude", longitude)
