import serial

class Delta:
	def __init__(self, comm_port='/dev/ttyACM0', enable_checksum=True):
		self.serial = serial.Serial(comm_port, 9600, timeout=1)
		self.command_counter = 0;
		self.enable_checksum = enable_checksum

	def __calculate_checksum__(self, cmd):
		checksum = 0
		for l in cmd:
			checksum = checksum ^ ord(l)
		return checksum

	def __send_command__(self, cmd):
		if self.enable_checksum:
			cmd = 'N'+str(self.command_counter)+' '+cmd
			cmd = cmd + '*'+str(self.__calculate_checksum__(cmd))
			self.command_counter += 1
		print cmd
		return
		self.serial.write(cmd)

		line= ''
		while not line.startswith("ok"):
			line = self.serial.readline()
			print line[:-1]
			if line.startswith("rs"):
				line_number = int(line[3:])
				raise Exception("Error: need to resend line number "+ str(line_number) + '\n'+cmd)

	def move_to(self, x,y,z, feedrate=3200):
		cmd = "G0 X"+str(x)+" Y"+str(y)+" Z"+str(z)+ " F"+str(feedrate)
		self.__send_command__(cmd)
