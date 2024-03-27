ops=0
count=0
while [[ $ops -lt 701 ]]
do
	arg="$(jot -r 100 -900000000 900000000 | tr '\n' ' ' | awk "{print $1}")"
	echo $arg | tr ' ' ', '
	./push_swap $arg > out.txt
	ops=$(cat out.txt | wc -l)
	count=$(($count + 1))
	echo "Number of ops: "; cat out.txt | wc -l
	echo "Count: " $count
	./checker_Mac $arg < out.txt
done;
