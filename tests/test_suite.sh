find units/ -name '*.c' -type f -exec basename {} .c \; > test_files.txt
make fclean
make test-prod
