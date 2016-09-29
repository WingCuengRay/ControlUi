import serial  
import random
import time


def send_rubbish(cnt, delay, usart):
	while 1:
		ba = bytearray(cnt);
		i = 0;
		while i < cnt:
			ba[i] = random.randint(0, 255);
			i = i+1;
		print ba;
		usart.write(ba);
		time.sleep(delay);
	
# def send_message(mess, len, t)
#	for num in mess:
#		t.write(num);
		
  
t = serial.Serial('com4',9600);
n = t.write('you are my world');

send_rubbish(5, 1, t);