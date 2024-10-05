/* Defines functions for converting characters between tabs and spaces.
 * CSC 357, Assignment 1
 * Given code, Spring '24. */

#include "chars.h"
#include "string.h"
#include "stdio.h"

/* istext: Checks whether or not a character is plain text.
 * NOTE: Do not alter this function. It returns 1 if "c" has an ASCII code in
 *       the ranges [0x08, 0x0D] or [0x20, 0x7E], and 0 otherwise. */
int istext(char c) {
 return (c >= 0x08 && c <= 0x0D) || (c >= 0x20 && c <= 0x7E);
}


 int getIndex(char str[]){
    int i = 0;
    for (i = 0; i < 9; i++){
        if (str[i] != '\0'){
            continue;
        }
        else{
            return i;
        }
    }
return i;
}

/* ttos: Converts a character from tabs to spaces.
 *  * TODO: Implement this function. It should return the number of characters
 *   *       placed into "str": 1 to 8 spaces if "next" is a tab (depending on the
 *    *       current line length), and "next" otherwise. Use "dflt" instead if
 *     *       "next" is not plain text, and do nothing if neither is plain text.
 *      *       See also the given unit tests. */



int currentcharactercount = 0;

int ttos(char next, char str[], char dflt) {
    int usethischar; /* the valid character I want to use */
    /* str[0] = '\0';  initialize the string to be empty */

   /* printf("what is in the string right now: '%s'\n", str);*/

    if (istext(next) == 0) { /* if next is not printable */
        if (istext(dflt) == 1) {  /* if default is printable */
            usethischar = dflt; /* then use default */
        } else {
            usethischar = '\0'; /* if default is also not printable return 0 */
        }
    } else {
        usethischar = next; /* if next is printable use next */
    }

    if (usethischar != '\0') { /* if it's a valid character */

     /*   printf("what is in the string right now: '%s'\n", str);*/

        /* then proceed to check other cases */
        if (usethischar == '\t') { /* if it's a tab */
            int i = 0;
            int spacestoadd; /* initialize the variable here */

          /*  printf("what is in the string right now: '%s'\n", str);*/

          /*  printf("getIndex(str) returns: %d\n", getIndex(str));*/

          /*  printf("current charactercount before calculating: '%d'\n", currentcharactercount);*/
            spacestoadd = 8 - (currentcharactercount % 8); /* calculate the spaces to add */

          /*  printf("spaces to add: %d\n", spacestoadd);*/

          /*  printf("str before adding spaces: '%s'\n", str);*/

            for (i = 0; i < spacestoadd; i++) { /* for all the spaces that need to be added */
                str[i] = ' '; /* add a space to the string array */
            }
            str[i] = '\0';

         /*   printf("str after adding spaces: '%s'\n", str);*/
	    
	    currentcharactercount = 0; /* once reaching the next tab stop, clear it */	 

            return spacestoadd;
        }

        if (usethischar == '\n') { /* if the character is a new line */

          /*  printf("str before adding newline/char: '%s'\n", str);*/

            str[0] = '\n'; /* add in the new line */
            str[1] = '\0'; /* indicate string is done */
	    currentcharactercount = 0;
           /* printf("str after adding newline/char: '%s'\n", str);*/
            return 1;
        }
        else { /* if usethischar is just a char */

         /*   printf("what char am I looking at rn: '%c'\n", usethischar);*/

	 /*   printf("current charactercount: '%d'\n", currentcharactercount);*/
   

            str[0] = usethischar; /* add in the char */

	   /* printf("str after adding in the regular char: '%s'\n", str);*/

            currentcharactercount ++;
            str[1] = '\0'; /* indicate string is done */
            return 1;
        }
    }
    else { /* if not a valid character just do nothing */
        str[0] = '\0';
        return 0;
    }
    return 0;
   /* printf("current length of string: %d\n", getIndex(str));*/
}

/* stot: Converts a character from spaces to tabs.
 *  * TODO: Implement this function. It should return the number of characters
 *   *       placed into "str": a tab or nothing if "next" is a space (depending on
 *    *       the current line length), and 0 to 7 spaces followed by "next"
 *     *       otherwise. Use "dflt" instead if "next" is not plain text, and do
 *      *       nothing if neither is plain text. See also the given unit tests. */

int spacecount = 0;
int charactercount = 0;

int stot(char next, char str[], char dflt) {
    int usethischar; /* the valid character I want to use */

 /*   printf("current spacecount: '%d'\n", spacecount);*/
 /*   printf("current charactercount: '%d'\n", charactercount);*/

    if (istext(next) == 0) { /* if next is not printable */
        if (istext(dflt) == 1) {  /* if default is printable */
            usethischar = dflt; /* then use default */
        } else {
            usethischar = 0; /* if default is also not printable return 0 */
        }
    } else {
        usethischar = next; /* if next is printable use next */
    }

  /*  printf("char being used: '%c'\n", usethischar);*/

    if (usethischar != 0) { /* if it's a valid character */
        /* then proceed to check other cases */
        if (usethischar == ' ') { /* if it's an empty space */
            spacecount++;
	    

  	/*    printf("current charactercount '%d'\n", charactercount);*/
        /*    printf("current spacecount: '%d'\n", spacecount);*/

	    if((spacecount + charactercount) % 8 == 0){
                str[0] = '\t';
                str[1] = '\0';
                spacecount = 0;
                charactercount = 0;
		
	/*	printf("what is in the string right now: '%s'\n", str);*/

                return 1;
            }
            else {
	   /* printf("BOOBS \n");*/
            str[0] = '\0';
            return 0;
        }
       }
       
        /* as soon as the next thing isn't a space */
      /*  if (usethischar == '\n') {
            str[0] = '\n';
            str[1] = '\0';
            spacecount = 0; 
            charactercount = 0;
            return 1;
        } */
          else { /* if it's just a character */
            /* check for if space count is not zero and I am at a character */

	   /* printf("space count before adding regular character: '%d'\n", spacecount);*/

            if (spacecount > 0) {
                int i = 0;
                /* initialize the variable here */
		
	/*	printf("character count: '%d'\n", charactercount);*/
		

		

	/*	printf("SPACECOUNT: '%d'\n", spacecount);*/

                 /* calculate the spaces to add */


                for (i = 0; i < spacecount; i++) { /* for all the spaces that need to be added */
                    str[i] = ' '; /* add a space to the string array */
                }

                str[spacecount] = usethischar;
		i = spacecount + 1;
		charactercount = charactercount+ spacecount + 1;
		str[spacecount + 1] = '\0';
		spacecount = 0;
		if ((usethischar == '\t') || (usethischar == '\n')){
                   charactercount = 0;
                }
                return i;
            }
            else {
		if (usethischar == '\n'){
	     	  str[0] = '\n';
                  str[1] = '\0';
                  spacecount = 0;
                  charactercount = 0;
                  return 1;
              }

		if (usethischar == '\t'){
                  str[0] = '\t';
                  str[1] = '\0';
                  spacecount = 0;
                  charactercount = 0;
                  return 1;
              }
 
                str[0] = usethischar;
                str[1] = '\0';

	/*	printf("string when its just a character: '%s'\n", str);*/
                charactercount++; /* update charactercount */
		return 1;
		}
            }
        }
    else { /* if not a valid character just do nothing */
        str[0] = '\0';
        return 0;   
    }
return 0;
}


