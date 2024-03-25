arg="$(jot -r 100 0 50000 | tr '\n' ' ' | awk "{print $1}")"
echo $arg
./push_swap $arg > out.txt
echo "Number of ops: "; cat out.txt | wc -l
./checker_Mac $arg < out.txt
