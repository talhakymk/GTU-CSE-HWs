.data
#grid:  .asciiz  ".....................................O...O...O....O..O............O..O...O...O....O..O...O...O...........O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O....O..O...O...O.."
grid:   .space 258
Str1:  .asciiz "Please enter map: "
bombIndex:   .word 256
bomb:   .byte 'O'
length:  .word 256

.text
main:
    #printing Str1
    la $a0, Str1
    li $v0, 4
    syscall
    
    #read input grid
    la $a0, grid
    li $a1, 258
    li $v0, 8
    syscall
    jal print_grid
    
    #finding bomb indexes and bomb number
    la $s2, bombIndex
    lb $s0, bomb # O represents bomb
    li $t0, 0 # restarting t0 register (probably unnecesery)
    li $t1, 0 # restarting t1 register (probably unnecesery)
    li $t2, 0 # restarting t2 register (probably unnecesery)
    li $t3, 0 # restarting t3 register (probably unnecesery)
    li $t4, 0 # restarting t4 register (probably unnecesery)
    li $t5, 0 # restarting t5 register (probably unnecesery)
    li $t6, 0 # restarting t6 register (probably unnecesery)
    
    #loop
    	add $t0, $zero, $zero # index -> t0, initialized as 0
	add $s3, $zero, $zero # counter -> t1, initialized as 0
	la $s1, grid # save address of the
Loop:	beq $t0, 258, LoopExit 
	lb $t3, 0($s1) # storing current grid index for comparing
	addi $s1, $s1, 1
	addi $t0, $t0, 1 # index ++
	bne $t3, $s0, Loop
	addi $s3, $s3, 1 # counter ++
	subi $t0, $t0, 1
	sw $t0, 0($s2) #Saving bomb indexes to array
	addi $s2, $s2, 4 #Adding four because one integer is four byte
	addi $t0, $t0, 1
	j Loop
LoopExit:
       # li $v0, 1
	#move $a0, $s3 #printing bomb number
	#syscall
#/////////////////////////////////////////////////////////////////control of bomb index and printing it	
	la $a0, bombIndex

    # Load the value at index 2 (assuming the array has at least 3 elements)
    li $t1, 0
    mul $t2, $t1, 4      # Each element is 4 bytes (word)
    add $t3, $a0, $t2    # $t3 = base address + offset
    lw $a0, 0($t3)       # Load the value at index 2 into $a0

    # Print the integer
    #li $v0, 1            # System call code for print_int
    #syscall
   
 #//////////////////////////////////////////////////////////////////////////////////////////second 2 (fill everywhere with bomb)
    # Load the base address of the string
    la $a0, grid

    # Load the character to fill the string
    li $t0, 'O'

    # Load the number of characters to fill
    li $t1, 256  # Adjust the size as needed

    # Loop to fill the string
    fill_loop:
        # Store the character in the string
        sb $t0, 0($a0)

        # Move to the next character
        addi $a0, $a0, 1

        # Decrease the count
        subi $t1, $t1, 1

        # Continue the loop if more characters need to be filled
        bnez $t1, fill_loop

    # Null-terminate the string
    sb $zero, 0($a0)
   jal print_grid
   j hadi
 
hadi:
   #//////////////////////////////////////////////////////////////second three which means all bombs boom
   
   la $t0, bombIndex #addres of bombIndex
   la $t1, grid #addres of grid
   li $s0, 46 #ASCII value of .
   add $t2, $zero, $zero #grid index counter
   add $t4, $zero, $zero #bombIndex index counter
Looop: 
       lw $t3, 0($t0) #storing bomb index into t3 register
       beq $t2, $t3, make_bomb #if bomb index and grid index equal then plant the bomb
       addi $t2, $t2, 1 #increasing grid index counter
       addi $t1, $t1, 1 #increasing grid index
       j Looop
       
make_bomb: sb $s0, 0($t1) # this makes . to bomb index in grid
	   addi $t2, $t2, 1 # add one to index
	   bgt $t2, 256, dontAddOne #control that if we pass the boundries
	   addi $t1, $t1, 1 #increasing grid index if everything is okey
	   sb $s0, 0($t1) #putting . to right side of a bomb
	   subi $t1, $t1, 1 #because of we increased index with one we have to decrease it one so 
	   j OneAdded
