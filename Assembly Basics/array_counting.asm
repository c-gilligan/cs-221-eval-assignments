# I'm assuming these ints are signed because the assignment doesn't specify

# Array stored in $a0, length stored in $a1
# Compare values: $t0, $t1, $t2

# Counting results (range inclusive on bottom and exclusive on top)
# Less than all = $s0
# Greater than all = $s1
# Within range 1 = $s2
# Within range 2 = $s3

# Offset address = $a3 (increment by 4)
# Current int = $s4
main: 
	# Test case
	addi $t0, $zero, 10		# Set bottom of r1 to 10
	addi $t1, $zero, 20		# Set r1/r2 boundary to 20
	addi $t2, $zero, 30		# Set top of r2 to 30

	addi $sp, $sp, -32 		# Allocate memory for 1 element of test array
	add $a0, $sp, $zero 	# Store array address in $a0

	addi $s5, $zero, 1 		# Store imm 1 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $sp, $sp, -32 		# Allocate memory for another element
	addi $s5, $zero, 11 	# Store imm 11 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $sp, $sp, -32 		# Allocate memory for another element
	addi $s5, $zero, 12 	# Store imm 12 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $sp, $sp, -32 		# Allocate memory for another element
	addi $s5, $zero, 21		# Store imm 21 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $sp, $sp, -32 		# Allocate memory for another element
	addi $s5, $zero, 22 	# Store imm 22 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $sp, $sp, -32 		# Allocate memory for another element
	addi $s5, $zero, 31		# Store imm 31 in $s5
	sw $s5, 0($sp) 			# Store $s5 in stack 

	addi $a1, $zero, 6 		# Store size of array in $a1

	# Actual main stuff
	add $a3, $a0, $zero		# Initialize $a3
	add $s7, $a1, $zero 	# Store size of array in $s7


loop:
	blt $s7, 1, return 		# If $a1 < 1, return
	lw $s4, 0($a3)       	# Load current int

	# If int less than $t0, branch (increment $s0)
	blt $s4, $t0, below_ranges

	# If int less than $t1, branch (increment $s1)
	blt $s4, $t1, range_1

	# If int less than $t2, branch (increment $s2)
	blt $s4, $t2, range_2

	# If int geq $t2, branch (increment $s3)
	bge $s4, $t3, above_ranges

below_ranges:
	addi $s0, $s0, 1 		# Increment $s0
	addi $s7, $s7, -1 		# Decrement $a1
	addi $a3, $a3, -32 		# Decrement $a3 by 32
	j loop

range_1:
	addi $s1, $s1, 1 		# Increment $s1
	addi $s7, $s7, -1 		# Decrement $a1
	addi $a3, $a3, -32 		# Decrement $a3 by 32
	j loop

range_2: 
	addi $s2, $s2, 1 		# Increment $s2
	addi $s7, $s7, -1 		# Decrement $a1
	addi $a3, $a3, -32 		# Decrement $a3 by 32
	j loop

above_ranges: 
	addi $s3, $s3, 1 		# Increment $s3
	addi $s7, $s7, -1 		# Decrement $a1
	addi $a3, $a3, -32 		# Decrement $a3 by 32
	j loop

return: 
	j $ra 					# End of file

