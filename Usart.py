import serial  
import random
import time
import thread


def send_rubbish(cnt, delay, usart):
	j = 0;
	while 1:
		ba = bytearray(cnt);
		i = 0;
		while i < cnt:
			ba[i] = random.randint(0, 255);
			i = i+1;
		# print [hex(x) for x in ba];
		j = j+1;
		if j%100 == 0:
			print("Rubbish Have been sent: " + str(j) + " times\n");
		try:
			t.write(ba);
		except:
			print("Write Rubbish error\n");
		time.sleep(delay);

def send_message(mess, delay, usart):
	i = 0;
	while 1:
		try:
			t.write(mess);
		except:
			print("Write Message error\n");
		i = i+1;
		if i%100 == 0:
			print("have Sent: "+ str(i) + " times\n");
		time.sleep(delay);


'''
def send_message(delay, usart):
	i = 0;
	while 1:
		t.write(mess);
		i = i+1;
		if i%100 == 0:
			print("have Sent: "+ str(i) + " times\n");
		time.sleep(delay);
'''
		
  
t = serial.Serial('com4', 9600);
n = t.write('you are my world');

''' the assignment of Object: bytearray  '''
# mess = bytearray(b'\x7e\x06\x06\x58\x49\x23\x59\x68\x03\x7e');
mess = bytearray(b'\x7e\x01\x55\x54\x7e');
# mess = bytearray(b'\x7e\x01\x7D\x31\x10\x7e');


# change bytearray (char) to array (int)
# mess_hex = [ hex(x) for x in bytearray(b'\x7e\x01\x55\x54\x7e')];
# print mess_hex;


try:
	thread.start_new_thread(send_message, (mess, 0.001, t));
	thread.start_new_thread(send_rubbish, (5, 0.002, t));
except:
	print "Error: unable to start thread"
	
while 1:
	pass