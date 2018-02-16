# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 23:04:33 by vguerand          #+#    #+#              #
#    Updated: 2018/02/16 02:43:05 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player1=carli.filler
player2=vguerand.filler

n_turns=10
map=00

# dont touch after this line --------------------------------------------------

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./filler_vm -f ./maps/map$map -p1 \
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

echo $player1
echo $p1
echo $player2
echo $p2
