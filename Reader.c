/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Winter, 2025
* Author: Aayush Sajwan | Amardeep Sandhu
* Professors: Paulo Sousa
************************************************************
#
# ECHO "=--------------------------------------------------="
# ECHO "|       COMPILERS - ALGONQUIN COLLEGE (W25)        |"
# ECHO "=--------------------------------------------------="
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@ /    - - - - - -    \@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   /    @@@@@@   \   |@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   |    @@@@@@@   |   |@@@---------@@@    ”
# ECHO "    @@@@@|   |    @@@@@@@   |   |@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   |    @@@@@@@   |   |@@@---------@@@    ”
# ECHO "    @@@@@|   |	  @@@@@@   /    |@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   | -----------     |@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   |    ____________/@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@|   \  |@@@@@@| /   |@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@@|   \  |@@@@| /   |@@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@@@|   \  |@@| /   |@@@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@@@@|   \     /   |@@@@@@@@@@    ”
# ECHO "    @@@@@|   |   |@@@@@@@|    |    |@@@@@@@@@@@@    ”
# ECHO "    @@@@@@\_____/@@@@@@@@|    |    |@@@@@@@@@@@@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@|    |    |@@@@@@@@@@@@    ”
# ECHO "    @@@@@@ P Y - - @@@@@@|___ | ___|@@@@@@@@@@@@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "                                                    "
# ECHO "[READER SCRIPT ....................................]"
# ECHO "                                                    "
*/

/*
***********************************************************
* File name: Reader.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: 301
* Assignment: A12.
* Date: May 01 2024
* Professor: Paulo Sousa
* Purpose: This file is the main code for Buffer/Reader (A12)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * - Please check the "TODO" labels to develop your activity.
 * - Review the functions to use "Defensive Programming".
 *.............................................................................
 */

#include <ctype.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#include "Reader.h"
#endif

 /*
 ***********************************************************
 * Function name: readerCreate
 * Purpose: Creates the buffer reader according to capacity, increment
	 factor and operational mode ('f', 'a', 'm')
 * Author: Svillen Ranev / Paulo Sousa
 * History/Versions: S22
 * Called functions: calloc(), malloc()
 * Parameters:
 *   size = initial capacity
 *   increment = increment factor
 *   mode = operational mode
 * Return value: bPointer (pointer to reader)
 * Algorithm: Allocation of memory according to inicial (default) values.
 * TODO ......................................................
 *	- Adjust datatypes for your LANGUAGE.
 *   - Use defensive programming
 *	- Check boundary conditions
 *	- Check flags.
 *************************************************************
 */

BufferPointer readerCreate(pym_int size, pym_int increment, pym_char mode) {
	BufferPointer readerPointer;
	pym_int count = 0;
	/* TO_DO: Defensive programming */
	if (size < 0)
		return PYM_INVALID;
	if (!size)
		size = READER_DEFAULT_SIZE;
	if (!increment)
		increment = READER_DEFAULT_INCREMENT;
	if (!mode)
		mode = MODE_FIXED;
	readerPointer = (BufferPointer)calloc(1, sizeof(Buffer));
	if (!readerPointer)
		return PYM_INVALID;
	readerPointer->content = (pym_str)malloc(size);
	/* TO_DO: Defensive programming */
	if (!readerPointer->content)
	{
		free(readerPointer);
		return PYM_INVALID;
	}
		
	/* TO_DO: Initialize the histogram */
	for (int i = 0; i < NCHAR; i++)
	{
		readerPointer->histogram[i] = 0;
	}
	
	/* TO_DO: Initialize errors */

	readerPointer->mode = mode;
	readerPointer->size = size;
	readerPointer->increment = increment;
	/* TO_DO: Initialize flags */
	readerPointer->flags.isEmpty = PYM_TRUE;
	readerPointer->flags.isFull = PYM_FALSE;
	readerPointer->flags.isMoved = PYM_FALSE;
	readerPointer->flags.isRead = PYM_FALSE;
	/* TO_DO: Default checksum */
	readerPointer->checksum = 0;
	return readerPointer;
}


