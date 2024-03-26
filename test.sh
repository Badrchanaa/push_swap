max=$(($1 - 1))
arg="$(shuf -i 0-$max)"
echo $arg | tr ' ' ', '
./push_swap $arg > out.txt
echo "Number of ops: "; cat out.txt | wc -l
./checker_linux $arg < out.txt
