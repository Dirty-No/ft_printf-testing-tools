
# ft_printf-testing-tools
**ft_printf testing tools provides you tools and tests to compare your ft_printf to the real printf.
ft_printf is a 42 school's project where you have to recreate C stdio's printf from scratch.**

 # SETUP
### Run this command in the directory where libftprintf.a is created :

   ### `make && git clone https://github.com/Dirty-No/ft_printf-testing-tools.git && cd ft_printf-testing-tools`

#### You may have to change ft_printf's header filepath in ptf_tester.h if the relative path is not *`"../../libftprintf.h"`.
# FEATURES
 - ### `test.sh` allows you to compile and run the code located in src/main.c
- `src/main.c` allow you to use :
	
	- #### A default unit test.
	-  A variadic macro `T_PRINTF()` that compare your ft_printf to the real printf.
	- Memory leaks check with system leaks (installed on 42's Macs).
	- Return errors check (ft_printf's return != printf's return) .
	- Pretty colors.

Feel free to copy and use `T_PRINTF()` how you want, it is located at the very top of `src/ptf_tester.h .`

- ### diff_it.sh allows to diff the output of ft_printf and the output of the real printf
	- To use it, simply write any test you want in src/diff_it.c using printer() and launch diff_it.sh, the script will automatically compile the program, run it using printf and ft_printf, and diff the outputs.
	-  #### By default, an unit test is launched but nothing prevents you from adding your own tests.

	-  If nothing seems no happen when you launch the script, it means there is no difference between ft_printf's output and printf's output.

# CONTACT
If you encounter any issue with this project and wish to contact me:

 - E-Mail : smaccary@student.42.fr
 - Twitter : [https://twitter.com/slutymeme](https://twitter.com/slutymeme)
 
 (I'll reply way faster on twitter)
 
 (Don't worry I have nothing else to do)

# USEFUL

### Shortcut to this repo : https://s.42l.fr/ptf
