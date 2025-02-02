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
# ECHO "    @@@@@|   | -----------	   |@@@@@@@@@@@@@@@@    ”
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
************************************************************
* File name: Reader.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: 301
* Assignment: A12.
* Date: Feb 2 2025
* Professor: Paulo Sousa
* Purpose: This file is the main header for Reader (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * Please check the "TODO" labels to develop your activity.
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#define READER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer reader) */
enum READER_MODE {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls (not need to change) */
#define READER_TERMINATOR	'\0'							/* General EOF */

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* You should add your own constant definitions here */
#define READER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

#define READER_DEFAULT_SIZE			250		/* default initial buffer reader capacity */
#define READER_DEFAULT_INCREMENT	10		/* default increment factor */

#define NCHAR				128			/* Chars from 0 to 127 */

#define CHARSEOF			(-1)		/* EOF Code for Reader */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct flag {
	pym_bool isEmpty;			/* indicates if the buffer is empty */
	pym_bool isFull;			/* indicates if the buffer is full */
	pym_bool isRead;			/* indicates if the buffer was completely read */
	pym_bool isMoved;			/* indicates if the buffer memory was changed */
} Flag;

/* Offset declaration */
typedef struct position {
	pym_int wrte;			/* the offset to the add chars (in chars) */
	pym_int read;			/* the offset to the get a char position (in chars) */
	pym_int mark;			/* the offset to the mark position (in chars) */
} Position;

/* Buffer structure */
typedef struct bufferReader {
	pym_str		content;			/* pointer to the beginning of character array (character buffer) */
	pym_int		size;				/* current dynamic memory size (in bytes) allocated to character buffer */
	pym_int		increment;			/* character array increment factor */
	pym_char	mode;				/* operational mode indicator */
	Flag		flags;				/* contains character array reallocation flag and end-of-buffer flag */
	Position	positions;			/* Offset / position field */
	pym_int		histogram[NCHAR];	/* Statistics of chars */
	pym_int		numReaderErrors;	/* Number of errors from Reader */
	pym_byte	checksum;
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer	readerCreate		(pym_int, pym_int, pym_char);
BufferPointer	readerAddChar		(BufferPointer const, pym_char);
pym_bool		readerClear		    (BufferPointer const);
pym_bool		readerFree		    (BufferPointer const);
pym_bool		readerIsFull		(BufferPointer const);
pym_bool		readerIsEmpty		(BufferPointer const);
pym_bool		readerSetMark		(BufferPointer const, pym_int);
pym_int			readerPrint		    (BufferPointer const);
pym_int			readerLoad			(BufferPointer const, FILE* const);
pym_bool		readerRecover		(BufferPointer const);
pym_bool		readerRetract		(BufferPointer const);
pym_bool		readerRestore		(BufferPointer const);
pym_void		readerCalcChecksum	(BufferPointer const);
pym_bool		readerPrintFlags	(BufferPointer const);
pym_void		readerPrintStat     (BufferPointer const);
/* Getters */
pym_char	readerGetChar		(BufferPointer const);
pym_str		readerGetContent	(BufferPointer const, pym_int);
pym_int		readerGetPosRead	(BufferPointer const);
pym_int		readerGetPosWrte	(BufferPointer const);
pym_int		readerGetPosMark	(BufferPointer const);
pym_int		readerGetSize		(BufferPointer const);
pym_int		readerGetInc		(BufferPointer const);
pym_char	readerGetMode		(BufferPointer const);
pym_int		readerGetNumErrors	(BufferPointer const);

#endif
