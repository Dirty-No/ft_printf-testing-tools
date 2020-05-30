# ft_printf-testing-tools
ft_printf testing tools provides you tools to compare your ft_printf to the real printf.
 # SETUP
Just clone this repository where the Makefile for ft_printf is.

You may have to change the libftprintf.h's path in the .c source files it isn't located at the same place as the Makefile.
# FEATURES
 - test.sh allows you to compile and run src/test.c
- src/test.c contains :
	-  A variadic macro T_PRINTF() that compare your ft_printf to the real printf
	- Some pre-made tests
	- Memory leaks check with system leaks (installed on 42's Macs)
	- Return errors check (ft_printf's return != printf's return) 
	- Pretty colors

Feel free to copy and use T_PRINTF() how you want, it is located at the very top of src/test.c .

- diff_it.sh allows to diff the output of ft_printf and the output of the real printf
	- To use it, simply write any test you want in src/diff_it.c using printer() and launch diff_it.sh, the script will automatically compile the program, run it using printf and ft_printf, and diff the outputs.

	-  If nothing seems no happen when you launch the script, it means there is no difference between ft_printf's output and printf's output.

# CONTACT
If you encounter any issue with this project and wish to contact me:

 - E-Mail : smaccary@student.42.fr
 - Twitter : [https://twitter.com/slutymeme](https://twitter.com/slutymeme)
 
 (I'll reply way faster on twitter)
 
 (Don't worry I have nothing else to do)



Shortcut to this repo : https://s.42l.fr/ptf
