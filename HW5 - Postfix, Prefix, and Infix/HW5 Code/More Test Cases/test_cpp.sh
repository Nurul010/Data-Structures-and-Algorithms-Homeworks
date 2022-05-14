#Compile the code
# if the file HW5 exits then remove it
if [ -f HW5 ]; then
    rm HW5
fi
g++ HW5.cpp -o HW5
# if the file HW5 does not exit then exit the test
if [ ! -f HW5 ]; then
    echo   "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
rm -f *.output *.stdcout *.stderr 


#==================Infix to Postfix Test Cases========================================================
./HW5 2 "2-3*4+5/6" "itp_1.output" 1>itp_1.stdcout 2>itp_1.stderr
bash -c 'diff -iEBwu itp_1.output itp_1.txt >itp_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_1    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_1.diff
fi

./HW5 2 "(2+3)^4*5" "itp_2.output" 1>itp_2.stdcout 2>itp_2.stderr
bash -c 'diff -iEBwu itp_2.output itp_2.txt >itp_2.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_2    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_2    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_2.diff
fi

./HW5 2 "((1+(2*3))-4)" "itp_3.output" 1>itp_3.stdcout 2>itp_3.stderr
bash -c 'diff -iEBwu itp_3.output itp_3.txt >itp_3.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_3    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_3    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_3.diff
fi

./HW5 2 "((8*((((1+((2+3)*4))*6)*7)*5))+0)" "itp_4.output" 1>itp_4.stdcout 2>itp_4.stderr
bash -c 'diff -iEBwu itp_4.output itp_4.txt >itp_4.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_4    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_4    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_4.diff
fi

./HW5 2 "1+2-3*4+(5^6)*3/1/2*0+7" "itp_5.output" 1>itp_5.stdcout 2>itp_5.stderr
bash -c 'diff -iEBwu itp_5.output itp_5.txt >itp_5.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_5    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_5    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_5.diff
fi

./HW5 2 "(1*(2+(3/4)))" "itp_6.output" 1>itp_6.stdcout 2>itp_6.stderr
bash -c 'diff -iEBwu itp_6.output itp_6.txt >itp_6.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_6    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_6    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_6.diff
fi

./HW5 2 "1+(2*3+4)/5" "itp_7.output" 1>itp_7.stdcout 2>itp_7.stderr
bash -c 'diff -iEBwu itp_7.output itp_7.txt >itp_7.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_7    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_7    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_7.diff
fi

./HW5 2 "((4+5)-2*3^4-5*(6/3)+5-8*2^3)/6" "itp_8.output" 1>itp_8.stdcout 2>itp_8.stderr
bash -c 'diff -iEBwu itp_8.output itp_8.txt >itp_8.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_8    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_8    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_8.diff
fi

./HW5 2 "(5^2)^3-4*7^2+5+7*2^5+4^3/4" "itp_9.output" 1>itp_9.stdcout 2>itp_9.stderr
bash -c 'diff -iEBwu itp_9.output itp_9.txt >itp_9.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case itp_9    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case itp_9    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f itp_9.diff
fi

#==================Postfix Evaluation Test Cases========================================================

./HW5 3 "23+4^5*" "p_1.output" 1>p_1.stdcout 2>p_1.stderr
bash -c 'diff -iEBwu p_1.output p_1.txt >p_1.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_1      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_1      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_1.diff
fi


./HW5 3 "23+-" "p_2.output" 1>p_2.stdcout 2>p_2.stderr
bash -c 'diff -iEBwu p_2.output p_2.txt >p_2.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_2      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_2      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_2.diff
fi

./HW5 3 "42351-+*+*" "p_3.output" 1>p_3.stdcout 2>p_3.stderr
bash -c 'diff -iEBwu p_3.output p_3.txt >p_3.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_3      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_3      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_3.diff
fi

./HW5 3 "5379++" "p_4.output" 1>p_4.stdcout 2>p_4.stderr
bash -c 'diff -iEBwu p_4.output p_4.txt >p_4.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_4      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_4      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_4.diff
fi


./HW5 3 "23*+/9-" "p_5.output" 1>p_5.stdcout 2>p_5.stderr
bash -c 'diff -iEBwu p_5.output p_5.txt >p_5.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_5      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_5      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_5.diff
fi


./HW5 3 "52^3^472^*-5+725^*+43^4/+" "p_6.output" 1>p_6.stdcout 2>p_6.stderr
bash -c 'diff -iEBwu p_6.output p_6.txt >p_6.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_6      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_6      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_6.diff
fi


