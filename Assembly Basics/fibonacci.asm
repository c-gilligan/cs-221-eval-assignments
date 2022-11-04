main: # Store iteration counter at $s0, previous two numbers at $s1 and $v0
	addi $a0, $0, 4 			# Set n = 4 for testing

	beq $a0, 0, return 		# If n = 0, return 0

	# Initialization conditions
	add $s1, $0, $0 		# Set $s1 = 0
	addi $v0, $0, 1 		# Set $v0 = 1
	addi $s0, $0, 1 		# Set $s0 = 1

loop:
	beq $s0, $a0, return # If i = n then jump to return

	add $v0, $s1, $v0 		# Add the previous two numbers together and store result at v0
	sub $s1, $v0, $s1		# s1 = v0 - s1 (find old value of v0 and move to s1)

	addi $s0, $s0, 1 		# Increment loop counter

	j loop 

return:
	j $ra 				# End of file