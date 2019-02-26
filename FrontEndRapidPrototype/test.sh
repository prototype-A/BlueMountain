# This is a basic shell script that loops through
# the different test names
tests = (login logout create delete refund buy addCredit sell);
numTests = (3 5 6 5 5 5 5 5);
for i in {0..8}; do 
    test = ${tests[$i]}
    for num in $(seq 1 ${numTests[$i]}); do
    echo $test $num
    done
done
