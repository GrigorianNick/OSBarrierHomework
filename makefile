all:
	g++ -g main.cpp -lpthread -o max

gen:
	g++ gen.cpp
	./a.out > random.txt

run: all gen
	cat ./random.txt | ./max

clean:
	rm -f random.txt
	rm -f max