./HW5 3 "32+2^3+9-32^+" "p_7.output" 1>p_7.stdcout 2>p_7.stderr
bash -c 'diff -iEBwu p_7.output p_7.txt >p_7.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_7      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_7      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_7.diff
fi


./HW5 3 "231*+9-" "p_8.output" 1>p_8.stdcout 2>p_8.stderr
bash -c 'diff -iEBwu p_8.output p_8.txt >p_8.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_8      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_8      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_8.diff
fi


./HW5 3 "4572+-*" "p_9.output" 1>p_9.stdcout 2>p_9.stderr
bash -c 'diff -iEBwu p_9.output p_9.txt >p_9.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_9      \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_9      \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_9.diff
fi


./HW5 3 "45+234^*-563/*-5+823^*-6/" "p_10.output" 1>p_10.stdcout 2>p_10.stderr
bash -c 'diff -iEBwu p_10.output p_10.txt >p_10.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_10     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_10     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_10.diff
fi


./HW5 3 "34 +2*7/" "p_11.output" 1>p_11.stdcout 2>p_11.stderr
bash -c 'diff -iEBwu p_11.output p_11.txt >p_11.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_11     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_11     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_11.diff
fi

./HW5 3 "a15+9-" "p_12.output" 1>p_12.stdcout 2>p_12.stderr
bash -c 'diff -iEBwu p_12.output p_12.txt >p_12.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_12     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_12     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_12.diff
fi

./HW5 3 "*2+2^13+9-532^+" "p_13.output" 1>p_13.stdcout 2>p_13.stderr
bash -c 'diff -iEBwu p_13.output p_13.txt >p_13.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_13     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_13     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_13.diff
fi

./HW5 3 "*2a+4^5*" "p_14.output" 1>p_14.stdcout 2>p_14.stderr
bash -c 'diff -iEBwu p_14.output p_14.txt >p_14.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_14     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_14     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_14.diff
fi

./HW5 3 "2/4+31^5*" "p_15.output" 1>p_15.stdcout 2>p_15.stderr
bash -c 'diff -iEBwu p_15.output p_15.txt >p_15.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_15     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_15     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_15.diff
fi

./HW5 3 "25a" "p_16.output" 1>p_16.stdcout 2>p_16.stderr
bash -c 'diff -iEBwu p_16.output p_16.txt >p_16.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_16     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_16     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_16.diff
fi

./HW5 3 "32+2^3+9-32^a" "p_17.output" 1>p_17.stdcout 2>p_17.stderr
bash -c 'diff -iEBwu p_17.output p_17.txt >p_17.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_17     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_17     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_17.diff
fi

./HW5 3 "457+-*2" "p_18.output" 1>p_18.stdcout 2>p_18.stderr
bash -c 'diff -iEBwu p_18.output p_18.txt >p_18.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_18     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_18     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_18.diff
fi

./HW5 3 "/a3+-4*17-2" "p_19.output" 1>p_19.stdcout 2>p_19.stderr
bash -c 'diff -iEBwu p_19.output p_19.txt >p_19.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_19     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_19     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_19.diff
fi

./HW5 3 "34+2*7/" "p_20.output" 1>p_20.stdcout 2>p_20.stderr
bash -c 'diff -iEBwu p_20.output p_20.txt >p_20.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_20     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_20     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_20.diff
fi

./HW5 3 "57+62-*" "p_21.output" 1>p_21.stdcout 2>p_21.stderr
bash -c 'diff -iEBwu p_21.output p_21.txt >p_21.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_21     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_21     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_21.diff
fi

./HW5 3 "42+351-*+" "p_22.output" 1>p_22.stdcout 2>p_22.stderr
bash -c 'diff -iEBwu p_22.output p_22.txt >p_22.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_22     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_22     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_22.diff
fi

./HW5 3 "69+42*42^++" "p_23.output" 1>p_23.stdcout 2>p_23.stderr
bash -c 'diff -iEBwu p_23.output p_23.txt >p_23.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_23     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_23     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_23.diff
fi

./HW5 3 "21421+*3++*" "p_24.output" 1>p_24.stdcout 2>p_24.stderr
bash -c 'diff -iEBwu p_24.output p_24.txt >p_24.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_24     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_24     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_24.diff
fi

./HW5 3 "562^2-*" "p_25.output" 1>p_25.stdcout 2>p_25.stderr
bash -c 'diff -iEBwu p_25.output p_25.txt >p_25.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_25     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_25     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_25.diff
fi

