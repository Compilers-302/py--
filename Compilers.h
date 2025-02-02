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
* File name: Compilers.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: 301
* Assignment: A12, A22, A32.
* Date: Jan 27 2025
* Professor: Paulo Sousa
* Purpose: This file defines the functions called by main function.
* Function list: mainReader(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: reader > scanner > parser).
 * ............................................................................
 */

/* TO_DO: Adjust your language (cannot be "py--") */

/* TO_DO: Language name */
#define STR_LANGNAME	"py--"

/* TO_DO: Logical constants - adapt for your language */
#define PYM_TRUE		1
#define PYM_FALSE		0
#define PYM_ERROR		(-1)	/* General error message */

#define PYM_INVALID	NULL

/*
------------------------------------------------------------
Data types definitions
NOTE: Some types may not be directly used by your language,
		but they can be necessary for conversions.
------------------------------------------------------------
*/


/* TO_DO: Define your typedefs */
typedef char			pym_char;
typedef char*			pym_str;
typedef int				pym_int;
typedef float			pym_float;
typedef void			pym_void;

typedef char			pym_bool;
typedef unsigned char	pym_byte;

typedef long			pym_long;
typedef double			pym_double;

/*
------------------------------------------------------------
Programs:
1: Reader - invokes MainReader code
2: Scanner - invokes MainScanner code
3: Parser - invokes MainParser code
------------------------------------------------------------
*/
enum PROGRAMS {
	PGM_READER  = '1',
	PGM_SCANNER = '2',
	PGM_PARSER  = '3'
};

/*
------------------------------------------------------------
Main functions signatures
(Code will be updated during next assignments)
------------------------------------------------------------
*/
pym_int mainReader(pym_int argc, pym_str* argv);
/* TO_DO: Remove comment in next assignments */
/*
sofia_intg mainScanner(sofia_intg argc, sofia_string* argv);
sofia_intg mainParser(sofia_intg argc, sofia_string* argv);
*/

pym_void printLogo();

#endif
