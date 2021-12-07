# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:56:45 by cchen             #+#    #+#              #
#    Updated: 2021/12/07 12:06:22 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To be executed in github actions environment. Takes all necessary .c and .h
# files, and places them in the root repositor for submission

rm -rf ./intra-uuid-*/*
cp ./$REPO_NAME/author ./intra-uuid-*
touch ./intra-uuid-*/Makefile
sed '/\nprod/,$d' ./$REPO_NAME/Makefile > ./intra-uuid-*/Makefile
cp ./$REPO_NAME/srcs/p1/* ./intra-uuid-*
cp ./$REPO_NAME/srcs/p2/* ./intra-uuid-*
cp ./$REPO_NAME/srcs/bonus/* ./intra-uuid-*
cp ./$REPO_NAME/includes/* ./intra-uuid-*
