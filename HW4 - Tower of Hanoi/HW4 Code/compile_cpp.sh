#Compile the code
# if the file HW4 exits then remove it
if [ -f HW4 ]; then
    rm HW4
fi
g++ HW4.cpp -o HW4
# if the file HW1 does not exit then exit the test
if [ ! -f HW4 ]; then
    echo   "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
