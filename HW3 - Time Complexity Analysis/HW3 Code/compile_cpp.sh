#Compile the code
# if the file HW3 exits then remove it
if [ -f HW3 ]; then
    rm HW3
fi
g++ HW3.cpp -o HW3
# if the file HW3 does not exit then exit the test
if [ ! -f HW3 ]; then
    echo   "\033[1;91mCompile FAILED.\033[0m"
    exit
fi