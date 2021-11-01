# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:56:45 by cchen             #+#    #+#              #
#    Updated: 2021/11/01 16:55:06 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To be executed in github actions environment. Takes all necessary .c and .h
# files, and places them in the root repositor for submission

cp ./${{ github.event.repository.name }}/author ./libft_vogsphere
cp ./${{ github.event.repository.name }}/Makefile ./libft_vogsphere
cp ./${{ github.event.repository.name }}/srcs/* ./libft_vogsphere
cp ./${{ github.event.repository.name }}/includes/* ./libft_vogsphere