dontAddOne:jal dontAddOne_reverse #if we dont add one because of the boundries go to reverse function
OneAdded:  
	   subi $t2, $t2, 1 #decreasing grid index counter 
	   blt $t2, 0, dontSubOne #control that if we pass the boundries
	   subi $t1, $t1, 1 #decreasing grid index if everything is okey
	   sb $s0, 0($t1) #putting . to left side of a bomb
	   addi $t1, $t1, 1 #because of we decreased index with one we have to increase it one so 
	   j OneSubed
dontSubOne:jal dontSubOne_reverse #if we dont sub one because of the boundries go to reverse function
OneSubed:
	   addi $t2, $t2, 16 # add sixteen to index
	   bgt $t2, 270, dontAddSixteen #control that if we pass the boundries (256+16=271)
	   addi $t1, $t1, 16 #increasing grid index if everything is okey
	   sb $s0, 0($t1) #putting . to bottom side of a bomb
	   subi $t1, $t1, 16 #because of we increased index with one we have to decrease it one so 
	   j SixteenAdded
dontAddSixteen:jal dontAddSixteen_reverse #if we dont add sixteen because of the boundries go to reverse function
SixteenAdded:
	   subi $t2, $t2, 16 #decreasing grid index counter 
	   blt $t2, 0, dontSubSixteen #control that if we pass the boundries
	   subi $t1, $t1, 16 #decreasing grid index if everything is okey
	   sb $s0, 0($t1)  #putting . to up side of a bomb
	   addi $t1, $t1, 16 #because of we decreased index with sixteen we have to increase it one so 
	   j SixteenSubed
dontSubSixteen:jal dontSubSixteen_reverse #if we dont sub sixteen because of the boundries go to reverse function
SixteenSubed:

	   addi $t0, $t0, 4 #increase bombIndex index (integers are 4 bytes so we increase it 4)
	   addi $t4, $t4, 1 #increase bombIndex counter for comparison
	   beq $s3, $t4, continue #comparing bomb number and bombIndex index (if they are equal then all bombs handled)
	   j Looop
continue:  jal print_grid
	   j exit

dontAddOne_reverse:subi $t2, $t2, 1 #because we dont add one we must subtract 1 to index 
		   jr $ra
dontSubOne_reverse:addi $t2, $t2, 1 #because we dont sub one we must subtract 1 to index 
	           jr $ra
dontAddSixteen_reverse:subi $t2, $t2, 16 #because we dont add sixteen we must subtract 1 to index 
		         jr $ra
dontSubSixteen_reverse:addi $t2, $t2, 16 #because we dont sub sixteen we must subtract 1 to index 
	           	   jr $ra
#////////////////////////////////////////////////////////////////////////////
    print_grid:    # PRINT GRID
    li $t0, 0 # Outer loop index (i)

outer_loop:
    li $t1, 0 # Inner loop index (j)

inner_loop:
    # Calculate the offset into the array
    li $t2, 16 # Number of columns
    mul $t3, $t0, $t2 # $t3 = row * num_columns
    add $t4, $t3, $t1 # $t4 = row * num_columns + column

    # Calculate the memory address of the array element
    la $t5, grid # Load base address of the array
    add $t6, $t5, $t4 # $t6 = base address + offset

    # Load the character from the array element
    lb $a0, 0($t6) # Load the character to be printed

    # Print the character
    li $v0, 11 # Print character system call
    syscall

    # Update inner loop index
    addi $t1, $t1, 1
    bne $t1, 16, inner_loop

    # Print a newline character for better readability
    li $a0, 10 # ASCII value of newline character
    li $v0, 11 # Print character system call
    syscall

    # Update outer loop index
    addi $t0, $t0, 1
    bne $t0, 16, outer_loop
    li $a0, 10 # ASCII value of newline character
    li $v0, 11 # Print character system call
    syscall
    jr $ra
	
exit:
    # Exit program////////////////////////////////////////////////////////////////////////////////////////
    li $v0, 10 # Exit system call
    syscall
