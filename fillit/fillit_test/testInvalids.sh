# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testErrors.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 11:02:08 by vvaltone          #+#    #+#              #
#    Updated: 2019/11/25 11:05:21 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
echo "Running fillit with no arguments gives this output:"
../fillit
echo ""
echo "Running fillit with two arguments gives this output:"
../fillit valid1 valid2
echo ""
echo "Invalid 1 looks like this: "
cat -e invalid1
echo "And the output is: "
../fillit invalid1
echo ""
echo "Invalid with bad character looks like this: "
cat -e invalidbadchar
echo "And the output is: "
../fillit invalidbadchar
echo ""
echo "Invalid with no new line looks like this: "
cat -e invalidnonewline
echo "And the output is: "
../fillit invalidnonewline
echo ""
echo "File with 27 tetriminos shoud give us error:"
../fillit invalid27