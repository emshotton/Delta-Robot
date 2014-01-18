#!/usr/bin/env python
import matplotlib.pyplot as plt
import matplotlib

print(matplotlib.rcsetup.all_backends)

def main():
	Vin = 3.0

	Ry = 1200.0
	R1 = 1200.0

	f = open("data.txt")
	data = []
	for l in f:
		(Rv, temp) = l.split()
		temp = float(temp)
		Rv = float(Rv) * 1000.0
		#Rv = 420.0 #variable
		Rx = (Rv * R1)/(Rv + R1)
		#Rx = Rv
		I = (Vin/(Ry+Rx))
		Vout = I*Rx
		#print Vout, I, Rv, temp
		data.append((Vout, temp))

	volt, temp = zip(*data)
	p = plt.plot(volt, temp)
	plt.show()
	plt.savefig("out.png")


if __name__ == "__main__":
	main()