/*
***********************************************************
* Function name: readerAddChar
* Purpose: Adds a char to buffer reader
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   ch = char to be added
* Return value:
*	readerPointer (pointer to Buffer Reader)
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

BufferPointer readerAddChar(BufferPointer readerPointer, pym_char ch) {
	pym_str tempReader = PYM_INVALID;
	pym_int newSize = 0;
	pym_char tempChar = ' ';
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_INVALID;

	if (!ch)
		return PYM_ERROR;

	/* TO_DO: Reset Realocation */
	readerPointer->flags.isMoved = PYM_FALSE;
	//realloc(readerPointer->size, newSize);
	/* TO_DO: Test the inclusion of chars */
	if (readerPointer->positions.wrte * (pym_int)sizeof(pym_char) < readerPointer->size) {
		/* TO_DO: This buffer is NOT full */
		readerPointer->flags.isFull = PYM_ERROR;
	}
	else {
		/* TO_DO: Reset Full flag */
		readerPointer->flags.isEmpty = PYM_FALSE;
		readerPointer->flags.isFull = PYM_FALSE;
		readerPointer->flags.isMoved = PYM_FALSE;
		readerPointer->flags.isRead = PYM_FALSE;

		switch (readerPointer->mode) {
		case MODE_FIXED:
			/* TO_DO: Update the last position with Terminator */
			readerPointer->positions.wrte = PYM_ERROR;
			readerPointer->positions.read = PYM_ERROR;
			readerPointer->positions.mark = PYM_ERROR;
			break;
		case MODE_ADDIT:
			/* TO_DO: Update size for Additive mode */
			newSize = readerPointer->size + readerPointer->increment;
			/* TO_DO: Defensive programming */
			if (newSize >= 0 && newSize < READER_MAX_SIZE)
				return readerPointer->size = newSize;
			break;
		case MODE_MULTI:
			/* TO_DO: Update size for Additive mode */
			newSize = readerPointer->size * readerPointer->increment;
			/* TO_DO: Defensive programming */
			if (newSize >= 0 && newSize < READER_MAX_SIZE)
				return readerPointer->size = newSize;
			break;
		default:
			return PYM_INVALID;
		}
		/* TO_DO: Reallocate */
		tempReader = (pym_str)realloc(readerPointer->content, newSize);
		//readerPointer->content = realloc(readerPointer->content, newSize);
		/* TO_DO: Defensive programming */
		if (readerPointer->content == PYM_INVALID)
			return PYM_INVALID;
		return readerPointer;
	}
	/* TO_DO: Update the flags */
	if (readerPointer->positions.wrte == readerPointer->size) {
		readerPointer->flags.isFull = 1;
	}

	if (readerPointer->positions.wrte == 0) {
		readerPointer->flags.isEmpty = 1;
	}

	readerPointer->flags.isMoved = 1;
	readerPointer->content[readerPointer->positions.wrte++] = ch;
	/* TO_DO: Updates histogram */
	readerPointer->histogram[ch]++;
	return readerPointer;
}

/*
***********************************************************
* Function name: readerClear
* Purpose: Clears the buffer reader
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerClear(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_INVALID;
	/* TO_DO: Adjust the write, mark and read to zero */
	readerPointer->positions.wrte = PYM_FALSE;
	readerPointer->positions.read = PYM_FALSE;
	readerPointer->positions.mark = PYM_FALSE;
	/* TO_DO: Adjust flags */
	readerPointer->flags.isFull = PYM_FALSE;
	readerPointer->flags.isEmpty = PYM_TRUE;
	readerPointer->flags.isRead = PYM_FALSE;
	readerPointer->flags.isMoved = PYM_FALSE;
	return PYM_TRUE;
}


/*
***********************************************************
* Function name: readerFree
* Purpose: Releases the buffer address
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerFree(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Free pointers */
	if (readerPointer->content)
		free(readerPointer->content);
	free(readerPointer);
	return PYM_TRUE;
}