./HW5 3 "545*+5/" "p_26.output" 1>p_26.stdcout 2>p_26.stderr
bash -c 'diff -iEBwu p_26.output p_26.txt >p_26.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_26     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_26     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_26.diff
fi

./HW5 3 "12345*+*+" "p_27.output" 1>p_27.stdcout 2>p_27.stderr
bash -c 'diff -iEBwu p_27.output p_27.txt >p_27.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_27     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_27     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_27.diff
fi

./HW5 3 "53+62/*35*+" "p_28.output" 1>p_28.stdcout 2>p_28.stderr
bash -c 'diff -iEBwu p_28.output p_28.txt >p_28.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_28     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_28     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_28.diff
fi

./HW5 3 "23*45/-" "p_29.output" 1>p_29.stdcout 2>p_29.stderr
bash -c 'diff -iEBwu p_29.output p_29.txt >p_29.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_29     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_29     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_29.diff
fi

./HW5 3 "234*-56/+" "p_30.output" 1>p_30.stdcout 2>p_30.stderr
bash -c 'diff -iEBwu p_30.output p_30.txt >p_30.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_30     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_30     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_30.diff
fi

./HW5 3 "42^3-526^*+75/-" "p_31.output" 1>p_31.stdcout 2>p_31.stderr
bash -c 'diff -iEBwu p_31.output p_31.txt >p_31.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_31     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_31     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_31.diff
fi

./HW5 3 "97/" "p_32.output" 1>p_32.stdcout 2>p_32.stderr
bash -c 'diff -iEBwu p_32.output p_32.txt >p_32.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_32     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_32     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_32.diff
fi

./HW5 3 "54/" "p_33.output" 1>p_33.stdcout 2>p_33.stderr
bash -c 'diff -iEBwu p_33.output p_33.txt >p_33.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_33     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_33     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_33.diff
fi

./HW5 3 "98/" "p_34.output" 1>p_34.stdcout 2>p_34.stderr
bash -c 'diff -iEBwu p_34.output p_34.txt >p_34.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_34     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_34     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_34.diff
fi

./HW5 3 "96/" "p_35.output" 1>p_35.stdcout 2>p_35.stderr
bash -c 'diff -iEBwu p_35.output p_35.txt >p_35.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_35     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_35     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_35.diff
fi

./HW5 3 "86/" "p_36.output" 1>p_36.stdcout 2>p_36.stderr
bash -c 'diff -iEBwu p_36.output p_36.txt >p_36.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_36     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_36     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_36.diff
fi

./HW5 3 "086/-" "p_37.output" 1>p_37.stdcout 2>p_37.stderr
bash -c 'diff -iEBwu p_37.output p_37.txt >p_37.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_37     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_37     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_37.diff
fi

./HW5 3 "83/" "p_38.output" 1>p_38.stdcout 2>p_38.stderr
bash -c 'diff -iEBwu p_38.output p_38.txt >p_38.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_38     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_38     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_38.diff
fi

./HW5 3 "054/-" "p_39.output" 1>p_39.stdcout 2>p_39.stderr
bash -c 'diff -iEBwu p_39.output p_39.txt >p_39.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_39     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_39     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_39.diff
fi

./HW5 3 "5233^*-77*+" "p_40.output" 1>p_40.stdcout 2>p_40.stderr
bash -c 'diff -iEBwu p_40.output p_40.txt >p_40.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_40     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_40     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_40.diff
fi

./HW5 3 "054*1+54*/-" "p_41.output" 1>p_41.stdcout 2>p_41.stderr
bash -c 'diff -iEBwu p_41.output p_41.txt >p_41.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_41     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_41     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_41.diff
fi

./HW5 3 "10/" "p_42.output" 1>p_42.stdcout 2>p_42.stderr
bash -c 'diff -iEBwu p_42.output p_42.txt >p_42.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_42     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_42     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_42.diff
fi

./HW5 3 "001-^" "p_43.output" 1>p_43.stdcout 2>p_43.stderr
bash -c 'diff -iEBwu p_43.output p_43.txt >p_43.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_43     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_43     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_43.diff
fi

./HW5 3 "01-12/^" "p_44.output" 1>p_44.stdcout 2>p_44.stderr
bash -c 'diff -iEBwu p_44.output p_44.txt >p_44.diff'
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case p_44     \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e  "Test case p_44     \033[1;92mPASSED.\033[0m"
    # remove the file 2.diff
    rm -f p_44.diff
fi