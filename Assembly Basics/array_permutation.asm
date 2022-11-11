# Array stored in $a0
# Permutations stored in $a1
# Length stored in $a2

# C program function: Permutation is an array of indices. 
# For each element in the array, swap its value with the of the item with the 
# same index in permutation.

# Store iterator in $s0
# Store current location in array at $s1, location in perm at $s2
# Temp vars: arr[i] = $s3, address of arr[perm[i]] = $s4, arr[perm[i]] = $s6
# Store imm 32 in $s5 because MIPS has no multiply immediate


# Note to self: Always use instructions for *unsigned ints* w/ registers containing pointers
main: 
	addu $s0, $a2, $zero 	# Store length in $s0
	addu $s1, $a0, $zero 	# Store array location in $s1
	addu $s2, $a1, $zero 	# Store perm location in $s2
	addiu $s5, $zero, 32	# Store imm 32 in $s5 because MIPS has no mult immediate

loop: 
	blt $s0, 1, return 		# Return if $s0 less than 1

	lw $s3, 0($s1)			# Load value of array element into $s3
	lw $s4, 0($s2)			# Load value of perm element into $s4
	mul $s4, $s4, $s5		# Multiply $s4 by 32 
	subu $s4, $s1, $s4 		# Store location of arr[perm[i]] in $s4
	lw $s6, 0($s4) 			# Load value of arr[perm[i]] into $s6

	sw $s6, 0($s1) 			# Store value of arr[perm[i]] at arr[i]
	sw $s3, 0($s4) 			# Store old value of arr[i] at arr[perm[i]]

	addi $s0, $s0, -1 		# Decrement $s0 by 1
	addi $s1, $s1, -32 		# Decrement $s1 (array location) by 32
	addi $s2, $s2, -32 		# Decrement $s2 (perm location) by 32

	j loop


return: 
	j $ra 					# End of file