/*
***********************************************************
* Function name: readerIsFull
* Purpose: Checks if buffer reader is full
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerIsFull(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Check flag if buffer is FUL */
	if (readerPointer->flags.isFull == PYM_TRUE)
		return PYM_TRUE;
	return 0;
}


/*
***********************************************************
* Function name: readerIsEmpty
* Purpose: Checks if buffer reader is empty.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerIsEmpty(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Check flag if buffer is EMP */
	return readerPointer->flags.isEmpty;
}

/*
***********************************************************
* Function name: readerSetMark
* Purpose: Adjust the position of mark in the buffer
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   mark = mark position for char
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerSetMark(BufferPointer const readerPointer, pym_int mark) {
	/* TO_DO: Defensive programming */
	if (!readerPointer || mark < 0 || mark > readerPointer->positions.wrte)
		return PYM_FALSE;
	/* TO_DO: Adjust mark */
	readerPointer->positions.mark = mark;
	return PYM_TRUE;
}



/*
***********************************************************
* Function name: readerPrint
* Purpose: Prints the string in the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Number of chars printed.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerPrint(BufferPointer const readerPointer) {
	pym_int cont = 0;
	pym_char c;
	/* TO_DO: Defensive programming (including invalid chars) */
	if (!readerPointer)
		return PYM_FALSE;

	c = readerGetChar(readerPointer);
	while (cont < readerPointer->positions.wrte) {
		cont++;
		printf("%c", c);
		c = readerGetChar(readerPointer);
	}
	return cont;
}

/*
***********************************************************
* Function name: readerLoad
* Purpose: Loads the string in the buffer with the content of
	an specific file.
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   fileDescriptor = pointer to file descriptor
* Return value:
*	Number of chars read and put in buffer.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerLoad(BufferPointer readerPointer, FILE* const fileDescriptor) {
    pym_int size = 0;
    pym_char c;
    
    /* TO_DO: Defensive programming */
	if (!readerPointer || !fileDescriptor)
		return PYM_ERROR;

	while (!feof(fileDescriptor)) {
		c = (pym_char)fgetc(fileDescriptor);
		if (c == EOF)
			break;

		if (!readerAddChar(readerPointer, c))
			return PYM_ERROR;

		size++;
	}

    return size;
}


/*
***********************************************************
* Function name: readerRecover
* Purpose: Rewinds the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerRecover(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;

	/* TO_DO: Recover positions: read and mark must be zero */
	readerPointer->positions.read = PYM_FALSE;
	readerPointer->positions.mark = PYM_FALSE;
	/* TO_DO: Update flags */
	readerPointer->flags.isRead = PYM_FALSE;

	return PYM_TRUE;
}


/*
***********************************************************
* Function name: readerRetract
* Purpose: Retracts the buffer to put back the char in buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerRetract(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	if (readerPointer->positions.read <= 0)
		return PYM_FALSE;
	/* TO_DO: Retract (return 1 pos read) */
	readerPointer->positions.read--;

	return PYM_TRUE;
}

/*
***********************************************************
* Function name: readerRestore
* Purpose: Resets the buffer.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Boolean value about operation success
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_bool readerRestore(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Restore positions (read to mark) */
	readerPointer->positions.read = readerPointer->positions.mark;

	return PYM_TRUE;
}



/*
***********************************************************
* Function name: readerGetChar
* Purpose: Returns the char in the getC position.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Char in the getC position.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_char readerGetChar(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer || !readerPointer->content)
		return PYM_INVALID;

	/* TO_DO: Check condition to read */
	if (readerPointer->positions.read >= readerPointer->size)
		return PYM_INVALID;  // Return EOF or a sentinel value if out of bounds

	/* TO_DO: Read character and increment read position */
	return readerPointer->content[readerPointer->positions.read++];
}


