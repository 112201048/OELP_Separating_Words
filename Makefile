all:
	g++ prob.cpp -o prob

run:
	./prob
	python3 plot.py
	
clean:
	rm -f prob data.txt
