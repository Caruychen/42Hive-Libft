# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:56:45 by cchen             #+#    #+#              #
#    Updated: 2021/12/07 12:25:20 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To be executed in github actions environment. Takes all necessary .c and .h
# files, and places them in the root repositor for submission

rm -rf ./$VOGSPHERE/*
cp ./$REPO_NAME/author ./$VOGSPHERE/author
sed '/prod/,$d' ./$REPO_NAME/Makefile > ./$VOGSPHERE/Makefile
cp ./$REPO_NAME/srcs/p1/* ./$VOGSPHERE/
cp ./$REPO_NAME/srcs/p2/* ./$VOGSPHERE/
cp ./$REPO_NAME/srcs/bonus/* ./$VOGSPHERE/
cp ./$REPO_NAME/includes/* ./$VOGSPHERE/