/*
***********************************************************
* Function name: readerGetContent
* Purpose: Returns the pointer to String.
* Parameters:
*   readerPointer = pointer to Buffer Reader
*   pos = position to get the pointer
* Return value:
*	Position of string char.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_str readerGetContent(BufferPointer const readerPointer, pym_int pos) {
	/* TO_DO: Defensive programming */
	if (!readerPointer || pos < 0 || pos >= readerPointer->positions.wrte)
		return PYM_INVALID;
	return readerPointer->content + pos;
}


/*
***********************************************************
* Function name: readerGetPosRead
* Purpose: Returns the value of getCPosition.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	The read position offset.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetPosRead(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Return read */
	return readerPointer->positions.read;
}


/*
***********************************************************
* Function name: readerGetPosWrte
* Purpose: Returns the position of char to be added
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Write position
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetPosWrte(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return 0;
	/* TO_DO: Return wrte */
	return readerPointer->positions.wrte;
}


/*
***********************************************************
* Function name: readerGetPosMark
* Purpose: Returns the position of mark in the buffer
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Mark position.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetPosMark(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return 0;
	/* TO_DO: Return mark */
	return readerPointer->positions.mark;
}


/*
***********************************************************
* Function name: readerGetSize
* Purpose: Returns the current buffer capacity
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Size of buffer.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetSize(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return 0;
	/* TO_DO: Return size */
	return readerPointer->size;
}

/*
***********************************************************
* Function name: readerGetInc
* Purpose: Returns the buffer increment.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	The Buffer increment.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetInc(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return 0;
	/* TO_DO: Return increment */
	return readerPointer->increment;
	return 0;
}

/*
***********************************************************
* Function name: readerGetMode
* Purpose: Returns the operational mode
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Operational mode.
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_char readerGetMode(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_ERROR;
	/* TO_DO: Return mode */
	return readerPointer->mode;
}

/*
***********************************************************
* Function name: readerShowStat
* Purpose: Shows the char statistic.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value: (Void)
* TO_DO:
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_void readerPrintStat(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;

	/* TO_DO: Updates the histogram */
	pym_bool first = PYM_TRUE;
	for (pym_int i = 0; i < NCHAR; i++) {
		if (readerPointer->histogram[i] > 0) {
			if (!first)
				printf(", ");
			printf("B [%c] = %d", (char)i, readerPointer->histogram[i]);
			first = PYM_FALSE;
		}
	}
	printf("\n");
}

/*
***********************************************************
* Function name: readerNumErrors
* Purpose: Returns the number of errors found.
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	Number of errors.
* TO_DO:
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
pym_int readerGetNumErrors(BufferPointer const readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Returns the number of errors */
	return readerPointer->numReaderErrors;
}

/*
***********************************************************
* Function name: readerCalcChecksum
* Purpose: Calculates the checksum of the reader (8 bits).
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	[None]
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

pym_void readerCalcChecksum(BufferPointer readerPointer) {
	pym_int i;
	pym_byte checksum = 0;

	/* Defensive programming */
	if (!readerPointer)
		return;

	/* Calculate checksum */
	for (i = 0; i < readerPointer->positions.wrte; i++)
		checksum += (pym_byte)readerPointer->content[i];

	readerPointer->checksum = checksum;
}

/*
***********************************************************
* Function name: readerPrintFlags
* Purpose: Sets the checksum of the reader (4 bits).
* Parameters:
*   readerPointer = pointer to Buffer Reader
* Return value:
*	[None]
* TO_DO:
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

pym_bool readerPrintFlags(BufferPointer readerPointer) {
	/* TO_DO: Defensive programming */
	if (!readerPointer)
		return PYM_FALSE;
	/* TO_DO: Shows flags */
	printf("isEmpty: %d\n", readerPointer->flags.isEmpty);
	printf("isFull: %d\n", readerPointer->flags.isFull);
	printf("isRead: %d\n", readerPointer->flags.isRead);
	printf("isMoved: %d\n", readerPointer->flags.isMoved);

	return PYM_TRUE;
}
