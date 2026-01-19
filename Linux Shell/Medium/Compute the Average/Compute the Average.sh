read N
sum=0

for ((i=0; i<N; i++)); do
    read num
    sum=$((sum + num))
done

printf "%.3f" $(echo "$sum / $N" | bc -l)