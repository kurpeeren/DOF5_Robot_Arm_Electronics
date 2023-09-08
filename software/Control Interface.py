import serial
import time
import pyautogui
arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=115200, timeout=.1)
def map_range(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data


#while True:
  #  num = input("Enter a number: ")
  #  value = write_read(num)
 #   print(value)



import pyglet
import pyglet.window.key
import struct




width = 500
height = 500
title = "Kol Test"


window = pyglet.window.Window(width, height, title)

text = "TrexDCAS"
led = struct.pack("BBBB",255,255,255,255)


label = pyglet.text.Label(text,
						font_name ='Times New Roman',
						font_size = 36,
						x = window.width//2, y = window.height//2,
						anchor_x ='center', anchor_y ='center')

new_label = pyglet.text.Label(text,
						font_name ='Times New Roman',
						font_size = 10,
						x = 25, y = 25)
@window.event
def on_draw():

	
	window.clear()
	
	label.draw()

@window.event
def on_key_press(symbol, modifier):

	if symbol == pyglet.window.key.C:
		
		print("Key C is pressed")


"""
@window.event
def on_mouse_motion(x, y, dx, dy):

	print(str(x)+","+str(y))
"""

@window.event
def on_mouse_drag(x,y,dx,dy,buttons,modifiers):
	
    print(str(x)+","+str(y)+","+str(dx)+","+str(dy)+","+str(buttons))

global ii
ii=0
# on mouse scroll event
@window.event
def on_mouse_scroll(x, y, scroll_x, scroll_y):
	global ii
	
	if(scroll_y==1):
		
		ii+=5
	
	else:
		
		ii-=5
		
	if (ii<0 or ii>255):
		ii=10
	# printing some message
	print("Mouse scrolled"+str(x)+","+str(y)+","+str(scroll_x)+","+str(scroll_y)+",")
	ere="""{},{},{}\n""".format(map_range(x,0,180,0,500),map_range(y,0,180,0,500),map_range(ii,0,180,0,500))
	write_read(ere)
	#value = write_read(ere+str(struct.unpack("l",struct.pack("BBBBBBBB",ii,0,128-int(ii/2),int(ii/2)+128,0,0,0,0)))[1:-2]+"\n")
	#print("12,12,12,12,12,12,"+str(struct.unpack("l",struct.pack("BBBBBBBB",255,255,255,255,0,0,0,0)))[1:-2]+"\n")
	print(ere)



pyglet.app.run()
