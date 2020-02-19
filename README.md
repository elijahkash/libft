# *LIBFT*
This project is one of the first and major in **_School 42_**.
This is `C` library with my own implementation of some of the `libc` functions including some additional useful ones.
At the first stage of schooling (about 10 projects for me) we had to use `C` language, and Standart C Library is forbidden for us! So, starting with such basic utilites as `memcpy(); memmove(); strlen();`, I wrote this library for use it in all of the following `C` projects. Now, in addition to the basic functions, it contains a number of useful modules.
Here is a partial list:
- simple memory manager
- dynamic array (similar to a `vector` in c++)
- dynamic cyclical deque
- dynamic list, realised on array (for best performance)
- get_next_line() (aka getline() from libc) + fast_input_gnl()
- ft_printf() (my own printf() from stdio.h)
- output buffer (implemented for ft_printf() but as part of the libft)
- print_memory (like `xdd` util in unix)
- qsort
- and other
### More detailed description [posted on wiki](https://github.com/elijahkash/libft/wiki)

_*Also this library includes 3 projects of "School 42":*_ [libft, ft_get_next_line, ft_printf](https://www.google.com/search?q=ecole+42+subjects&oq=ecole+42+subjects) (Sorry for Google, but by law, I can't upload tasks.)

## Foreword

- Be welcome to use my lib, `clone` and `fork` it!
- If you find a bug, please, create new `issue` (or contact with me in any way you want) to report about it! I will be glad to fix it! If you find a mistake in my spelling (because I'm from Russia, and English is not my native language), please notify me too!
- If you `clone/fork` this lib and realise some new feature, you can create `pull request`! I am definitely interested in this!
- Also, I will be happy if you `follow` me, or `star` this project, ecpecially if you find it usefull, or use my code!
- For all questions be welcome to contact me in any way you want 👋
> Here is my  mail: _elijahkash.code@gmail.com_

## How to use:

#### 1. Compile

- run `make` or `make libft` to compile `libft.a`
- run `make clean` to delete tmp files after compile (only `libft.a` will be remain)
- run `make fclean` to delete all files after compile
- run `make cmake` if you change any filename.c/h to update the configuration of build (and include new file)
- run `make re` to recompile all files

> _There is no real need to do this! If you change a file and run `make`, the project will recompile this file, as well as all files that depend on this file and relink the lib!_

#### 2. Include

To use `libft` in you project:
- just `#include <libft.h>`
- compile you files with `-I /libft/includes` 
- compile `libft`
- link you binary with `-L /libft -lft`

#### 3. Debug

If you run `make` or `make libft`, the compiler will compile the library with the `-O3 -Wall -Wextra -Werror` flags for better code performance and strict error checking!
But if you want to debug some code, you probably want to ignore warnings and be able to use a debugger (lldb, gdb, etc.).
In that case
- run `make debug`

`libftdebug.a` will be created, and compiler flags now will be `-g3 -Wall -Wextra`.

#### 4. Quick opportunity test

If you want to quick execute some code, to test something (does not matter what exactly), write it in [/test/test.c](/test/test.c) than
- run `make test`

`/test/test` binary file will be created! Also, it use `libftdebug.a` (and build it, if necessary) and use `-g3` flag, so you can use debugger to debug you code!

#### 5. If you use Visual Studio code ...

... then you can find something useful in [.vscode](/.vscode)
- press `CMD + SHIFT + B` to build `libft.a` (default keys is VSC) - same to run `make`
- press `F5` to build `libftdebug.a`, `/test/test`, and start debug session of `/test/test` binary  

#### 6. Cmake

In fact, I use `Cmake`, to compile this lib. You may find [CMakeLists.txt](CMakeLists.txt) with it config.

If you use my project, as `submodule` for you project, and use `Cmake` too, you can `add_subdirectory(${LIBFT_DIR})`
and `add_dependencies(${YOUR_PROJECT} libft)` or `add_dependencies(${YOUR_PROJECT_DEBUG} libftdebug)` to easy configure dependencies!

> _Of course, first time I don't use Cmake, because it's forbidden by subject! So if you just started in 42, watch out! Write you own Makefile!_

## Template

Want to start new project and use my `libft`?

You can use [THIS TEMPLATE](https://github.com/elijahkash/libft_based_template)

> If you don't know nothing about template repositories, [read man](https://help.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-from-a-template)!

## NORMINETTE

If you are part of the **_42_** society, you now all about the *_norminette_* and you may skip this part.
Otherwise, you may discover some strange `code` and /file_structure in this project.
This is becouse all project in **_42_** must be written in [accordance with the NORM](https://www.google.com/search?q=ecole+42+norme.en.pdf&oq=ecole+42+norme.en.pdf).

Here are the point that most affect the code:
- You cannot have more than 5 function-definitions in a `.c` file.

We have programm called `norminette`. It check every project. If it found an error, project considered as **FAIL**

## Contributors

- I would like to say a few words of gratitude to my teammate @odrinkwa ([@semrunner](https://github.com/SemRunner)) by the `ft_printf` _project_, for develop [`float/double/long double`](/sources/printf_src/bn_for_double) part of printf! Thanks a lot!

## License
- See the [LICENSE](./LICENSE) file for license rights and limitations (MIT).

## Support
- If you like my activity, you may say “thank you” to me and support me for any amount! Use 'Sponsor' button in github!
