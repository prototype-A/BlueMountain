# This is a basic shell script that loops through
# the different test names
rm resultsfile.txt
touch resultsfile.txt
tests=(login logout create delete refund buy addCredit sell);
numTests=(3 5 6 5 5 5 5 5);
for i in {0..7}; do 
    test=${tests[$i]}
    for num in $(seq 1 ${numTests[$i]}); do
        echo $test$num.in
        #Starts the program
        ./console currentaccounts.txt availabletickets.txt transout.atf

        #Runs the commands saving the output to a temp output file
        sh $test$num.in > out.out

        #Saves the differences between the files and recrods info
        outputDiff=$(diff out.out $test$num.out)
        diff out.out $test$num.out > $test$numerrors.out
        toutputDiff=$(diff dailytransactionfile.txt $test$num.tout)
        diff dailytransactionfile.txt $test$num.tout > $test$numerrors.tout
        
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
