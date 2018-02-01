# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 23:04:33 by vguerand          #+#    #+#              #
#    Updated: 2017/12/28 23:04:39 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player1=carli.filler
player2=tfontain.filler

n_turns=10
map=00

# dont touch after this line --------------------------------------------------

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./resources/filler_vm -f ./resources/maps/map$map -p1 \
		./resources/players/$player1 -p2 \
		./resources/players/$player2
	result=$(cat filler.trace | grep won)
	if echo "$result" | grep -q "$player1"
	then
		((p1++))
	else
		((p2++))
	fi
	((n_turns--))
done

echo $player1
echo $p1
echo $player2
echo $p2
