# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:56:45 by cchen             #+#    #+#              #
#    Updated: 2021/12/07 12:31:49 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To be executed in github actions environment. Takes all necessary .c and .h
# files, and places them in the root repositor for submission

rm -rf ./intra-uuid-*/*
sed '/prod/,$d' ./$REPO_NAME/Makefile > ./$REPO_NAME/Makefile
cp ./$REPO_NAME/author ./intra-uuid-*
cp ./$REPO_NAME/Makefile ./intra-uuid-*
cp ./$REPO_NAME/srcs/p1/* ./intra-uuid-*
cp ./$REPO_NAME/srcs/p2/* ./intra-uuid-*
cp ./$REPO_NAME/srcs/bonus/* ./intra-uuid-*
cp ./$REPO_NAME/includes/* ./intra-uuid-*
