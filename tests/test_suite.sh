find units/ -name '*.c' -type f | sed 's/units\/\///g' | sed 's/\.c//g' > test_files.txt
make fclean
make test-prod
