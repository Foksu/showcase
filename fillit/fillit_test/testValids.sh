# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testValids.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 11:17:29 by vvaltone          #+#    #+#              #
#    Updated: 2019/11/25 11:17:36 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
echo "Valid 1 looks like this: "
cat -e valid1
echo "And the output is: "
../fillit valid1
echo ""

echo "Valid 2 looks like this: "
cat -e valid2
echo "And the output is: "
../fillit valid2
echo ""

echo "Valid 3 looks like this: "
cat -e valid3
echo "And the output is: "
../fillit valid3
echo ""

echo "Valid 4 looks like this: "
cat -e valid4
echo "And the output is: "
../fillit valid4
echo ""

echo "Valid 5 looks like this: "
cat -e valid5
echo "And the output is: "
../fillit valid5
echo ""

echo "Valid All Horizontal looks like this: "
cat -e validAllHoriz
echo "And the output is: "
../fillit validAllHoriz
echo ""

echo "Valid All L looks like this: "
cat -e validAllL
echo "And the output is: "
../fillit validAllL
echo ""

echo "Valid All Squares looks like this: "
cat -e validAllSquares
echo "And the output is: "
../fillit validAllSquares
echo ""

echo "And now we should be getting stuck in really big file called Valid26:"
../fillit valid26
