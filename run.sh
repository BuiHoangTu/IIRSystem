gcc iirGenerator.c  -o iirGenerator.out -O3
./iirGenerator.out | python3 ./draw.py