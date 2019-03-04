# This is a basic shell script that loops through
# the different test names
rm resultsfile.txt
touch resultsfile.txt
mkdir -p ErrorReports
mkdir -p OutFiles
tests=(login logout create delete refund buy addcredit sell);
#parent_path=$( cd "$dirname "${BASH_SOURCE[0]}")" ; pwd -P )
#cd "$parent_path"
numTests=(4 8 13 4 9 10 5 13);
for i in {0..7}; do 
    test=${tests[$i]}
    for num in $(seq 1 ${numTests[$i]}); do
        echo Testing FrontEndRequirements/input/$test/$test$num.inp

        #Starts the program and passes in the output of shcat $test$num.in line by line
        cat FrontEndRequirements/input/$test/$test$num.inp | ./FrontEndRapidPrototype/main > OutFiles/$test$num.out

        #Saves the differences between the files and recrods info
        echo Comparing $test$num.out
        diff OutFiles/$test$num.out FrontEndRequirements/output/$test/$test$num.out > ErrorReports/$test${num}errors.out
        echo Comparing $test$num.tout
        toutputDiff=$(diff FrontEndRapidPrototype/dailytransactionfile.txt FrontEndRequirements/output/$test/$test$num.tout)
        diff FrontEndRapidPrototype/dailytransactionfile.txt FrontEndRequirements/output/$test/$test$num.tout > ErrorReports/$test${num}errors.tout
        
        if diff -w OutFiles/$test$num.out FrontEndRequirements/output/$test/$test$num.out > /dev/null
        then
            echo $test$num PASSED >> resultsfile.txt
        else
            echo $test$num FAILED >> resultsfile.txt
        fi
    done
done
