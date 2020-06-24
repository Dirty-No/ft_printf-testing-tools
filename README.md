
# ft_printf-testing-tools (NEW CURSUS)
**ft_printf testing tools provides you tools and tests to compare your ft_printf to the real printf.**

**ft_printf is a 42 school's project where you have to recreate C stdio's printf from scratch.**

 # SETUP
### Run this command in the directory where libftprintf.a is created :

   #### `git clone https://github.com/Dirty-No/ft_printf-testing-tools.git && cd ft_printf-testing-tools`

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

The default tests are based on ft_printf correction's instructions, no unnessecary tests are made.

# CONTACT
If you encounter any issue with this project and wish to contact me:

 - E-Mail : smaccary@student.42.fr
 - Twitter : [https://twitter.com/slutymeme](https://twitter.com/slutymeme)
 - 42's slack : smaccary
 - You may also find me on 42's discord server from time to time
 
## USEFUL LINKS FOR FT_PRINTF

### Shortcut to this repo : https://s.42l.fr/ptf

#### PFT_2019 tester : https://github.com/cclaude42/PFT_2019

#### mazoise's tester https://github.com/Mazoise/42TESTERS-PRINTF

#### printf-unit-test https://github.com/alelievr/printf-unit-test

