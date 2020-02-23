## Hive Helsinki Sudoku Group Project

This was a rush group project, which means the project had to be done in one weekend.

To run the Sudoku program:
1. Compile the file with `gcc -o sudoku *.c`
2. Run `./sudoku line1 line2 line3 line4 line5 line6 line7 line8 line9 | cat -e`. 

Where each line is a 9-char string, number to indicate existing sudoku, . to indicate empty space. 

Example `/sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e`

3. Then, you shall see the result. If output is  `Error`, it might because you enter the format the input wrong or it's a non-solvable sudoku. 

The solution for the example:
```
./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e
9 1 4 3 7 5 2 6 8 $
2 8 7 4 9 6 1 5 3 $
3 6 5 8 1 2 4 7 9 $
8 4 6 5 2 1 3 9 7 $
5 2 9 6 3 7 8 1 4 $
7 3 1 9 8 4 5 2 6 $
1 5 3 7 4 9 6 8 2 $
6 9 8 2 5 3 7 4 1 $
4 7 2 1 6 8 9 3 5 $
```
