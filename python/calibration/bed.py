#!/usr/bin/env python
from  control import Delta


def main():
	delta = Delta()

	delta.move_to(0,0,10)
	print
	print "moving to 40, 40, 10"
	raw_input('press enter to continue..')
	delta.move_to(40,40,10)
	print
	print "Decending"
	raw_input('press enter to continue..')
	delta.move_to(40,40,0, 500)
	delta.move_to(40,40,10, 500)

	print
	print "moving to -40, 40, 10"
	raw_input('press enter to continue..')
	delta.move_to(-40,40,10)
	print
	print "Decending"
	raw_input('press enter to continue..')
	delta.move_to(-40,40,0, 500)
	delta.move_to(-40,40,10, 500)	

	print
	print "moving to -40, -40, 10"
	raw_input('press enter to continue..')
	delta.move_to(-40,-40,10)
	print
	print "Decending"
	raw_input('press enter to continue..')
	delta.move_to(-40,-40,0, 500)
	delta.move_to(-40,-40,10, 500)	

	print
	print "Moving to 40, -40, 10"
	raw_input('press enter to continue..')
	delta.move_to(40,-40,10)
	print
	print "Decending"
	raw_input('press enter to continue..')
	delta.move_to(40,-40,0, 500)
	delta.move_to(40,-40,10, 500)	

	print
	print "Resetting"
	raw_input('press enter to continue..')
	delta.move_to(0,0,10)




if __name__ == "__main__":
	main()