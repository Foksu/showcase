This was a group project. 

After finishing [libft](https://github.com/Foksu/showcase/tree/master/libft), fillit is the
second mandatory project before [get\_next\_line](https://github.com/Foksu/showcase/tree/master/get_next_line),
and after that, you branch out. The purpose is to make the
smallest possible "square" (which can contain holes) with a given list of
tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```

My fillit tester can be found here: https://github.com/foksu/fillit_test
