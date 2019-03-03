# This is a basic shell script that loops through
# the different test names
rm resultsfile.txt
touch resultsfile.txt
tests=(login logout create delete refund buy addCredit sell);
numTests=(4 8 13 4 9 10 5 13);
for i in {0..7}; do 
    test=${tests[$i]}
    for num in $(seq 1 ${numTests[$i]}); do
        echo Testing $test$num.in
        #Starts the program and passes in the output of shcat $test$num.in line by line
        cat $test$num.in |./main currentaccounts.txt availabletickets.txt transout.atf > out.out

        #Saves the differences between the files and recrods info
        echo Comparing $test$num.out
        outputDiff=$(diff out.out $test$num.out)
        diff out.out $test$num.out > $test${num}errors.out
        echo Comparing $test$num.tout
        toutputDiff=$(diff dailytransactionfile.txt $test$num.tout)
        diff dailytransactionfile.txt $test$num.tout > $test${num}errors.tout
        
        #If it passes (diff empty) then records the test as a pass in file
        if [ "$outputDiff" != "" ]
        then
            echo $test$num PASSED >> resultsfile.txt
        #If it doesnt pass append a failure
        else
            echo $test$num FAILED >> resultsfile.txt;
        fi
    done
done
