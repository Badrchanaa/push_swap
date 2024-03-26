max=$(($1 - 1))
arg="$(shuf -i 0-$max)"
echo $arg | tr ' ' ', '
valgrind --log-file=valgrind.txt ./push_swap $arg > out.txt
echo "Number of ops: "; cat out.txt | wc -l
./checker_linux $arg < out.txt
vl=$(cat valgrind.txt | grep "No leaks are possible" | wc -l)
echo $vl
if [$vl -gt 0] then
	echo "No leaks"

	echo "Leaks detected"

