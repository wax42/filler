# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 23:04:33 by vguerand          #+#    #+#              #
#    Updated: 2018/03/06 08:18:13 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player2=carli.filler
player1=vguerand.filler

# dont touch after this line --------------------------------------------------

map=0;
p1=0;
p2=0;

while [ $map != 3 ]
do
	n_turns=3
	while [ $n_turns != 0 ]
	do
		./filler_vm -f ./maps/map0$map -p1 \
			./players/$player1 -p2 \
			./players/$player2
		result=$(cat filler.trace | grep won)
		if echo "$result" | grep -q "$player1"
		then
			((p1++))
		else
			((p2++))
		fi
		((n_turns--))
	done
	((map++))
done
echo $player1
echo $p1
echo $player2
echo $p2
