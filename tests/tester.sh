echo "100"
echo "==="
count=15
operations=0
for i in $(seq $count); do
    ./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l
done
echo "\n"
echo "500"
echo "==="
count=15
for i in $(seq $count); do
    ./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` | wc -l
done
echo "\n"
